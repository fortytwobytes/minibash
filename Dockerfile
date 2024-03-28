FROM gcc:10-bookworm

WORKDIR /app

COPY . .

RUN make

ENTRYPOINT ["./minibash"]
