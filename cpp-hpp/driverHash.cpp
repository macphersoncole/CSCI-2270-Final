#include "hash.hpp"
#include <iostream>

using namespace std;

int main(){
    int arr[10] = {11,22,33,44,43,62,71,88,99};
    HashTable* ht = new HashTable(15);

    //testing for chaining hash table:
    
    bool garbo;
    for(int i = 0; i < 10; ++i){
        garbo = ht->insertItem(arr[i]);
    }
    ht->insertItem(30);
    ht->insertItem(104);
    cout << ht->searchItem(104) << endl;
    cout << ht->searchItem(11) << endl;
    ht->printTable();
    
   
}