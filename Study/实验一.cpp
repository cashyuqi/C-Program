#include <iostream>
using namespace std;
class SeqList
{
	public:
		SeqList(int a[],int n)
		{
			if(n>100) throw "Error：参数非法";
			for(int i=0;i<n;i++)
				data[i]=a[i];
			length=n;
		}
		void Insert(int i,int x)
		{
			if(i<1||i>length+1) throw "Error：插入位置非法";
			for(int j=length;j>=i;j--)
				data[j]=data[j-1];
			data[i-1]=x;
			length++;
		}
		void Delete(int i)
		{
			if(length==0) throw "Error:顺序表长度已为0";
			if(i<1||i>length) throw "Error：删除位置非法";
			for(int j=i;j<length;j++)
				data[j-1]=data[j];
			length--;
		}
		void PrintList()
		{
			for(int i=0;i<length;i++)
				cout<<data[i]<<" ";
			cout<<"\n";
		}
	private:
		int data[100];
		int length;
}; 
int main()
{
	try
	{
		int arr[5]={1,3,5,7,9};
		SeqList s(arr,5);
		s.PrintList();
		cout<<"input number and position:";
		int i,x;
		cin>>x>>i;
		s.Insert(i,x);
		s.PrintList();
		cout<<"delete position:";
		cin>>i;
		s.Delete(i);
		s.PrintList();
	}
	catch(const char *s)
	{
		cout<<s<<"\n";
	}
	
	return 0;
}