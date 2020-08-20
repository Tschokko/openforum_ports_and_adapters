#!/bin/sh
CC="${CC:-g++}"
CFLAGS="${CFLAGS:--O2 -Wall -g}"
CPPFLAGS="${CPPFLAGS:--std=c++17}"
LDFLAGS=

$CC $CPPFLAGS $CFLAGS -c -o build/main.o src/main.cpp && \
$CC $CFLAGS $LDFLAGS -o bin/demo build/main.o
