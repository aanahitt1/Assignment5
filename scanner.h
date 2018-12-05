#include "binaryST.h"
#include "HashArray.h"

template <class T>
class Scanner {
	public:
		virtual T scan(T& product) = 0;
		virtual ~Scanner() {};
};

template <class T>
class BSTScanner: public Scanner<T> {

	BinarySearchTree<T> database;

	public:
	//Has to be initialized with a complete BST, because there's no add functions. This is a search only template.
	BSTScanner(BinarySearchTree<T>*& _database) : database(*_database) {}

	T scan(T& product) {
		return database.search(product);
	}

	void setDatabase(BinarySearchTree<T>& _database) {
		database = _database;
	}
};

template <class T>
class ArrayScanner: public Scanner<T> {
	T* database;
	int SIZE;

	public:
	ArrayScanner(T* _database, int size) : database(_database), SIZE(size) {}

	T scan(T& product) {
		T found;
		for(int i = 0; i< SIZE; i++) {
                	if(database[i] == product) {
                        	found = database[i];
                       		break;
               		 }
		}
		return found;
        }

	void setDatabase(T* _database) {
		delete[] database;
		database = _database;
	}

	~ArrayScanner() {
		delete[] database;
	}

};

template <class T>
class HashScanner: public Scanner<T> {

	HashArray<T> database;

	public:
	HashScanner(HashArray<T>*& _database) : database(*_database) {}

	T scan(T& product) {
		return database.returnItem(product);
	}

	void setDatabase(HashArray<T> _database) {
		database = _database;
	}
};

