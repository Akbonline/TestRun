CC = g++
CFLAGS = -std=c++11

main: main.cpp
	g++ -c -std=c++11 main.cpp

test1:
	g++ -std=c++11 testfile.cpp
	./a.out

test2:
	g++ -std=c++11 testfile2.cpp
	./a.out

test3:
	g++ -std=c++11 testfile3.cpp
	./a.out

clean:
	rm -f core *.o a.out test
	clear