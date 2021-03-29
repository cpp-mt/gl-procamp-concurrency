#CXX = g++-7
CXX = g++
CC=gcc
CPPSTD=-std=c++17
#CPPSTD=-std=c++14
#DEBUG=-O
CXXFLAGS  =  -Wall $(DEBUG) $(CPPSTD) -pthread

BINS= timed_mutex_sample \
      shared_mutex_sample \
      big_buff_deadlock \
      counter_non_atomic


all: $(BINS)

clean:
	- rm -f *.o $(BINS)

