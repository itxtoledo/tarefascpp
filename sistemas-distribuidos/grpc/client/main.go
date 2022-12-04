package main

import (
	"context"
	"flag"
	"fmt"
	"log"
	"time"

	pb "grpcdistribuidos/grpcdistribuidos"

	"github.com/eiannone/keyboard"
	"google.golang.org/grpc"
	"google.golang.org/grpc/credentials/insecure"
)

var (
	addr = flag.String("addr", "localhost:50051", "the address to connect to")
)

func main() {
	flag.Parse()
	// Set up a connection to the server.
	conn, err := grpc.Dial(*addr, grpc.WithTransportCredentials(insecure.NewCredentials()))
	if err != nil {
		log.Fatalf("did not connect: %v", err)
	}
	defer conn.Close()
	c := pb.NewDistribuidosClient(conn)

	if err := keyboard.Open(); err != nil {
		panic(err)
	}
	defer func() {
		_ = keyboard.Close()
	}()

	fmt.Println("Press ESC to quit")
	for {
		char, key, err := keyboard.GetKey()
		if err != nil {
			panic(err)
		}
		fmt.Printf("You pressed: rune %q, key %X\r\n", char, key)
		if key == keyboard.KeyEsc {
			break
		} else if key == keyboard.KeyCtrlT {
			ctx, cancel := context.WithTimeout(context.Background(), time.Second)
			defer cancel()
			r, err := c.GetTimestamp(ctx, &pb.GetTimestampParams{})
			if err != nil {
				log.Fatalf("could not get timestamp: %v", err)
			}
			parsed := time.Unix(r.GetTimestamp(), 0)
			log.Printf("Recebido: %v", parsed)
		} else if key == keyboard.KeyCtrlB {
			ctx, cancel := context.WithTimeout(context.Background(), time.Second)
			defer cancel()
			r, err := c.GetCryptoPrice(ctx, &pb.GetCryptoPriceParams{Symbol: "BTC"})
			if err != nil {
				log.Fatalf("could not get bitcoin price: %v", err)
			}
			log.Printf("Recebido: %v", r.Price)
		}
	}

}
