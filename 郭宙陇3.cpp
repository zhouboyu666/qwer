#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
struct student {
	int id;
	int chinese;
	int math;
	int english;
	int sum;
}stu[10];

bool cmp(struct student a, struct student b) {
	if (a.sum != b.sum) {
		return a.sum > b.sum;
	}
	else {
		if (a.chinese != b.chinese) {
			return a.chinese > b.chinese;
		}
		else {
			return a.id < b.id;
		}
	}
}

int main() {
	int n, i;
	cin >> n;
	for (i = 0; i < n; ++i) {
		stu[i].id = i + 1;
		cin >> stu[i].chinese >> stu[i].math >> stu[i].english;
		stu[i].sum = stu[i].chinese + stu[i].math + stu[i].english;
	}// ≥ı ºªØ
	sort(stu, stu + n, cmp);
	for (i = 0; i < 5; ++i) {
		cout << stu[i].id << " " << stu[i].sum << endl;
	}
	return 0;
}
