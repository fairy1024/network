header_path = -I/home/zhong/webServer/tiny-network/src/base -I/home/zhong/webServer/tiny-network/src/net -I/home/zhong/webServer/tiny-network/src/timer -I/home/zhong/webServer/tiny-network/src/logger
LIBS=-ltiny_network -lpthread
CFLAGS= -g -Wall

all:server test

server: HttpServer.cc HttpContext.cc HttpResponse.cc
	g++ HttpServer.cc HttpContext.cc HttpResponse.cc ${CFLAGS} ${header_path} ${LIBS} -o HttpServer

clean:
	rm -r HttpServer

