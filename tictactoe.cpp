//  Created by Morgan Lucas on 9/27/20.
//  tictactoe  

#include <iostream>
using namespace std;

// prototypes
void tictactoe (char arr[3][3]);
void initArray (char arr [3][3]);
void playerTurn(char arr [3][3], int &num, int &choiceRow, int &choiceCol, char &ch, int &turn);
bool checkWon (char arr [3][3], char ch);
bool checkCats(char arr[3][3], char ch);
bool illegal( int &choiceRow, int &choiceCol);

int main(int argc, const char * argv[]) {
    cout << "Welcome to Tic-Tac-Toe" << endl;
    cout << "======================" << endl;
    
    //initializing variables
    char arr[3][3];
    int num;
    int choiceRow;
    int choiceCol;
    int turn;
    char ch;
    
    // initializes tictactoe grid to be filled with blank spaces to start the game
    initArray(arr);
   
    //tictactoe loop runs until someone wins, theres an illegal move, or its a cats game
    do {
    playerTurn(arr, num, choiceRow,choiceCol, ch, turn);
    illegal(choiceRow, choiceCol); //checks to see if the user input was valid or not
    arr[choiceRow][choiceCol] = ch;
    } while (checkWon(arr, ch) && checkCats(arr, ch));
    
    return 0;
}

//prints tictactoe grid
void tictactoe (char arr[3][3]) {
    
    cout <<   arr[0][0] << "   |   " << arr[0][1] <<  "  |   " << arr[0][2]  << endl;
    cout << "-------------------" << endl;
    cout <<   arr[1][0] << "   |   " << arr[1][1] <<  "  |   " << arr[1][2]  << endl;
    cout << "-------------------" << endl;
    cout <<   arr[2][0] << "   |   " <<  arr[2][1] << "  |   " << arr[2][2]  << endl;
    
}

//initializes grid to be filled with blank spaces
void initArray (char arr[3][3]) {
    
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            arr[row][col] = ' ';
        }
    }
    
}

//switches from player X to player O and allows them to take their turn
void playerTurn (char arr [3][3], int &num, int &choiceRow, int &choiceCol, char &ch, int &turn) {
    if (turn % 2 == 0){
        num = 1;
        ch = 'X';
    }
    if (turn % 2 != 0 ) {
        num = 2;
        ch = 'O';
    }
    turn++;
    cout << "Player " << num << " turn " << ch << endl;
    tictactoe (arr);
    cout << "Which Row would you like?" << endl;
    cin >> choiceRow;
    cout << "Which Col would you like?" << endl;
    cin >> choiceCol;
   
}

// if theres three in a row of either X or O, loop stops and tells the respective player they have won
bool checkWon(char arr[3][3], char ch) {
    //checking rows
    for (int i = 0; i < 3; i++){
        
        if((arr[i][0] == arr[i][1]) && (arr[i][1] == arr[i][2]) && (arr[i][2] == ch)) {
            tictactoe(arr);
            cout << ch << " Player wins!" << endl;
            return false;
            }
    }
    
    // checking columns
    for (int i =0; i < 3; i++){
        if ((arr[0][i] == arr[1][i]) && (arr[1][i] == arr[2][i]) && (arr[2][i]== ch)) {
            tictactoe(arr);
            cout << ch << "Player Wins!" << endl;
            return false;
        }
        
    }
    
        return true;
        
    }

// checks for a cats game--if there is no blank spaces and no one has won, its a cats game
bool checkCats(char arr[3][3], char ch) {
    
    //checking rows
    for (int i = 0; i < 3; i++){
        
        if((arr[i][0] != ' ') && (arr[i][1]!= ' ') && (arr[i][2] != ' ')) {
            tictactoe(arr);
            cout << "Cats game" << endl;
            return false;
            }
    }
    
    // checking columns
    for (int i =0; i < 3; i++){
        if ((arr[0][i] != ' ') && (arr[1][i] != ' ') && (arr[2][i]!= ' ')) {
            tictactoe(arr);
            cout << " cats game" << endl;
            return false;
        }
        
    }
    
        return true;
    
}


// if ther player chooses a space that is already occupied by an X or an O--illegal move
bool illegal( int &choiceRow, int &choiceCol) {
    if ((choiceRow != ' ') && (choiceCol != ' ')) {
        cout << "Ilegal move" << endl;
        return false;
    }
    return true;
}
