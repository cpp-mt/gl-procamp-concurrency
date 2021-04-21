CXX = g++
#LD = g++
CC=g++

CXXFLAGS  = -Wall $(DEBUG) -std=c++14 -pthread 

BINS= runner \
     
all: $(BINS)

.cpp.o: $(DEPS)
	@echo "executing rule .o.cpp"
	$(CXX) -c -o $@ $< $(CXXFLAGS)

#.o.cpp : 
#	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $^ 


#OBJS= atm.o 
OBJS= 

runner : runner.o $(OBJS)
	@echo "Building $@"
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread -o $@ $^  

clean:
	- rm -f *.o $(BINS)
