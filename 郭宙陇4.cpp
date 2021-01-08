#include<iostream>
using namespace std;

//struct space{
//	int id;
//}sc[15][15];

void main() {
	char a[10][10];
	char sc[10][10];
	int i, j, k;
	int n, m;
	int c;
	cin >> n >> m;
	cin >> c;
	for (i = 0; i < n; i++) { //初始化
		for (j = 0; j < m; j++) {
			cin >> a[i][j];
			sc[i][j] = a[i][j];
		}
	}
	for (k = 0; k < c; k++) {
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				if (a[i][j] == 'x') {     //传染，将传染结果记录在sc内  //1.0更新，最开始写错了 把==写成'=' =-怪不得一直bug
					if (sc[i][j] != 'p')      sc[i][j] = 'x';
					if (sc[i][j + 1] != 'p' && j + 1 >= 0) sc[i][j + 1] = 'x';
					if (sc[i + 1][j] != 'p' && i + 1 >= 0) sc[i + 1][j] = 'x';
					if (sc[i - 1][j] != 'p' && i - 1 >= 0) sc[i - 1][j] = 'x';
					if (sc[i][j - 1] != 'p' && j - 1 >= 0) sc[i][j - 1] = 'x';
				}
			}
		}
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				a[i][j] = sc[i][j];   //将最终结果赋给a
			}
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cout << a[i][j];
		}
		cout << endl;
	}
}
