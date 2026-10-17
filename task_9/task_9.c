//A library shelf holds 5 books. Read each title (with spaces) using the scanset scanf(" %[^\n]", titles[i]) into char titles[5][50], and read its number of copies into an int. Then: 1. Print the catalog as a neat table. 2. Count the vowels in each title using nested loops. 3. Let the user enter a single letter, then show which titles start with that letter. 4. Print the title with the most copies.
#include <stdio.h>
#include <ctype.h>
int main(){
    char titles[5][50];
    int copies[5];
    for (int i=0;i<5;i++){
        printf("Enter Title of Book %d: ",i+1);
        scanf(" %[^\n]",titles[i]);
        printf("Number Of Copies : ");
        scanf("%d",&copies[i]);
        
    }
    printf("--------------------Catalogue--------------------\n");
    printf("%-3s | %-35s | %6s\n","No","Book Title","Copies");
    printf("-------------------------------------------------\n");
    for (int i=0;i<5;i++){
        printf("%-3d | %-35s | %6d\n",i+1,titles[i],copies[i]);
    }
    printf("-------------------------------------------------\n");

    printf("--------Vowel Count--------\n");
    for (int i=0;i<5;i++){
        int vowels=0;
        for (int j=0;titles[i][j]!='\0';j++){
            char c=tolower(titles[i][j]);
            if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
                vowels++;
            }
        }
        printf("%s : %d vowels\n",titles[i],vowels);
    }

    char letter;
    int found=0;
    printf("Enter A Letter : ");
    scanf(" %c",&letter);
    printf("--------Titles Starting With %c--------\n",toupper(letter));
    for (int i=0;i<5;i++){
        if (tolower(titles[i][0])==tolower(letter)){
            printf("%s\n",titles[i]);
            found++;
        }
    }
    if (found==0){
        printf("None\n");
    }

    int most=0;
    for (int i=1;i<5;i++){
        if (copies[i]>copies[most]){
            most=i;
        }
    }
    printf("--------Most Copies--------\n");
    printf("%s (%d copies)\n",titles[most],copies[most]);
    return 0;
}
