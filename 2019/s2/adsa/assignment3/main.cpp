#include <iostream>
#include <string>
#include <vector>

using namespace std;

class HashTable
{
private:
	vector<string> table;
	vector<bool> tombstone;

public:

	HashTable()
	{
		//Initialise table and tombstone vectors
		for (int i = 0; i < 26; i++)
		{
			table.push_back("");
			tombstone.push_back(false);
		}
	};


	int search(string target)
	{
		int hashKey = target[target.length()-1] - 97;

		//Check hashkey table element
		if (table[hashKey] == target && tombstone[hashKey] == false)
		{
			return hashKey;
		}
		else
		{
			//Search next elements if occupied
			int i = hashKey + 1;
			while(i != hashKey)
			{
				//loop around table
				if (i > 25)
				{
					i = i - 26;
				}
				if (i == hashKey)
				{
					break;
				}

				//Found element
				if (table[i] == target && tombstone[i] == false)
				{
					return i;
				}
				//Table element not used
				else if (table[i] == "" && tombstone[i] == false)
				{
					return -1;
				}

				i++;
			}

			return -1;
		}
		return -1;
	};

	void insert(string target)
	{
		//Stop if already in table
		if (search(target) != -1)
		{
			return;
		}

		int hashKey = target[target.length()-1] - 97;

		//Insert if unoccupied
		if (table[hashKey] == "" || tombstone[hashKey] == true)
		{
			table[hashKey] = target;
			tombstone[hashKey] = false;
		}
		else
		{
			//Goto next element if occupied
			int i = hashKey + 1;
			while(i != hashKey)
			{
				//loop around table
				if (i > 25)
				{
					i = i - 26;
				}
				if (i == hashKey)
				{
					break;
				}

				//Found unoccupied element
				if (table[i] == "" || tombstone[i] == true)
				{
					table[i] = target;
					tombstone[i] = false;
					return;
				}

				i++;
			}

		}

		return;
	};

	void deletion(string target)
	{
		int hashKey = search(target);

		//Stop if not in table
		if (hashKey == -1)
		{
			return;
		}
		else
		{
			//Set index to tombstone
			tombstone[hashKey] = true;
		}
		return;
	}

	void printAll()
	{
		//For outputting spacing
		bool firstPrint = false;

		//Iterate over all elements
		for (unsigned i = 0; i < table.size(); i++)
		{
			//Output if not empty or tombstone
			if (table[i] != "" && tombstone[i] != true)
			{
				//Outputs space if not first output
				if (firstPrint == true)
				{
					cout << " ";
				}

				cout << table[i];

				if (firstPrint == false)
				{
					firstPrint = true;
				}
			}
		}
		cout << endl;
		return;
	};

};

int main()
{
	vector<string> commands;
	string line;

	//Takes input
	getline(cin, line);
	int tracker = -1;
	int commandNum = 0;
	for (unsigned i = 0; i < line.length(); i++)
	{
		//Push new command if a space or end of line
		if (line[i] == ' ' || i == line.length()-1)
		{
			//Move end of command marker if end of line
			if (i == line.length()-1)
			{
				i++;
			}
			commands.push_back("");
			//Copy each character
			for (unsigned j = tracker + 1; j < i; j++)
			{
				commands[commandNum] += line[j];
			}
			tracker = i;
			commandNum++;
		}

	}

	//Create hashtable
	HashTable table1;

	//Do commands
	for (unsigned i = 0; i < commands.size(); i++)
	{
		//Insert command
		if (commands[i][0] == 'A')
		{
			commands[i].erase(commands[i].begin());
			table1.insert(commands[i]);
		}
		//Delete command
		else if (commands[i][0] == 'D')
		{
			commands[i].erase(commands[i].begin());
			table1.deletion(commands[i]);
		}
	}
	//Print all elements of hashtable
	table1.printAll();

	return 0;
}
