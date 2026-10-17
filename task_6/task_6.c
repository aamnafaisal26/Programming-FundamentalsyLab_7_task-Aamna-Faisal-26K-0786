//Read a finished 3x3 board using scanf(" %c", &board[i][j]) (characters X, O, or -). Check all rows, columns, and both diagonals, then print the winner or declare a draw.
#include <stdio.h>
#include <ctype.h>
int main(){
    char board[3][3];
    for (int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("Row %d Collumn %d?",i+1,j+1);
            scanf(" %c",&board[i][j]);
            board[i][j]=toupper(board[i][j]);
        }
    }
    if((board[0][0]==board[1][1] && board[0][0] == board[2][2])&& board[0][0] != '-'){
        printf("The Winner is %c",board[0][0]);
        return 0;
     }
     else if ((board[0][2]==board[1][1] && board[0][2]==board[2][0])&&board[2][0] != '-'){
        printf("The Winner is %c",board[0][2]);
        return 0;
     }
     else{
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if((board[i][0]==board[i][1] && board[i][0]== board[i][2]) && board[i][0] !='-' ){
                    printf("Winner is %c",board[i][0]);
                    return 0;
                }
                else if ((board[0][j]==board[1][j] && board[0][j]==board[2][j])&&board[0][j]!='-'){
                    printf("Winner is %c",board[0][j]);
                    return 0;
                }
            }
        }
     }
    printf("Its a Draw");
    return 0;
}
