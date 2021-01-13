#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <string>

using namespace std;

struct LLnode {
    int key;
    LLnode* next;
};

class LinkedList {
    private:
        LLnode* head;
    public:
        LinkedList();
        void insertLL(int val);
        LLnode* searchLL(int val);
        void displayLL();
};


#endif