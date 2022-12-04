Compile .proto file

```
protoc --go_out=. --go_opt=paths=source_relative --go-grpc_out=. --go-grpc_opt=paths=source_relative grpcdistribuidos/grpcdistribuidos.proto
```

Run server

```
go run .\server\main.go
```

Run client

```
go run .\client\main.go
```