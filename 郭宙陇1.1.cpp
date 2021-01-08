#include<iostream>
using namespace std;

int fun(int a, int b)
{
	int c;
	int ge, shi, bai, qian;
	qian = a % 10;
	shi = a / 10;
	ge = b / 10;
	bai = b % 10;
	c = ge + 10 * shi + 100 * bai + 1000 * qian;
	return c;

}
int main()
{
	int a, b, c;
	cin >> a >> b;
	c = fun(a, b);
	cout << c;
	return 0;

}
