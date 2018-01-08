# Put the directory above 'DNest4' into an environment variable
# called DNEST4_PATH for this to work.

CC = g++
CXXFLAGS = -std=c++11 -O3 -Wall -Wextra -pedantic -DNDEBUG
LIBS = -ldnest4 -lpthread

default:
	$(CC) -I ../../inst/DNest4/include/ $(CXXFLAGS) -c *.cpp
	$(CC) -pthread -L ../../inst/DNest4/lib/ -o main *.o $(LIBS)
	rm *.o

clean:
	rm -rf *.o
	rm -rf __pycache__

cleanall:
	rm -rf *.o main __pycache__ *.txt MyModel.cpp MyModel.h