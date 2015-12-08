CXX="g++"
CXXFLAGS=-std=c++14 -ggdb -Wall -Wextra -Wpedantic -Wconversion -Wsign-conversion

all: default main.o gui.o calc.o clean

default: main.o gui.o calc.o
	$(CXX) $(CXXFLAGS) main.o gui.o calc.o -o bin/test

main.o:
	$(CXX) $(CXXFLAGS) -c main.cc include/calc.h include/gui.h

gui.o: src/gui.cc include/gui.h
	$(CXX) $(CXXFLAGS) -c src/gui.cc include/gui.h

calc.o: src/calc.cc include/calc.h
	$(CXX) $(CXXFLAGS) -c src/calc.cc include/calc.h

clean:
	rm *.o
