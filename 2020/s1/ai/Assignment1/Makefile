all: pathfinder test

pathfinder: helpers.cpp main.cpp
	g++ -o pathfinder.bin helpers.cpp main.cpp

test: pathfinder.bin
	./pathfinder.bin map.txt bfs euclidean
