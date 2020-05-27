compileAll: distanceVectorCompile poisonedReverseCompile

developmentTest: distanceVectorCompile DVtest

distanceVectorCompile: main.cpp
	g++ -Wall -o DistanceVector main.cpp

DVtest: DistanceVector
	./DistanceVector sampleData/config0 sampleData/configConfig0

poisonedReverseCompile: main.cpp
	g++ -Wall -o PoisonedReverse main.cpp

PRtest: PoisonedReverse
	./PoisonedReverse sampleData/config0 sampleData/configConfig0
