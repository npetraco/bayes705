CXX = g++
export CXX
CXXFLAGS = -std=c++11 -O3 -Wall -Wextra -pedantic -DNDEBUG
LIBS = -ldnest4 -lpthread

default:
	$(CXX) -I ../../inst/DNest4/include/ $(CXXFLAGS) -c *.cpp
	$(CXX) -pthread -L ../../inst/DNest4/lib/ -o main *.o $(LIBS)
	rm *.o

clean:
	rm -rf *.o
	rm -rf __pycache__

