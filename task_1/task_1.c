//A cinema hall has 5 rows and 8 seats per row. Seats are stored in seats[5][8] (0 = empty, 1 =booked). Read the booking status of every seat, then print the seating map using . for empty andX for booked. Also report how many seats are free in each row and in total.
#include <stdio.h>
int main(){
    int seats[5][8];
    for (int i=0;i<5;i++){
         for (int j=0;j<8;j++){
            printf("Is Seat %d in Row %d Occupied?\n0.Yes\n1.No\nChoice(0-1)",j+1,i+1);
            scanf("%d",&seats[i][j]);
         }        
    }
    for (int i =0;i<5;i++){
        int free=0;
        for(int j=0;j<8;j++){
            if (seats[i][j]==0){
                printf(" . ");
                free++;
            }
            else{
                printf(" x ");
            }
        }
        printf("free seats in row %d is %d\n",i+1,free);
        
    }
return 0;


}