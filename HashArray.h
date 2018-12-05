#include <iostream>
#include <string>
#include <vector>
#include "linkedList.h"

using namespace std;

template <class T>
class HashArray {
	//The HashArray NEEDS to be given items that have a key member. It will not work in instances where there is no specific field labeled 'key'.

	vector<LinkedList<T>>* database;
	int SIZE;

	public:
	//Simple constructor. It is recommended to choose a prime number as the size.
	HashArray(int size) {
		database = new vector<LinkedList<T> >(size);
		SIZE = size;
	}

	HashArray(const HashArray<T>& other) {
		database = other.database;
		SIZE = other.SIZE;
	}

	//Adds using the linkedlist.
	void add(T& product) {
		int index = hash(product.key);
		//I don't know why, but unless I use 'index' somewhere first, it tries to add out of bounds. This isn't necessary for return.
		(*database)[index].addItem(product);
	}

	//Removes using linkedlist
	void remove(T& product) {
		int index = hash(product.key);
		(*database)[index].deleteItem(product);
	}

	//Returns using linkedlist
	T returnItem(T& product) {
		int index = hash(product.key);
		return (*database)[index].returnItem(product);
	}


	private:
	//We are working with long numbers, and so it makes sense to use the numbers individually to create a more unique index, especially as the key is actually read as a string.
	int hash(string key) {
		int sum;
		for(int i = 0; i<key.length()-1; i++) {
			int chr = key[i];
			sum *= chr;
		}
		return sum%SIZE;
	}

};
