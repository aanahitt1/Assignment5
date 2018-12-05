#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>
#include <iostream>
#include "list.h"
#include "node.cpp"

struct EmptyList:public exception {
	const char * what () const throw ()
    {
    	return "Empty List";
    }
};

struct NotFound:public exception {
	const char * what () const throw ()
    {
    	return "Item Not Found";
    }
};

template <typename T>
class LinkedList:public List<T> {

	public:
		int count;
		Node<T>* head;
		Node<T>* tail;


		LinkedList() :
			count(0), head(NULL), tail(NULL) {}

		//VIEW FUNCTIONS
		bool isEmpty() const;	//Checks if list is empty
		int length() const;	//Returns length of list
		T returnItem(T& item) const;	//Returns whatever data member you are looking for - a little useless considering you are looking for it with the item, but necessary.
		template <class U>
		friend ostream& operator<<(ostream& os, LinkedList<U>& rhs);	//Prints out to console


		//CHANGE FUNCTIONS
		virtual void addItem(T& item);	//Adds item at beginning
		void addToEnd(T& item);		//Adds item at the end
		void deleteItem(T& item);	//deletes item you are looking for
		void clear();			//Removes all items in list

		//BIG THREE
		virtual ~LinkedList() {
			this->clear();
		}
		LinkedList(const LinkedList<T>& other);	//copy constructor
		virtual LinkedList<T>& operator=(LinkedList<T>&);	//Assignment operator

};

template <typename T>
bool LinkedList<T>::isEmpty() const {
	return this->count == 0;
}

template <typename T>
int LinkedList<T>::length() const {
	return count;
}

template <typename T>
T LinkedList<T>::returnItem(T& item) const {

	Node<T>* p = head;
	if(p == NULL) {			//Make sure list isn't empty
		throw EmptyList();
	}
	while(p != NULL && p->data != item) { //Search list
		p=p->next;
	}
	if(p == NULL) {			//If item is not found, the user needs to be told.
		throw NotFound();
	}
	return p->data;

}

template <typename T>
void LinkedList<T>::addItem(T& item) {

	head = new Node<T>(item, head);
	count++;
	if(tail == NULL) {		//Checks if list was empty before and creates a valid state
		tail = head;
	}

}

template <typename T>
void LinkedList<T>::addToEnd(T& item) {

	if(head == NULL) {		//Handles an empty list
		head = tail = new Node<T>(item);
		count = 1;
	}
	else {
		tail = tail->next = new Node<T>(item);
		count++;
	}

}

template <typename T>
void LinkedList<T>::deleteItem(T& item) {
	if(isEmpty()) {			//handles an empty list
		throw EmptyList();
	}
	if(head->data == item) {	//deleting first node
		Node<T>* temp = head;
		head = head->next;
		delete temp;
		count--;
		if(head == NULL) {
			tail = NULL;
		}
	}
	else {				//searches
		Node<T>* p;
		Node<T>* q;
		p = head;
		q = head->next;
		while(q != NULL && q->data != item) {
			p = q;
			q = q->next;
		}
		if (q == NULL) {
			throw NotFound();
		}
		else {			//deletes if found and handles if it's the tail
			p->next = q->next;
			if (q->next == NULL) {
				tail = p;
			}
			delete q;
			count--;
		}
	}
}

template<typename T>
void LinkedList<T>::clear() {
	Node<T>* p = head;		//Just deletes everything
	while (head != NULL) {
		head = head->next;
		delete p;
		p = head;
	}
	tail = NULL;

}

template<typename T> LinkedList<T>::LinkedList(const LinkedList<T>& other) {
	head = NULL;
	Node<T>* temp = other.head;
	while(temp != NULL) {
		this->addToEnd(temp->data);
	}
}

template<typename T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T>& list) {
	this->clear();			//Copies everything
	Node<T>* temp = list.head;
	while(temp != NULL) {
		this->addToEnd(temp->data);
	}
	return *this;
}

template <typename T>
ostream& operator<<(ostream& out, LinkedList<T>& rhs) {
	Node<T>* temp = rhs.head;
	while (temp != NULL) {
		out<<temp->data;
		temp = temp->next;
	}
}

#endif
