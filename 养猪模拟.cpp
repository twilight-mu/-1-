using namespace std;
#include<bits/stdc++.h>
struct pig
{
	int species; //黑猪为1 小花猪为2 大白花猪为3 
	int id; 	//编号 
	int gday; 	//成长天数 
	int gmonth; //成长月份 (每月都按30天计算,一年360天) 
	int isInfected; //被感染为1 没被感染为2 
	double weight; //体重 
	pig *next;
};
class pigsty
{
	private:
		pig *head;
		int isblack;
		int sum;
	public:
		pigsty();				//初始化 
		int getspecies(int i);	//获取种类信息 
		int getgday(int i);		//获取成长天数信息 
		double getweight(int i);//获取重量 
		double getprice();		//获取价钱
		void print();			//打印猪圈信息 
		void clear();			//清空猪圈 
		void addpig(pig*p);		//加猪 
		void setisblack(int i);	//设置黑猪圈,1为黑猪圈，0为非黑猪圈 
		int getisblack();		//获取猪圈是否为黑猪圈 
		int getspecies1();		//获取黑猪数		
		int getspecies2();		//获取小花猪数 
		int getspecies3();		//获取大白花猪数 
};
pigsty::pigsty()
{
	int sum=0;
	int isblack=0;
	head=NULL;
}
int pigsty::getspecies(int i) 
{
	pig *p=head;
	for(int k=0;k<i&&p!=NULL;k++)
	{
		p=p->next;
	}
	return p->species;
}
int pigsty::getgday(int i)
{
	int sumday;
	pig *p=head;
	for(int k=0;k<i&&p!=NULL;k++)
	{
		p=p->next;
	}
	sumday=p->gmonth*30+p->gday;
	return sumday;
}
double pigsty::getweight(int i)
{
	pig *p=head;
	for(int k=0;k<i&&p!=NULL;k++)
	{
		p=p->next;
	}
	return p->weight;
}
double pigsty::getprice()
{
	double price=0;
	if(head==0)	//空猪圈返回0 
	return 0;
	int month,day,flag=0;
	pig *p=head,*p1=p;
	while(p)
	{
		int sumday;
		sumday=p->gmonth*30+p->gday;
		if(sumday>=360||p->weight>75)
		{
			if(sum==1) //只有一头猪，清空猪圈 
			{
			setisblack(0); 
			head=NULL;
			delete p;
			sum--;
			break;
			}
			if(p->species==1)
			{
			price+=30*p->weight;
			}
			if(p->species==2)
			{
			price+=14*p->weight;
			}
			if(p->species==3)
			{
			price+=12*p->weight;
			}
			p1->next=p->next;
			delete p;
			p=p1->next;
			sum--;
			continue;
		}
		else if(flag==0)
		{
		flag=1;
		head=p;
		}
		p1=p;
		p=p1->next;
	}
	return price;
}
int pigsty::getspecies1()
{
	int count;
	pig *p=head;
	for(int k=0;k<sum&&p!=NULL;k++)
	{
		if(p->species==1)
		count++;
		p=p->next;
	}
	return count;
}
int pigsty::getspecies2()
{
	int count;
	pig *p=head;
	for(int k=0;k<sum&&p!=NULL;k++)
	{
		if(p->species==2)
		count++;
		p=p->next;
	}
	return count;
}
int pigsty::getspecies3()
{
	int count;
	pig *p=head;
	for(int k=0;k<sum&&p!=NULL;k++)
	{
		if(p->species==3)
		count++;
		p=p->next;
	}
	return count;
}
int main()
{
	return 0;
}
