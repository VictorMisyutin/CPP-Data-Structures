#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void process(string name){
    int count = 0;
    int frontNum = 1;
    int spaceLocation = name.find(' ');
    for (int i = 0;i< name.size();i++){
        if(i==spaceLocation){
            frontNum = 2;
            cout << endl;
        // continue
        }
        else{
            if(frontNum > 9){
                cout << frontNum << setw(i+1) << char(toupper(name[i])) << endl;
                frontNum += 2;
            }
            else{
                if(frontNum <= 9){
                cout << frontNum << setw(i+2) << char(toupper(name[i])) << endl;
                frontNum += 2;
                }
            }
        }
    }
}

int main(){
    string myName = "Juandiego Vargas";
    cout << "Enter your name as \"First Last\"" << endl;
    string userName;
    getline(cin, userName, '\n');
    cout << "Your Name: " << userName << endl;
    process(userName);
    int myNameLength = myName.size();
    cout << "The length of myName including the space is: " << myNameLength << endl;
    cout << "The first character in myName: " << myName[0] << endl;
    cout << "The last character in myName: " << myName[myNameLength-1] << endl;

    for (int i = 0; i< myName.size();i++){
        if((i+1) > 9){
            cout << (i+1) << setw(i+1) << char(toupper(myName[i])) << endl;
        }
        else{
            cout << (i+1) << setw(i+2) << char(toupper(myName[i])) << endl;
        }
    }
    return 0;
}

