all: creditrating test

creditrating: helpers.cpp helpers.h data.h main.cpp
	g++ -Wall -o creditrating.bin helpers.cpp main.cpp

test: creditrating.bin
	./creditrating.bin data/train01 data/test01 20
