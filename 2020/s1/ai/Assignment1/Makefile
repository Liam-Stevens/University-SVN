all: pathfinder test

pathfinder: Node.h Node.cpp Graph.h Graph.cpp helpers.h helpers.cpp map.h main.cpp
	g++ -Wall -o pathfinder.bin Node.cpp Graph.cpp helpers.cpp main.cpp

test: pathfinder.bin
	./pathfinder.bin map.txt ucs
