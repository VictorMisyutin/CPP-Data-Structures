#include "HashType.cpp"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;
void buildHashTable(ifstream& inFile, HashType<string>& hashTable, int type);

int main(){
    // int collisions;
    ifstream file1("hashText1.txt");
    ifstream file2("hashText2.txt");
    ifstream file3("hashText3.txt");
    ifstream file4("hashText4.txt");
        

    int primeNumber;
    string currentLine;
    // file 1
    // -------------------
    getline(file1, currentLine);
    primeNumber = stoi(currentLine);
    HashType<string> map1(primeNumber, 0);
    cout << "HashText1.txt\n" << endl;
    // LINEAR
    cout << "Linear: " << endl;
    cout << "Hash Table Size: " << primeNumber << endl;
    map1.setA(33);
    buildHashTable(file1, map1, 1);
    cout << "Number of collisions with a = 33: " << map1.GetCollisions() << endl; 
    cout << "Hash Table Size: " << primeNumber << endl;
    file1.clear();
    file1.seekg(0,ios::beg);
    map1.MakeEmpty();
    map1.setA(37);
    buildHashTable(file1, map1, 1);
    cout << "Number of collisions with a = 37: " << map1.GetCollisions() << endl; 
    cout << "Hash Table Size: " << primeNumber << endl;
    file1.clear();
    file1.seekg(0,ios::beg);
    map1.MakeEmpty();
    map1.setA(39);
    buildHashTable(file1, map1, 1);
    cout << "Number of collisions with a = 39: " << map1.GetCollisions() << endl; 
    cout << "Hash Table Size: " << primeNumber << endl;
    file1.clear();
    file1.seekg(0,ios::beg);
    map1.MakeEmpty();
    map1.setA(41);
    buildHashTable(file1, map1, 1);
    cout << "Number of collisions with a = 41: " << map1.GetCollisions() << endl; 
    // QUADRATIC
    cout << "Quadratic: " << endl;
    cout << "Hash Table Size: " << primeNumber << endl;
    map1.setA(33);
    buildHashTable(file1, map1, 0);
    cout << "Number of collisions with a = 33: " << map1.GetCollisions() << endl; 
    cout << "Hash Table Size: " << primeNumber << endl;
    file1.clear();
    file1.seekg(0,ios::beg);
    map1.MakeEmpty();
    map1.setA(37);
    buildHashTable(file1, map1, 0);
    cout << "Number of collisions with a = 37: " << map1.GetCollisions() << endl; 
    cout << "Hash Table Size: " << primeNumber << endl;
    file1.clear();
    file1.seekg(0,ios::beg);
    map1.MakeEmpty();
    map1.setA(39);
    buildHashTable(file1, map1, 0);
    cout << "Number of collisions with a = 39: " << map1.GetCollisions() << endl; 
    cout << "Hash Table Size: " << primeNumber << endl;
    file1.clear();
    file1.seekg(0,ios::beg);
    map1.MakeEmpty();
    map1.setA(41);
    buildHashTable(file1, map1, 0);
    cout << "Number of collisions with a = 41: " << map1.GetCollisions() << endl; 
    
    // file 2
    // -------------------
    cout << "\nHashText2.txt\n" << endl;
    getline(file2, currentLine);
    primeNumber = stoi(currentLine);
    HashType<string> map2(primeNumber, 0);
    // LINEAR
    cout << "Linear: " << endl;
    cout << "Hash Table Size: " << primeNumber << endl;
    map2.setA(33);
    buildHashTable(file2, map2, 1);
    cout << "Number of collisions with a = 33: " << map2.GetCollisions() << endl; 
    cout << "Hash Table Size: " << primeNumber << endl;
    file2.clear();
    file2.seekg(0,ios::beg);
    map2.MakeEmpty();
    map2.setA(37);
    buildHashTable(file2, map2, 1);
    cout << "Number of collisions with a = 37: " << map2.GetCollisions() << endl; 
    cout << "Hash Table Size: " << primeNumber << endl;
    file2.clear();
    file2.seekg(0,ios::beg);
    map2.MakeEmpty();
    map2.setA(39);
    buildHashTable(file2, map2, 1);
    cout << "Number of collisions with a = 39: " << map2.GetCollisions() << endl; 
    cout << "Hash Table Size: " << primeNumber << endl;
    file2.clear();
    file2.seekg(0,ios::beg);
    map2.MakeEmpty();
    map2.setA(41);
    buildHashTable(file2, map2, 1);
    cout << "Number of collisions with a = 41: " << map2.GetCollisions() << endl; 
    // QUADRATIC
    cout << "Quadratic: " << endl;
    cout << "Hash Table Size: " << primeNumber << endl;
    map2.setA(33);
    buildHashTable(file2, map2, 0);
    cout << "Number of collisions with a = 33: " << map2.GetCollisions() << endl; 
    cout << "Hash Table Size: " << primeNumber << endl;
    file2.clear();
    file2.seekg(0,ios::beg);
    map2.MakeEmpty();
    map2.setA(37);
    buildHashTable(file2, map2, 0);
    cout << "Number of collisions with a = 37: " << map2.GetCollisions() << endl; 
    cout << "Hash Table Size: " << primeNumber << endl;
    file2.clear();
    file2.seekg(0,ios::beg);
    map2.MakeEmpty();
    map2.setA(39);
    buildHashTable(file2, map2, 0);
    cout << "Number of collisions with a = 39: " << map2.GetCollisions() << endl; 
    cout << "Hash Table Size: " << primeNumber << endl;
    file2.clear();
    file2.seekg(0,ios::beg);
    map2.MakeEmpty();
    map2.setA(41);
    buildHashTable(file2, map2, 0);
    cout << "Number of collisions with a = 41: " << map2.GetCollisions() << endl; 

    // file 3
    // -------------------
    cout << "\nHashText3.txt\n" << endl;
    getline(file3, currentLine);
    primeNumber = stoi(currentLine);
    HashType<string> map3(primeNumber, 0);
    // LINEAR
    cout << "Linear: " << endl;
    cout << "Hash Table Size: " << primeNumber << endl;
    map3.setA(33);
    buildHashTable(file3, map3, 1);
    cout << "Number of collisions with a = 33: " << map3.GetCollisions() << endl; 
    cout << "Hash Table Size: " << primeNumber << endl;
    file3.clear();
    file3.seekg(0,ios::beg);
    map3.MakeEmpty();
    map3.setA(37);
    buildHashTable(file3, map3, 1);
    cout << "Number of collisions with a = 37: " << map3.GetCollisions() << endl; 
    cout << "Hash Table Size: " << primeNumber << endl;
    file3.clear();
    file3.seekg(0,ios::beg);
    map3.MakeEmpty();
    map3.setA(39);
    buildHashTable(file3, map3, 1);
    cout << "Number of collisions with a = 39: " << map3.GetCollisions() << endl; 
    cout << "Hash Table Size: " << primeNumber << endl;
    file3.clear();
    file3.seekg(0,ios::beg);
    map3.MakeEmpty();
    map3.setA(41);
    buildHashTable(file3, map3, 1);
    cout << "Number of collisions with a = 41: " << map3.GetCollisions() << endl; 
    // QUADRATIC
    cout << "Quadratic: " << endl;
    cout << "Hash Table Size: " << primeNumber << endl;
    map3.setA(33);
    buildHashTable(file3, map3, 0);
    cout << "Number of collisions with a = 33: " << map3.GetCollisions() << endl; 
    cout << "Hash Table Size: " << primeNumber << endl;
    file3.clear();
    file3.seekg(0,ios::beg);
    map3.MakeEmpty();
    map3.setA(37);
    buildHashTable(file3, map3, 0);
    cout << "Number of collisions with a = 37: " << map3.GetCollisions() << endl; 
    cout << "Hash Table Size: " << primeNumber << endl;
    file3.clear();
    file3.seekg(0,ios::beg);
    map3.MakeEmpty();
    map3.setA(39);
    buildHashTable(file3, map3, 0);
    cout << "Number of collisions with a = 39: " << map3.GetCollisions() << endl; 
    cout << "Hash Table Size: " << primeNumber << endl;
    file3.clear();
    file3.seekg(0,ios::beg);
    map3.MakeEmpty();
    map3.setA(41);
    buildHashTable(file2, map3, 0);
    cout << "Number of collisions with a = 41: " << map3.GetCollisions() << endl; 

    // file 4
    // -------------------
    cout << "\nHashText4.txt\n" << endl;
    getline(file4, currentLine);
    primeNumber = stoi(currentLine);
    HashType<string> map4(primeNumber, 0);
    // LINEAR
    cout << "Linear: " << endl;
    cout << "Hash Table Size: " << primeNumber << endl;
    map4.setA(33);
    buildHashTable(file4, map4, 1);
    cout << "Number of collisions with a = 33: " << map4.GetCollisions() << endl; 
    cout << "Hash Table Size: " << primeNumber << endl;
    file4.clear();
    file4.seekg(0,ios::beg);
    map4.MakeEmpty();
    map4.setA(37);
    buildHashTable(file4, map4, 1);
    cout << "Number of collisions with a = 37: " << map4.GetCollisions() << endl; 
    cout << "Hash Table Size: " << primeNumber << endl;
    file4.clear();
    file4.seekg(0,ios::beg);
    map4.MakeEmpty();
    map4.setA(39);
    buildHashTable(file4, map4, 1);
    cout << "Number of collisions with a = 39: " << map4.GetCollisions() << endl; 
    cout << "Hash Table Size: " << primeNumber << endl;
    file4.clear();
    file4.seekg(0,ios::beg);
    map4.MakeEmpty();
    map4.setA(41);
    buildHashTable(file4, map4, 1);
    cout << "Number of collisions with a = 41: " << map4.GetCollisions() << endl; 
    // QUADRATIC
    cout << "Quadratic: " << endl;
    cout << "Hash Table Size: " << primeNumber << endl;
    map4.setA(33);
    buildHashTable(file4, map4, 0);
    cout << "Number of collisions with a = 33: " << map4.GetCollisions() << endl; 
    cout << "Hash Table Size: " << primeNumber << endl;
    file4.clear();
    file4.seekg(0,ios::beg);
    map4.MakeEmpty();
    map4.setA(37);
    buildHashTable(file4, map4, 0);
    cout << "Number of collisions with a = 37: " << map4.GetCollisions() << endl; 
    cout << "Hash Table Size: " << primeNumber << endl;
    file4.clear();
    file4.seekg(0,ios::beg);
    map4.MakeEmpty();
    map4.setA(39);
    buildHashTable(file4, map4, 0);
    cout << "Number of collisions with a = 39: " << map4.GetCollisions() << endl; 
    cout << "Hash Table Size: " << primeNumber << endl;
    file4.clear();
    file4.seekg(0,ios::beg);
    map4.MakeEmpty();
    map4.setA(41);
    buildHashTable(file4, map4, 0);
    cout << "Number of collisions with a = 41: " << map4.GetCollisions() << endl; 


    return 0;
}

void buildHashTable(ifstream& inFile, HashType<string>& hashTable, int type){
    string word;
    int length;
    if (inFile.is_open()){
        while(inFile >> word){
            length = word.size();
            for (int i = 0; i < length; i++){
                // check whether character is punctuation or not
                if(ispunct(word[i])){
                    word.erase(i--, 1);
                    length = word.size();
                }
            }
            if(type == 1){
                hashTable.InsertItemLinear(word);
            }
            else
                hashTable.InsertItemQuadratic(word);
        }
    }
}