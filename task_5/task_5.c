//A hotel has 4 floors with 6 rooms each, stored in rooms[4][6]. Read 1 for occupied and 0 for vacant. Find the floor with the most vacancies. Then check whether any floor has 3 or more consecutive vacant rooms, and print the floor and the starting room number.
#include <stdio.h>
int main(){
    int rooms[4][6];
    for(int i=0;i<4;i++){
        for(int j=0;j<6;j++){
            printf("Room %d On Floor %d (1 = Occupied, 0 = Vacant) : ",j+1,i+1);
            scanf("%d",&rooms[i][j]);
        }
    }
    int most_vacant_floor;
    int highest=-1;
    for(int i=0;i<4;i++){
        int vacancy=0;
        for(int j=0;j<6;j++){
            if(rooms[i][j]==0){
                vacancy++;
            }
        }
        if (vacancy > highest){
            most_vacant_floor=i+1;
            highest=vacancy;
        }
    }
    int three_cons_floor[4],starting_room[4];
    int count=0;
    for(int i=0;i<4;i++){
        int streak=0;
        for(int j=0;j<6;j++){
            if(rooms[i][j]==0){
                streak++;
            }
            else{
                streak=0;
            }
            if(streak==3){
                three_cons_floor[count]=i+1;
                starting_room[count]=j-1;
                count++;
            }
        }
    }
    printf("-----Most Vacant Floor-----\n");
    printf("Floor : %d\n",most_vacant_floor);
    printf("Vacant Rooms : %d\n",highest);
    printf("-----Floors With 3 Or More Consecutive Vacant Rooms-----\n");
    if(count==0){
        printf("None\n");
    }
    for(int i=0;i<count;i++){
        printf("-----------\n");
        printf("Floor: %d\n",three_cons_floor[i]);
        printf("Starting Room : %d\n",starting_room[i]);
    }
    return 0;
}
