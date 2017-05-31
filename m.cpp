#include "Hastable.h"
#include <iostream>
#include <string>

void main()
{
	Table<int,double> t(15);
	t.addElem(100.1, 15);
	t.addElem(102.1, 37);
	t.addElem(101.2, 49);
	t.addElem(103.2, 41);

	std::cout << t[15] << std::endl;
	std::cout << t[37] << std::endl;
	std::cout << t[49] << std::endl;
	std::cout << t[41] << std::endl;
	t.resize(25);

	std::cin.get();

}