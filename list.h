#include<iostream>
#include<string>

typedef struct LNode  //结构体
{
	int number;
	int telenum;
    char name[20];//string name;
    struct LNode *next;
}LNode,*LinkList;

class List
{
public:
	List(){};//构造函数
	~List(){};//析构函数
	LinkList CreatIncreLink();//建立链表
	void DeleteELem(LinkList L,int i);//从通讯录中按序号删除第i个元素
	int DelMsg(LinkList L,char n[]);//按姓名删除通讯者记录
	int DelMsg(LinkList L,int n);//重载函数delMsg()，按学号删除通讯者记录
	void InsertYouXu(LinkList L,LinkList Elem);//有序的插入一条通讯记录
	LinkList prior(LinkList L,LinkList p);
	void PrintList(LinkList L);//打印指针地址为L的通讯录1
	int Search(LinkList L,char n[]);//按姓名查找通讯者记录
	int Search(LinkList L,int n);//重载函数Search()按学号查找通讯者记录
};
