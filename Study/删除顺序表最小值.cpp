#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void delMin(int *arr,int len){
    if(!len){
        printf("lt's empty!");
        return;
    }
    int min = *arr, minPos = 0;
    for (int i = 0; i < len;i++){
        if(min>*(arr+i)){
            min = *(arr + i);
            minPos = i;
        }
    }
    *(arr + minPos) = *(arr + len - 1);
    *(arr + len - 1) = NULL;
}

int main(){
    int n;
    printf("please input length:n=");
    scanf("%d", &n);
    int *arr = (int *)malloc(sizeof(n));
    printf("please input value:");
    for (int i=0;i<n;i++){
        scanf("%d",arr+i);
    }
    for (int i=0;i<n;i++){
        printf("%d ", *(arr + i));
    }
            printf("\n");
    delMin(arr, n);
    for (int i=0;i<n-1;i++){
        printf("%d ", *(arr + i));
    }
        return 0;
}