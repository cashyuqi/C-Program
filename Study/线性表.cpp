#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100
typedef int ElemType;
typedef struct{
    ElemType data[MaxSize];
    int length;
} SqList;
bool ListInsert(SqList& L,int i,ElemType e){
    if (i < 1 || i>L.length+1)
        return false;
    if(L.length>=MaxSize)
        return false;
    for (int j = L.length; j >= 1;j--)
        L.data[j]=L.data[j-1];
    L.data[i-1] = e;
    L.length++;
    return true;
}
bool ListDelete(SqList& L,int i,ElemType & e){
    if(i<1||i>L.length)
        return false;
    e = L.data[i-1];
    for (int j = i; j < L.length;j++)
        L.data[j-1]=L.data[j];
    L.length--;
    return true;
}

void PrintList(SqList& L){
    for (int i = 0; i < L.length;i++){
        printf("%3d", L.data[i]);
    }
    printf("\n");
}

int main(){
    SqList L;
    bool ret_1;
    bool ret_2;
    ElemType del;
    int add_p;
    int del_p;
    scanf("%d", &add_p);
    L.data[0] = 1;
    L.data[1] = 2;
    L.data[2] = 3;
    L.length = 3;
    ret_1 = ListInsert(L, 2, add_p);
    if(ret_1){
        PrintList(L);
    }
    else{
        printf("false\n");
    }
    scanf("%d", &del_p);
    ret_2 = ListDelete(L, del_p, del);
    if(ret_2){
        PrintList(L);
    }
    else{
        printf("false");
    }
    return 0;
}