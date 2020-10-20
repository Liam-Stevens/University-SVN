all: compile ARBtest

compile: PageReplacement.cpp
	g++ -std=c++11 -Wall PageReplacement.cpp -o PageReplacement

FIFOtest: PageReplacement
	./PageReplacement test_data/case1/input.txt 4096 4 FIFO

LRUtest:
	./PageReplacement test_data/case0/input.txt 4096 32 LRU

ARBtest:
	./PageReplacement test_data/case2/input.txt 4096 4 ARB 1 1

WSARB1test:
	./PageReplacement test_data/case0/input.txt 4096 32 WSARB-1 8 3 11

WSARB2test:
	./PageReplacement test_data/case0/input.txt 4096 32 WSARB-2 8 3 11
