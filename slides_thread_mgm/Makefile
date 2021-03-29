#CXX = g++-7
CXX = g++
CC=gcc
CPPSTD=-std=c++17
#DEBUG=-O
CXXFLAGS  =  -Wall $(DEBUG) $(CPPSTD) -pthread

BINS= thread_raii \
      this_thread \
      tls 


all: $(BINS)

clean:
	- rm -f *.o $(BINS)

