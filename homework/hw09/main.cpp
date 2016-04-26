//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

#include "BinaryNodeTree.h"  // ADT binary tree operations
#include <iostream>
#include <string>

using namespace std;

void display(string& anItem)
{
	cout << "Displaying item - " << anItem << endl;
}  // end display

void check(bool success)
{
	if (success)
		cout << "Done." << endl;
	else
		cout << " Entry not in tree." << endl;
}  // end check

int main()
{

	BinaryTreeInterface<string>* tree1 = new BinaryNodeTree<string>();
	BinaryTreeInterface<string>* tree2 = new BinaryNodeTree<string>();
	
	tree1->add("quick");
	tree2->add("quick");
	
	tree1->add("brown");
	tree2->add("brown");
	
	tree1->add("fox");
	tree2->add("fox");
	
	tree1->add("lazy");
	tree2->add("lazy");
	
	tree1->add("dog");	
	tree2->add("dog");

	cout << "Added randomly: quick brown fox lazy dog\n";
	cout << "Tree 1 inorder traversal\n";
	tree1->inorderTraverse(display);
	
	cout << "Tree 2 inorder traversal\n";
	tree2->inorderTraverse(display);
	
	return 0;
}  // end main
