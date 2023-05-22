#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#define MAX 10    /*二维数组最大阶数*/
void count_two(int mark[10][10],int n);   /*计算二次矩阵*/
int sum2(int mark[10][10], int n, int i,int j);   /*二次方矩阵运算函数*/
void count_three(int mark[10][10],int n);
int sum3(int answer[10][10],int mark[10][10], int n, int i, int j);  /*三次方矩阵运算函数*/
void count_four(int mark[10][10],int n);
int sum4(int answer[10][10], int mark[10][10], int n, int i, int j); /*四次方矩阵运算函数*/
void display(int mark[10][10],int n,int k);     /*显示矩阵函数*/
int main()
{
	system("color F0");
	int i, j;     /*二维数组循环变量*/
	int mark[MAX][MAX]; /*定义二维数组*/
	int n;        /*二维数组阶数*/
	printf("输入需要计算的矩阵阶数n:");
	scanf("%d", &n);
	printf("输入%d个元素:", n * n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &mark[i][j]);  /*双循环输入数据*/
		}
	}
	int choice;  /*选择项*/
	do {
		printf("1.显示矩阵\n2.矩阵二次方\n3.矩阵三次方\n4.矩阵四次方\n0.退出\n");
		scanf("%d", &choice);      /*接受到choice值*/
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
	static int answer[10][10];    /*计算结果存储数组*/
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			answer[i][j] = sum2(mark, n,i,j);
		}
	}
	display(answer, n,2);   /*二次结果矩阵展示*/
}
int sum2(int mark[10][10], int n,int i,int j)   /*Mark传递数组 n传递阶数 i和j传递当前的位置   二次方矩阵运算函数*/  
{
	/*此函数不要改动！！！！*/
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
	/*此函数不要改动！！！！*/
}
void count_three(int mark[10][10], int n)
{
	static int answer[10][10],answer2[10][10];    /*计算结果存储数组*/  /*answer2存储三次矩阵运算的结果*/
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			answer[i][j] = sum2(mark, n, i, j);     /*answer存储着二次矩阵的运算结果*/
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			answer2[i][j] = sum3(answer,mark, n, i, j);     /*answer2存储着三次矩阵的运算结果  answer携带着二次运算结果传入函数sum3*/
		}
	}
	display(answer2, n,3);  /*三次结果矩阵展示*/
}
int sum3(int answer[10][10],int mark[10][10], int n, int i, int j)  /*Mark传递数组 n传递阶数 i和j传递当前的位置   三次方矩阵运算函数*/
{
	/*此函数不要改动！！！！*/
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
	/*此函数不要改动！！！！*/
}
void count_four(int mark[10][10], int n)
{
	static int answer[10][10], answer2[10][10],answer3[10][10];    /*计算结果存储数组*/  /*answer2存储三次矩阵运算的结果*/ /*answer3存储四次矩阵运算结果*/
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			answer[i][j] = sum2(mark, n, i, j);     /*answer存储着二次矩阵的运算结果*/
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			answer2[i][j] = sum3(answer, mark, n, i, j);     /*answer2存储着三次矩阵的运算结果  answer携带着二次运算结果传入函数sum3*/
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			answer3[i][j] = sum4(answer2, mark, n, i, j);     /*answer3存储着三次矩阵的运算结果  answer2携带着三次运算结果传入函数sum4*/
		}
	}
	display(answer3, n,4);  /*四次矩阵结果展示*/
}
int sum4(int answer2[10][10], int mark[10][10], int n, int i, int j) /*Mark传递数组 n传递阶数 i和j传递当前的位置   四次方矩阵运算函数*/
{
	/*此函数不要改动！！！！*/
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
	/*此函数不要改动！！！！*/
}
void display(int mark[10][10], int n,int k)   /*矩阵显示*/
{
	int i, j;
	printf(" 矩阵的%d次方如下：\n", k);
	printf("\n        ");
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%d\t", mark[i][j]);  /*双循环输出数据*/
		}
		printf("\n\n\n        ");
	}
	printf("\n");
}
