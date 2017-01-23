#pragma once

#include <iostream>
#include <vector>

// leafs (numbers)
template<typename T>
struct Node {
	T key;
	Node(int init = 0);
	void set(T);
	Node<T> operator= (T value);
	~Node();
};

// nodes between root and leafs
template<typename T>
class Keeper {
public:
	std::vector<Node<T>> descendants;

	Keeper(unsigned long children = 0);
	~Keeper();

	Node<T> &operator[] (unsigned long index);
};

// Root
template<typename T>
class Holder {	
public:
	std::vector<Keeper<T>> descendants;

	Holder(unsigned long raws = 1, unsigned long columns = 1);
	~Holder();

	Keeper<T> &operator[] (unsigned long index);
	void operator=(T **);
};