package main

import (
	"context"
	"flag"
	"fmt"
	"log"
	"net"
	"time"

	pb "grpcdistribuidos/grpcdistribuidos"

	"net/http"

	"github.com/bt51/ntpclient"
	"google.golang.org/grpc"

	gohttpclient "github.com/bozd4g/go-http-client"
)

var (
	port       = flag.Int("port", 50051, "The server port")
	httpClient = http.Client{
		Timeout: time.Second * 2, // Timeout after 2 seconds
	}
)

type server struct {
	pb.UnimplementedDistribuidosServer
}

func (s *server) GetTimestamp(ctx context.Context, in *pb.GetTimestampParams) (*pb.TimestampReply, error) {
	log.Printf("Recebido: requisicao de timestamp")
	t, err := ntpclient.GetNetworkTime("0.pool.ntp.org", 123)
	if err != nil {
		fmt.Println(err)
	}
	return &pb.TimestampReply{Timestamp: t.Unix()}, nil
}

type CoinsambaIndexRes struct {
	Success  bool
	Message  string
	Response CoinsambaIndexResResponse
}

type CoinsambaIndexResResponse struct {
	Open   float64
	High   float64
	Low    float64
	Close  float64
	Vol    float64
	Change float64
}

func (s *server) GetCryptoPrice(ctx context.Context, in *pb.GetCryptoPriceParams) (*pb.GetCryptoPriceReply, error) {
	log.Printf("Recebido: requisicao de preco de criptomoeda %s", in.GetSymbol())

	client := gohttpclient.New("https://api.coinsamba.com/v1")

	response, err := client.Get(ctx, fmt.Sprintf("/index?base=%s&quote=BRL", in.GetSymbol()))
	if err != nil {
		log.Fatalf("error: %v", err)
	}

	fmt.Println(response.Get().Request.URL.String())

	var index CoinsambaIndexRes
	if err := response.Unmarshal(&index); err != nil {
		log.Fatalf("error: %v", err)
	}

	return &pb.GetCryptoPriceReply{Price: index.Response.Close}, nil
}

func main() {
	flag.Parse()
	lis, err := net.Listen("tcp", fmt.Sprintf(":%d", *port))
	if err != nil {
		log.Fatalf("failed to listen: %v", err)
	}
	s := grpc.NewServer()
	pb.RegisterDistribuidosServer(s, &server{})
	log.Printf("server listening at %v", lis.Addr())
	if err := s.Serve(lis); err != nil {
		log.Fatalf("failed to serve: %v", err)
	}
}
