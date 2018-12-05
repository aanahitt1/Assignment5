#include <iostream>

using namespace std;

template <typename T>
struct Node {
	T data;
	Node* next;
	
	Node(T data) : data(data), next(NULL)
	{}

	Node(T data, Node* next) : data(data), next(next)
	{}

};


