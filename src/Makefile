CXX=g++
CXXFLAG= -Wall -std=c++11
LDFLAGS=

.PHONY: all debug clean

all:
	@$(CXX) $(CXXFLAGS) *.cpp $(LDFLAGS)

debug:
	@$(CXX) $(CXXFLAGS) -ggdb *.cpp $(LDFLAGS)

clean:
	@rm a.out
