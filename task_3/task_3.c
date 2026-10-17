//A weather station records the temperature at 4 times of day (morning, noon, evening, night) for 7days in temp[7][4]. Find the hottest and coldest readings with their day and time slot, and list the days where the noon temperature was above the weekly noon average.
#include <stdio.h>
int main(){
    int temp[7][4];
    char *time[4]={"Morning","Noon","Evening","Night"};
    int hottest=-100,coldest=1000;
    int hottest_day,coldest_day;
    char *hottest_time,*coldest_time;
    float weekly_avg_noon;
    int count=0;
    int total=0;
    
    for(int i=0;i<7;i++){
        for (int j=0;j<4;j++){
            printf("Enter Temperature Of Day %d At %s ",i+1,time[j]);
            scanf("%d",&temp[i][j]);
            
        }
    }
    for(int i=0;i<7;i++){
        for (int j=0;j<4;j++){
            if (temp[i][j] > hottest){
                  hottest=temp[i][j];
                  hottest_day=i+1;
                  hottest_time=time[j];
            }
            if (temp[i][j] < coldest){
                  coldest=temp[i][j];
                  coldest_day=i+1;
                  coldest_time=time[j];
            }
            if (j==1){
                total+=temp[i][j];
            }

            
        }
    }
    weekly_avg_noon=total/7.0;
    int days_above_noon_avg[7];
    for(int i=0;i<7;i++){
        if(temp[i][1]>weekly_avg_noon){
            days_above_noon_avg[count]=i+1;
            count++;
        }
    }
    printf("----Hottest---- \nTemperature : %d \nDay : %d \nTime : %s \n",hottest,hottest_day,hottest_time);
    printf("----Coldest----\nTemperature : %d \nDay : %d\nTime : %s \n",coldest,coldest_day,coldest_time);
    printf("---- Days Above Weekly Noon Average----\n");
    for (int i=0;i<count;i++){
        printf("------------------\n");
        printf("Day : %d \nTemperature : %d\n",days_above_noon_avg[i],temp[days_above_noon_avg[i]-1][1]);

    }
    printf("Weekly Noon Average : %.2f\n",weekly_avg_noon);

    return 0;
}
