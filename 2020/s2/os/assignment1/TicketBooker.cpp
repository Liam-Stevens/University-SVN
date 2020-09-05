/*
Created By: Liam Stevens
ID: a1742143
Time:05.09.2020
Contact Email: a1742143@student.adelaide.edu.au

TODO: Include int main(int argc,char *argv[])
Input: argv[1]
Output: screen

Input Sample:
TODO: ID arrival_time priority age total_tickets_required
for example: s1 3 1 0 50

Output Sample:
TODO: ID, arrival and termination times, ready time and durations of running and waiting
*/

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

/*

    TODO: Comment

*/
class Customer
{
private:
	string name;
    int arrival;
    int priority;
    int age;
    int tickets;

public:
	//Constructors
    Customer()
    {
        name = "TEST";
        arrival = 0;
        priority = 1;
        age = 0;
        tickets = 1;
    }

    Customer(string newName, int newArrival, int newPriority, int newAge, int newTickets)
    {
        name = newName;
        arrival = newArrival;
        priority = newPriority;
        age = newAge;
        tickets = newTickets;
    }

    //Setters
    void setName(string newName)
    {
        name = newName;
    }

    void setArrival(int newArrival)
    {
        arrival = newArrival;
    }

    void setPriority(int newPriority)
    {
        priority = newPriority;
    }

    void setAge(int newAge)
    {
        age = newAge;
    }

    void setTickets(int newTickets)
    {
        tickets = newTickets;
    }

    //Getters
    string getName()
    {
        return name;
    }

    int getArrival()
    {
        return arrival;
    }

    int getPriority()
    {
        return priority;
    }

    int getAge()
    {
        return age;
    }

    int getTickets()
    {
        return tickets;
    }

};

/*

    TODO: Comment

*/
class Arena
{
private:
	vector<Customer *> queue1;
    vector<Customer *> queue2;

public:
	//Constructor
    Arena()
    {
        //Do Nothing
    }

    //TODO: Comment
    void addToQueue(Customer * myCustomer, int priority)
    {
        //TODO: May need more complex sorting
        if (priority <= 3)
        {
            queue1.push_back(myCustomer);
        }
        else
        {
            queue2.push_back(myCustomer);
        }
    }

    //Test output
    void outputQueues()
    {
        cout << "Queue1: " << endl;
        for (int i = 0; i < (signed)queue1.size(); i++)
        {
            cout << "Name: " << queue1[i]->getName() << " | Arrival: " << queue1[i]->getArrival() << " | Priority: ";
            cout << queue1[i]->getPriority() << " | Age: " << queue1[i]->getAge() << " | Tickets: ";
            cout << queue1[i]->getTickets() << endl;
        }
        cout << "Queue2: " << endl;
        for (int i = 0; i < (signed)queue2.size(); i++)
        {
            cout << "Name: " << queue2[i]->getName() << " | Arrival: " << queue2[i]->getArrival() << " | Priority: ";
            cout << queue2[i]->getPriority() << " | Age: " << queue2[i]->getAge() << " | Tickets: ";
            cout << queue2[i]->getTickets() << endl;
        }
    }

    //Destructor
    ~Arena()
    {
        for (int i = 0; i < (signed)queue1.size(); i++)
        {
            delete queue1[i];
        }
        for (int i = 0; i < (signed)queue2.size(); i++)
        {
            delete queue2[i];
        }
    }
};

//TODO: Comment
bool readFile(string fileLocation, vector<string> * fileLines)
{
    string line;
  	ifstream inputFile (fileLocation.c_str());

	//Open the file
  	if (inputFile.is_open())
  	{
    	while ( getline (inputFile,line) )
    	{
      		fileLines->push_back(line);
    	}
    	inputFile.close();
  	}
	//Unable to open the file
  	else {
		return 1;
	}
    return 0;
}

//TODO: Comment
bool initialise(vector<string> fileLines, Arena * myArena)
{
    for (int i = 0; i < (signed)fileLines.size(); i++)
    {
        string custName;
        int custArrive, custPriority, custAge, custTickets;

        stringstream ss2Cust( fileLines[i] );
        ss2Cust >> custName >> custArrive >> custPriority >> custAge >> custTickets;

        Customer * temp;
        temp = new Customer(custName, custArrive, custPriority, custAge, custTickets);
        myArena->addToQueue(temp, custPriority);
    }

    return 0;
}

//TODO: Comment
bool process(Arena * myArena)
{
    return 0;
}

//TODO: Comment
bool output(Arena myArena)
{
    /*cout << "name   arrival   end   ready   running   waiting" << endl;
    for(int i=0; i < 10; i++) // every result
    {

    }
    cout << endl;*/
    return 0;
}

//TODO: Comment
int main(int argc, char **argv)
{
    string fileLocation = argv[1];
    vector<string> fileLines;
    Arena melbourne;

    if ( readFile(fileLocation, &fileLines) )
    {
        cout << "FAILED AT READ" << endl;
        return 1;
    }

    if ( initialise(fileLines, &melbourne) )
    {
        cout << "FAILED AT INITIALISATION" << endl;
        return 1;
    }

    if ( process(&melbourne) )
    {
        cout << "FAILED AT PROCESSING" << endl;
        return 1;
    }

    if ( output(melbourne) )
    {
        cout << "FAILED AT OUTPUT" << endl;
        return 1;
    }

    return 0;
}
