#ifndef LIST_H
#define LIST_H

#include <string>

template <typename T>
class List {

	public:
		virtual ~List() {};
		virtual bool isEmpty() const = 0;
		virtual int length() const= 0;
		virtual void addItem(T& item) = 0;
		virtual void deleteItem(T& item) = 0;
		virtual T returnItem(T& item) const = 0;
};

#endif

