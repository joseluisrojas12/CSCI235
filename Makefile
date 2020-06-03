CXX=g++
CXXFLAGS=-Wall -g

main: main.o Vector.o Set.o
	$(CXX) $(CXXFLAGS) main.o Vector.o Set.o -o main

Vector.o: Vector.cpp Vector.h
	$(CXX) $(CXXFLAGS) -c Vector.cpp

Set.o: Set.cpp Set.h
	$(CXX) $(CXXFLAGS) -c Set.cpp

clean:
	rm main Set.o Vector.o
