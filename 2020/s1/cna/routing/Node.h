#ifndef NODE_H
#define NODE_H

#include <vector>
#include <string>

class Node
{
private:
    std::string key;
    int id;
    std::vector<int> connections;
    std::vector<int> localWeights;
    std::vector< std::vector<int> > distanceTable;

public:
	//Constructor
    Node();
    Node(std::string newKey, int newId);

    //Setters
    void setKey(std::string newKey);
    void setId(int newId);

    //Getters
    std::string getKey();
    int getId();
    std::vector<int> getConnections();
    std::vector<int> getLocalWeights();
    std::vector< std::vector<int> > getTable();

    //Functions

    //Adds a neighbour and weight of the connection
    void addConnection(int, int);

    void initializeTable(int);

    bool updateTable(std::vector< std::vector<int> >);

    //Debug
    void printTable();
};


#endif
