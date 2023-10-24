#include <iostream>
using namespace std;
#define MAGIC_SUM 34

int main() {
    int board[4][4];  //This board allows 16 numbers.
    cout << "Enter 16 numbers: ";
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            cin >> board[i][j];
        }
    }
    //Make sure the user enters 16 numbers. Keep in mind they might enter any numbers here.

    //Check that 1 to 16 has been entered.
    bool numCheck[16];
    for(int i = 0; i < 16; i++){
        numCheck[i] = false;
    }
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(board[i][j] >= 1 and board[i][j] <= 16){
                numCheck[board[i][j]-1] = true;
            }
        }
    }
    for(int i = 0; i < 16; i++){
        if(numCheck[i] == false)
            cout << "Not all numbers have been entered." << endl;
    }

    //Sum the rows
    int rowSums[] = {0, 0, 0, 0};
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            rowSums[i] += board[i][j];
        }
    }

    //Sum the columns
    int colSums[] = {0, 0, 0, 0};
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            colSums[j] += board[i][j];
        }
    }

    //Diagonal sums
    int diagSums[] = {0, 0};
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 4; j++){
            diagSums[i] += board[j][j];
        }
    }
    //Display the square and the sums for the rows, columns, and diagonals
    // Display board
    cout << endl << "This is the board: " << endl;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    // display sums
    for(int i = 0; i < 4; i++){
        cout << "The sum of row " + to_string(i+1) + " is " + to_string(rowSums[i]) << endl;
    }
    cout << endl;
    for(int i = 0; i < 4; i++){
        cout << "The sum of column " + to_string(i+1) + " is " + to_string(colSums[i]) << endl;
    }
    cout << endl;
    for(int i = 0; i < 2; i++){
        cout << "The sum of diagnol " + to_string(i+1) + " is " + to_string(colSums[i]) << endl;
    }
    cout << endl;
    //Check the sums of the rows
    bool badBoard = false;
    int sum = colSums[0];
    for(int i = 0; i < 4; i++){
        if(colSums[i] != sum || rowSums[i] != sum){
            badBoard = true;
            break;
        }
    }

    if(badBoard)
        cout << "This board is not a magic square." << endl;
    else
        cout << "This board is a magic square!" << endl; 
    return 0;
}