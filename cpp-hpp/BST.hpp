#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP

#include <string>

using namespace std;

struct BSTnode {
    int key;
    BSTnode* left;
    BSTnode* right;
};

class BST {
    private:
        BSTnode* head;
    public:
        BST();
        void insertBST(int key);
        BSTnode* searchBST(int key);
        void displayBST();
};


#endif