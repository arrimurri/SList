# makefile
CC = g++ -Wall -Wextra
test: test.o testclass.o slist.o elem.o
	$(CC) -o test test.o testclass.o slist.o elem.o
test.o: test.cpp
	$(CC) -c test.cpp
testclass.o: testclass.cpp
	$(CC) -c testclass.cpp
slist.o: slist.cpp
	$(CC) -c slist.cpp
elem.o: elem.cpp
	$(CC) -c elem.cpp
