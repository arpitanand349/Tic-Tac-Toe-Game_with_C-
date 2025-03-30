#include<iostream>

using namespace std;

// Board created
char board[3][3]={
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
};
// player created
int currentPlayer = 1;

//display board
void displayBoard(){
    cout << endl << "The Tic Tac Toe Board is : " << endl;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// check winnner
bool checkWinner(){
    for(int i=0; i<3; i++){
        // row and col
        if( (board[i][0]==board[i][1] && board[i][1]==board[i][2]) || (board[0][i]==board[1][i] && board[1][i]==board[2][i])){
            return true;
        }
        // diagonal
        if( (board[0][0]==board[1][1] && board[1][1]==board[2][2]) || (board[0][2]==board[1][1] && board[1][1]==board[2][0])){
            return true;
        }
    }
    return false;
}

//if no winner then check draw or not
bool checkDraw(){
     for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(board[i][j] != 'X' && board[i][j] !='O'){
                return false;
            }
        }
    }
    return true;
}

//switching player
void switchPlayer(){
    currentPlayer = (currentPlayer==1)?2:1;
}

//updating board
void updateBoard(int choice){
    char mark = (currentPlayer==1)?'X':'O';
    int row = (choice-1)/3;
    int col = (choice-1)%3;
    
    if(board[row][col]!='X' && board[row][col]!='O'){
        board[row][col]=mark;
    }
    else{
        cout << "The Cell is Already Marked, Choose Another Cell " << endl;
        return;
    }

}

int main(){
    int choice;
    displayBoard();

    while(true){
        cout << endl << "For Player 1 => X is sign, For Player 2 => O is sign"<<endl<< "Player " << currentPlayer << ", Enter the Cell of your Choice from [1-9]9 : " ;
        cin >> choice;

        if(choice<1 || choice > 9){
            cout << "Invalid Cell Choosed! Choose Another Cell." << endl;
            continue;
        }

        updateBoard(choice);
        displayBoard();

        if(checkWinner()){
            cout << "Player "<< currentPlayer << ", Congo you have won the game!"<< endl;
            break;
        }
        else if(checkDraw()){
            cout  << "Oh! there is a draw!"<< endl;
            break;
        }
        switchPlayer();
    }
    return 0;
}


