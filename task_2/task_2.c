//A teacher has 6 students and 4 subjects. Read the marks into marks[6][4]. Print each student’total and average, each subject’s class average, and the name of the subject (by number) whereclass performed best.
#include <stdio.h>
int main(){
    int marks[6][4];
    for(int i=0;i<6;i++){
        for(int j=0;j<4;j++){
            printf("Enter Marks For Student %d of Subject %d  :",i+1,j+1);
            scanf("%d",&marks[i][j]);
        }
    }
    int student_total[6];
    float Subj_Avg[4],Student_Avg[6];
    for(int i=0;i<6;i++){
        student_total[i]=0;
        for(int j=0; j<4;j++){
            student_total[i]+=marks[i][j];

        }
        Student_Avg[i]=student_total[i]/4;}
        for(int j=0;j<4;j++){
            int total=0;
            for(int i=0;i<6;i++){
                total+=marks[i][j];

            }
            Subj_Avg[j]=total/6;
        }
        float highest=-1;
        int class;
        for (int i=0;i<4;i++){
            if (Subj_Avg[i]>highest){
                highest=Subj_Avg[i];
                class=i+1;
            }
        }
    printf("Student | Total | Average\n");
    for (int i=0;i<6;i++){
        printf("%d       | %d    |%.2f\n",i+1,student_total[i],Student_Avg[i]);
    }
    printf("Class | Average \n");
    for (int i=0;i<4;i++){
        printf("%d     | %.2f\n",i+1,Subj_Avg[i]);
    }
    printf("Best Class : %d\nAvergae : %.2f",class,highest);
}