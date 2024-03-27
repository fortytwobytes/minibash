FROM alpine:latest

WORKDIR /app

RUN apk add libc-dev readline-dev make gcc

COPY . .

RUN make

ENTRYPOINT ["./minibash"]

