# mcandre/docker-getaddrinfo - getaddrinfo() example dans Docker containers

# EXAMPLES

```console
$ docker run mcandre/docker-getaddrinfo google.com
172.217.4.110
172.217.4.110
2607:f8b0:4009:800::200e
2607:f8b0:4009:800::200e

$ docker run mcandre/docker-getaddrinfo localhost
::1
::1
127.0.0.1
127.0.0.1

$ docker run mcandre/docker-getaddrinfo -t tcp google.com
172.217.4.110
2607:f8b0:4009:800::200e

$ docker run mcandre/docker-getaddrinfo -t udp google.com
172.217.4.110
2607:f8b0:4009:800::200e

$ docker run mcandre/docker-getaddrinfo -f v4 square.com
74.122.190.80
74.122.190.80

$ docker run mcandre/docker-getaddrinfo -f v6 square.com
Error resolving address square.com: Name does not resolve

$ docker run mcandre/docker-getaddrinfo -h
Usage: /bin/getaddrinfo <address>

-s <service>	Specify a port number or well known network service name
-f <family>	Specify a network family (any, v4, v6)
-t <socket>	Specify a socket type (any, tcp, udp)
-p <protocol>	Specify a protocol (any, tcp, udp, icmp)
-g <value>	Specify hints.ai_flags as an integer
-h		Show usage information
```

# REQUIREMENTS

* [Docker](https://www.docker.com)
* [gcc](https://gcc.gnu.org)
* [libc6-dev](https://www.gnu.org/software/libc/), [musl-dev](http://www.musl-libc.org), etc.

## Optional

* [make](https://www.gnu.org/software/make/)
* [editorconfig-cli](https://github.com/amyboyd/editorconfig-cli) (e.g. `go get github.com/amyboyd/editorconfig-cli`)
* [flcl](https://github.com/mcandre/flcl) (e.g. `go get github.com/mcandre/flcl/...`)

# COMPILE FOR HOST OS TARGET

```console
$ make clean && make
```

# CROSS-COMPILE FOR LINUX TARGET

```console
$ bash crosscompile/build-docker
$ bash crosscompile/compile-c

$ file bin/getaddrinfo
bin/getaddrinfo: ELF 64-bit LSB shared object, x86-64, version 1 (SYSV), dynamically linked, not stripped

$ bash build-docker
```

# PUBLISH

```console
$ docker push mcandre/getaddrinfo-build-bot
$ docker push mcandre/docker-getaddrinfo
```
