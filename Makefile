CXX = g++
AR = ar
FLAGS = -Wall -O2 -std=c++11

all : timeit

timeit : timeit.cpp timeit.h
	$(CXX) $(FLAGS) -o $@.o -c $<
	$(AR) rcs $@.a $@.o

clean :
	rm -rf timeit.o timeit.a

.PHONY : all clean
