#include<stdio.h>
#include<string.h>
#include<math.h>
#include <stdlib.h>

//学生信息的结构体
typedef struct student
{
        int num;
        char name[20];
        float math;
        float english;
}Student;
//链表的结点
typedef struct node
{
    Student data;
    struct node *next;
}Node;
//链表
typedef struct 
{
    Node *head;     //链表头节点
    Node *list1;    //链表的最后一个元素
    int num;        //链表的元素个数
}NList;
//创建链表数据
void CreatList(NList *list);
//向链表中添加数据
void AddList(NList *list);
//显示结点数据
int Show(Node * node);
//打印链表中的所有数据
void ShowList(NList list);
//查找数据
Node * find(NList list,int num);
//删除结点
void DelNode(NList *list,int num);
//删除链表
void DelList(NList *list);
//菜单选择
int menu();

int main ()
{
    NList list2;
    CreatList(&list2);
    int i = 1;
    while(i)
    {
        switch(menu())
        {
            case 0:
            {
                DelList(&list2);
                i = 0;
                break;
            }
            case 1:
            {
                AddList(&list2);
                break;
            }
            case 2:
            {
                ShowList(list2);
                break;
            }
            case 3:
            {
                printf("请输入要查找的学生的编号：");
                int m = 0;
                scanf("%d",&m);
                if(!Show(find(list2,m))) printf("没有找到该学生信息\n");
                break;
            }
            case 4:
            {
                printf("请输入要删除的学生的编号：");
                int m = 0;
                scanf("%d",&m);
                DelNode(&list2,m);
                break;
            }
            default:
                break;
        }
        getchar();
        printf("等待继续操作");
        getchar();
        system("cls");
    }
    system("cls");
    return 0;
}

//创建链表数据
void CreatList(NList *list)
{
    list->head=NULL;
    list->list1=NULL;
    list->num=0;
}
//向链表中添加数据
void AddList(NList *list)
{
    Student data;
    printf(" 请按下面的格式输入信息：编号|姓名|数学|英语\n");
    scanf("%d%s%f%f",&data.num,&data.name,&data.math,&data.english);
    if(list->head==NULL)
    {
            list->head=(Node*)malloc(sizeof(Node));
            list->head->data=data;
            list->head->next=NULL;
            list->list1=list->head;
            list->num=1;
    }
    else
    {
        Node*p=(Node*)malloc(sizeof(Node));
        list->list1->next = p;
        p->data = data;
        list->list1 = p;
        list->list1->next=NULL;
        list->num++;
    }
}
//显示结点数据
int Show(Node * node)
{
    if(node != NULL)
    {
        printf("|%8d|%9.2s|%12.2f|%12.2f|%12.2f|\n",node->data.num,node->data.name,node->data.math,node->data.english);
        return 1;
    }
    return 0;
}
//打印链表中的所有数据
void ShowList(NList list)
{
    Node *P1;
    P1=list.head;
    while(P1 != NULL)
    {
        Show(P1);
        P1=P1->next;
    }
}
//查找数据
Node * find(NList list,int num)
{
    Node * P1;
    P1=list.head;
    while(P1 != NULL)
    {
        if(P1->data.num == num)
        {
            break;
        }
        P1 = P1->next;
    }  
    return P1;
}
//删除结点
void DelNode(NList *list,int num)
{
    //删除头结点数据
    if(list->head->data.num == num)
    {
        Node *p = list->head;
        list->head = p->next;
        free(p);
        return ;
    }
    //删除后面的数据
    Node *last = list->head;
    Node *now = last->next;
    while(now != NULL)
    {
        if(now->data.num == num)
        {
            last->next = now->next;
            free(now);
            return;
        }
        last = now;
        now = now->next;
    }
}
//删除链表
void DelList(NList * list)
{
    while(list->head= NULL)
    {
        Node * p = list->head;
        list->head = p->next;
        list->num--;
        free(p);
    }
    printf("数据完全清空\n");
}
//菜单
int menu()
{
    printf("****************************成绩管理系统******************************\n");
    printf("*从系统中退出-------------------------------------------------------0*\n");
    printf("*向系统中添加学生信息-----------------------------------------------1*\n");
    printf("*显示系统中所有数据-------------------------------------------------2*\n");
    printf("*从系统中搜索学生信息-----------------------------------------------3*\n");
    printf("*从系统中删除学生信息-----------------------------------------------4*\n");
    printf("**********************************************************************\n");
    printf("请输入：");
    int i = 0;
    scanf("%d",&i);
    return i;
}
