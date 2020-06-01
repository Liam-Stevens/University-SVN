compileAll: distanceVectorCompile poisonedReverseCompile

developmentTest: distanceVectorCompile DVtest

distanceVectorCompile: data.h helpers.h helpers.cpp Node.h Node.cpp Graph.h Graph.cpp main.cpp
	g++ -Wall -o DistanceVector helpers.cpp Node.cpp Graph.cpp main.cpp

DVtest: DistanceVector
	./DistanceVector sampleData/config0 sampleData/changeConfig0

poisonedReverseCompile: data.h helpers.h helpers.cpp Node.h Node.cpp Graph.h Graph.cpp main.cpp
	g++ -Wall -o PoisonedReverse helpers.cpp Node.cpp Graph.cpp main.cpp

PRtest: PoisonedReverse
	./PoisonedReverse sampleData/configL sampleData/configConfigL
