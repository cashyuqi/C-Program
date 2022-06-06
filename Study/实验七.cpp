#include<iostream>
#include<malloc.h>
using namespace std;
 
int numData[10];
 
int Shunxu_Search(int numData[],int searchElem) {
	for (int i = 0; i < 10; i++)
	{
		if (numData[i] == searchElem)
			return i;
	}
	return -1;
}
 
int Zheban_Search(int numData[], int n) {
	int small = 0;
	int large = 9;
	int middle;
	if (n > numData[large] || n < numData[0])
		return -1;
	while (small <= large)
	{
		middle = (small + large) / 2;
		if (n == numData[middle])
			return middle;
		else if (n > numData[middle])
			small = middle + 1;
		else
			large = middle - 1;
	}
	return -1;
 
}
 
int main() {
	int n,i;
	cout << "折半查找"<<endl;
	cout << "输入数组:";
	for(i=0;i<10;i++){
		cin>>numData[i];
	}
	cout << "输入你想查找的数: ";
	cin >> n;
	int k;
	k = Zheban_Search(numData, n);
	if (k == -1)
		cout << "找不到 " << endl;
	else
		{
			cout << "所在数组下标位置为:a[" << k ;
			cout << "]" <<endl<<endl;
		}
		
	cout << "顺序查找"<<endl;
	cout << "输入你想查找的数: ";
	cin >> n;
	k = Shunxu_Search(numData, n);
	if (k == -1)
		cout << "找不到 " << endl;
	else
		{
			cout << "所在数组下标位置为:a[" << k ;
			cout << "]" <<endl;
		}
	return 0;
}
