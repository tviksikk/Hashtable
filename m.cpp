#include "Hastable.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void main()
{
	Table<int,string> t(15);
	
	ifstream file("base.txt");
	string str;
	int key;
	int counter = 0;
	while (getline(file, str, '\n'))
	{

		if (counter % 2 == 0)
			key = stoi(str);
		else
			t.addElem(str, key);
		counter++;
	}

	cout << t[15] << t[27] << t[34];


	t.resize(25);

	std::cin.get();

}