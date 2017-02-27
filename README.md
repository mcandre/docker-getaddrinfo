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
-h		Show usage information
```

# REQUIREMENTS

* [Docker](https://www.docker.com)
* [gcc](https://gcc.gnu.org)
* [libc6-dev](https://www.gnu.org/software/libc/), [musl-dev](http://www.musl-libc.org), etc.

## Optional

* [make](https://www.gnu.org/software/make/)

# COMPILE FOR HOST OS TARGET

```console
$ make clean && make
```

# CROSS-COMPILE FOR LINUX TARGET

```console
$ crosscompile/build.sh
$ crosscompile/compile.sh

$ file bin/getaddrinfo
bin/getaddrinfo: ELF 64-bit LSB shared object, x86-64, version 1 (SYSV), dynamically linked, not stripped

$ ./build.sh
```

# PUBLISH

```console
$ docker push mcandre/getaddrinfo-build-bot
$ docker push mcandre/docker-getaddrinfo
```
