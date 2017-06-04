#ifndef _HT_H_
#define _HT_H_

#include <iostream>
#include <string>
#include <fstream>
#include "node.h"
#include "LinkedList.h"

template <class KEY, class DATA>
class Table
{
protected:
	int size;
	int count;
	LinkedList<Node<KEY, DATA>>* arraylist;
	int Hash(KEY K);
public:
	Table(int size_ = 1);
	Table(Table& ht);
	~Table();
	DATA& operator[](KEY k_);
	Table& operator=(Table& ht);
	void addElem(DATA val_, KEY k_);
	void removeElem(KEY k_);
	void resize(int newSize);
	void gitDataFromFile(std::string&);
};

template <class KEY, class DATA>
Table<KEY, DATA>::Table(int size_)
{
	size = size_;
	count = 0;
	arraylist = new LinkedList<Node<KEY, DATA>>[size];
}

template <class KEY, class DATA>
Table<KEY, DATA>::Table(Table& ht)
{
	size = ht.size;
	count = ht.count;

	arraylist = new LinkedList<Node<KEY, DATA>>[ht.size];
	for (int i = 0; i<ht.size; ++i)
		arraylist[i] = ht.arraylist[i];
}

template <class KEY, class DATA>
Table<KEY, DATA>::~Table()
{
	delete[] arraylist;
	size = 0;
	count = 0;
}
 
template <>
void Table<int, std::string>::gitDataFromFile(std::string& name)
{
	std::ifstream file(name);
	std::string str;
	int key;
	int counter = 0;
	while (std::getline(file, str, '\n'))
	{

		if (counter % 2 == 0)
			key = std::stoi(str);
		else
			addElem(str, key);
		counter++;
	}
}

template <class KEY, class DATA>
int Table<KEY, DATA>::Hash(KEY K)
{
	return ((int)K) % size;

}
template <class KEY, class DATA>
DATA& Table<KEY, DATA>::operator[](KEY K)
{
	int index = Hash(K);
	Node<KEY, DATA> nod;
	nod.SetKey(K);
	if (!arraylist[index].contains(nod))
		throw 5;

	return arraylist[index].get(arraylist[index].indexOf(nod)).GetData();
}

template<class KEY, class DATA>
Table<KEY, DATA> & Table<KEY, DATA>::operator=(Table & ht)
{
	size = ht.size;
	count = ht.count;
	p = ht.p;
	arraylist = new Node[ht.size];
	for (int i = 0; i<ht.size; ++i)
		arraylist[i] = ht.arraylist[i];
}

template <class KEY, class DATA>
void Table<KEY, DATA>::addElem(DATA val_, KEY k_)
{
	int index = Hash(k_);

	Node<KEY, DATA> nod;
	nod.SetKey(k_);
	nod.SetVal(val_);
	if (!arraylist[index].contains(nod))
	{
		arraylist[index].addElem(nod);
	}
	else
	{
		Node<KEY, DATA>* tmp = &arraylist[index].get(arraylist[index].indexOf(nod));
		tmp->SetVal(val_);
	}
}

template<class KEY, class DATA>
void Table<KEY, DATA>::removeElem(KEY k_)
{
	int index = Hash(k_);

	Node<KEY, DATA> nod;
	nod.SetKey(k_);
	if (arraylist[index].contains(nod))
	{
		arraylist[index].removeElem(arraylist[index].indexOf(nod));
	}
}

template<class KEY, class DATA>
void Table<KEY, DATA>::resize(int newSize)
{
	LinkedList<Node<KEY, DATA>>*tmp = arraylist;
	if (count > newSize)
		throw 112;
	arraylist = new LinkedList<Node<KEY, DATA>>[newSize];
	count = 0;
	int oldSize = size;
	size = newSize;
	for (int i = 0; i < oldSize; i++)
	{
		for (size_t x = 0; x<tmp[i].size(); x++)
			addElem(tmp[i].get(x).GetData(), tmp[i].get(x).GetKey());
	}
	delete[] tmp;
}

#endif