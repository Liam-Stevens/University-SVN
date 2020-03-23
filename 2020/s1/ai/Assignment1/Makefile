all: pathfinder test

pathfinder: Node.cpp Graph.cpp helpers.cpp main.cpp
	g++ -o pathfinder.bin Node.cpp Graph.cpp helpers.cpp main.cpp

test: pathfinder.bin
	./pathfinder.bin map.txt bfs euclidean
