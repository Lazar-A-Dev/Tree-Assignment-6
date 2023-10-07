#pragma once
#include<iostream>
#include"Node.h"
using namespace std;
class Tree
{
public:
	Node* root;
	int size;

public:

	Tree();
	~Tree();
	void InsertNode(int p);
	Node* FindNode(int p);
	int NumberOfLeaves();
	int max(int a, int b);
	int NumberOfLeaves(Node* p);
	int Height();
	int Height(Node* p);
	void Mirror();
	void Mirror(Node* p);
	int LevaSuma();
	int LevaSuma(Node* p);
	int DesnaSuma();
	int DesnaSuma(Node* p);
	void PrintTree(Node* p);
	void PrintTree();
};

