using namespace std;
#include<bits/stdc++.h>
struct pig
{
	int species; //����Ϊ1 С����Ϊ2 ��׻���Ϊ3 
	int id; 	//��� 
	int gday; 	//�ɳ����� 
	int gmonth; //�ɳ��·� (ÿ�¶���30�����,һ��360��) 
	int isInfected; //����ȾΪ1 û����ȾΪ2 
	double weight; //���� 
	pig *next;
};
class pigsty
{
	private:
		pig *head;
		int isblack;
		int sum;
	public:
		pigsty();				//��ʼ�� 
		int getspecies(int i);	//��ȡ������Ϣ 
		int getgday(int i);		//��ȡ�ɳ�������Ϣ 
		double getweight(int i);//��ȡ���� 
		double getprice();		//��ȡ��Ǯ
		void print();			//��ӡ��Ȧ��Ϣ 
		void clear();			//�����Ȧ 
		void addpig(pig*p);		//���� 
		void setisblack(int i);	//���ú���Ȧ,1Ϊ����Ȧ��0Ϊ�Ǻ���Ȧ 
		int getisblack();		//��ȡ��Ȧ�Ƿ�Ϊ����Ȧ 
		int getspecies1();		//��ȡ������		
		int getspecies2();		//��ȡС������ 
		int getspecies3();		//��ȡ��׻����� 
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
	if(head==0)	//����Ȧ����0 
	return 0;
	int month,day,flag=0;
	pig *p=head,*p1=p;
	while(p)
	{
		int sumday;
		sumday=p->gmonth*30+p->gday;
		if(sumday>=360||p->weight>75)
		{
			if(sum==1) //ֻ��һͷ�������Ȧ 
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
