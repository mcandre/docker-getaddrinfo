#!/bin/sh

build_bot_dir="$(dirname $0)"

docker build -t mcandre/getaddrinfo-build-bot "$build_bot_dir"
