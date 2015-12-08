CXX=g++
CXXFLAGS=-std=c++14 -ggdb -Wall -Wextra -Wpedantic -Wconversion -Wsign-conversion -c
LDFLAGS=
SOURCES=main.cpp gui.cpp calc.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=main

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -f *.o

distclean: clean
	rm -f ./$(EXECUTABLE)
