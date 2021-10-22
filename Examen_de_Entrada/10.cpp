#include <stdio.h>

void merge(int* pArrayA, int* pArrayB,int m, int n){
    int index=m+n-1;
    int i=m-1;
    int j=n-1;
    while (i>=0 && j>=0){
        pArrayA[index--]=pArrayA[i]>pArrayB[j]?pArrayA[i--]:pArrayB[j--];
    }
    while(j>=0){
        pArrayA[index--]=pArrayB[j--];
    }
}
int main(){
    int arrayA[20]={1,3,5,7,9};
    int arrayB[7]={2,4,6,8,10,12,14};
    merge(arrayA,arrayB,5,7);

    for(int i=0;i<20;++i){
        printf("%d",arrayA[i]);
    }
    printf("\n");
}