CXX="g++"
CXXFLAGS=-std=c++11 -Wall
EXECUTABLE=bin/main
SOURCES=main.cc sort.cc
OBJECTS=$(SOURCES:.cc=.o)

all: default $(OBJECTS)

default: main.o sort.o
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(EXECUTABLE)

main.o:
	$(CXX) $(CXXFLAGS) -c main.cc include/sort.h

sort.o: src/sort.cc include/sort.h
	$(CXX) $(CXXFLAGS) -c src/sort.cc include/sort.h
clean:
	rm *.o
distclean: clean
	rm bin/*
