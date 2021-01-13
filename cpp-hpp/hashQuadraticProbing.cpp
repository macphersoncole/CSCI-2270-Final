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
        table[index] = n;
        n->next = 0;
        return 1;
    } else {
        int j = 1;
        for(int i = index+1; i != index; i = i+(j^2)) {
            if(i > (tableSize-1)){
                i = i - tableSize - 1;
                if(i > (tableSize-1)){
                    return 0;
                }
            }
            if(table[i] == 0){
                table[i] = n;
                return 1;
            }
            numOfcolision++;
            j++;
            //if((j^2) > tableSize){
            //    return 0;
            //}
        }
        return 1;
    }
}

unsigned int HashTable::hashFunction(int key){
    return key % tableSize;
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
        int j = 1;
        while(table[iterator] != 0){
            if(table[iterator]->key == key){
                return table[iterator];
            }
            if(iterator > tableSize - 1){
                iterator = iterator - tableSize - 1;
                if(iterator > tableSize - 1){
                    return 0;
                }
            } else {
                iterator = iterator + (j^2);
            }
            numOfcolision++;
        }
        return 0;
    }
}