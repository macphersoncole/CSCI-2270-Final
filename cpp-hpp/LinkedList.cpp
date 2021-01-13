#include "LinkedList.hpp"
#include <iostream>

using namespace std;

LinkedList::LinkedList(){
    head = 0;
}

void LinkedList::insertLL(int val){
    LLnode* n = new LLnode();
    n->key = val;
    if(head == 0){
        head = n;
        n->next = 0;
    } else {
        LLnode* curr = head;
        while(curr != 0){
            if(curr->next == 0){
                curr->next = n;
                n->next = 0;
                return;
            }
            curr = curr->next;
        }
    }
    return;
}

LLnode* LinkedList::searchLL(int val){
    LLnode* curr = head;
    while(curr != 0){
        if(curr->key == val){
            return curr;
        }
        curr = curr->next;
    }
    return 0;
}

void LinkedList::displayLL(){
    LLnode* curr = head;
    while(curr != 0){
        cout << curr->key << "->";
        curr = curr->next;
    }
    cout << "END" << endl;
    return;
}