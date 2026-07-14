#include <iostream>
#include <string>
#include <limits> 
#include <cstdlib> 
#include <ctime> 
using namespace std;

int gameMode; 
string player1Name = "Player1"; 
string player2Name = "Player2"; 
char board[3][3];
int row, column;

// Check if there are any empty spaces left
bool isBoardFull(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[i][j] == ' '){
                return false;
            }
        }
    }
    return true;
}

// Initialize the board with empty spaces
void resetBoard(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            board[i][j] = ' ';
        }
    }
    cout << "\nResetting the board process done." << endl;
}

void funcMode1(){
    cout << "Enter your name: ";
    cin >> player1Name;
    cout << "Player1: \e[1m" << player1Name << "\e[0m" << endl;
    cout << "Player2: \e[1mPC-Alaa-Droid\e[0m" << endl;
    cout << "The game about to be started get ready..." << endl;
}
    
void funcMode2(){
    cout << "Enter player1 name: ";
    cin >> player1Name;
    cout << "Enter player2 name: ";
    cin >> player2Name;
    cout << "Player1: \e[1m" << player1Name << "\e[0m and Player2: \e[1m" << player2Name << "\e[0m" << endl;
    cout << "The game about to be started get ready..." << endl;
}

void displayBoard(){    
    cout << "┌───┬───┬───┐\n│ " << board[0][0] << " │ " << board[0][1] << " │ " << board[0][2] << " │\n├───┼───┼───┤\n│ " << board[1][0] << " │ " << board[1][1] << " │ " << board[1][2] << " │\n├───┼───┼───┤\n│ " << board[2][0] << " │ " << board[2][1] << " │ " << board[2][2] << " │\n└───┴───┴───┘\n";
    cout << "──────────────────────────────────" << endl;
}

void player1Move(){
    if(isBoardFull()) return;
    cout << "\e[1mPlayer1\e[0m " << player1Name << " \e[0mmove: ";
    cout << "\nEnter row number then column number: ";
    
    while(true){
        if(cin >> row >> column){
            if(row >= 1 && row <= 3 && column >= 1 && column <= 3){
                if(board[row-1][column-1] == ' '){
                    board[row-1][column-1] = 'X';
                    break;
                } else {
                    cout << "\nSpot already taken! Try again please: ";
                }
            } else {
                cout << "Invalid coordinates! Please enter numbers between 1 and 3: ";
            }
        } else {
            cout << "\033[31m" << "Error: Please enter numbers, not characters!" << "\033[0m" << endl;    
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard bad input
            cout << "Enter row number then column number: ";
        }
    } 
}

void player2Move(){
    if(isBoardFull()) return;
    cout << "Player2 \e[1m" << player2Name << "\e[0m move: ";
    cout << "\nEnter row number then column number: ";
    
    while(true){
        if(cin >> row >> column){
            if(row >= 1 && row <= 3 && column >= 1 && column <= 3){
                if(board[row-1][column-1] == ' '){
                    board[row-1][column-1] = 'O';
                    break;
                } else {
                    cout << "\nSpot already taken! Try again please: ";
                }
            } else {
                cout << "Invalid coordinates! Please enter numbers between 1 and 3: ";
            }
        } else { 
            cout << "\033[31m" << "Error: Please enter numbers, not characters!" << "\033[0m" << endl;    
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter row number then column number: ";
        }
    }
}

void pcMove(){
    if(isBoardFull()) return;
    cout << "\n\e[1mPC-Alaa Droid move:\e[0m \n";
    while(true){
        int pcRow = (rand() % 3) + 1;
        int pcCol = (rand() % 3) + 1;
        
        // Ensure the random spot is available
        if(board[pcRow - 1][pcCol - 1] == ' '){
            board[pcRow - 1][pcCol - 1] = 'O';
            break;
        }
    }
}

char checkWinner(){
    // Check rows
    for(int i = 0 ; i < 3; i++){
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' '){
            return board[i][0];    
        }
    }
    // Check columns
    for(int i = 0 ; i < 3; i++){
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' '){
            return board[0][i];    
        }
    }
    // Check diagonals
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' '){
        return board[0][0];    
    }
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' '){
        return board[0][2]; 
    }
    
    return 0;
}

int main(){
    
    resetBoard();
    srand(time(0)); // Seed for random moves
    
    cout << "┌────────────────────────────────┐" << endl;
    cout << "|   \e[1mHELLO to TIC TAC TOE GAME\e[0m    |" << endl;
    cout << "└────────────────────────────────┘" << endl;
    cout << "┌───┬───┬───┐\n│ X │ O │ O │\n├───┼───┼───┤\n│ O │ X │ O │\n├───┼───┼───┤\n│ X │ O │ X │\n└───┴───┴───┘\n";
    
    // Game mode selection loop
    while (true) { 
        cout << "\nChoose the game mode:\n •2Player (enter '2') \n •1Player (enter '1')\n";
        
        if (cin >> gameMode) { 
            if (gameMode == 1 || gameMode == 2) {
                break; 
            }
            cout << "Invalid choice. Please enter 1 or 2." << endl;
        } else {
            cout << "\033[31m" << "Error: Please enter a number, not characters!" << "\033[0m" << endl;
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        }
    }
    
    switch(gameMode){
        
        case 1:
            cout << "FunctionMode1 selected" << endl;
            funcMode1();
            cout << "\nTo select the correct place: \n" << "Column:   1     2     3\nRow:   ┌─────┬─────┬─────┐\n     1 │ 1 1 │ 1 2 │ 1 3 │\n       ├─────┼─────┼─────┤\n     2 │ 2 1 │ 2 2 │ 2 3 │\n       ├─────┼─────┼─────┤\n     3 │ 3 1 │ 3 2 │ 3 3 │\n       └─────┴─────┴─────┘\n";
            cout << "──────────────────────────────────" << endl;
            
            while(true){
                player1Move();
                displayBoard();
                if(checkWinner() == 'X' || checkWinner() == 'O') break;
                if(isBoardFull()) break;
                
                pcMove();
                displayBoard();
                if(checkWinner() == 'X' || checkWinner() == 'O') break;
                if(isBoardFull()) break;
            }
            
            if(checkWinner() == 'X'){
                cout << "The player: " << player1Name << " WON congratulations!" << endl;
            } else if(checkWinner() == 'O'){
                cout << "You lost against the PC player -_-" << endl;
            } else {
                cout << "It is DRAW!" << endl;
            }
            break;
        
        case 2:
            cout << "FunctionMode2 selected" << endl;
            funcMode2();
            cout << "\nTo select the correct place: \n" << "Column:   1     2     3\nRow:   ┌─────┬─────┬─────┐\n     1 │ 1 1 │ 1 2 │ 1 3 │\n       ├─────┼─────┼─────┤\n     2 │ 2 1 │ 2 2 │ 2 3 │\n       ├─────┼─────┼─────┤\n     3 │ 3 1 │ 3 2 │ 3 3 │\n       └─────┴─────┴─────┘\n";
            cout << "─────────────────────────────────" << endl;
            
            while(true){
                player1Move();
                displayBoard();
                if(checkWinner() == 'X' || checkWinner() == 'O') break;
                if(isBoardFull()) break;
                
                player2Move();
                displayBoard();
                if(checkWinner() == 'X' || checkWinner() == 'O') break;
                if(isBoardFull()) break;
            }
            
            if(checkWinner() == 'X'){
                cout << "The player: " << player1Name << " WON congratulations!" << endl;
            } else if(checkWinner() == 'O'){
                cout << "The player: " << player2Name << " WON congratulations!" << endl;
            } else {
                cout << "It is DRAW!" << endl;
            }
            break;
    }

    return 0;
}
