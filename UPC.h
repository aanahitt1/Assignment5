#ifndef _UPC_H_
#define _UPC_H_
#include <iostream>

using namespace std;

struct UPC {
	string key;
	string item;

	UPC(string key, string item) : key(key), item(item) {}
	UPC() : key(""), item("") {}

	//Insert functions because I'm having some trouble
	void addkey(string words) {key = words;}
	void additem(string words) {item = words;}

	//Override operators so that items are only compared by key. KEy is an integer and easily comparable.
	bool operator<(const UPC& rhs) {
		return key<rhs.key;
	}
	bool operator>(const UPC& rhs) {
		return key>rhs.key;
	}
	bool operator==(const UPC& rhs) {
		return key==rhs.key;
	}
	bool operator!=(const UPC& rhs) {
		return key != rhs.key;
	}
	
	friend ostream& operator<<(ostream&, UPC&);	
};

ostream& operator<<(ostream& os, UPC& rhs) {
	os<<rhs.key<<endl<<rhs.item;
	return os;
}

#endif
