
GCC := g++-7
GCC := g++
#CC := clang
#CXX := clang

SOURCES := $(wildcard *.cpp)
#CCFLAGS := -std=c++17 -pthread -fsanitize=thread
CCFLAGS := -std=c++17 -pthread  -lstdc++
#CXXFLAGS := -std=c++17 -pthread -lstdc++
CXXFLAGS := -std=c++17 -pthread 
EXECUTABLES := false_sharing_intel \
               false_sharing_solved \
               branch_prediction


all: $(EXECUTABLES)


false_sharing_intel: false_sharing_intel.cpp time_logger.cpp

false_sharing_solved: false_sharing_solved.cpp time_logger.cpp


clean:
	- rm $(EXECUTABLES) 

.PHONY: all

