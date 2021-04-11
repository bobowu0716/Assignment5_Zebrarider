/* CSCI1520
*
* Assignment:5
* Student ID:1155142172
* Name:Wu Xi Bao
* Email:1155142172@link.cuhk.edu.hk
*/
#include <iostream>
using namespace std;

const int SIZE=8;

//To print out the board.
void print_Board(char board[SIZE][SIZE]){
  int i,j;
  char C;
  cout<<"  ";
  for(i=0;i<SIZE;i++){
    C=65+i;
    cout<<C<<" ";
  }
  cout<<endl;
  for(i=0;i<SIZE;i++){
    cout<<i+1<<" ";
    for(j=0;j<SIZE;j++){
      cout<<board[i][j]<<" ";
    }
    cout<<endl;
  }
};

void Renew_board(char board[SIZE][SIZE],char col,int row){
  int new_col=col-65;
  board[row][new_col]='Z';
  print_Board(board);
};

int main() {
  char board[SIZE][SIZE];
  int i,j;
  for(i=0;i<SIZE;i++){
    for(j=0;j<SIZE;j++){
      board[i][j] = '.';
    }
  }
  char col;
  int row;
  print_Board(board);
  cout<<"Put a zebrarider (col row): ";
  cin>>col>>row;
  Renew_board(board,col,row);
  
};