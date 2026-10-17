//A warehouse has 3 buildings, 4 shelves per building, and 5 slots per shelf, stored in stock[3][4][5]. Each element is the number of items in that slot. Print the total stock per building, find the single fullest shelf and report its building and shelf number, and list every slot with fewer than 5 items as "needs restock" along with its [building][shelf][slot] position.
#include <stdio.h>
int main(){
    int stock[3][4][5];
    int stock_per_building[3],stock_per_shelf[3][4];
    int total_stock,total_shelf;

    for(int i=0;i<3;i++){
        printf("----------\n---Building %d---\n",i+1);
        total_stock=0;
        for(int j=0;j<4;j++){
            total_shelf=0;
            for(int k=0;k<5;k++){
                printf("Shelf : %d\nSlot : %d\nHow Many Items? : ",j+1,k+1);
                scanf("%d",&stock[i][j][k]);
                total_shelf+=stock[i][j][k];
                total_stock+=stock[i][j][k];
             
            }
            stock_per_shelf[i][j]=total_shelf;
        }
        stock_per_building[i]=total_stock;
    }
    int highest=-1,highest_building,highest_shelf;

    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            if(stock_per_shelf[i][j]>highest){
                highest=stock_per_shelf[i][j];
                highest_building=i+1;
                highest_shelf=j+1;
            }
        }
    }

    
    printf("-------Stocks Per Building-------\n");
    for (int i =0;i<3;i++){
        printf("Building %d : %d\n",i+1,stock_per_building[i]);
    }
    printf("---------------------------------\n");
    printf("--------Fullest Shelf--------\n");
    printf("Building : %d\n",highest_building);
    printf("Shelf : %d \n",highest_shelf);
    printf("Stock : %d Elements\n",highest);
    printf("------------------------------");
    printf("--------Needs Restock--------\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            for(int k=0;k<5;k++){
                if (stock[i][j][k]<5){
                    
                    printf("Building : %d \nShelf : %d \nSlot : %d\nElements : %d \n",i+1,j+1,k+1,stock[i][j][k]);
                }
            }
        }
    }


    return 0;
}
