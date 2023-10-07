#include<iostream>
#include"Tree.h"
using namespace std;
void main() {
	Tree t;
	t.InsertNode(15);
	t.InsertNode(4);
	t.InsertNode(2);
	t.InsertNode(5);
	t.InsertNode(20);
	t.InsertNode(16);
	t.InsertNode(22);
	t.InsertNode(21);
	t.InsertNode(23);

	t.PrintTree();
	cout << endl;
	cout << "Broj lista: " << t.NumberOfLeaves() << endl;

	system("pause");
}