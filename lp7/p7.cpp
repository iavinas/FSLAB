#include<iostream>
#include<string>
#include<fstream>
#include<ctype.h>
using namespace std;



class conseq
{
	public:
		string list1[100],list2[100];
		int c1,c2;
		void l_list();
		void s_list();
		void match();
};
void conseq::l_list()
{
	fstream fp;
	char name[100];
	c1=-1;c2=-1;
	fp.open("a1.txt",ios::in);
	while(fp)
	{
		fp.getline(name,100,'\n');
		list1[++c1]=name;
	}
	fp.close();
	fp.open("a2.txt",ios::in);
	while(fp)
	{
		fp.getline(name,100,'\n');
		list2[++c2]=name;
	}
	fp.close();
}
void conseq::s_list()
{
	int i,j;
	string temp;
	for(i=0;i<=c1;i++)
	{
		for(j=i+1;j<=c1;j++)
		{
			if(list1[i]>list1[j])
			{
				temp=list1[i];
				list1[i]=list1[j];
				list1[j]=temp;
			}
		}
	}
	for(i=0;i<=c2;i++)
	{
		for(j=i+1;j<=c2;j++)
		{
			if(list2[i]>list2[j])
			{
				temp=list2[i];
				list2[i]=list2[j];
				list2[j]=temp;
			}
		}
	}
}
void conseq::match()
{
	int i=0,j=0;
	while(i<=c1&&j<=c2)
	{
		if(list1[i]==list2[j])
		{
			cout<<"\n"<<list1[i];
			i++;
			j++;
		}
		if(list1[i]<list2[j])
			i++;
		if(list1[i]>list2[j])
			j++;
	}
}
int main()
{
	conseq c;
	c.l_list();
	c.s_list();
	c.match();
	return 0;
}