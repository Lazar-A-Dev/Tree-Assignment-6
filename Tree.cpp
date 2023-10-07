#include "Tree.h"
Tree::Tree() {
	root = NULL;
	size = 0;
}

Tree::~Tree() {

}

void Tree::InsertNode(int p) {
	if (root == NULL) {
		Node* tmp = new Node(p, NULL, NULL, NULL);
		root = tmp;
		size = 1;
	}
	else {
		Node* first = root;
		Node* second = NULL;

		while (first != NULL) {
			second = first;
			if (first->info > p)
				first = first->left;
			else if (first->info < p)
				first = first->right;
		}

		if (second->info > p) {
			second->left = new Node(p, NULL, NULL, second);
			size++;
		}
		else if (second->info < p) {
			second->right = new Node(p, NULL, NULL, second);
			size++;
		}
	}
}

Node* Tree::FindNode(int p) {
	Node* tmp = root;
	while (tmp != NULL) {
		if (tmp->info == p)
			return tmp;
		if (tmp->info > p)
			tmp = tmp->left;
		else if (tmp->info < p)
			tmp = tmp->right;
	}
	return 0;
}

int Tree::NumberOfLeaves() {
	return NumberOfLeaves(root);
}

int Tree::NumberOfLeaves(Node* p) {
	if (p == NULL)
		return 0;
	else if (p->left == NULL && p->right == NULL)
		return 1;
	return NumberOfLeaves(p->left) + NumberOfLeaves(p->right);
}

int Tree::Height() {
	return Height(root);
}

int Tree::Height(Node* p) {
	if (p == NULL)
		return 0;
	if (p->left == NULL && p->right == NULL)
		return 1;
	return 1 + max(Height(p->left), Height(p->right));

}

int Tree::max(int a, int b) {
	if (a >= b)
		return a;
	else return b;
}

void Tree::Mirror() {
	Mirror(root);
}

void Tree::Mirror(Node* p) {
	if (p != NULL) {
		Node* tmp = p->left;
		p->left = p->right;
		p->right = tmp;

		Mirror(p->left);
		Mirror(p->right);
	}
	else return;
}

int Tree::LevaSuma() {
	return LevaSuma(root);
}

int Tree::LevaSuma(Node* p) {
	if (p == NULL)
		return 0;
	if (p->left != NULL) {
		Node* tmp = p->left;
		return tmp->info + LevaSuma(tmp) + DesnaSuma(tmp);
	}
	else return 0;
}

int Tree::DesnaSuma() {
	return DesnaSuma(root);
}

int Tree::DesnaSuma(Node* p) {
	if (p == NULL)
		return 0;
	if (p->right != NULL) {
		Node* tmp = p->right;
		return tmp->info + LevaSuma(tmp) + DesnaSuma(tmp);
	}
	else return 0;
}

void Tree::PrintTree(Node* p) {
	if (p != NULL) {
		cout << "[" << p->info << "] ";
		PrintTree(p->left);
		PrintTree(p->right);
	}
}

void Tree::PrintTree() {
	PrintTree(root);
}
