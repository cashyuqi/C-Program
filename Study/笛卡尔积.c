#include <stdio.h>

int main()
{
	int N,M,i,j,t=0;
	char A[]={'a','r','g'};
	char B[]={'2','5','9'};
	N=sizeof(A)/sizeof(A[0]);//求集合A中的元素个数
	M=sizeof(B)/sizeof(B[0]);//求集合B中的元素个数
	char C[N*M][2];//用一个二维数组来存储笛卡儿积 每一行代表一个笛卡儿积（有顺序）
	printf("A*B的结果为：\n"); 
	printf("C={ ");//集合C是一个集合，所以要有大括号，满足集合的输出格式
	
	
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			C[t][0]=A[i];
			C[t][1]=B[j];	
			printf("(%c,%c) ",C[t][0],C[t][1]);
			t++;
		}
	}

	
	printf("}");
	printf("\n");
	return 0;
}