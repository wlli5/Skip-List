#include "skipList.h"
int main()
{
	srand(time(NULL));
	for (int i = 1; i <= 4; ++i)
	{
		string filep = to_string(i) + "p";
		string filel = to_string(i) + "l";
		string filer = to_string(i) + "r";
		skipList fileP;
		fileP.loadIn(filep);
		fileP.printing();
		fileP.deleteIn(filep);
		fileP.findAvgInsert();
		fileP.findAvgDelete();
		cout << endl;
		skipList fileL;
		fileL.loadIn(filel);
		fileL.printing();
		fileL.deleteIn(filel);
		fileL.findAvgInsert();
		fileL.findAvgDelete();
		cout << endl;
		skipList fileR;
		fileR.loadIn(filer);
		fileR.printing();
		fileR.deleteIn(filer);
		fileR.findAvgInsert();
		fileR.findAvgDelete();
		cout << endl;
	}

	//killme.insertN(15);
	//killme.printing();
	system("pause");
}