compileAll: distanceVectorCompile poisonedReverseCompile

developmentTest: distanceVectorCompile DVtest

distanceVectorCompile: data.h helpers.h helpers.cpp main.cpp
	g++ -Wall -o DistanceVector helpers.cpp main.cpp

DVtest: DistanceVector
	./DistanceVector sampleData/config0 sampleData/changeConfig0

poisonedReverseCompile: main.cpp
	g++ -Wall -o PoisonedReverse main.cpp

PRtest: PoisonedReverse
	./PoisonedReverse sampleData/config0 sampleData/configConfig0
