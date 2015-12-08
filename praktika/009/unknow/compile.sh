#!/bin/bash
OPTIONS="-std=c++14 -ggdb -Wall -Wextra -Wpedantic -Wconversion -Wsign-conversion"
g++ -c $OPTIONS *.cc
g++ -o main *.o
rm *.o
