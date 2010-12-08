# makefile
CC = g++ -Wall -Wextra
test: testclass.o slist.o elem.o
	$(CC) -o test test.cpp testclass.o slist.o elem.o
testclass.o: testclass.cpp
	$(CC) -c testclass.cpp
slist.o: slist.cpp slist.h
	$(CC) -c slist.cpp
elem.o: elem.cpp elem.h
	$(CC) -c elem.cpp
