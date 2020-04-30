all: creditrating test

creditrating: Node.h Node.cpp Graph.h Graph.cpp helpers.h helpers.cpp data.h main.cpp
	g++ -Wall -o creditrating.bin Node.cpp Graph.cpp helpers.cpp main.cpp

test: creditrating.bin
	./creditrating.bin data/train01 data/test01 20
