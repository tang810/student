#include<iostream>
#include<cstring>
#include<cstdlib>
#include "list.h"

using namespace std;

int seat;    //通讯录成员的序号


LinkList List::CreatIncreLink() 
{ 
	LinkList L= new LNode; 
	L->next=NULL;
	LinkList p;
	int num=1,number;
	int telenum;
	char name[20];

	cout<<"请输入学生学号，姓名和电话号码，建立通讯录，以‘-1’为输入结束标志"<<endl;
     cout<<"请输入学号"<<num<<":";
	 cin>>number;   
	 cout<<"请输入姓名 "<<num<<":";
	 cin>>name;
	 cout<<"请输入电话号码"<<num<<":";
	cin>>telenum; 

	while(number>=0)
	{
	  p= new LNode;
	  p->number=number;
	  p->telenum=telenum;
	  strcpy(p->name,name);
	  InsertYouXu(L,p);   
	  num++;
	  cout<<"请输入学号"<<num<<":";
	  cin>>number;
	  cout<<"请输入姓名"<<num<<":";
	  cin>>name;
	  cout<<"请输入电话号码"<<num<<":";
	  cin>>telenum;
	}
	return(L);
}


void List::DeleteELem(LinkList L,int i)
{
	LinkList p=L;
	int j=0;
	while (p->next && j<i-1)
	{
	  p = p->next;
	  j++;
	}
	if(!(p->next))  //判断i是否合fa 
	{
	  cout<<"第"<<i<<"个元素删除失败"<<endl;
	  return;
	}
	LinkList q=p->next;
	p->next = q->next;
	delete q;
}

//按姓名删除通讯者
int List::DelMsg(LinkList L,char n[])
{
 int flag=0;   //判断要删除的通讯者和通讯录中的姓名是否匹配
 LinkList p=L->next;
 seat=1;
 if(L->next==NULL)
	 cout<<"该链表中没有元素，查找失败"<<endl;
 else
 {
   while(p != NULL)
   {
    if(!strcmp(p->name,n))//比较输入的姓名和通讯录中的名字
    {
      flag=1;
	 cout<<"p->name";
	 p=p->next;
	 List::DeleteELem(L,seat);
    }
    else
    {
	    p=p->next;
	    seat++;
    }                    
	 //输入姓名不匹配
   }
   if(flag)
	   cout<<"被删除"<<endl;
 }
 return flag;
}

//按学号删除通讯者
int List::DelMsg(LinkList L,int n)
{
  int flag=0;  //判断要删除的通讯者和通讯录中的学号是否匹配
  LinkList p=L->next;
  seat =1;
  if(L->next==NULL)
	  cout<<"该链表中没有元素，删除失败"<<endl;
  else
  {
    while(p !=NULL)
    {
      if(p->number<=n)
	 {
	   if(p->number == n)
	   {
	    flag =1; //输入学号匹配
	    cout<<"   "<<p->number;
	    p=p->next;
		List::DeleteELem(L,seat);
	   }
	   break;
	 }
	 else
	 {
	   p=p->next;
	   seat++;
	 }
	 cout<<"被删除"<<endl;
    }
  }
   return flag;
}

//插入一个元素，使原有序表仍为有序
void List::InsertYouXu(LinkList L,LinkList Elem)
{
 LinkList p=L->next;
 while(p !=NULL && Elem->number>=p->number)
 { if(p->number == Elem->number)
	 {
	  cout<<"重复输入！！"<<endl;
	  return;
	 }
	 p=p->next;  //确定Elem插入的位置
 }
 if(p==NULL)
 {
	 p=prior(L,p);
	 Elem->next=NULL;
	 p->next=Elem;
 }
 else
 {
	 p=prior(L,p);
	 Elem->next=p->next;
	 p->next=Elem;
 }
}

//打印头结点地址为L的通讯录
void List::PrintList(LinkList L)
{
 cout<<"\n           --------------------------------\n"; 
 cout<<"           序号   学号     姓名     电话号码\n";
 cout<<"           ---------------------------------\n"; 
 LinkList p=L;
 int n=1;
 if(L==NULL || L->next==NULL)
	 cout<<"该通讯录中没有元素"<<endl;
 else
	 while(p->next != NULL)
	 {
	   cout<<"            "<<n<<"      "<<p->next->number<<"      ";
	   cout<<p->next->name<<"    "<<p->next->telenum<<endl;
	   p=p->next;
	   n++;
	 }
	 cout<<"           ---------------------------------\n";
	 return;
}

LinkList List::prior(LinkList L,LinkList p)
{
 if(L->next==NULL)
	 return (L);
 LinkList p_prior=L;
 while(p_prior->next != p)
	 p_prior=p_prior->next;
 return (p_prior);
}
//按姓名查找通讯者
int List::Search(LinkList L,char n[])
{
  int flag=0;   //标志要查找的通讯录中的姓名是否匹配
  LinkList p=L->next;
  seat=1;
  if(L->next==NULL || L==NULL)
	  cout<<"该通讯录中没有元素，查找失败"<<endl;
  else
  {
	  while(p !=NULL)
	  {
         if(!strcmp(p->name,n))  //比较要查找的姓名是否和当前通讯录所指姓名匹配
	    {
	       flag=1;
	       cout<<"要查找的是第"<<seat<<"位通讯者："<<endl;
		   cout<<"学号： "<<p->number<<"   姓名："<<p->name<<"  电话号码.："<<p->telenum<<endl;
	    }
	    p=p->next;
	    seat++;
	  }
  }
  return flag;
}

//按学号查找通讯者
int List::Search(LinkList L,int n)
{
  int flag=0;   //标志要查找的通讯者和通讯录中的学号是否匹配
  LinkList p=L->next;
  seat=1;
  if(L->next==NULL)
	  cout<<"该链表中没有元素，查找失败"<<endl;
  else
  {
     while(p !=NULL)
	{
	  if(p->number<=n)
		  if(p->number==n)
		  {
		    flag=1;     
		    cout<<"要查找的是第"<<seat<<"位通讯者："<<endl;
		    cout<<"学号： "<<p->number<<"  姓名："<<p->name<<"  电话号码.："<<p->telenum<<endl;
		  }
		  p=p->next;
		  seat++;
	}	
  }
  return flag;
}
