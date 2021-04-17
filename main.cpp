/* CSCI1520
*
* Assignment:5
* Student ID:1155142172
* Name:Wu Xi Bao
* Email:1155142172@link.cuhk.edu.hk
*/
#include <iostream>
using namespace std;
const int SIZE = 8;

//To print out the board.
void print_Board(char board[SIZE][SIZE]) {
	int i, j; 
	char C;
	//print the row that state the column number(A-Z which depends on the size of the chess).
	std::cout << "  ";
	for (i = 0; i < SIZE; i++) {
		C = 65 + i;
		cout<< C << " ";
	}
	cout << endl;
	//print the row number(1-SIZE) and the board.
	for (i = 0; i < SIZE; i++) {
		cout << i << " ";
		for (j = 0; j < SIZE; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
};

//To refresh the status of the chess board after player enter a new zebrarider to the board.
void Renew_board(char board[SIZE][SIZE], char col, int row) {
	int org_col = col - 65;
	int org_row = row ;
	int new_col = col - 65;
	//enter the new zebrarider to the board.
	board[row][new_col] = 'Z';
	//change the status of the squares which are attaked by the new zebrarider.
	while (row + 3 < SIZE&&new_col + 2 < SIZE) {
		if (board[row + 3][new_col + 2] != 'Z') {
			board[row + 3][new_col + 2] = '=';
		}
		row = row + 3;
		new_col = new_col + 2;
	}
	new_col = org_col;
	row = org_row;
	while (row + 3 < SIZE&&new_col - 2 >= 0) {
		if (board[row + 3][new_col - 2] != 'Z') {
			board[row + 3][new_col - 2] = '=';
		}
		row = row + 3;
		new_col = new_col - 2;
	}
	new_col = org_col;
	row = org_row;
	while (row - 3 >= 0 && new_col + 2 < SIZE) {
		if (board[row - 3][new_col + 2] != 'Z') {
			board[row - 3][new_col + 2] = '=';
		}
		row = row - 3;
		new_col = new_col + 2;
	}
	new_col = org_col;
	row = org_row;
	while (row - 3 >= 0 && new_col - 2 >= 0) {
		if (board[row - 3][new_col - 2] != 'Z') {
			board[row - 3][new_col - 2] = '=';
		}
		row = row - 3;
		new_col = new_col - 2;
	}
	new_col = org_col;
	row = org_row;
	while (row + 2 < SIZE&&new_col + 3 < SIZE) {
		if (board[row + 2][new_col + 3] != 'Z') {
			board[row + 2][new_col + 3] = '=';
		}
		row = row + 2;
		new_col = new_col + 3;
	}
	new_col = org_col;
	row = org_row;
	while (row + 2 < SIZE&&new_col - 3 >= 0) {
		if (board[row + 2][new_col - 3] != 'Z') {
			board[row + 2][new_col - 3] = '=';
		}
		row = row + 2;
		new_col = new_col - 3;
	}
	new_col = org_col;
	row = org_row;
	while (row - 2 >= 0 && new_col + 3 < SIZE) {
		if (board[row - 2][new_col + 3] != 'Z') {
			board[row - 2][new_col + 3] = '=';
		}
		row = row - 2;
		new_col = new_col + 3;
	}
	new_col = org_col;
	row = org_row;
	while (row - 2 >= 0 && new_col - 3 >= 0) {
		if (board[row - 2][new_col - 3] != 'Z') {
			board[row - 2][new_col - 3] = '=';
		}
		row = row - 2;
		new_col = new_col - 3;
	}
	new_col = org_col;
	row = org_row;
}

//To state out the number of zebrariders, attacked squares and free squares respectively.
void print_status(char board[SIZE][SIZE]) {
	int no_of_zebrarider = 0;
	int no_of_attackedsquares = 0;
	int no_of_freesquares = 0;
	int i, j;
	//count the number of 'Z','=' and '.' respectively.
	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			if (board[i][j] == 'Z')
				no_of_zebrarider++;
			if (board[i][j] == '=')
				no_of_attackedsquares++;
			if (board[i][j] == '.')
				no_of_freesquares++;
		}
	}
	//print out the number of 'Z','=' and '.' respectively for record.
	cout << "Zebrariders: " << no_of_zebrarider << endl;
	cout << "Attacked squares: " << no_of_attackedsquares << endl;
	cout << "Free squares: " << no_of_freesquares << endl;
}

//To count the number of free squares in the chess board.
int no_of_blank(char board[SIZE][SIZE]) {
	int blank = 0;
	int i, j;
	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			if (board[i][j] == '.')
				blank++;
		}
	}
	return blank;
}

//To check the column and row that player entered is valid for zebrarider or not.
bool isgamevalid(char board[SIZE][SIZE], char col, int row) {
	int col_no = col-65;
	if (col_no < 0 || col_no >= SIZE)
		return false;
	else if (row<0 || row>=SIZE)
		return false;
	else if (board[row][col_no] == 'Z')
		return false;
	//To check that the free squares will be reduced after entered a zebrarider.
	else {
		int blankinorg = no_of_blank(board);
		Renew_board(board, col, row);
		if (no_of_blank(board) < blankinorg)
			return true;
		else
			return false;
	}
}

//To check that is there any free square in the chess for determining that the game need to continue or not
bool nofreesquare(char board[SIZE][SIZE]){
	int emptysquare = 0;
	int i, j;
	//count the number of free squares in board.
	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			if (board[i][j] == '.')
				emptysquare++;
		}
	}
	//If there is no free square, then end the game.
	if (emptysquare == 0)
		return true;
	else
		return false;
}


int main() {
	//set up the origin board with all free squares.
	char board[SIZE][SIZE];
	int i, j;
	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			board[i][j] = '.';
		}
	}
	char col;
	int row;
	bool endgame = false;
	bool startgame = false;
	print_Board(board);
	print_status(board);
	//For the main game operation.
	while (endgame == false) {
		while (startgame == false) {
			cin.clear();
			cout << "Put a zebrarider (col row): ";
			cin >> col >> row;
			startgame = isgamevalid(board, col, row);
			//if the cin col and row is invalid for a zebrarider, ask the player to cin again.
			if (startgame == false)
				cout << "Invalid. Try again!\n";
		}
		Renew_board(board, col, row);
		print_Board(board);
		print_status(board);
		endgame = nofreesquare(board);
		startgame = false;
	}
}
