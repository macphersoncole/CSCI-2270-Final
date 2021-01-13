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
    n->key = key;
    int index = hashFunction(key);
    if(table[index] == 0){
        //cout << "1" << endl;
        table[index] = n;
        n->next = 0;
        return 1;
    } else {
        //cout << "2" << endl;
        for(int i = index+1; i != index; ++i) {
            if(i == tableSize-1){
                i = 0;
            }
            if(table[i] == 0){
                table[i] = n;
                return 1;
            }
            numOfcolision++;
        }
        /*
        int i = index+1;
        while(i != index){
            if(i==tableSize-1){
                i = 0;
            }
            if(table[i] == 0){
                table[i] = n;
                return 1;
            }
            i++;
            numOfcolision++;
        }
        */
        return 1;
    }
}

unsigned int HashTable::hashFunction(int key){
    return key % tableSize;
}

void HashTable::printTable(){
    for(int i = 0; i < tableSize; ++i){
        if(table[i] == 0){
            cout << "[" << i << "] -> empty" << endl; 
        } else if(table[i] != 0){
            cout << "[" << i << "] -> key:" << table[i]->key << " (#" << hashFunction(table[i]->key) << ") Value: " << table[i]->key << endl; 
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
        //if the index of the hash of the key is empty, then item does not exist
        return 0;
    } else if(table[hash]->key == key){
        //if index of hash of key has the key you are seaching for, then return that node
        return table[hash];
    } else {
        //If index where hash of key goes is filled, but does not have the key you are looking for,
        //then search until you hit an empty array location and compare each node's key with the key
        //you are looking for. If it matches at any point, return that value. Also, loop iterator 
        int iterator = hash;
        while(table[iterator] != 0){
            if(table[iterator]->key == key){
                return table[iterator];
            }
            if(iterator == tableSize - 1){
                iterator = 0;
            } else {
                iterator++;
            }
            numOfcolision++;
        }
        return 0;
    }
}