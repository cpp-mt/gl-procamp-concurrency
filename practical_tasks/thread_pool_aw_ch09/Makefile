
GCC := g++

OUTPUT := thread_pool_simple
SOURCES := $(wildcard *.cpp)
CCFLAGS := -std=c++14 -pthread

all: $(OUTPUT)

thread_pool_simple: 
	$(GCC) -o thread_pool_simple $(CCFLAGS) thread_pool_simple.cpp

clean:
	rm $(OUTPUT)

.PHONY: all

