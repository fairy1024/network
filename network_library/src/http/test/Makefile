header_path = -I/home/zhong/webServer/tiny-network/src/base -I/home/zhong/webServer/tiny-network/src/net
LIBS=-lpthread
CFLAGS= -g -Wall

test: test.cc
	g++ test.cc ${CFLAGS} ${header_path} ${LIBS}  -o test

clean:
	rm -r test

