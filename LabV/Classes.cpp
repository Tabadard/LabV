#include "Classes.h"

template<typename T>
inline Node<T>::Node(int init = 0)
{
	key = init;
}

template<typename T>
Node<T>::~Node()
{
}

template<typename T>
void Node<T>::set(T value)
{
	key = value;
}

template<typename T>
Node<T> Node<T>::operator=(T value)
{
	key = value;
	return *this;
}



template<typename T>
Keeper<T>::Keeper(unsigned long children)
{
	descendants.resize(children);
	for (unsigned long i = 0; i < children; i++)
	{
		descendants[i] = Node<T>(i);
	}
}

template<typename T>
Keeper<T>::~Keeper()
{
	for (unsigned long i = 0; i < descendants.size(); i++)
	{
		descendants[i].~Node();
	}
	descendants.~vector();
}

template<typename T>
inline Node<T> &Keeper<T>::operator[](unsigned long index)
{
	if (index < descendants.size())
	{
		return descendants[index];
	}
	else {
		std::cout << "Wrong index!\n";
		return Node<T>(-1);
	}
}



template<typename T>
Holder<T>::Holder(unsigned long raws = 0, unsigned long columns = 0)
{
	descendants.resize(raws);
	for (unsigned long i = 0; i < raws; i++)
	{
		descendants[i] = Keeper<T>(columns);
	}
}

template<typename T>
Holder<T>::~Holder()
{
	for (unsigned long i = 0; i < descendants.size(); i++)
	{
		descendants[i].~Keeper();
	}
	descendants.~vector();
}

template<typename T>
Keeper<T> &Holder<T>::operator[](unsigned long index)
{
	if (index < descendants.size())
	{
		return descendants[index];
	}
	else {
		std::cout << "Wrong index!\n";
		return Keeper<int>();
	}
}

template<typename T>
void Holder<T>::operator=(T ** matrix)
{
	for (unsigned long i = 0; i < descendants.size(); i++)
	{
		for (unsigned long j = 0; j < descendants[0].descendants.size(); j++)
		{
			descendants[i].descendants[j].key = matrix[i][j];
		}
	}
}