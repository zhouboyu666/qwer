#include<iostream>
using namespace std;
int main()
{
	int m, n, number, count = 1;		//number�Ǻ���ʣ�������count�ǵ�ǰ����
	int monkey[999];
	int t;						//t�������±�
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
				cout << "����" << t + 1 << "��" << count << endl;
				count++;
				t = (t + 1) % m;		//t=(t+1)%mʵ�������±��1,��t����M��ʱ�򣬻ص����鿪ͷ
			}
			else
			{
				monkey[t] = 0;
				cout << "����" << t + 1 << "��" << count << endl;
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
			cout << "���Ӵ���" << monkey[i] << endl;
	}
	return 0;
}
