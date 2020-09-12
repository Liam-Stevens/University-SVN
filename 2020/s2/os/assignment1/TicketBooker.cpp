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
#include <math.h>
#include <cmath>

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
    //Output storage
    int endTime;
    int readyTime;
    int runningTime;
    int waitingTime;

    int quantumTime;
    int lastRun;

public:
	//Constructors
    Customer()
    {
        name = "UNDEFINED";
        arrival = 0;
        priority = 1;
        age = 0;
        tickets = 1;
        endTime = -1;
        readyTime = -1;
        runningTime = 0;
        waitingTime = 0;
        quantumTime = 0;
		lastRun = 0;
    }

    Customer(string newName, int newArrival, int newPriority, int newAge, int newTickets)
    {
        name = newName;
        arrival = newArrival;
        priority = newPriority;
        age = newAge;
        tickets = newTickets;
        endTime = -1;
        readyTime = -1;
        runningTime = 0;
        waitingTime = 0;
        quantumTime = 0;
		lastRun = 0;
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

    void setEndTime(int newEndTime)
    {
        endTime = newEndTime;
    }

    void setReadyTime(int newReadyTime)
    {
        readyTime = newReadyTime;
    }

    void tickRun()
    {
        runningTime += 5;
    }

    void tickWait()
    {
        waitingTime += 5;
    }

    void setQuantumTime(int newQuantumTime)
    {
        quantumTime = newQuantumTime;
    }

    void setLastRun(int newLastRun)
    {
        lastRun = newLastRun;
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

    int getEndTime()
    {
        return endTime;
    }

    int getReadyTime()
    {
        return readyTime;
    }

    int getRunningTime()
    {
        return runningTime;
    }

    int getWaitingTime()
    {
        return waitingTime;
    }

    int getQuantumTime()
    {
        return quantumTime;
    }

    int getLastRun()
    {
        return lastRun;
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

    void tickAll()
    {
        tick();

        for (int i = 0; i < (signed)queue1.size(); i++)
        {
			//queue1[i]->setLastRun(queue1[i]->getLastRun() + 5); //TODO: Check if needed
            if (queue1[i]->getReadyTime() >= 0 && (queue1[i]->getArrival() != timer-5 || queue1[i]->getArrival() == 0))
            {
                queue1[i]->tickWait();
            }
        }

		vector<Customer *> moveQueue = queue2;

        for (int i = 0; i < (signed)moveQueue.size(); i++)
        {
            if (moveQueue[i]->getReadyTime() >= 0 && (moveQueue[i]->getArrival() != timer-5 || moveQueue[i]->getArrival() == 0))
            {
                moveQueue[i]->tickWait();

            }
			if ((moveQueue[i]->getArrival() != timer-5 || moveQueue[i]->getArrival() == 0))
			{
				moveQueue[i]->setLastRun(moveQueue[i]->getLastRun() + 5);
			}
			checkAge(moveQueue[i]);
        }
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
    bool activeQueue(int queueNum)
    {
        if (queueNum == 0)
        {
            if (queue1.size() > 0 || queue2.size() > 0 || arrivals.size() > 0)
            {
                return true;
            }
        }
        else if (queueNum == 1)
        {
            if (queue1.size() > 0)
            {
                return true;
            }
        }
        else if (queueNum == 2)
        {
            if (queue2.size() > 0)
            {
                return true;
            }
        }
        return false;
    }

    //TODO: Comment
    void swapCustomers(Customer * firstCustomer, Customer * secondCustomer)
    {
        Customer * temp;
        temp = firstCustomer;
        firstCustomer = secondCustomer;
        secondCustomer = temp;
    }

	void checkAge(Customer * myCustomer)
	{
		if (myCustomer->getLastRun() >= 100)
		{
			myCustomer->setLastRun(0);
			myCustomer->setPriority( myCustomer->getPriority() - 1);
			if (myCustomer->getPriority() <= 3)
			{
				promote(myCustomer);
			}
		}
	}

    //TODO: Comment
    void backQueue1(Customer * myCustomer)
    {
        int iterator;
        for (int i = 0; i < (signed)queue1.size(); i++)
        {
            if (queue1[i] == myCustomer)
            {
                iterator = i;
                break;
            }
        }

        queue1.erase(queue1.begin()+iterator);

        //Move to the back of the priority sub queue
        if (queue1.size() != 0)
        {
            for (int i = 0; i < (signed)queue1.size(); i++)
            {
                //Insert in order of arrival time, within the range
                if ( queue1[i]->getPriority() > myCustomer->getPriority() )
                {
                    queue1.insert(queue1.begin()+i, myCustomer);
                    break;
                }
                if (i == (signed)queue1.size() - 1)
                {
                    queue1.push_back(myCustomer);
                    break;
                }
            }
        }
        else
        {
            queue1.push_back(myCustomer);
        }

    }

    //TODO: Comment
    void promote(Customer * myCustomer)
    {
        int iterator;
        for (int i = 0; i < (signed)queue2.size(); i++)
        {
            if (queue2[i] == myCustomer)
            {
                iterator = i;
                break;
            }
        }

        addToQueue1(myCustomer);
		backQueue1(myCustomer);
		myCustomer->setQuantumTime(0);
        queue2.erase(queue2.begin() + iterator);

		//TEST OUTPUT
        //cout << "Promoted " << myCustomer->getName() << " at time " << timer << endl;
        //outputQueues();
    }

    //TODO: Comment
    void demote(Customer * myCustomer)
    {
        int iterator;
        for (int i = 0; i < (signed)queue1.size(); i++)
        {
            if (queue1[i] == myCustomer)
            {
                iterator = i;
                break;
            }
        }

        addToQueue2(myCustomer);
        queue1.erase(queue1.begin() + iterator);

		myCustomer->setLastRun(myCustomer->getLastRun() + 5);
		//myCustomer->tickWait();

		//TEST OUTPUT
        //cout << "Demoted " << myCustomer->getName() << " at time " << timer << endl;
        //outputQueues();
    }

    //TODO: Comment
    void terminateCustomer(Customer * myCustomer)
    {
        vector<Customer *> * targetVector;
        int iterator;
        for (int i = 0; i < (signed)queue1.size(); i++)
        {
            if (queue1[i] == myCustomer)
            {
                targetVector = &queue1;
                iterator = i;
                break;
            }
        }

        for (int i = 0; i < (signed)queue2.size(); i++)
        {
            if (queue2[i] == myCustomer)
            {
                targetVector = &queue2;
                iterator = i;
                break;
            }
        }

        terminated.push_back(myCustomer);
        targetVector->erase(targetVector->begin() + iterator);
    }

    //TODO: Comment
    void incrementWaitTime(Customer * myCustomer)
    {

        for (int i = 0; i < (signed)queue1.size(); i++)
        {
			if (queue1[i] != myCustomer)
			{
				//queue1[i]->setLastRun(queue1[i]->getLastRun() + 5);
			}

            if (queue1[i]->getReadyTime() >= 0 && queue1[i] != myCustomer && (queue1[i]->getArrival() != timer-5 || queue1[i]->getArrival() == 0))
            {
                queue1[i]->tickWait();
            }
        }

		vector<Customer *> moveQueue = queue2;

        for (int i = 0; i < (signed)moveQueue.size(); i++)
        {
            if (moveQueue[i]->getReadyTime() >= 0 && moveQueue[i] != myCustomer && (moveQueue[i]->getArrival() != timer-5 || moveQueue[i]->getArrival() == 0))
            {
                moveQueue[i]->tickWait();
            }
			if (moveQueue[i] != myCustomer && (moveQueue[i]->getArrival() != timer-5 || moveQueue[i]->getArrival() == 0))
			{
				moveQueue[i]->setLastRun(moveQueue[i]->getLastRun() + 5);
			}
			checkAge(moveQueue[i]);
        }
    }

    //TODO: Comment
    void processTicket(int queueNum)
    {
        vector<Customer *> * targetVector;
        int iterator = 0;
        if (queueNum == 1)
        {
            targetVector = &queue1;
        }
        else if (queueNum == 2)
        {
            targetVector = &queue2;
        }
        else
        {
            cout << "Error in processing ticket for queue " << queueNum << endl;
            return;
        }

        Customer * targetCustomer = targetVector->at(iterator);

        if (targetCustomer->getReadyTime() < 0)
        {
            targetCustomer->setReadyTime(timer);
        }

        //Current run time increased
		targetCustomer->setTickets(targetCustomer->getTickets() - 1);
        targetCustomer->setQuantumTime(targetCustomer->getQuantumTime() + 5);
        tick();
        targetCustomer->tickRun();
        enqueueArrivals( timer );

        //Queue1 aging
        if (targetCustomer->getPriority() <= 3)
        {
            int timeQuantum = (10 - targetCustomer->getPriority())*10;
            //cout << "Name: " << targetCustomer->getName() << " | time: " << timer << " | timeQuantum: " << timeQuantum << " | currentRuntime: "<< targetCustomer->getQuantumTime() << endl;
            if (targetCustomer->getQuantumTime() >= timeQuantum)
            {
                targetCustomer->setAge( targetCustomer->getAge() + 1 );
                targetCustomer->setQuantumTime(0);

                if (targetCustomer->getAge() >= 2)
                {
                    targetCustomer->setPriority(targetCustomer->getPriority() + 1);
					targetCustomer->setAge(0);
                    //cout << "New Priority: " <<  targetCustomer->getPriority() << endl;
                }
                //cout << "Priority: " <<  targetCustomer->getPriority() << endl;
                //Move to the back of the priority sub queue
                if (targetCustomer->getPriority() <= 3)
                {
                    backQueue1(targetCustomer);
                    //cout << "Moved " << targetCustomer->getName() << endl;
                }
                //Demoted to queue2
                else
                {
                    demote(targetCustomer);
                }
                //cout << endl << "Time: " << timer << endl;
                //outputQueues();
            }
        }


        //Increase the waiting period for every other customer
        incrementWaitTime(targetCustomer);
		targetCustomer->setLastRun(0);

        //Finished processing this customer
        if (targetCustomer->getTickets() <= 0)
        {
            targetCustomer->setEndTime(timer);
            terminateCustomer(targetCustomer);
			//TEST OUTPUT
			//cout << endl << "Time: " << timer << endl;
			//outputQueues();
            return;
        }

    }

    /*

        TODO: Comment

    */
    void addToQueue1(Customer * myCustomer)
    {
        //If the vector contains customers
        if (queue1.size() != 0)
        {
            int rangeBegin = -1;
            int rangeEnd = -1;
            //Search for range of same priorities
            for (int i = 0; i < (signed)queue1.size(); i++)
            {
                //End of the same value
                if ( (queue1[i]->getPriority() > myCustomer->getPriority() ) && (rangeBegin >= 0))
                {
                    rangeEnd = i;
                    break;
                }

                //All the same value to the end of the vector
                if (rangeBegin >= 0 && i == (signed)queue1.size() - 1)
                {
                    rangeEnd = (signed)queue1.size();
                    break;
                }

                //Start of the same value
                if (queue1[i]->getPriority() == myCustomer->getPriority())
                {
                    rangeBegin = i;
                }
            }

            //If no priority the same
            if (rangeEnd < 0)
            {
                for (int i = 0; i < (signed)queue1.size(); i++)
                {
                    //Insert in order of priority
                    if ( queue1[i]->getPriority()  > myCustomer->getPriority() )
                    {
                        queue1.insert(queue1.begin()+i, myCustomer);
                        break;
                    }
                    else if (i == (signed)queue1.size() - 1)
                    {
                        queue1.insert(queue1.begin()+i+1, myCustomer);
                        break;
                    }
                }
            }
            //If there is a range of priorities which are the same
            else
            {

                for (int i = rangeBegin; i < rangeEnd; i++)
                {
                    //Insert in order of arrival time, within the range
                    if ( queue1[i]->getArrival() > myCustomer->getArrival() )
                    {
                        queue1.insert(queue1.begin()+i, myCustomer);
                        break;
                    }
                    if (i == rangeEnd - 1)
                    {
                        queue1.insert(queue1.begin()+i+1, myCustomer);
                        break;
                    }
                }
            }
        }
        //If the vector is empty
        else
        {
            queue1.push_back(myCustomer);
        }

    }

    /*

        TODO: Comment

    */
    void addToQueue2(Customer * myCustomer)
    {
		//If the vector contains customers
        if (queue2.size() != 0)
        {
            int rangeBegin1 = -1;
            int rangeEnd1 = -1;
            //Search for range of same tickets
            for (int i = 0; i < (signed)queue2.size(); i++)
            {
                //End of the same value
                if ( (queue2[i]->getTickets() > myCustomer->getTickets() ) && (rangeBegin1 >= 0))
                {
                    rangeEnd1 = i;
                    break;
                }

                //All the same value to the end of the vector
                if (rangeBegin1 >= 0 && i == (signed)queue2.size() - 1)
                {
                    rangeEnd1 = queue2.size();
                    break;
                }

                //Start of the same value
                if (queue2[i]->getTickets() == myCustomer->getTickets())
                {
                    rangeBegin1 = i;
                }
            }

            //If no tickets the same
            if (rangeEnd1 < 0)
            {
                for (int i = 0; i < (signed)queue2.size(); i++)
                {
                    //Insert in order of tickets remaining
                    if ( queue2[i]->getTickets() > myCustomer->getTickets() )
    				{
    					queue2.insert(queue2.begin()+i, myCustomer);
    					break;
    				}
    				else if (i == (signed)queue2.size() - 1)
    				{
    					queue2.push_back( myCustomer );
    					break;
    				}
                }
            }
            //If there is a range of tickets which are the same
            else
            {
                //cout << "Same Tickets Detected " << rangeBegin1 << " | " << rangeEnd1 << endl;
                int rangeBegin2 = -1;
                int rangeEnd2 = -1;
                //Search for range of same priorities
                for (int i = rangeBegin1; i < rangeEnd1; i++)
                {
                    //End of the same value
                    if ( (queue2[i]->getPriority() > myCustomer->getPriority() ) && (rangeBegin2 >= 0))
                    {
                        rangeEnd2 = i;
                        break;
                    }

                    //All the same value to the end of the vector
                    if (rangeBegin2 >= 0 && i == (signed)queue2.size() - 1)
                    {
                        rangeEnd2 = queue2.size();
                        break;
                    }

                    //Start of the same value
                    if (queue2[i]->getPriority() == myCustomer->getPriority())
                    {
                        rangeBegin2 = i;
                    }
                }

                //If no priority the same
                if (rangeEnd2 < 0)
                {
                    for (int i = rangeBegin1; i < rangeEnd1; i++)
                    {
                        //Insert in order of priority
                        if ( queue2[i]->getPriority()  > myCustomer->getPriority() )
        				{
        					queue2.insert(queue2.begin()+i, myCustomer);
        					break;
        				}
        				else if (i == rangeEnd1 - 1)
        				{
        					queue2.insert(queue2.begin()+i+1, myCustomer);
        					break;
        				}
                    }
                }
                //If there is a range of priorities which are the same
                else
                {

                    for (int i = rangeBegin2; i < rangeEnd2; i++)
        			{
                        //Insert in order of arrival time, within the range
                        if ( queue2[i]->getArrival() > myCustomer->getArrival() )
        				{
        					queue2.insert(queue2.begin()+i, myCustomer);
        					break;
        				}
        				if (i == rangeEnd2 - 1)
        				{
                            queue2.insert(queue2.begin()+i+1, myCustomer);
        					break;
        				}
        			}
                }
            }
        }
        //If the vector is empty
        else
        {
            queue2.push_back(myCustomer);
        }

    }

    /*

        TODO: Comment

    */
    void addToArrivals(Customer * myCustomer)
    {
        //If the vector contains customers
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
        //If the vector is empty
        else
        {
            arrivals.push_back(myCustomer);
        }
    }

    /*

        TODO: Comment

    */
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
					//TEST OUTPUT
			        //cout << "Queued " << arrivals[i]->getName() << " into queue 1 at time: " << currentTime << endl;
					//outputQueues();
                }
                else
                {
                    addToQueue2(arrivals[i]);
					//TEST OUTPUT
			        //cout << "Queued " << arrivals[i]->getName() << " into queue 2 at time: " << currentTime << endl;
					//outputQueues();
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

    void padSpaces(int num)
    {
        for (int i = 0; i < num; i++)
        {
            cout << ' ';
        }
    }

    int countDigitChars(int num)
    {
        if (num == 0)
        {
            return 1;
        }
        else if (num < 0)
        {
            return log10( abs(num) ) + 2;
        }
        else
        {
            return log10(num) + 1;
        }
    }

    void outputTerminated()
    {
        for (int i = 0; i < (signed)terminated.size(); i++)
        {
            cout << terminated[i]->getName();
            padSpaces(10-countDigitChars(terminated[i]->getArrival()));
            cout << terminated[i]->getArrival();
            padSpaces(10-countDigitChars(terminated[i]->getEndTime()));
            cout << terminated[i]->getEndTime();
            padSpaces(10-countDigitChars(terminated[i]->getReadyTime()));
            cout << terminated[i]->getReadyTime();
            padSpaces(10-countDigitChars(terminated[i]->getRunningTime()));
            cout << terminated[i]->getRunningTime();
            padSpaces(10-countDigitChars(terminated[i]->getWaitingTime()));
            cout << terminated[i]->getWaitingTime() << endl;
        }
    }

    //Output all queues
    void outputQueues()
    {
        cout << "Queue1: " << endl;
        for (int i = 0; i < (signed)queue1.size(); i++)
        {
            cout << "Name: " << queue1[i]->getName() << " | Arrival: " << queue1[i]->getArrival()  << " | Tickets: ";
            cout << queue1[i]->getTickets() << " | Running " << queue1[i]->getRunningTime() << " | Priority: " << queue1[i]->getPriority();
            cout << " | Runs: " << queue1[i]->getAge() << " | Waiting: " << queue1[i]->getWaitingTime() << endl;
        }
        cout << "Queue2: " << endl;
        for (int i = 0; i < (signed)queue2.size(); i++)
        {
			cout << "Name: " << queue2[i]->getName() << " | Arrival: " << queue2[i]->getArrival()  << " | Tickets: ";
            cout << queue2[i]->getTickets() << " | Running " << queue2[i]->getRunningTime() << " | Priority: " << queue2[i]->getPriority();
            cout << " | LastRun: " << queue2[i]->getLastRun() << " | Waiting: " << queue2[i]->getWaitingTime() << endl;
        }
        cout << "Arrivals: " << endl;
        for (int i = 0; i < (signed)arrivals.size(); i++)
        {
			cout << "Name: " << arrivals[i]->getName() << " | Arrival: " << arrivals[i]->getArrival()  << " | Tickets: ";
            cout << arrivals[i]->getTickets() << " | Running " << arrivals[i]->getRunningTime() << " | Priority: " << arrivals[i]->getPriority();
            cout << " | LastRun: " << arrivals[i]->getLastRun() << " | Waiting: " << arrivals[i]->getWaitingTime() << endl;
        }
        cout << "Terminated: " << endl;
        for (int i = 0; i < (signed)terminated.size(); i++)
        {
			cout << "Name: " << terminated[i]->getName() << " | Arrival: " << terminated[i]->getArrival()  << " | Tickets: ";
            cout << terminated[i]->getTickets() << " | Running " << terminated[i]->getRunningTime() << " | Priority: " << terminated[i]->getPriority();
            cout << " | LastRun: " << terminated[i]->getLastRun() << " | Waiting: " << terminated[i]->getWaitingTime() << endl;
        }
		cout << endl;
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
    myArena->enqueueArrivals( myArena->getTime() );
    //While a queue has a customer
    while(myArena->activeQueue(0))
    {


        if (myArena->activeQueue(1))
        {
            myArena->processTicket(1);
        }
        else if (myArena->activeQueue(2))
        {
            myArena->processTicket(2);
        }
        else
        {
            myArena->tickAll();
            myArena->enqueueArrivals( myArena->getTime() );
            //cout << "TICK ALL" << endl;
        }



    }

    return 0;
}

//TODO: Comment
bool output(Arena myArena)
{
    cout << "name   arrival   end   ready   running   waiting" << endl;
    myArena.outputTerminated();
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
    //melbourne.outputQueues();

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
    //cout << endl << endl;
    //TODO: Remove this
    //melbourne.outputQueues();

    return 0;
}
