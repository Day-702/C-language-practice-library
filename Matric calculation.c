#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#define MAX 10    /*��ά����������*/
void count_two(int mark[10][10],int n);   /*������ξ���*/
int sum2(int mark[10][10], int n, int i,int j);   /*���η��������㺯��*/
void count_three(int mark[10][10],int n);
int sum3(int answer[10][10],int mark[10][10], int n, int i, int j);  /*���η��������㺯��*/
void count_four(int mark[10][10],int n);
int sum4(int answer[10][10], int mark[10][10], int n, int i, int j); /*�Ĵη��������㺯��*/
void display(int mark[10][10],int n,int k);     /*��ʾ������*/
int main()
{
	system("color F0");
	int i, j;     /*��ά����ѭ������*/
	int mark[MAX][MAX]; /*�����ά����*/
	int n;        /*��ά�������*/
	printf("������Ҫ����ľ������n:");
	scanf("%d", &n);
	printf("����%d��Ԫ��:", n * n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &mark[i][j]);  /*˫ѭ����������*/
		}
	}
	int choice;  /*ѡ����*/
	do {
		printf("1.��ʾ����\n2.������η�\n3.�������η�\n4.�����Ĵη�\n0.�˳�\n");
		scanf("%d", &choice);      /*���ܵ�choiceֵ*/
		switch (choice) {
		case 1:display(mark, n, 1);  break;
		case 2:count_two(mark, n);   break;
		case 3:count_three(mark, n); break;
		case 4:count_four(mark, n);  break;
		}
	} while (choice != 0);
	return 0;
}
void count_two(int mark[10][10],int n)
{
	static int answer[10][10];    /*�������洢����*/
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			answer[i][j] = sum2(mark, n,i,j);
		}
	}
	display(answer, n,2);   /*���ν������չʾ*/
}
int sum2(int mark[10][10], int n,int i,int j)   /*Mark�������� n���ݽ��� i��j���ݵ�ǰ��λ��   ���η��������㺯��*/  
{
	/*�˺�����Ҫ�Ķ���������*/
	int a = 0;
	int a1, b1, a2, b2;
	if (i != 0) {
		a1 = i;
		a2 = 0;
	}
	else {
		a1 = a2 = i;
	}
	if (j != 0) {
		b1 = 0;
		b2 = j;
	}
	else {
		b1 = b2 = j;
	}
		do {
			a = a + mark[a1][b1] * mark[a2][b2];
			b1++;
			a2++;
		} while (b1 < n);
		return a;
	/*�˺�����Ҫ�Ķ���������*/
}
void count_three(int mark[10][10], int n)
{
	static int answer[10][10],answer2[10][10];    /*�������洢����*/  /*answer2�洢���ξ�������Ľ��*/
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			answer[i][j] = sum2(mark, n, i, j);     /*answer�洢�Ŷ��ξ����������*/
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			answer2[i][j] = sum3(answer,mark, n, i, j);     /*answer2�洢�����ξ����������  answerЯ���Ŷ������������뺯��sum3*/
		}
	}
	display(answer2, n,3);  /*���ν������չʾ*/
}
int sum3(int answer[10][10],int mark[10][10], int n, int i, int j)  /*Mark�������� n���ݽ��� i��j���ݵ�ǰ��λ��   ���η��������㺯��*/
{
	/*�˺�����Ҫ�Ķ���������*/
	int a = 0;
	int a1, b1, a2, b2;
	if (i != 0) {
		a1 = i;
		a2 = 0;
	}
	else {
		a1 = a2 = i;
	}
	if (j != 0) {
		b1 = 0;
		b2 = j;
	}
	else {
		b1 = b2 = j;
	}
	do {
		a = a + answer[a1][b1] * mark[a2][b2];
		b1++;
		a2++;
	} while (b1 < n);
	return a;
	/*�˺�����Ҫ�Ķ���������*/
}
void count_four(int mark[10][10], int n)
{
	static int answer[10][10], answer2[10][10],answer3[10][10];    /*�������洢����*/  /*answer2�洢���ξ�������Ľ��*/ /*answer3�洢�Ĵξ���������*/
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			answer[i][j] = sum2(mark, n, i, j);     /*answer�洢�Ŷ��ξ����������*/
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			answer2[i][j] = sum3(answer, mark, n, i, j);     /*answer2�洢�����ξ����������  answerЯ���Ŷ������������뺯��sum3*/
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			answer3[i][j] = sum4(answer2, mark, n, i, j);     /*answer3�洢�����ξ����������  answer2Я�����������������뺯��sum4*/
		}
	}
	display(answer3, n,4);  /*�Ĵξ�����չʾ*/
}
int sum4(int answer2[10][10], int mark[10][10], int n, int i, int j) /*Mark�������� n���ݽ��� i��j���ݵ�ǰ��λ��   �Ĵη��������㺯��*/
{
	/*�˺�����Ҫ�Ķ���������*/
	int a = 0;
	int a1, b1, a2, b2;
	if (i != 0) {
		a1 = i;
		a2 = 0;
	}
	else {
		a1 = a2 = i;
	}
	if (j != 0) {
		b1 = 0;
		b2 = j;
	}
	else {
		b1 = b2 = j;
	}
	do {
		a = a + answer2[a1][b1] * mark[a2][b2];
		b1++;
		a2++;
	} while (b1 < n);
	return a;
	/*�˺�����Ҫ�Ķ���������*/
}
void display(int mark[10][10], int n,int k)   /*������ʾ*/
{
	int i, j;
	printf(" �����%d�η����£�\n", k);
	printf("\n        ");
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%d\t", mark[i][j]);  /*˫ѭ���������*/
		}
		printf("\n\n\n        ");
	}
	printf("\n");
}
