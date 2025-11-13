FROM debian:latest AS build
RUN apt update && apt install just gcc -y
WORKDIR /app
COPY . .
RUN just build-static

FROM scratch AS base
WORKDIR /
COPY --from=build /app/c_node c_node
CMD [ "/c_node" ]
