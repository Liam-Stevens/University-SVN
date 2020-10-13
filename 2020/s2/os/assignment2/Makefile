all: compile FIFOtest

compile: PageReplacement.cpp
	g++ -std=c++11 -Wall PageReplacement.cpp -o PageReplacement

FIFOtest: PageReplacement
	./PageReplacement test_data/case0/input.txt 4096 32 FIFO

LRUtest:
	./PageReplacement test_data/case0/input.txt 4096 32 LRU

ARBtest:
	./PageReplacement test_data/case0/input.txt 1024 16 ARB 3 3

WSARB1test:
	./PageReplacement test_data/case0/input.txt 4096 32 WSARB-1 8 3 11

WSARB2test:
	./PageReplacement test_data/case0/input.txt 4096 32 WSARB-2 8 3 11
