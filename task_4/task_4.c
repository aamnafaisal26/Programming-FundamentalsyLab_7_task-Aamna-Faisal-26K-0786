//A shop sells 5 products across 3 branches. Read monthly sales into sales[3][5]. Print the total sales per branch, total sales per product, the best-selling branch, and the product with the lowest sales overall.
#include <stdio.h>
int main(){
    int sales[3][5];
    int branch_sales[3],product_sales[5];
    int best_branch,lowest_product;
    int most_branch_sales=-1,least_product_sales=100000;    
    for(int i=0;i<3;i++){
        for(int j=0;j<5;j++){
            printf("Enter Sales Of Product %d In Branch %d : ",j+1,i+1);
            scanf("%d",&sales[i][j]);
        }
    }
    for(int i=0;i<3;i++){
        branch_sales[i]=0;
        for(int j=0;j<5;j++){
            branch_sales[i]+=sales[i][j];
        }
        
    }
    for (int i=0;i<5;i++){
        product_sales[i]=0;
        for(int j=0;j<3;j++){
            product_sales[i]+=sales[j][i];
        }
        
    }
    for(int i = 0;i<3;i++){
        if(branch_sales[i]>most_branch_sales){
            best_branch=i+1;
            most_branch_sales=branch_sales[i];
        }
    }
    for(int i=0;i<5;i++){
        if(product_sales[i]<least_product_sales){
            least_product_sales=product_sales[i];
            lowest_product=i+1;
        }
    }
    printf("----Sales Per Branch----\n");
    for(int i=0;i<3;i++){
        printf("-----------\n");
        printf("Branch %d : %d\n",i+1,branch_sales[i]);
    }
    printf("----Sales Per Product----\n");
    for(int i=0;i<5;i++){
        printf("-----------\n");
        printf("Product %d : %d\n",i+1,product_sales[i]);
    }
    printf("----Best Branch----\n");
    printf("Branch : %d \nSales : %d\n",best_branch,most_branch_sales);
    printf("----Worst Product----\n");
    printf("Product : %d \nSales : %d",lowest_product,least_product_sales);
    return 0;
}
