#include <stdio.h>
void insert(int arr[],int *n)
{
	int j,x,i;
	printf("input number and position:");
	scanf("%d,%d",&x,&i);
	for(j=*n-1;j>=i-1;j--)
		arr[j+1]=arr[j];
		
	arr[j+1]=x;
	(*n)++;
	
}
void delete(int arr[],int *n)
{
	int j,i;
	printf("delete position:");
	scanf("%d",&j);
	for(i=j-1;i<*n-1;i++)
		arr[i]=arr[i+1];
	(*n)--;
	
}
void print(int arr[],int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
}
int main()
{
	int a[30]={1,2,3,4,5},n=5;
	print(a,n);
	insert(a,&n);
	print(a,n);
	delete(a,&n);
	print(a,n);
	return 0;
}