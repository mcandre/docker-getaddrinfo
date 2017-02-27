FROM alpine
COPY bin/getaddrinfo /bin/getaddrinfo
ENTRYPOINT ["/bin/getaddrinfo"]
