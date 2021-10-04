all: mstprimdriver


# list the test program all classes (cpp files)
#  cpp files must use #include , to include *.h or *.hpp files

mstprimdriver: mstprimtest.cpp illegal_exception.cpp Edge.cpp Graph.cpp Vertex.cpp MinPQ.cpp
	g++ -std=c++11 -o mstprimdriver mstprimtest.cpp illegal_exception.cpp Edge.cpp Graph.cpp Vertex.cpp MinPQ.cpp

# List all the executables under 'all:'
clean:
	rm *.o mstprimdriver