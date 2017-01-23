#include <iostream>
#include "Classes.h"
#include "Classes.cpp"

using namespace std;

int main()
{
	int size1 = 3;
	int size2 = 4;
	Holder<int> ex = Holder<int>(size1,size2);
	//cout << ex[0][0].key << "\n";
	//ex[0][0].set(23);
	cout << ex[0][0].key << "\n";
	ex[0][0] = 44;
	cout << ex[0][0].key << "\n";

	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2; j++)
			cout << ex[i][j].key << " ";
		cout << "\n";
	}
	system("pause");
	return 0;
}