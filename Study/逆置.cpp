#include <stdio.h>
#include <stdlib.h>

void reverse(int *arr,int len){
    int tmp;
    for (int i = 0; i<len/2; i++) {
        tmp = *(arr+i);
        *(arr + i) = *(arr + len - i - 1);
        *(arr + len - i - 1)=tmp;
    }
}
int main(){
    int n;//手动输入数组的元素个数
    printf("请输入数组长度:n=");
    scanf("%d",&n);
    int *arr = (int *)malloc(sizeof(n));//动态分配数组
    printf("请输入数组的元素值:");
    for (int i = 0; i<n; i++) {
        scanf("%d",arr+i);
    }
    for (int i = 0; i<n; i++) {
        printf("%d",*(arr+i));
    }
    reverse(arr, n);
    for (int i = 0; i<n; i++) {
        printf("%d",*(arr+i));
    }
    return 0;
}