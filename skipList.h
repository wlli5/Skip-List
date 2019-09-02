#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <random>
#include <limits>
#include <sstream>
#include <fstream>
#include <string>
#include <ctime>
const int pinf = numeric_limits<int>::max();
const int ninf = numeric_limits<int>::min();
struct Node
{
	int value;
	list<Node>::iterator down;
	Node(int newvalue, list<Node>::iterator D)
	{
		value = newvalue;
		down = D;
	}
};

class skipList 
{
private:
	vector<list<Node>> lvl;
public:
	skipList()
	{ 
		//list<Node> emp;
		lvl.push_back(list<Node>());
		lvl[0].push_back(Node(ninf, lvl[0].end()));
		lvl[0].push_back(Node(pinf, lvl[0].end()));
		//lvl[0].insert(lvl[0].begin(), Node(ninf, lvl[0].begin()));
		//lvl[0].insert(lvl[0].end(), Node(pinf, lvl[0].end()));
		for (int i = 1; i < 10; ++i)
		{
			//list<Node> empty;
			lvl.push_back(list<Node>());
			lvl[i].push_back(Node(ninf, lvl[i-1].begin()));
			lvl[i].push_back(Node(pinf, lvl[i-1].begin()));
			//lvl[i].insert(lvl[i].begin(), Node(ninf, lvl[i].begin()));
			//lvl[i].insert(lvl[i].end(), Node(pinf, lvl[i].end()));
		}
	}
	int maxHeight = 1;
	float avgDelete = 0;
	float avgInsert = 0;
	float numberOfNodes = 1;
	bool searchN(int val);
	void insertN(int val);
	void deleteN(int val);
	void loadIn(string inputf);
	void deleteIn(string inputf);
	int randomz();
	void printing();
	void findAvgInsert();
	void findAvgDelete();
};