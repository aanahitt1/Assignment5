#include <iostream>
#include <fstream>
#include "scanner.h"
#include "UPC.h"

using namespace std;

UPC scan(Scanner<UPC>* scanner, UPC product) {
	return scanner->scan(product);
}

int main() {
	//This file will test how fast a search takes using a binary search tree of various sizes. It will test this using the last item inserted, AKA Worst Case Scenario, as the item will be a leaf.
        const int POINTS = 7;
        int SIZE = 1;

        //This loop will formulate each search anew. I create a new tree each time in order to make the reading of material easier as per the for loop.
        for(int i = 0; i < POINTS; i++) {
        SIZE *= 7;
        cout<<SIZE<<endl;
	BinarySearchTree<UPC>* bst = new BinarySearchTree<UPC>();
	UPC* array = new UPC[SIZE];
	HashArray<UPC>* hash = new HashArray<UPC>(SIZE + 1);
        fstream read;
        read.open("upc_corpus.txt");
        string value;
        string words;
        UPC last;
 //Reads information into the structures. This is a lengthy portion of the process. I wish I could explain why the cout needs to be there, but without it the whole program crashes.
        for(int i = 0; i<SIZE; i++) {
                getline(read, value, ',');
                getline(read, words);
                UPC current(value, words);
		hash->add(current);
		last = current;
		cout<<"";
		array[i] = current;
		cout<<"";
                bst->insert(current);
		
        }

	cout<<endl;
	//I tried to do the scanners, but it created a lot of issues. And since there's a search function for each, it seemed unnecessary. Besides, I have to create the three structures individually, I can't use the scanners.

	UPC found;
        //Track time and search
	//BST search
        clock_t tBST = clock();
        found = bst->search(last);
        tBST = clock()-tBST;

	//Array search
	clock_t tA = clock();
	for(int i = 0; i< SIZE; i++) {
                        if(array[i] == last) {
                                found = array[i];
				break;
        	}
        }
	tA = clock() - tA;

	//Hash search
	clock_t tH = clock();
	found = hash->returnItem(last);
	tH = clock() - tH;

	//Print results
        cout<<found<<endl;
        cout<<"Time for BST search: "<<tBST<<" milliseconds"<<endl;
	cout<<"Time for Array search: "<<tBST<<" milliseconds"<<endl;
        cout<<"Time for HashArray search: "<<tH<<" milliseconds"<<endl;
        cout<<"Size of file: "<<SIZE<<endl;
        delete bst;
	delete[] array;
	delete hash;
        }

        return 0;
}
