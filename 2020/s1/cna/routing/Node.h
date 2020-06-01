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

    //Modifies the weight of a connection (or creates new ones if one does not exist)
    void changeConnection(int, int);

    //Initializes the whole table to INF
    void initializeTable(int);

    //Update this node table with another node's table
    bool updateTable(int, std::vector< std::vector<int> >, int);

    //Calculate the route to each other node
    void calcRoutingTable();

    //Calculate route to a specific node
    void routeFor(int);

    //Finds the minimum number in a vector (excluding -1)
    int getLeastDistance(std::vector<int>);

    //Finds the maximum number in a vector
    int findMax(std::vector<int>);

    //Checks if two tables are different
    bool differentTables(std::vector< std::vector<int> >, std::vector< std::vector<int> >, int);

    //Output table change to console
    void outputTableChange(int, int, int, int, int);

    //Output routing table line to console
    void outputRoutingLine(int, int, int);

    //Bubble sort connection vector
    std::vector<int> sortConnections();


    //Debug

    //Prints the distance table of this node to console
    void printTable();
};


#endif
