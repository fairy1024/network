header_path = -I../../base -I../../net
LIBS=-lpthread
CFLAGS= -g -Wall

test: test.cc
	g++ test.cc ${CFLAGS} ${header_path} ${LIBS}  -o test

clean:
	rm -r test

