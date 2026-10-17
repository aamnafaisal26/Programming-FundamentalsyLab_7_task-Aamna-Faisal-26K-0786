//A university has 3 departments, 4 students per department, and 5 subjects each, stored in marks[3][4][5]. Print every student's average, the topper of each department, and the department with the highest overall average. Mark any student with a subject below 40 as "FAIL".
#include <stdio.h>
int main(){
    int marks[3][4][5];
    float topper[3][2];
    float avg[3][4];
    float dep_avg[3];
    int highest=-1,best_dep;
    for(int i=0;i<3;i++){
        printf("----Department %d----\n",i+1);
        for(int j=0;j<4;j++){
            printf("Student %d :\n",j+1);
            for(int k=0;k<5;k++){
                printf("Enter Marks %d :",k+1);
                scanf("%d",&marks[i][j][k]);
            }
        }
    }
    int total;
    for (int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            total=0;
            for(int k=0;k<5;k++){
                total+=marks[i][j][k];
            }
            avg[i][j]=total/5;
        }
    }
    int top;
    for(int i=0;i<3;i++){
        top=-1;
        for (int j=0;j<4;j++){
            if(avg[i][j]>top){
                topper[i][0]=j+1;
                topper[i][1]=avg[i][j];
            }
        }
    }
    for(int i=0;i<3;i++){
        dep_avg[i]=0;
        for(int j=0;j<4;j++){
            dep_avg[i]+=avg[i][j];
        }
        dep_avg[i]=dep_avg[i]/4;
        if(dep_avg[i]>highest){
            highest=dep_avg[i];
            best_dep=i+1;
        }
    }
    for(int i=0;i<3;i++){
        printf("----Department %d----\n",i+1);
        for(int j=0;j<4;j++){
            int fail=0;
            for(int k=0;k<5;k++){
                if(marks[i][j][k]<40){
                    fail=1;
                }
            }
            printf("Student %d Average : %.2f",j+1,avg[i][j]);
            if(fail==1){
                printf("  FAIL");
            }
            printf("\n");
        }
        printf("Topper : Student %.0f (Average %.2f)\n",topper[i][0],topper[i][1]);
        printf("Department Average : %.2f\n",dep_avg[i]);
    }
    printf("----Best Department----\n");
    printf("Department : %d\nAverage : %.2f\n",best_dep,highest);
    return 0;
}
