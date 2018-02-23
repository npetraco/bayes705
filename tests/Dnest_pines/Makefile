# Handy Makefile to manage a DNest project.
# 1. Make sure -I and -L options are set to find the DNest library components.
# 2. Also compiler (CC) should be the same one used to compile the DNest library. 

CC = g++
CXXFLAGS = -std=c++11 -O3 -Wall -Wextra -pedantic -DNDEBUG
LIBS = -ldnest4 -lpthread

default:
	$(CC) -I ../../inst/DNest4/include/ $(CXXFLAGS) -c *.cpp
	$(CC) -pthread -L ../../inst/DNest4/lib/ -o main *.o $(LIBS)
	rm *.o

copy:
	cp ../Dnest_template/* .

gen:
	python3 -B model_gen.py

show:
	python3 -B showresults.py

clean:
	rm -rf *.o main __pycache__ levels.txt posterior_sample.txt sample_info.txt sample.txt sampler_state.txt weights.txt

cleantxt:
	rm -rf *.o
	rm -rf __pycache__
	rm levels.txt posterior_sample.txt sample_info.txt sample.txt sampler_state.txt weights.txt

cleanall:
	rm -rf *.o main __pycache__ *.txt MyModel.cpp MyModel.h
