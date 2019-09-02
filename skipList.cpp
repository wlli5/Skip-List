#include "skipList.h"

bool skipList::searchN(int val)
{
	int cost = 0;
	list<Node>::iterator hori;
	for (int i = maxHeight; i >= 0; --i)//MAX HEIGHT,COUNTER +
	{
		
		hori = lvl[i].begin();
		++cost;
		while (hori != lvl[i].end())
		{
			
			if (hori->value == val)
			{
				cout << "search cost:  " << cost << " comparisons for " << val << endl;
				return true;	
				
			}
			++hori;
		}
	}
	cout << "search cost:  " << cost << " comparisons for " << val << endl;

	
	return false;
	
}
void skipList::loadIn(string inputf)
{
	cout << "SkipList for " << inputf << endl;
	ifstream filename(inputf);
	string num;
	int i;

	while (!filename.eof())
	{
		getline(filename, num);
		stringstream number(num);
		number >> i;
		insertN(i);
	}

}
void skipList::deleteIn(string inputf)
{
	ifstream filename(inputf);
	string num;
	int i;
	while (!filename.eof())
	{
		getline(filename, num);
		stringstream number(num);
		number >> i;
		deleteN(i);
	}

}
int skipList::randomz()
{
	int counter = 0;
	int coin = rand() % 2 + 1;
	while (coin == 1)//head = 1
	{
		counter++;
		coin = rand() % 2 + 1;
	}
	return counter;
}
void skipList::insertN(int val)//once tails stop
{
	numberOfNodes++;
		float cost = 0;
		int count = randomz();
		Node newNode = Node(0, lvl[count].begin());
		newNode.value = val;
		list<Node>::iterator trackdown;
		list<Node>::iterator hori;
		if (count + 1 > maxHeight)
		{
			maxHeight = count + 1;
		}
		for (int i = count; i >= 0; --i)
		{
			hori = lvl[i].begin();
			while (hori != lvl[i].end())
			{
				cost++;
				if (newNode.value < hori->value)
				{

					lvl[i].insert(hori, newNode);
					--hori;
					trackdown = hori;
					trackdown->down = hori;
					++hori;
					break;
				}
				++hori;
			}
		}
		if(numberOfNodes <= 16)
		{
		avgInsert = avgInsert + cost;
		cout << "# of comparisons: " << cost << " for " << val << " at level " << count << endl;
		}
		else
		{
			cout << "exceeded the max number of nodes" << endl;
		}
	
	

}
void skipList::deleteN(int val)
{
	//--numberOfNodes;
	float cost = 0;
	list<Node>::iterator k = lvl[maxHeight].begin();
	list<Node>::iterator hori;
	if (numberOfNodes <= 16)
	{
		for (int i = maxHeight; i >= 0; --i)
		{
			hori = lvl[i].begin();
			while (hori != lvl[i].end())
			{
				cost++;
				if (hori->value == val)
				{
					lvl[i].erase(hori);
					break;
				}
				++hori;
			}

		}
		avgDelete = avgDelete + cost;
		cout << "delete cost:  " << cost << " comparisons for " << val << endl;
	}
	else
	{
		cout << "exceeded the max number of nodes" << endl;
	}
	
}
void skipList::printing()
{
	for (int i = maxHeight; i >= 0; --i)
	{
		list<Node>::iterator hori;
		hori = lvl[i].begin();
		cout << "<";
		while (hori != lvl[i].end())
		{
			if (hori->value == ninf)
			{
				cout << "-inf ";
			}
			else if (hori->value == pinf)
			{
				cout << "inf ";
			}
			else
			{
				cout << hori->value << " ";
			}
			++hori;
		}
		cout << ">" << endl;
	}
}
void skipList::findAvgInsert()
{
	cout << "Average insert cost: " << avgInsert / numberOfNodes << endl;
	

}
void skipList::findAvgDelete()
{
	cout << "Average delete cost: " << avgDelete / numberOfNodes << endl;
}