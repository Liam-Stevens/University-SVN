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
					i = i - 25;
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
		if (table[hashKey] == "" && tombstone[hashKey] == false)
		{
			table[hashKey] = target;
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
					i = i - 25;
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
		for (int i = 0; i < table.size(); i++)
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

	//Take the inputs
	while(cin >> line)
	{
		//Check for end of file
		if (cin.eof())
		{
			break;
		}

		//Push back operation
		commands.push_back(line);
	}

	//Create hashtable
	HashTable table1;

	//Do commands
	for (int i = 0; i < commands.size(); i++)
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
