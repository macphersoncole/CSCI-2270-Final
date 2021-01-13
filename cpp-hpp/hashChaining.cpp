#include "hash.hpp"
#include <iostream>

using namespace std;

HashTable::HashTable(int bsize){
    tableSize = bsize;
    table = new node*[tableSize];
    for(int i = 0; i < tableSize; ++i){
        table[i] = 0;
    }
}

bool HashTable::insertItem(int key){
    node* n = new node();
    //cout << "7" << endl;
    n->key = key;
    n->next = 0;
    //cout << "6" << endl;
    int index = hashFunction(key);
    //cout << index << endl;
    //cout << table[index] << endl;
    if(table[index] == 0){
        //cout << "4" << endl;
        table[index] = n;
        //cout << "1" << endl;
    } else {
        //cout << "3" << endl;
        n->next = table[index];
        table[index] = n;
        numOfcolision++;
        //cout << "2" << endl;
    }
}

unsigned int HashTable::hashFunction(int key){
    unsigned int hash = key % tableSize;
    //cout << hash << endl;
    return hash;
}

void HashTable::printTable(){
    for(int i = 0; i < tableSize; ++i){
        if(table[i] == 0){
            cout << "[" << i << "] -> empty"; 
        } else if(table[i] != 0){
            cout << "[" << i << "] -> key:" << table[i]->key << "(#" << hashFunction(table[i]->key) << ")" << endl; 
        }
    }
}

int HashTable::getNumOfCollision(){
    int temp = numOfcolision;
    numOfcolision = 0;
    return temp;
}

node* HashTable::searchItem(int key){
    int hash = hashFunction(key);
    if(table[hash] == 0){
        return 0;
    } else {
        node* curr = table[hash];
        while(curr != 0){
            if(curr->key == key){
                return curr;
            }
            curr = curr->next;
        }
        numOfcolision++;
    }
}