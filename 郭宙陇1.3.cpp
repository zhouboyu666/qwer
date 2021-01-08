#include<iostream>
using namespace std;

void fun(int* p, int* q, int* l)
{
	int ge, shi, bai, qian;
	qian = *p % 10;
	shi = *p / 10;
	ge = *q / 10;
	bai = *q % 10;
	*l = ge + 10 * shi + 100 * bai + 1000 * qian;
}
int main()
{
	int a, b, c = 0;
	cin >> a >> b;
	fun(&a, &b, &c);
	cout << c;
	return 0;

}
