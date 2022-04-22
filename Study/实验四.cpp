#include <iostream>
#include <string>
using namespace std;
class SeqStack
{
	public:
		SeqStack()
		{
			top=-1;
		}
		~SeqStack(){}
		void Push(int x)
		{
			if(top==99) throw "上溢";
			data[++top]=x;

		}
		int Pop()
		{
			int x;
			if(top==-1) throw "下溢";
			x=data[top--];
			return x;
		}
		int GetTop()
		{
			if(top==-1) throw "下溢";
			return data[top];
		}
		int Empty()
		{
			return top==-1?1:0;
		}
	private:
		int data[100];
		int top;
};
int range(char c)//将算术运算符字符转换为对应数组下标
{
	switch(c)
	{
		case '+': return 0;
		case '-': return 1;
		case '*': return 2;
		case '/': return 3;
		case '(': return 4;
		case ')': return 5;
		case '#': return 6;
	} 
	return 7;
}
int compare(char a,char b)
{
	int i,j,arr[7][7]={{1,1,-1,-1,-1,1,1},
					   {1,1,-1,-1,-1,1,1},
					   {1,1,1,1,-1,1,1},
					   {1,1,1,1,-1,1,1},
					   {-1,-1,-1,-1,-1,0,2},
					   {2,2,2,2,2,2,2},
					   {-1,-1,-1,-1,-1,2,0}};//存储表达式优先级比较结果表
	i=range(a);
	j=range(b);
	if(i!=7&&j!=7)
		return arr[i][j];	//返回比较结果
	else//如果i和j为7，则所比较字符不是算术运算符，抛出异常
		throw "比较出错！";
	
}
int cal2(int a,int b,char oper)//表达式计算，返回计算结果
{
	switch(oper)
	{
		case '+': return a+b;
		case '-': return a-b;
		case '*': return a*b;
		case '/': return a/b;
	}
	throw "非法参数";
}
string convert(string str1)
{
	SeqStack stack;//存储运算符的栈
	string str2;//存储转换后的后缀表达式字符串
	int i=0;
	char c;
	stack.Push('#');//标志表达式起始，将#压入栈
	while(!stack.Empty())//直到栈为空，算法结束
	{
		
		if(str1[i]>='0'&&str1[i]<='9')
			str2+=str1[i++];//当字符是数字时，将字符增加到str2中
		else if(compare(stack.GetTop(),str1[i])==-1)	
				stack.Push(str1[i++]);//当前运算符优先级比栈顶运算符高，当前运算符进栈，继续处理下一个字符
		else if(compare(stack.GetTop(),str1[i])==1)
		{
			c=stack.Pop();//当前运算符优先级比栈顶运算符低，将栈顶字符串出栈，增加到str2中
			str2+=c;
		}
		else if(compare(stack.GetTop(),str1[i])==0)
		{
			stack.Pop();//当前运算符优先级和栈顶相同时，即分别为）和（或#和#，栈顶元素出栈，继续处理下一个字符
			i++;
		}
		else
			throw "非法表达式！";//以上结果都不是即表达式输入有误
		
	}
	return str2;
}
int cal1(string str)
{
	SeqStack stack;//存储数字的栈
	int i,a,b,r;
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]>='0'&&str[i]<='9')//当前字符是数字时，入栈
			stack.Push(str[i]-48);
		else//当前字符是运算符时，将两个运算对象分别出栈，与当前运算符进行运算，将运算结果再入栈
		{
			a=stack.Pop();
			b=stack.Pop();
			r=cal2(b,a,str[i]);
			stack.Push(r);
			cout<<b<<str[i]<<a<<"="<<r<<endl;
		}
	}
	return stack.GetTop();
}
int main()
{
	try
	{
		string str;
		int result;
		cin>>str;
		str+='#';//增加一个表达式结束标志符
		str=convert(str);//转换为后缀表达式
		cout<<endl<<"转换后的后缀表达式："<<str<<endl<<endl;
		cout<<"计算步骤："<<endl;
		result=cal1(str);//输出最终计算结果
		cout<<endl<<"计算结果："<<result<<endl;
	}
	catch(const char *s)
	{
		cout<<s<<endl;//抛出异常
	}
	return 0;
	
}
