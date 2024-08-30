header_path = -I../base -I../net -I../timer -I../logger
LIBS=-ltiny_network -lpthread
CFLAGS= -g -Wall

server: HttpServer.cc HttpContext.cc HttpResponse.cc main.cc
	g++ main.cc HttpServer.cc HttpContext.cc HttpResponse.cc ${CFLAGS} ${header_path} ${LIBS} -o HttpServer

clean:
	rm -r HttpServer

