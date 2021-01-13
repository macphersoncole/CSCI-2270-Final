#include "LinkedList.hpp"
#include "BST.hpp"
#include "hash.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>
#include <cstdlib>
#include <iomanip>

using namespace std;
using namespace std::chrono;


int main(){

	ifstream inFile;
	int data[40000];
	float insert[400];
	float search[400];
	int insertCollision[400];
	int searchCollision[400];
	inFile.open("dataSetA.csv");
	int j = 0;
	string inputNum;
	int num;
	while (getline(inFile,inputNum,',')) {
		num = stoi(inputNum);
		data[j] = num;
		j++;
	}
	inFile.close();


    //Linked List testing////////////////////////////////
    // int arr[7] = {4,52,8,27,901,14,22};
    // LinkedList ll1;
    // for(int i = 0; i < 7; ++i){
    //     ll1.insertLL(arr[i]);
    // }
    // ll1.insertLL(10);
    // ll1.insertLL(420);
    // ll1.insertLL(69);
    // ll1.displayLL();
    //
    //Linked List Eperiment//////////////////////////
	LinkedList ll;
	ofstream data_A;
    data_A.open("insert_search_LL_dataset_A.csv");
    data_A << "Intertion times" << "," << "Searching times" << endl;
	for (int k = 0; k < 400; k++) {
		// Linked list insert first 100
		auto startIN = steady_clock::now();
		for (int i = k*100; i < (k*100)+100; i++) {
	        ll.insertLL(data[i]);
	    }
	    auto stopIN = steady_clock::now();
	    auto durationIN = duration_cast<nanoseconds>(stopIN - startIN);
	    insert[k] = durationIN.count()/100;
	    // Linked list first search
	    int randNums[100];
	    for (int i = 0; i < 100; i++) {
	    	randNums[i] = rand() % ((k*100)+100);
	    }
	    LLnode* tempLLsearch;
	    auto startS = steady_clock::now();
	    for (int i = 0; i < 100; i++) {
	    	tempLLsearch = ll.searchLL(data[randNums[i]]);
	    }
	    auto stopS = steady_clock::now();
	    auto durationS = duration_cast<nanoseconds>(stopS - startS);
	    search[k] = durationS.count()/100;
	    // export data
	    data_A << insert[k] << ", " << search[k] << endl;
    }
    data_A.close();

	// //BST testing/////////////////////////////////////////
 //    // BST* tree = new BST();
 //    // for (int i = 0; i < 7; i++){
 //    // 	tree->insertBST(arr[i]);
 //    // }
 //    // tree->insertBST(10);
 //    // tree->insertBST(420);
 //    // tree->insertBST(69);
 //    // tree->displayBST();
 //    //BST Implementation//////////////////////////////////
    BST* tree = new BST();
    ofstream data_A_BST;
    data_A_BST.open("insert_search_BST_dataset_A.csv");
    data_A_BST << "Intertion times" << "," << "Searching times" << endl;
	for (int k = 0; k < 400; k++) {
    	// insertion
    	auto startIN = steady_clock::now();
		for (int i = k*100; i < (k*100)+100; i++) {
	        tree->insertBST(data[i]);
	    }
	    auto stopIN = steady_clock::now();
	    auto durationIN = duration_cast<nanoseconds>(stopIN - startIN);
	    insert[k] = durationIN.count()/100;
	    // search
	    int randNums[100];
	    for (int i = 0; i < 100; i++) {
	    	randNums[i] = rand() % ((k*100)+100);
	    }
	    BSTnode* tempBSTsearch;
	    auto startS = steady_clock::now();
	    for (int i = 0; i < 100; i++) {
	    	tempBSTsearch = tree->searchBST(data[randNums[i]]);
	    }
	    auto stopS = steady_clock::now();
	    auto durationS = duration_cast<nanoseconds>(stopS - startS);
	    search[k] = durationS.count()/100;

	    data_A_BST << insert[k] << ", " << search[k] << endl;
    }
    data_A_BST.close();

    //Hash testing////////////////////////////////////////
    // nt arr[10] = {11,22,33,44,43,62,71,88,99};
    // HashTable* ht = new HashTable(15);
    // bool garbo;
    // for(int i = 0; i < 10; ++i){
    //     garbo = ht->insertItem(arr[i]);
    // }
    // ht->insertItem(30);
    // ht->insertItem(104);
    // cout << ht->searchItem(104) << endl;
    // cout << ht->searchItem(11) << endl;
    // ht->printTable();
    //Hash implementation/////////////////////////////////
    HashTable* ht = new HashTable(40009);
    ofstream data_A_HT;
    data_A_HT.open("insert_search_HT_L_dataset_A.csv");
    data_A_HT << "Intertion times" << "," << "Searching times" << endl;
    for (int k = 0; k < 400; k++) {
    	// insertion
    	auto startIN = steady_clock::now();
		for (int i = k*100; i < (k*100)+100; i++) {
	        ht->insertItem(data[i]);
	    }
	    auto stopIN = steady_clock::now();
	    auto durationIN = duration_cast<nanoseconds>(stopIN - startIN);
	    insert[k] = durationIN.count()/100;
	    insertCollision[k] = ht->getNumOfCollision();
	    // search
	    int randNums[100];
	    for (int i = 0; i < 100; i++) {
	    	randNums[i] = rand() % ((k*100)+100);
	    }
	    node* tempHTsearch;
	    auto startS = steady_clock::now();
	    for (int i = 0; i < 100; i++) {
	    	tempHTsearch = ht->searchItem(data[randNums[i]]);
	    }
	    auto stopS = steady_clock::now();
	    auto durationS = duration_cast<nanoseconds>(stopS - startS);
	    search[k] = durationS.count()/100;
	    searchCollision[k] = ht->getNumOfCollision();

	    data_A_HT << insert[k] << ", " << search[k] << ", " << insertCollision[k] << ", "  << searchCollision[k] << endl;
    }
    data_A_HT.close();

    // DATA SET B
    inFile.open("dataSetB.csv");
	j = 0;
	string inputNum2;
	int num2;
	while (getline(inFile,inputNum2,',')) {
		num2 = stoi(inputNum2);
		data[j] = num2;
		j++;
	}
	inFile.close();

 //    //Linked List testing////////////////////////////////
 //    // int arr[7] = {4,52,8,27,901,14,22};
 //    // LinkedList ll1;
 //    // for(int i = 0; i < 7; ++i){
 //    //     ll1.insertLL(arr[i]);
 //    // }
 //    // ll1.insertLL(10);
 //    // ll1.insertLL(420);
 //    // ll1.insertLL(69);
 //    // ll1.displayLL();
 //    //
 //    //Linked List Eperiment//////////////////////////
	LinkedList ll2;
	ofstream data_B;
    data_B.open("insert_search_LL_dataset_B.csv");
    data_B << "Intertion times" << "," << "Searching times" << endl;
	for (int k = 0; k < 400; k++) {
		// Linked list insert first 100
		auto startIN = steady_clock::now();
		for (int i = k*100; i < (k*100)+100; i++) {
	        ll2.insertLL(data[i]);
	    }
	    auto stopIN = steady_clock::now();
	    auto durationIN = duration_cast<nanoseconds>(stopIN - startIN);
	    insert[k] = durationIN.count()/100;
	    // Linked list first search
	    int randNums[100];
	    for (int i = 0; i < 100; i++) {
	    	randNums[i] = rand() % ((k*100)+100);
	    }
	    LLnode* tempLLsearch;
	    auto startS = steady_clock::now();
	    for (int i = 0; i < 100; i++) {
	    	tempLLsearch = ll2.searchLL(data[randNums[i]]);
	    }
	    auto stopS = steady_clock::now();
	    auto durationS = duration_cast<nanoseconds>(stopS - startS);
	    search[k] = durationS.count()/100;
	    // export data
	    data_B << insert[k] << ", " << search[k] << endl;
    }
    data_B.close();

	// //BST testing/////////////////////////////////////////
 //    // BST* tree = new BST();
 //    // for (int i = 0; i < 7; i++){
 //    // 	tree->insertBST(arr[i]);
 //    // }
 //    // tree->insertBST(10);
 //    // tree->insertBST(420);
 //    // tree->insertBST(69);
 //    // tree->displayBST();
 //    //BST Implementation//////////////////////////////////
    BST* tree2 = new BST();
    ofstream data_B_BST;
    data_B_BST.open("insert_search_BST_dataset_B.csv");
    data_B_BST << "Intertion times" << "," << "Searching times" << endl;
	for (int k = 0; k < 400; k++) {
    	// insertion
    	auto startIN = steady_clock::now();
		for (int i = k*100; i < (k*100)+100; i++) {
	        tree2->insertBST(data[i]);
	    }
	    auto stopIN = steady_clock::now();
	    auto durationIN = duration_cast<nanoseconds>(stopIN - startIN);
	    insert[k] = durationIN.count()/100;
	    // search
	    int randNums[100];
	    for (int i = 0; i < 100; i++) {
	    	randNums[i] = rand() % ((k*100)+100);
	    }
	    BSTnode* tempBSTsearch;
	    auto startS = steady_clock::now();
	    for (int i = 0; i < 100; i++) {
	    	tempBSTsearch = tree2->searchBST(data[randNums[i]]);
	    }
	    auto stopS = steady_clock::now();
	    auto durationS = duration_cast<nanoseconds>(stopS - startS);
	    search[k] = durationS.count()/100;

	    data_B_BST << insert[k] << ", " << search[k] << endl;
    }
    data_B_BST.close();

    //Hash testing////////////////////////////////////////
    // nt arr[10] = {11,22,33,44,43,62,71,88,99};
    // HashTable* ht = new HashTable(15);
    // bool garbo;
    // for(int i = 0; i < 10; ++i){
    //     garbo = ht->insertItem(arr[i]);
    // }
    // ht->insertItem(30);
    // ht->insertItem(104);
    // cout << ht->searchItem(104) << endl;
    // cout << ht->searchItem(11) << endl;
    // ht->printTable();
    //Hash implementation/////////////////////////////////
    HashTable* ht2 = new HashTable(40009);
    ofstream data_B_HT;
    data_B_HT.open("insert_search_HT_L_dataset_B.csv");
    data_B_HT << "Intertion times" << "," << "Searching times" << endl;
    for (int k = 0; k < 400; k++) {
    	// insertion
    	auto startIN = steady_clock::now();
		for (int i = k*100; i < (k*100)+100; i++) {
	        ht2->insertItem(data[i]);
	    }
	    auto stopIN = steady_clock::now();
	    auto durationIN = duration_cast<nanoseconds>(stopIN - startIN);
	    insert[k] = durationIN.count()/100;
	    insertCollision[k] = ht->getNumOfCollision();
	    // search
	    int randNums[100];
	    for (int i = 0; i < 100; i++) {
	    	randNums[i] = rand() % ((k*100)+100);
	    }
	    node* tempHTsearch;
	    auto startS = steady_clock::now();
	    for (int i = 0; i < 100; i++) {
	    	tempHTsearch = ht2->searchItem(data[randNums[i]]);
	    }
	    auto stopS = steady_clock::now();
	    auto durationS = duration_cast<nanoseconds>(stopS - startS);
	    search[k] = durationS.count()/100;
	    searchCollision[k] = ht->getNumOfCollision();
		
		data_B_HT << insert[k] << ", " << search[k] << ", " << insertCollision[k] << ", "  << searchCollision[k] << endl;
    }
    data_B_HT.close();

    return 0;
}