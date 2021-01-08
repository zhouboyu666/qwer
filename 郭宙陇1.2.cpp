#include<iostream>
using namespace std;

void fun(int& a, int& b, int& c)
{
	int ge, shi, bai, qian;
	qian = a % 10;
	shi = a / 10;
	ge = b / 10;
	bai = b % 10;
	c = ge + 10 * shi + 100 * bai + 1000 * qian;
}

int main()
{
	int a, b, c = 0;
	cin >> a >> b;
	fun(a, b, c);
	cout << c;
	return 0;

}
