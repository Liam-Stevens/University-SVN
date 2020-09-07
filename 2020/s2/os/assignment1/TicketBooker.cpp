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
    vector<Customer *> arrivals;
    vector<Customer *> terminated;
    int timer;

public:
	//Constructor
    Arena()
    {
        timer = 0;
    }

    //TODO: Comment
    void tick()
    {
        timer += 5;
    }

    //TODO: Comment
    int getTime()
    {
        return timer;
    }

    //Gets the sum of the value of the characters in a string
    int nameValue(string name)
    {
        int sum = 0;
        for (int i = 0; i < (signed)name.length(); i++)
        {
            sum = sum + (int)name[i];
        }
        return sum;
    }

    //TODO: Comment
    bool activeQueues()
    {
        if (queue1.size() > 0 || queue2.size() > 0 || arrivals.size() > 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    //TODO: Comment
    void swapCustomers(Customer * firstCustomer, Customer * secondCustomer)
    {
        Customer * temp;
        temp = firstCustomer;
        firstCustomer = secondCustomer;
        secondCustomer = temp;
    }

    //TODO: Comment
    void addToQueue1(Customer * myCustomer)
    {
        queue1.push_back(myCustomer);
        cout << "Queued " << myCustomer->getName() << " into queue 1" << endl;
    }

    //TODO: Comment
    void addToQueue2(Customer * myCustomer)
    {
        queue2.push_back(myCustomer);
        cout << "Queued " << myCustomer->getName() << " into queue 2" << endl;
    }

    //TODO: Comment
    void addToArrivals(Customer * myCustomer)
    {
        if (arrivals.size() != 0)
        {
            int rangeBegin = -1;
            int rangeEnd = -1;
            //Search for range of same arrivals times
            for (int i = 0; i < (signed)arrivals.size(); i++)
            {
                //End of the same value
                if ( (arrivals[i]->getArrival() > myCustomer->getArrival() ) && (rangeBegin >= 0))
                {
                    rangeEnd = i;
                    break;
                }

                //All the same value to the end of the vector
                if (rangeBegin >= 0 && i == (signed)arrivals.size() - 1)
                {
                    rangeEnd = arrivals.size();
                    break;
                }

                //Start of the same value
                if (arrivals[i]->getArrival() == myCustomer->getArrival())
                {
                    rangeBegin = i;
                }
            }

            //If no times the same
            if (rangeEnd < 0)
            {
                for (int i = 0; i < (signed)arrivals.size(); i++)
                {
                    //Insert in order of arrival times
                    if ( arrivals[i]->getArrival()  > myCustomer->getArrival() )
    				{
    					arrivals.insert(arrivals.begin()+i, myCustomer);
    					break;
    				}
    				else if (i == (signed)arrivals.size() - 1)
    				{
    					arrivals.push_back( myCustomer );
    					break;
    				}
                }
            }
            //If there is a range of times which are the same
            else
            {
                for (int i = rangeBegin; i < rangeEnd; i++)
    			{
                    //Insert in order of name, within arrival time range
                    if ( nameValue(arrivals[i]->getName())  > nameValue(myCustomer->getName()) )
    				{
    					arrivals.insert(arrivals.begin()+i, myCustomer);
    					break;
    				}
    				if (i == rangeEnd - 1)
    				{
                        arrivals.insert(arrivals.begin()+i+1, myCustomer);
    					break;
    				}
    			}
            }
        }
        else
        {
            arrivals.push_back(myCustomer);
        }
    }

    //TODO: Comment
    void enqueueArrivals(int currentTime)
    {
        int rangeBegin = -1;
        int rangeEnd = -1;

        //Queue for the current time
        for (int i = 0; i < (signed)arrivals.size(); i++)
        {
            if ( arrivals[i]->getArrival() == currentTime )
            {
                //Record section to delete
                if (rangeBegin < 0)
                {
                    rangeBegin = i;
                }

                //Put into the appropriate queue
                if (arrivals[i]->getPriority() <= 3)
                {
                    addToQueue1(arrivals[i]);
                }
                else
                {
                    addToQueue2(arrivals[i]);
                }
            }

            //End of section to delete
            if (arrivals[i]->getArrival() > currentTime )
            {
                if (rangeBegin >= 0)
                {
                    rangeEnd = i;
                }
                break;
            }
        }

        //Delete until end of vector if all the same value to the end
        if (rangeBegin >= 0 && rangeEnd < 0)
        {
            rangeEnd = arrivals.size();
        }

        //cout << "Time: " << currentTime << " | rangeBegin: " << rangeBegin << " | rangeEnd: " << rangeEnd << endl;
        //Erase vector within the range
        if (rangeBegin >= 0)
        {
            arrivals.erase(arrivals.begin()+rangeBegin, arrivals.begin()+rangeEnd);
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
        cout << "Arrivals: " << endl;
        for (int i = 0; i < (signed)arrivals.size(); i++)
        {
            cout << "Name: " << arrivals[i]->getName() << " | Arrival: " << arrivals[i]->getArrival() << " | Priority: ";
            cout << arrivals[i]->getPriority() << " | Age: " << arrivals[i]->getAge() << " | Tickets: ";
            cout << arrivals[i]->getTickets() << endl;
        }
        cout << "Terminated: " << endl;
        for (int i = 0; i < (signed)terminated.size(); i++)
        {
            cout << "Name: " << terminated[i]->getName() << " | Arrival: " << terminated[i]->getArrival() << " | Priority: ";
            cout << terminated[i]->getPriority() << " | Age: " << terminated[i]->getAge() << " | Tickets: ";
            cout << terminated[i]->getTickets() << endl;
        }
    }

    //Destructor
    ~Arena()
    {
        //TODO: Need better way of deleting
        /*for (int i = 0; i < (signed)queue1.size(); i++)
        {
            delete queue1[i];
        }
        for (int i = 0; i < (signed)queue2.size(); i++)
        {
            delete queue2[i];
        }*/
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
        myArena->addToArrivals(temp);
    }

    return 0;
}

//TODO: Comment
bool process(Arena * myArena)
{
    //While a queue has a customer
    while(myArena->activeQueues())
    {
        myArena->enqueueArrivals( myArena->getTime() );

        myArena->tick();
        //TODO: Remove this
        if (myArena->getTime() > 200)
        {
            break;
        }
    }

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

    //TODO: Remove this
    melbourne.outputQueues();

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

    //TODO: Remove this
    melbourne.outputQueues();

    return 0;
}
