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
	head = p = p2 = (LINK)malloc(sizeof(Monkey));//����ָ��ָ��ͬһ���ڴ�
	for (i = 1; i < n; i++) {
		p = (LINK)malloc(sizeof(Monkey));
		p2->next = p;
		p2 = p;
	}
	p2->next = head;//���������β����
	p = head;//pָ���˵�һ�����
	printf("�Ժ��ӽ��б�ţ�\n");
	for (i = 1; i <= n; i++) {
		p->num = i;//�ӵ�һ����㵽���һ��������θ����ӱ��
		printf("%d�ź��ӣ�%d\n", p->num, p->num);
		p = p->next;
	}//ѭ��������pָ�������һ�����
	i = 0;
	p = head;//�ٰ�pָ���һ�����
	while (1) {
		i++;
		printf("%d�ź��ӱ���%d\n", p->num, i);
		if (p->next == p)
			break;//��Ϊwhileѭ���ĳ���
		if (i == m)//if�������ɾ�����Ĺ���
		{
			i = 0;
			printf("%d�źﱻ��̭\n", p->num);
			printf("\n");
			p2->next = p->next;//�ڴ�ɾ�����p
			p = p2->next;//pָ��������һ�����
			continue;
		}
		else
		{
			if (i == m - 1)
				p2 = p;//���潫Ҫ�˳�����ǰһ����㣨�浽p2�У�
			p = p->next;
		}
	}
	printf("ʤ��:%d", p->num);//���ʣ�µĽ����ǻ�ʤ�Ľ��
}
