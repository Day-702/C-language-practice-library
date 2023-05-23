#define _CRT_SECURE_NO_WARNINGS 1
/*一、实验目的
1、熟悉二叉树的链式存储;
2、掌握二叉树的建立、遍历等基本操作算法的思路;
3、掌握哈夫曼树的构造算法；
二、实验内容
1.建立一棵用二叉链表方式存储的二叉树，并实现对其进行先序、中序、后序三种方法遍历，输出遍历结果。
2.给定n个叶子结点和权值，建立哈夫曼树并输出。*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define N 20            //哈夫曼树最大子叶结点数
// 二叉树
typedef char datatype;
typedef struct Node {   //二叉链表结构定义
    datatype data;
    struct Node* left;
    struct Node* right;
}binary_tree_nodes;
struct box {            //元素输入存储结构
    int left_or_right;
    datatype elem;
};
typedef struct Node2 {
    int data;
    struct Node2* Lchild;
    struct Node2* Rchild;
}V2_binary_tree_nodes; 
//二叉树函数声明
void creat_tree(binary_tree_nodes* root);                   //建树
void V2_creat_tree(V2_binary_tree_nodes** t);               //V2建树
void binary_tree_traversal(binary_tree_nodes* root);        //遍历
void V2_binary_tree_traversal(V2_binary_tree_nodes** t);    //V2遍历
void traversal_children_first(binary_tree_nodes* root);     //先序遍历
void traversal_children_second(binary_tree_nodes* root);    //中序遍历
void traversal_children_third(binary_tree_nodes* root);     //后序遍历
void V2_traversal_children_first(V2_binary_tree_nodes* t);  //V2先序遍历
void V2_traversal_children_second(V2_binary_tree_nodes* t); //V2中序遍历
void V2_traversal_children_third(V2_binary_tree_nodes* t);  //V2后序遍历
binary_tree_nodes* root;                                    //全局变量根结点root 
V2_binary_tree_nodes* t; 

//哈夫曼树
typedef struct {
    int weight;
    int parent;
    int lchild;
    int rchild;
}huffman_tree_nodes;
huffman_tree_nodes huf_tree[2 * N];
//哈夫曼树函数声明
void creat_huffman_tree(huffman_tree_nodes huf_tree[]);                   //建哈夫曼树
void init_huaffman_tree(huffman_tree_nodes huf_tree[], int w[], int n);   //哈夫曼树的初始化 
void output_huaffman_tree(huffman_tree_nodes huf_tree[], int n);          //哈夫曼树的输出
void find_small(huffman_tree_nodes huf_tree[], int k, int** s1, int** s2);  //在输入的节点中找出两个最小的 下标存储在s1，s2中
int main()
{
    system("color F0");
    root = (binary_tree_nodes*)malloc(sizeof(binary_tree_nodes));        /*动态开辟存储空间给根指针*/
    int choice, choice2;
    do {
        printf("\n\n1.二叉树操作\n2.哈夫曼树操作\n0.退出\n\n");
        scanf("%d", &choice); 
        switch (choice) {
        case 1:
            do {
                printf("\n\n1.V1\n2.V2\n0.退出\n\n");
                scanf("%d", &choice2);
                switch (choice2) { 
                case 1:
                    printf("查看二叉树...\n");
                    Sleep(2000);
                    char command[] = "start C:B_tree.jpg";
                    system(command);
                    creat_tree(root);
                    binary_tree_traversal(root);
                    break;
                case 2:
                    printf("请输入第一个节点的值，-1表示没有叶节点：\n");
                    V2_creat_tree(&t);
                    V2_binary_tree_traversal(t);  
                    break;
                }
            } while (choice != 0);
            break;
        case 2:
            creat_huffman_tree(huf_tree);
            break;
        default:
            printf("\n重新选择有效选项\n");
            break;
        }
    } while (choice != 0);

    return 0;
}
//子函数----二叉树-----------------------------------------------------------
void creat_tree(binary_tree_nodes* root)
{
    //左枝
    root->data = '1';
    root->left = (binary_tree_nodes*)malloc(sizeof(binary_tree_nodes));
    if (!root->left) {
        printf("内存分配失败！1");
        exit(0);
    }
    root->left->data = '2';
    root->left->right = NULL;
    root->left->left = (binary_tree_nodes*)malloc(sizeof(binary_tree_nodes));
    if (!root->left->left) {
        printf("内存分配失败！2");
        exit(0);
    }
    root->left->left->data = '4';
    root->left->left->left = NULL;
    root->left->left->right = (binary_tree_nodes*)malloc(sizeof(binary_tree_nodes));
    if (!root->left->left->right) {
        printf("内存分配失败！3");
        exit(0);
    }
    root->left->left->right->data = '5';
    root->left->left->right->left = NULL;
    root->left->left->right->right = NULL;
    //右枝
    root->right = (binary_tree_nodes*)malloc(sizeof(binary_tree_nodes));
    if (!root->right) {
        printf("内存分配失败！4");
        exit(0);
    }
    root->right->data = '3';
    root->right->left = (binary_tree_nodes*)malloc(sizeof(binary_tree_nodes));
    if (!root->right->left) {
        printf("内存分配失败！5");
        exit(0);
    }
    root->right->left->data = '6';
    root->right->left->left = NULL;
    root->right->left->right = NULL;
    root->right->right = (binary_tree_nodes*)malloc(sizeof(binary_tree_nodes));
    if (!root->right->right) {
        printf("内存分配失败！6");
        exit(0);
    }
    root->right->right->data = '7';
    root->right->right->left = NULL;
    root->right->right->right = NULL;
    printf("\n\n二叉树建立完成！\n\n");
}
void V2_creat_tree(V2_binary_tree_nodes** t)
{
    int c;
    scanf("%d", &c);
    if (c == -1) {
        *t = NULL;
        return;
    }
    else {
        *t = (V2_binary_tree_nodes*)malloc(sizeof(V2_binary_tree_nodes));
        (*t)->data = c;
        printf("输入%d的 左 孩子结点：", c);
        V2_creat_tree(&((*t)->Lchild));
        printf("输入%d的 右 孩子结点：", c);
        V2_creat_tree(&((*t)->Rchild));  
    }
    return;
}
void binary_tree_traversal(binary_tree_nodes* root) {
    int choice;
    printf("输入需要遍历的方式：");
    do {
        printf("\n\n1.先序遍历\n2.中序遍历\n3.后序遍历\n4.全部打印\n0.退出\n\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            traversal_children_first(root);
            break;
        case 2:
            traversal_children_second(root);
            break;
        case 3:
            traversal_children_third(root);
            break;
        case 4:
            printf("先序"); traversal_children_first(root); printf("\n");
            printf("中序"); traversal_children_second(root); printf("\n");
            printf("后序"); traversal_children_third(root); printf("\n");
            break;
        default:
            if (choice == 0)
                break;
            printf("\n重新输入有效选项\n");
            break;
        }

    } while (choice != 0);
}
void traversal_children_first(binary_tree_nodes* root)
{
    if (root != NULL) {
        printf(" %c", root->data);
        traversal_children_first(root->left);
        traversal_children_first(root->right);
    }
}
void traversal_children_second(binary_tree_nodes* root)
{
    if (root != NULL) {
        traversal_children_second(root->left);
        printf(" %c", root->data);
        traversal_children_second(root->right);
    }
}
void traversal_children_third(binary_tree_nodes* root)
{
    if (root != NULL) {
        traversal_children_third(root->left);
        traversal_children_third(root->right);
        printf(" %c", root->data);
    }
}
void V2_binary_tree_traversal(V2_binary_tree_nodes** t)
{
    printf("\n先序遍历:");
    V2_traversal_children_first(t);
    printf("\n中序遍历:");
    V2_traversal_children_second(t);
    printf("\n后序遍历:");
    V2_traversal_children_third(t);
}
void V2_traversal_children_first(V2_binary_tree_nodes* t) 
{
    if (t == NULL){
        return;
    }
    else{
        printf("%d ", t->data);
        V2_traversal_children_first(t->Lchild);
        V2_traversal_children_first(t->Rchild); 
    }
}
void V2_traversal_children_second(V2_binary_tree_nodes* t)
{
    if (t == NULL) {
        return;
    }
    else {
        V2_traversal_children_second(t->Lchild);
        printf("%d ", t->data); 
        V2_traversal_children_second(t->Rchild);
    }
}
void V2_traversal_children_third(V2_binary_tree_nodes* t)
{
    if (t == NULL) {
        return;
    }
    else {
        V2_traversal_children_third(t->Lchild);
        V2_traversal_children_third(t->Rchild);
        printf("%d ", t->data);  
    }
}
//函数分界线------哈夫曼树----------------------------------------------------
void creat_huffman_tree(huffman_tree_nodes huf_tree[])
{
    int i, n, weight[N];
    printf("\n输入子叶结点数(<=20):");
    scanf("%d", &n);
    printf("输入%d个结点\n", n);
    for (i = 1; i <= n; i++) {
        printf("%d:", i);
        scanf("%d", &weight[i]);
    }
    printf("\n子叶结点接收完毕!");
    init_huaffman_tree(huf_tree, weight, n);
}
void init_huaffman_tree(huffman_tree_nodes huf_tree[], int w[], int n) {
    int i, * s1 = NULL, * s2 = NULL;
    for (i = 1; i <= 2 * n - 1; i++) {              //哈夫曼树的初始化
        if (i <= n) {
            huf_tree[i].weight = w[i];
            huf_tree[i].parent = 0;
            huf_tree[i].lchild = 0;
            huf_tree[i].rchild = 0;
        }
        else {
            huf_tree[i].weight = 0;
            huf_tree[i].parent = 0;
            huf_tree[i].lchild = 0;
            huf_tree[i].rchild = 0;
        }
    }
    printf(" done \n");
    for (i = n + 1; i <= (2 * n) - 1; i++) {
        printf("\n寻找\n");
        find_small(huf_tree, i - 1, &s1, &s2);                              //传入参数为i-1 比对范围向后扩展（因为有新的结点生成） 比对过的结点因为父亲结点不为零 不参与比对
        huf_tree[i].weight = huf_tree[*s1].weight + huf_tree[*s2].weight;   //新的结点权值赋值
        huf_tree[*s1].parent = huf_tree[*s2].parent = i;                    //父亲结点赋值
        huf_tree[i].lchild = *s1;                                           //孩子结点赋值
        huf_tree[i].rchild = *s2;                                           //孩子结点赋值
        printf("s1:[%d]parents=%d s2:[%d]parents=%d\n", *s1, huf_tree[*s1].parent, *s2, huf_tree[*s2].parent);
    }
    int cut = 0;
    printf("\n\n");
    for (i = 1; i <= 2 * n - 1; i++) {
        printf("结点%d 的父亲结点为%d\t", i, huf_tree[i].parent);
        cut++;
        cut % 3 == 0 ? printf("\n") : 0;
    }
    output_huaffman_tree(huf_tree, n);
}
void find_small(huffman_tree_nodes huf_tree[], int k, int** s1, int** s2)
{
    int i, min = 999999, index_1, index_2;       //min初始为一个较大值 index_1及index_2分别存储第一小和第二小的下标
    for (i = 1; i <= k; i++) {                  //第一遍找到最小的权值
        if (huf_tree[i].weight < min && huf_tree[i].parent == 0) {
            min = huf_tree[i].weight;           //一定有数小于999999  并更新min的值
            index_1 = i;                        //index1保存下标
        }
    }
    min = 999999;                               //min重新赋值
    for (i = 1; i <= k; i++) {
        if (huf_tree[i].weight < min && huf_tree[i].parent == 0 && i != index_1) {   //第二次找到除了第一次的
            //标值之外的最小值，即第二小
            min = huf_tree[i].weight;
            index_2 = i;                        //下标用index2保存

        }
    }
    *s1 = &index_1;                             //指针赋值 
    *s2 = &index_2;
    printf("s1,s2赋值完毕(s1,s2)分别是寻找到的最小两结点\n");
    printf("s1:weight=%d parent=%d Lchild=%d Rchild=%d\n", huf_tree[**s1].weight, huf_tree[**s1].parent,
        huf_tree[**s1].lchild, huf_tree[**s1].rchild);
    printf("s2:weight=%d parent=%d Lchild=%d Rchild=%d\n", huf_tree[**s2].weight, huf_tree[**s2].parent,
        huf_tree[**s2].lchild, huf_tree[**s2].rchild);
}
void output_huaffman_tree(huffman_tree_nodes huf_tree[], int n)
{
    int i;
    printf("\n\n哈夫曼输出：\n");
    for (i = 1; i <= 2 * n - 1; i++) {
        huf_tree[i].parent != 0 ? printf("结点%d weight=%d parent=%d Lchild=%d Rchild=%d \n", i, huf_tree[i].weight,
            huf_tree[i].parent, huf_tree[i].lchild, huf_tree[i].rchild) : printf("结点%d weight=%d parent=NULL Lchild=%d Rchild=%d \n",
                i, huf_tree[i].weight, huf_tree[i].lchild, huf_tree[i].rchild);
    }
}
/*void find_small(huffman_tree_nodes huf_tree[], int k, int** s1, int** s2)
{
    int i, min = 1, temp = 1, index = 0;               //假定min=1为当前最小值
    for (i = 1; i <= k; i++) {
        if ((huf_tree[i].weight <= huf_tree[min].weight) && (huf_tree[i].parent == 0)) {        //假如存在两个最小 本次找到的是靠后边的最小值
            min = i;
            index = i;
            *s1 = &min;         //记录到最小值的下标
        }
    }
    for (i = 1; i <= k; i++) {
        if ((huf_tree[i].weight == huf_tree[min].weight) && (huf_tree[i].parent == 0) && (i!=index)) { //本次找到的是先出现的最小值
            *s2 = &i;
            break;
        }
        else {          //若不存在相同的最小值 直接找第二小值 确保下标与第一次的最小值不同
            for (i = 1; i <= k; i++) {
                if ((huf_tree[i].weight < huf_tree[temp].weight) && (huf_tree[i].parent == 0)&&(i!=index)) {
                    temp = i;
                    *s2 = &temp;         //记录到最小值的下标
                }
            }
        }
    }
    printf("s1,s2赋值完毕\n");
    printf("s1:weight=%d parent=%d l=%d r=%d\n", huf_tree[**s1].weight, huf_tree[**s1].parent, huf_tree[**s1].lchild, huf_tree[**s1].rchild);
    printf("s2:weight=%d parent=%d l=%d r=%d\n", huf_tree[**s2].weight, huf_tree[**s2].parent, huf_tree[**s2].lchild, huf_tree[**s2].rchild);

}
oid find_small(huffman_tree_nodes huf_tree[], int k, int* s1, int* s2)
{
    int min1 = 9999, min2 = 9999;
    int j;
    for (j = 1; j <= k; j++) {
        if (huf_tree[j].weight < min1 && huf_tree[j].parent == 0) {
            min1 = huf_tree[j].weight;
            *s1 = j;
        }
    }
    int a;
    for (a = 1; a <= k; a++) {
        if (huf_tree[a].weight < min2 && a != *s1 && huf_tree[a].parent == 0) {
            min2 = huf_tree[a].weight;
            *s2 = a;
        }
    }
}*/