#include "Hastable.h"
#include <iostream>
#include <string>

using namespace std;

void main()
{
	Table<int,string> t(15);
	t.gitDataFromFile(string("base.txt"));

	cout << t[15] << t[27] << t[34];

	 
	t.resize(25);

	std::cin.get();

}