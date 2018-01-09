# Put the directory above 'DNest4' into an environment variable
# called DNEST4_PATH for this to work.

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
	python3 model_gen.py

show:
	python3 showresults.py

clean:
	rm -rf *.o
	rm -rf __pycache__

cleantxt:
	rm -rf *.o main
	rm -rf __pycache__
	rm levels.txt posterior_sample.txt sample_info.txt sample.txt sampler_state.txt weights.txt

cleanall:
	rm -rf *.o main __pycache__ *.txt MyModel.cpp MyModel.h
