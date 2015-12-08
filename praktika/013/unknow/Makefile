CXX=g++
CXXFLAGS=-std=c++14 -isystem ../../../vendor/ -ggdb -Wall -Wextra -Wpedantic -Wconversion -Wsign-conversion -c
LDFLAGS=-lpthread -lX11
SOURCES=./main.cpp ./MyRectangle.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=main
TEST_SOURCES=./test/main.cpp ./test/collision_test.cpp ./MyRectangle.cpp
TEST_OBJECTS=$(TEST_SOURCES:.cpp=.o)
TEST_EXECUTABLE=test_main

all: $(SOURCES) $(EXECUTABLE)

test: CXXFLAGS += -D UNITTEST
test: $(TEST_SOURCES) $(TEST_EXECUTABLE)

$(TEST_EXECUTABLE): $(TEST_OBJECTS)
	$(CXX) $(LDFLAGS) $(TEST_OBJECTS) -o $@

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -f *.o */*.o

distclean: clean
	rm -f ./$(EXECUTABLE) ./$(TEST_EXECUTABLE)
