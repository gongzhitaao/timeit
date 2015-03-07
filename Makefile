CXX = g++
AR = ar
FLAGS = -Wall -O2 -std=c++11

all : timeit

timeit : timeit.cpp timeit.h
	$(CXX) $(FLAGS) -o lib$@.o -c $<
	$(AR) rcs lib$@.a lib$@.o

clean :
	rm -rf libtimeit.o libtimeit.a

.PHONY : all clean
