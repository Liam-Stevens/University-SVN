#ifndef NODE_H
#define NODE_H

#include <vector>
#include <string>

class Node
{
private:
    std::string key;
    int id;
    std::vector<std::string> keyList;
    std::vector<int> connections;
    std::vector<int> localWeights;
    std::vector< std::vector<int> > distanceTable;

public:
	//Constructor
    Node(std::string, int);

    //Setters
    void setKey(std::string);
    void setId(int);
    void setKeys(std::vector<std::string>);

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

    bool updateTable(int, std::vector< std::vector<int> >, int);

    int getLeastDistance(std::vector<int>);
    int findMax(std::vector<int>);
    bool differentTables(std::vector< std::vector<int> >, std::vector< std::vector<int> >, int);

    void outputTableChange(int, int, int, int, int);

    //Debug
    void printTable();
};


#endif
