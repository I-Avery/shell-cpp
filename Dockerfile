# Build
FROM gcc:latest AS builder
WORKDIR /app
COPY . .

# compile
RUN g++ -std=c++17 -o my_shell src/main.cpp

# runtime
FROM ubuntu:24.04
WORKDIR /root/

COPY --from=builder /app/my_shell .
RUN apt-get update && apt-get install -y libstdc++6

ENTRYPOINT ["./my_shell"]