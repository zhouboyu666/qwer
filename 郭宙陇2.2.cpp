#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
typedef struct monkey
{
	int num;
	struct monkey* next;
} Monkey, * LINK;
void main()
{
	int n, m;
	cin >> n >> m;
	LINK p, head, p2;
	int i;
	head = p = p2 = (LINK)malloc(sizeof(Monkey));//三个指针指向同一块内存
	for (i = 1; i < n; i++) {
		p = (LINK)malloc(sizeof(Monkey));
		p2->next = p;
		p2 = p;
	}
	p2->next = head;//把链表的首尾相连
	p = head;//p指向了第一个结点
	printf("对猴子进行编号！\n");
	for (i = 1; i <= n; i++) {
		p->num = i;//从第一个结点到最后一个结点依次给猴子编号
		printf("%d号猴子：%d\n", p->num, p->num);
		p = p->next;
	}//循环结束，p指向了最后一个结点
	i = 0;
	p = head;//再把p指向第一个结点
	while (1) {
		i++;
		printf("%d号猴子报：%d\n", p->num, i);
		if (p->next == p)
			break;//此为while循环的出口
		if (i == m)//if语句中是删除结点的过程
		{
			i = 0;
			printf("%d号猴被淘汰\n", p->num);
			printf("\n");
			p2->next = p->next;//在此删除结点p
			p = p2->next;//p指向它的下一个结点
			continue;
		}
		else
		{
			if (i == m - 1)
				p2 = p;//保存将要退出结点的前一个结点（存到p2中）
			p = p->next;
		}
	}
	printf("胜出:%d", p->num);//最后剩下的结点就是获胜的结点
}
