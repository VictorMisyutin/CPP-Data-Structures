#include "HashType.cpp"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;
void buildHashTable(ifstream& inFile, HashType<string>& hashTable, int type);

int main(){
    int collisions;
    string content;
    string currentLine;
    string word;
    ifstream file1("hashText1.txt");
    ifstream file2("hashText2.txt");
    ifstream file3("hashText3.txt");
    ifstream file4("hashText4.txt");

    // file 1
    // -------------------
    // create mapping array
    a = 33;
    getline(file1,currentLine);
    primeNum = stoi(currentLine);

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
            if(type == 1)
                hashTable.InsertItemLinear(word);
            else
                hashTable.InsertItemQuadratic(word);
        }
    }
}