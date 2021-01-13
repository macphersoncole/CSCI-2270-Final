#include "BST.hpp"
#include <iostream>

using namespace std;

BST::BST() {
	head = NULL;
}

void printBST(BSTnode* curr) {
	if (curr->left != NULL) {
		printBST(curr->left);
	}
	cout << curr->key << " ";
	if (curr->right != NULL) {
		printBST(curr->right);
	}
	return;
}

void BST::displayBST() {
	printBST(head);
	return;
}

BSTnode* helpSearchBST(BSTnode* curr, int data) {
	if (curr == NULL) {
		return NULL;
	}
	if (curr->key == data) {
		return curr;
	}
	if (curr->key > data) {
		return helpSearchBST(curr->left, data);
	}
	return helpSearchBST(curr->right, data);
}

BSTnode* BST::searchBST(int key) {
	BSTnode* tree = helpSearchBST(head, key);
	return tree;
}

BSTnode* createBSTnode(int data) {
	BSTnode* newNode = new BSTnode;
    newNode->key = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void addBSTnode(BSTnode* curr, BSTnode* add) {
	if (add->key < curr->key && curr->left == NULL) {
		curr->left = add;
	} else if (add->key < curr->key && curr->left != NULL) {
		addBSTnode(curr->left,add);
	}
	if (add->key > curr->key && curr->right == NULL) {
		curr->right = add;
	} else if (add->key > curr->key && curr->right != NULL) {
		addBSTnode(curr->right,add);
	}
}

void BST::insertBST(int key) {
	BSTnode* add = createBSTnode(key);
	if (head == NULL) {
		head = add;
	} else {
		addBSTnode(head,add);
	}
	return;
}