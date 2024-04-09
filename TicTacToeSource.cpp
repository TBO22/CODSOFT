#include <iostream>
using namespace std;

//Global Variables declared here
char board[3][3] = { {' ',' ',' ' }, {' ', ' ', ' '}, {' ', ' ', ' '} }; //A board 3 by 3 matrix
char move1 = 'X'; //Player 1 is Assigned X
char move2 = 'O'; //Player 2 is Assignend O
char choice;
bool turnflag = false; //Flag variable to keep track of which players turn it is
int row, column; //to take input values from user for move positions

void drawboard() {
    //Displaying Board Function
	cout << "\t" << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
	cout << "\t" << "_________" << endl;
	cout << "\t" << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
	cout << "\t" << "_________" << endl;
	cout << "\t" << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
	cout << endl;
}
bool IsWin() {
	// Check for Player 1 wins
	for (int i = 0; i <=2; i++) {
        if (board[i][0] == move1 && board[i][1] == move1 && board[i][2] == move1) {
            return true;
        }
        if (board[0][i] == move1 && board[1][i] == move1 && board[2][i] == move1) {
            return true;
        }
	}
    if (board[0][0] == move1 && board[1][1] == move1 && board[2][2] == move1) {
        return true; //diagnol check
    }
    if (board[0][2] == move1 && board[1][1] == move1 && board[2][0] == move1) {
        return true; // reverse diagnol check
    }

	// Check for Player 2 wins
	for (int i = 0; i <=2; i++) {
        if (board[i][0] == move2 && board[i][1] == move2 && board[i][2] == move2) {
            return true;
        }
        if (board[0][i] == move2 && board[1][i] == move2 && board[2][i] == move2) {
            return true;
        }
	}
    if (board[0][0] == move2 && board[1][1] == move2 && board[2][2] == move2) {
        return true; //diagnol check
    }
    if (board[0][2] == move2 && board[1][1] == move2 && board[2][0] == move2) {
        return true; //reverse diagnol check
    }

		return false;
}
int main() {
    cout << "----------------Welcome to Tic Tac Toe--------------" << endl;
    drawboard();
    char choice;
    cout << "Player 1 plays first (Y OR N) : ";
    cin >> choice;
    if (choice == 'Y') {
        turnflag = true;
    }
    else {
        turnflag = false;
    }
    int cellCounter = 0;  // To count the number of filled cells

    while (IsWin() != true && cellCounter < 9) {  // Check for tie when no winner and not all cells filled
        if (turnflag == true) {
            cout << "Player 1, Enter Row and Column : ";
            cin >> row >> column;
            if (board[row][column] == ' ') {
                board[row][column] = move1;
                drawboard();
                cellCounter++;
                if (IsWin()) {
                    cout << "Player 1 'X' Wins!!!" << endl;
                    break;
                }
                turnflag = false;
            }
            else {
                cout << "Board Cell is already taken! Try again." << endl;
            }
        }
        else {
            cout << "Player 2, Enter Row and Column : ";
            cin >> row >> column;
            if (board[row][column] == ' ') {
                board[row][column] = move2;
                drawboard();
                cellCounter++;
                if (IsWin()) {
                    cout << "Player 2 'O' Wins!!!" << endl;
                    break;
                }
                turnflag = true;
            }
            else {
                cout << "Board Cell is already taken! Try again." << endl;
            }
        }
    }
    // Check for tie condition
    if (!IsWin() && cellCounter == 9) {
        cout << "It's a tie!" << endl;
    }
    return 0;
}
