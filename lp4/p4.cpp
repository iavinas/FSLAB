#include<iostream>
#include<string>
#include<fstream>
#include<stdlib.h>
#include <cstring>

using namespace std;
char st_no[5];
int no;
class record
{
	public:
		char usn[20];
		char name[20];
		char sem[2];
}
rec[20];
void retrieve_details()
{
	fstream file2;
	char name[20],usn[20],rrn[5],sem[5];
	file2.open("record.txt",ios::in);
	for(int i=0;i<no;i++)
	{
		file2.getline(rrn,5,'|');
		file2.getline(usn,20,'|');
		file2.getline(name,20,'|');
		file2.getline(sem,5,'\n');
		if(strcmp(rrn,st_no)==0)
		{
			cout<<"\n\n"<<"student details are:";
			cout<<"\n\nusn:"<<usn<<"\nname:"<<name<<"\nsem:"<<sem<<"\n";
		}
	}
	file2.close();
}
int main()
{
	fstream file1,file2;
	int ch;
	char rt_usn[20],st_rrn[20];
	char ind[2],name[20],sem[2];
	int i,flag,flag1;
	file1.open("index.txt",ios::out);
	file2.open("record.txt",ios::out);
	if(!file1||!file2)
	{
		cout<<"file creation error!\n";
		exit(0);
	}
	for(;;)
	{
		cout<<"\n1:add record"<<"\n2:search record";
		cin>>ch;
		switch(ch)
		{
			case 1:cout<<"enter the no of students:";
				cin>>no;
				cout<<"enter the details:\n";
				for(i=1;i<=no;i++)
				{
					cout<<"\nname:";
					cin>>rec[i].name;
					cout<<"usn:";
					cin>>rec[i].usn;
					cout<<"sem:";
					cin>>rec[i].sem;
					file1<<rec[i].usn<<"|"<<i<<"\n";
					file2<<i<<"|"<<rec[i].usn<<"|"<<rec[i].name<<"|"<<rec[i].sem<<"\n";
				}
				file1.close();
				file2.close();
				break;
			case 2:cout<<"enter rrn whose record is to be displayed:";
				cin>>st_rrn;
				file1.open("index.txt",ios::in);
				if(!file1)
				{
					cout<<"\nerror!\n";
					exit(0);
				}
				flag1=0;
				for(i=0;i<no;i++)
				{
					file1.getline(rt_usn,20,'|');
					file1.getline(st_no,4,'\n');
					if(strcmp(st_rrn,st_no)==0)
					{
						retrieve_details();
						flag1=1;
					}
				}
				if(!flag1)
					cout<<"record search failed!\n";
					file1.close();
					break;
			default : cout<<"invalid choice";
				exit(0);
				break;
			
		}
	}
}
