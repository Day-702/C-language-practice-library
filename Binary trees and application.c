#define _CRT_SECURE_NO_WARNINGS 1
/*һ��ʵ��Ŀ��
1����Ϥ����������ʽ�洢;
2�����ն������Ľ����������Ȼ��������㷨��˼·;
3�����չ��������Ĺ����㷨��
����ʵ������
1.����һ���ö�������ʽ�洢�Ķ���������ʵ�ֶ�������������򡢺������ַ���������������������
2.����n��Ҷ�ӽ���Ȩֵ���������������������*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define N 20            //�������������Ҷ�����
// ������
typedef char datatype;
typedef struct Node {   //��������ṹ����
    datatype data;
    struct Node* left;
    struct Node* right;
}binary_tree_nodes;
struct box {            //Ԫ������洢�ṹ
    int left_or_right;
    datatype elem;
};
typedef struct Node2 {
    int data;
    struct Node2* Lchild;
    struct Node2* Rchild;
}V2_binary_tree_nodes; 
//��������������
void creat_tree(binary_tree_nodes* root);                   //����
void V2_creat_tree(V2_binary_tree_nodes** t);               //V2����
void binary_tree_traversal(binary_tree_nodes* root);        //����
void V2_binary_tree_traversal(V2_binary_tree_nodes** t);    //V2����
void traversal_children_first(binary_tree_nodes* root);     //�������
void traversal_children_second(binary_tree_nodes* root);    //�������
void traversal_children_third(binary_tree_nodes* root);     //�������
void V2_traversal_children_first(V2_binary_tree_nodes* t);  //V2�������
void V2_traversal_children_second(V2_binary_tree_nodes* t); //V2�������
void V2_traversal_children_third(V2_binary_tree_nodes* t);  //V2�������
binary_tree_nodes* root;                                    //ȫ�ֱ��������root 
V2_binary_tree_nodes* t; 

//��������
typedef struct {
    int weight;
    int parent;
    int lchild;
    int rchild;
}huffman_tree_nodes;
huffman_tree_nodes huf_tree[2 * N];
//����������������
void creat_huffman_tree(huffman_tree_nodes huf_tree[]);                   //����������
void init_huaffman_tree(huffman_tree_nodes huf_tree[], int w[], int n);   //���������ĳ�ʼ�� 
void output_huaffman_tree(huffman_tree_nodes huf_tree[], int n);          //�������������
void find_small(huffman_tree_nodes huf_tree[], int k, int** s1, int** s2);  //������Ľڵ����ҳ�������С�� �±�洢��s1��s2��
int main()
{
    system("color F0");
    root = (binary_tree_nodes*)malloc(sizeof(binary_tree_nodes));        /*��̬���ٴ洢�ռ����ָ��*/
    int choice, choice2;
    do {
        printf("\n\n1.����������\n2.������������\n0.�˳�\n\n");
        scanf("%d", &choice); 
        switch (choice) {
        case 1:
            do {
                printf("\n\n1.V1\n2.V2\n0.�˳�\n\n");
                scanf("%d", &choice2);
                switch (choice2) { 
                case 1:
                    printf("�鿴������...\n");
                    Sleep(2000);
                    char command[] = "start C:B_tree.jpg";
                    system(command);
                    creat_tree(root);
                    binary_tree_traversal(root);
                    break;
                case 2:
                    printf("�������һ���ڵ��ֵ��-1��ʾû��Ҷ�ڵ㣺\n");
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
            printf("\n����ѡ����Чѡ��\n");
            break;
        }
    } while (choice != 0);

    return 0;
}
//�Ӻ���----������-----------------------------------------------------------
void creat_tree(binary_tree_nodes* root)
{
    //��֦
    root->data = '1';
    root->left = (binary_tree_nodes*)malloc(sizeof(binary_tree_nodes));
    if (!root->left) {
        printf("�ڴ����ʧ�ܣ�1");
        exit(0);
    }
    root->left->data = '2';
    root->left->right = NULL;
    root->left->left = (binary_tree_nodes*)malloc(sizeof(binary_tree_nodes));
    if (!root->left->left) {
        printf("�ڴ����ʧ�ܣ�2");
        exit(0);
    }
    root->left->left->data = '4';
    root->left->left->left = NULL;
    root->left->left->right = (binary_tree_nodes*)malloc(sizeof(binary_tree_nodes));
    if (!root->left->left->right) {
        printf("�ڴ����ʧ�ܣ�3");
        exit(0);
    }
    root->left->left->right->data = '5';
    root->left->left->right->left = NULL;
    root->left->left->right->right = NULL;
    //��֦
    root->right = (binary_tree_nodes*)malloc(sizeof(binary_tree_nodes));
    if (!root->right) {
        printf("�ڴ����ʧ�ܣ�4");
        exit(0);
    }
    root->right->data = '3';
    root->right->left = (binary_tree_nodes*)malloc(sizeof(binary_tree_nodes));
    if (!root->right->left) {
        printf("�ڴ����ʧ�ܣ�5");
        exit(0);
    }
    root->right->left->data = '6';
    root->right->left->left = NULL;
    root->right->left->right = NULL;
    root->right->right = (binary_tree_nodes*)malloc(sizeof(binary_tree_nodes));
    if (!root->right->right) {
        printf("�ڴ����ʧ�ܣ�6");
        exit(0);
    }
    root->right->right->data = '7';
    root->right->right->left = NULL;
    root->right->right->right = NULL;
    printf("\n\n������������ɣ�\n\n");
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
        printf("����%d�� �� ���ӽ�㣺", c);
        V2_creat_tree(&((*t)->Lchild));
        printf("����%d�� �� ���ӽ�㣺", c);
        V2_creat_tree(&((*t)->Rchild));  
    }
    return;
}
void binary_tree_traversal(binary_tree_nodes* root) {
    int choice;
    printf("������Ҫ�����ķ�ʽ��");
    do {
        printf("\n\n1.�������\n2.�������\n3.�������\n4.ȫ����ӡ\n0.�˳�\n\n");
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
            printf("����"); traversal_children_first(root); printf("\n");
            printf("����"); traversal_children_second(root); printf("\n");
            printf("����"); traversal_children_third(root); printf("\n");
            break;
        default:
            if (choice == 0)
                break;
            printf("\n����������Чѡ��\n");
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
    printf("\n�������:");
    V2_traversal_children_first(t);
    printf("\n�������:");
    V2_traversal_children_second(t);
    printf("\n�������:");
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
//�����ֽ���------��������----------------------------------------------------
void creat_huffman_tree(huffman_tree_nodes huf_tree[])
{
    int i, n, weight[N];
    printf("\n������Ҷ�����(<=20):");
    scanf("%d", &n);
    printf("����%d�����\n", n);
    for (i = 1; i <= n; i++) {
        printf("%d:", i);
        scanf("%d", &weight[i]);
    }
    printf("\n��Ҷ���������!");
    init_huaffman_tree(huf_tree, weight, n);
}
void init_huaffman_tree(huffman_tree_nodes huf_tree[], int w[], int n) {
    int i, * s1 = NULL, * s2 = NULL;
    for (i = 1; i <= 2 * n - 1; i++) {              //���������ĳ�ʼ��
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
        printf("\nѰ��\n");
        find_small(huf_tree, i - 1, &s1, &s2);                              //�������Ϊi-1 �ȶԷ�Χ�����չ����Ϊ���µĽ�����ɣ� �ȶԹ��Ľ����Ϊ���׽�㲻Ϊ�� ������ȶ�
        huf_tree[i].weight = huf_tree[*s1].weight + huf_tree[*s2].weight;   //�µĽ��Ȩֵ��ֵ
        huf_tree[*s1].parent = huf_tree[*s2].parent = i;                    //���׽�㸳ֵ
        huf_tree[i].lchild = *s1;                                           //���ӽ�㸳ֵ
        huf_tree[i].rchild = *s2;                                           //���ӽ�㸳ֵ
        printf("s1:[%d]parents=%d s2:[%d]parents=%d\n", *s1, huf_tree[*s1].parent, *s2, huf_tree[*s2].parent);
    }
    int cut = 0;
    printf("\n\n");
    for (i = 1; i <= 2 * n - 1; i++) {
        printf("���%d �ĸ��׽��Ϊ%d\t", i, huf_tree[i].parent);
        cut++;
        cut % 3 == 0 ? printf("\n") : 0;
    }
    output_huaffman_tree(huf_tree, n);
}
void find_small(huffman_tree_nodes huf_tree[], int k, int** s1, int** s2)
{
    int i, min = 999999, index_1, index_2;       //min��ʼΪһ���ϴ�ֵ index_1��index_2�ֱ�洢��һС�͵ڶ�С���±�
    for (i = 1; i <= k; i++) {                  //��һ���ҵ���С��Ȩֵ
        if (huf_tree[i].weight < min && huf_tree[i].parent == 0) {
            min = huf_tree[i].weight;           //һ������С��999999  ������min��ֵ
            index_1 = i;                        //index1�����±�
        }
    }
    min = 999999;                               //min���¸�ֵ
    for (i = 1; i <= k; i++) {
        if (huf_tree[i].weight < min && huf_tree[i].parent == 0 && i != index_1) {   //�ڶ����ҵ����˵�һ�ε�
            //��ֵ֮�����Сֵ�����ڶ�С
            min = huf_tree[i].weight;
            index_2 = i;                        //�±���index2����

        }
    }
    *s1 = &index_1;                             //ָ�븳ֵ 
    *s2 = &index_2;
    printf("s1,s2��ֵ���(s1,s2)�ֱ���Ѱ�ҵ�����С�����\n");
    printf("s1:weight=%d parent=%d Lchild=%d Rchild=%d\n", huf_tree[**s1].weight, huf_tree[**s1].parent,
        huf_tree[**s1].lchild, huf_tree[**s1].rchild);
    printf("s2:weight=%d parent=%d Lchild=%d Rchild=%d\n", huf_tree[**s2].weight, huf_tree[**s2].parent,
        huf_tree[**s2].lchild, huf_tree[**s2].rchild);
}
void output_huaffman_tree(huffman_tree_nodes huf_tree[], int n)
{
    int i;
    printf("\n\n�����������\n");
    for (i = 1; i <= 2 * n - 1; i++) {
        huf_tree[i].parent != 0 ? printf("���%d weight=%d parent=%d Lchild=%d Rchild=%d \n", i, huf_tree[i].weight,
            huf_tree[i].parent, huf_tree[i].lchild, huf_tree[i].rchild) : printf("���%d weight=%d parent=NULL Lchild=%d Rchild=%d \n",
                i, huf_tree[i].weight, huf_tree[i].lchild, huf_tree[i].rchild);
    }
}
/*void find_small(huffman_tree_nodes huf_tree[], int k, int** s1, int** s2)
{
    int i, min = 1, temp = 1, index = 0;               //�ٶ�min=1Ϊ��ǰ��Сֵ
    for (i = 1; i <= k; i++) {
        if ((huf_tree[i].weight <= huf_tree[min].weight) && (huf_tree[i].parent == 0)) {        //�������������С �����ҵ����ǿ���ߵ���Сֵ
            min = i;
            index = i;
            *s1 = &min;         //��¼����Сֵ���±�
        }
    }
    for (i = 1; i <= k; i++) {
        if ((huf_tree[i].weight == huf_tree[min].weight) && (huf_tree[i].parent == 0) && (i!=index)) { //�����ҵ������ȳ��ֵ���Сֵ
            *s2 = &i;
            break;
        }
        else {          //����������ͬ����Сֵ ֱ���ҵڶ�Сֵ ȷ���±����һ�ε���Сֵ��ͬ
            for (i = 1; i <= k; i++) {
                if ((huf_tree[i].weight < huf_tree[temp].weight) && (huf_tree[i].parent == 0)&&(i!=index)) {
                    temp = i;
                    *s2 = &temp;         //��¼����Сֵ���±�
                }
            }
        }
    }
    printf("s1,s2��ֵ���\n");
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