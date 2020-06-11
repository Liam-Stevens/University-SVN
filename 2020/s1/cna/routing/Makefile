compileAll: distanceVectorCompile poisonedReverseCompile

developmentTest: distanceVectorCompile DVtest poisonedReverseCompile PRtest

distanceVectorCompile: data.h helpers.h helpers.cpp Node.h Node.cpp Graph.h Graph.cpp main.cpp
	g++ -Wall -o DistanceVector helpers.cpp Node.cpp Graph.cpp main.cpp

DVtest: DistanceVector
	./DistanceVector sampleData/configL sampleData/changeConfigL

poisonedReverseCompile: data.h helpers.h helpers.cpp Node.h Node.cpp Graph.h Graph.cpp mainPoisoned.cpp
	g++ -Wall -o PoisonedReverse helpers.cpp Node.cpp Graph.cpp mainPoisoned.cpp

PRtest: PoisonedReverse
	./PoisonedReverse sampleData/configP sampleData/changeConfigP
