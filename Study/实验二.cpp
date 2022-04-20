	#include <iostream>
	using namespace std;
	class SeqList
	{
		friend SeqList Add(SeqList A,SeqList B);
		public:
			SeqList (){length=0;}
			SeqList(int a[],int n)
			{
				for(int i=n-1,j=0;i>=0;i--,j++)
					data[i]=a[j];
				length=n;
			}
			void PrintList()
			{
				for(int i=length-1;i>=0;i--)
					cout<<data[i];
				cout<<"\n";
			}
		private:
			int data[100];
			int length;
	}; 
	int input(int a[])
	{
		int n;
		for(n=0;cin.peek()!='\n';n++) 
				a[n]=cin.get()-48;
		cin.clear();
		cin.sync();
		return n;
	}
	SeqList Add(SeqList A,SeqList B)
	{
		SeqList C;
		int flag=0,i=0,n=A.length,m=B.length;
		while(i<n&&i<m)
		{
			C.data[i]=(A.data[i]+B.data[i]+flag)%10;
			flag=(A.data[i]+B.data[i]+flag)/10;
			i++;
		}
		for(;i<n;i++)
		{
			C.data[i]=(A.data[i]+flag)%10;
			flag=(A.data[i]+flag)/10;
		}
		for(;i<m;i++)
		{
			C.data[i]=(B.data[i]+flag)%10;
			flag=(B.data[i]+flag)/10;
		}
		C.length=max(m,n)+flag;
		if(flag==1) C.data[C.length-1]=1;
		return C;
	}
	int main()
	{
		int a[100],b[100],n1,n2;
		cout<<"请输入A：";
		n1=input(a);
		cout<<"请输入B：";
		n2=input(b);
		SeqList A(a,n1);
		SeqList B(b,n2);
		cout<<"\nA=";
		A.PrintList();
		cout<<"\nB=";
		B.PrintList();
		SeqList C=Add(A,B);
		cout<<"\nC=";
		C.PrintList();
		return 0;
	}
