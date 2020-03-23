all: pathfinder test

main.o:
	g++ -c main.cpp

helpers.o:
	g++ -c helpers.cpp

Node.o:
	g++ -c Node.cpp

Graph.o:
	g++ -c Graph.cpp

pathfinder: Node.o Graph.o helpers.o main.o
	g++ -o pathfinder.bin Node.o Graph.o helpers.o main.o

test: pathfinder.bin
	./pathfinder.bin map.txt bfs euclidean
