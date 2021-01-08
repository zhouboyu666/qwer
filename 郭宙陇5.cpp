#include<iostream>
#include<stack>
#include<string>
using namespace std;

int count(char z, int x, int y)
{
	switch (z)
	{
	case '+': return x + y;
	case '-': return x - y;
	case '*': return x * y;
	default: return 0;
	}
}
void main()
{
	char a[100];//定义输入
	int k[10][1];
	stack<char> s;// 括号
	stack<int> num;// 数字
	stack<char> r;// 符号
	int n = 0, m = 0, i; // n：判断括号内有几个运算符，m：判断当前在第几个括号内
	int check1 = 1;//判断是否遇到了左括号
	int check2 = 0;//判断是否遇到了右括号
	int z;
	cout << "输入算式" << endl;
	gets_s(a);//总的a数组输入方式
	int log = strlen(a);
	for (i = 0; i < log; i++)
	{
		if (a[i] == 40)
		{   //判断左括号，压入栈；
			m++;
			s.push(m);
			check1 = 1;
			k[m - 1][0] = n;
			n = 0;
			//cout<<"检测到左括号"<<endl;
		}
		else if (a[i] == 41)
		{  //判断右括号，匹配最后一个左括号，执行计算；
			s.pop();  //未完待续
			check2 = 1;
			//cout<<"检测到右括号"<<endl;
			while (n)
			{
				int bnow = num.top();  //数据出栈
				num.pop();
				int anow = num.top();
				num.pop();
				char ing = r.top();
				r.pop();
				int nowc = count(ing, anow, bnow);//当前结果
				num.push(nowc);
				n--;
			}
			//cout<<num.top()<<endl;
			m--;
			n = k[m][0];
			check2 = 0;
			check1 = 1;
		}
		else if ((a[i] >= 48 && a[i] <= 57) && (a[i - 1] >= 48 && a[i - 1] <= 57))//检测n位数，合成
		{
			switch (a[i])
			{
			case 48: z = 0; break;
			case 49: z = 1; break;
			case 50: z = 2; break;
			case 51: z = 3; break;
			case 52: z = 4; break;
			case 53: z = 5; break;
			case 54: z = 6; break;
			case 55: z = 7; break;
			case 56: z = 8; break;
			case 57: z = 9; break;
			}
			int nnum = num.top() * 10 + z;
			num.pop();
			num.push(nnum);
		}
		else if (a[i] >= 48 && a[i] <= 57)//检测到数字,入栈
		{
			switch (a[i])
			{
			case 48: z = 0; break;
			case 49: z = 1; break;
			case 50: z = 2; break;
			case 51: z = 3; break;
			case 52: z = 4; break;
			case 53: z = 5; break;
			case 54: z = 6; break;
			case 55: z = 7; break;
			case 56: z = 8; break;
			case 57: z = 9; break;
			}
			num.push(z);
			//cout<<z<<endl;
		}
		else if ((check1 == 1) && (a[i] < 48))
		{
			r.push(a[i]);
			check1 = 0;
			n++;
			//cout<<a[i]<<endl;
		}
		else if ((a[i] == '+' || a[i] == '-' || a[i] == '*') && (r.top() == '*'))
		{
			//cout<<a[i]<<endl;
			if (check1 == 0)
			{
				//cout<<"check1=0"<<endl;
				int bnow = num.top();  //数据出栈
				num.pop();
				int anow = num.top();
				num.pop();
				char ing = r.top();
				r.pop();
				int nowc = count(ing, anow, bnow);//当前结果
				num.push(nowc);
				r.push(a[i]); //新运算符进栈
				//cout<<num.top()<<endl;
			}
			else
			{
				//cout<<"check1=1"<<endl;
				r.push(a[i]);
				check1 = 0;
				n++;
			}
		}
		else if ((a[i] == '+' || a[i] == '-') && (r.top() == '+' || r.top() == '-'))
		{
			//cout<<a[i]<<endl;
			if (check1 == 0)
			{
				//cout<<"check=0"<<endl;
				int bnow = num.top();  //数据出栈
				num.pop();
				int anow = num.top();
				num.pop();
				char ing = r.top();
				r.pop();
				int nowc = count(ing, anow, bnow);//当前结果
				num.push(nowc);
				r.push(a[i]); //新运算符进栈
				//cout<<num.top()<<endl;
			}
			else
			{
				//cout<<"check1=1"<<endl;
				r.push(a[i]);
				check1 = 0;
				n++;
			}
		}
		else if ((a[i] == '*') && (r.top() == '+' || r.top() == '-'))
		{
			//cout<<a[i]<<endl;
			r.push(a[i]);
			check1 = 0;
			n++;
		}
		else if (a[i] == '=')
		{	//将剩余的运算符进行运算
			//cout<<"n="<<n<<endl;
			while (n)
			{
				int bnow = num.top();  //数据出栈
				num.pop();
				int anow = num.top();
				num.pop();
				char ing = r.top();
				r.pop();
				int nowc = count(ing, anow, bnow);//当前结果
				z = nowc;
				num.push(nowc);
				n--;
			}
		}
	}
	cout << z << endl;;
}
