#!/bin/sh

for f in source/*.cpp
do
    g++ -g -Wall -std=c++14 -Iinclude -c $f -o "${f%.*}.o"
    mv "${f%.*}.o" obj
done

ar rvs lib/libplaisio.a "obj/*.o"
