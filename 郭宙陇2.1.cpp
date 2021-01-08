#include<iostream>
using namespace std;
int main()
{
	int m, n, number, count = 1;		//number记猴子剩余个数，count记当前报数
	int monkey[999];
	int t;						//t记数组下标
	int i;
	cin >> m >> n;
	number = m;
	for (i = 0; i < m; i++)
		monkey[i] = i + 1;
	t = 0;
	while (number > 1)
	{
		if (monkey[t] > 0)
		{
			if (count != n)
			{
				cout << "猴子" << t + 1 << "报" << count << endl;
				count++;
				t = (t + 1) % m;		//t=(t+1)%m实现数组下标加1,当t大于M的时候，回到数组开头
			}
			else
			{
				monkey[t] = 0;
				cout << "猴子" << t + 1 << "报" << count << endl;
				count = 1;
				number--;
				t = (t + 1) % m;
			}
		}
		else
		{
			t = (t + 1) % m;
		}
	}
	for (i = 0; i < m; i++)
	{
		if (monkey[i] > 0)
			cout << "猴子大王" << monkey[i] << endl;
	}
	return 0;
}
