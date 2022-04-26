#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int findX(int *arr,int len,int x){
    int low = 0, high = len - 1, mid;
    while(low<=high&&(mid=(low+high)/2)){
        if(x==*(arr+mid))
            break;
        if(x<*(arr+mid)){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    if(low>high){
        int i;
        for (i = len - 1; i > high;i--)
            *(arr + i + 1) = *(arr + i);
        *(arr + i + 1) = x;
        return len + 1;
    }
    else{
        int tmp = *(arr + mid);
        *(arr + mid) = *(arr + mid + 1);
        *(arr + mid + 1) = tmp;
        return len;
    }
}

int main(){
    int arr[10] = {1, 3, 5, 6, 9, 12, 45, 78};
    int x, len;
    printf("input find element:x=");
    scanf("%d", &x);
    len = findX(arr, 8, x);
    for (int i = 0; i < len;i++)
        printf("%d ", *(arr + i));
    return 0;
}