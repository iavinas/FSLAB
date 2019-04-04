#include<fstream>
#include<string>
#include<iostream>
#include<cstring>
using namespace std;
class student
{
	public:
		string urn;
		string name;
		string sem;
		string Buf;
		char buf[100];
		void pack();
		void write_f(fstream &);
		void unpack();
		void print(ostream &);
		void read_f(fstream &);
};
void student::pack()
{
Buf=urn+"|"+name+"|"+sem+"\n";
}
void student::write_f(fstream &fp)
{
	fp<<Buf;
}
void student::print(ostream &stream)
{
	stream<<"student:"
               <<"\t urn'"<<urn<<"'\n"
		<<"\t name'"<<name<<"'\n"
		<<"\t sem'"<<sem<<"'\n";
}
void student::unpack()
{
	char stg[100];
	int pos=0,count=0,k;
	while(count<3)
	{
		k=0;
		for(int i=pos;i<strlen(buf);i++,k++)
		{
			stg[k]=buf[i];
			pos++;
			if(buf[i]=='|')
				break;
		}

		stg[k]='\0';
		count++;
		if(count==1) urn=stg;
		if(count==2) name=stg;
		if(count==3) sem=stg;
	}
}
void student::read_f(fstream &fp)
{
	fp.getline(buf,100,'\n');
}
int main()
{
	int ch;
	fstream fp;
	void search();
	student s;
	system("clear");
	do
	{
		cout<<"enter your choice\n";
		cout<<"1.insert a record\n"
			<<"2.search and modify a record\n"
			<<"3.exit\n";
		cin>>ch;
		switch(ch)
		{
			case 1:fp.open("in.txt",ios::out|ios::app);
				cout<<"enter urn";
				cin>>s.urn;
				cout<<"enter name";
				cin>>s.name;
				cout<<"enter sem";
				cin>>s.sem;
				s.pack();
				s.write_f(fp);
				fp.close();
				break;
			case 2:search();
				break;
			case 3:exit(1);
		}
	}
	while(ch<=3);
}
void search()
{
	int c=0,choice;
	string usn;
	student s[100];
	fstream fp1;
	fp1.open("in.txt",ios::in);
	cout<<"enter the usn of the student to be searched and modified\n";
	cin>>usn;
	int cnt=0;
	int i=0;
	while(fp1)
	{
		s[i].read_f(fp1);
		s[i].unpack();
		i++;
	}
	fp1.close();
	cnt=i-1;
	for(i=0;i<cnt;i++)
	{
		if(s[i].urn==usn)
		{
			c++;
			break;
		}
	}
	if(c==0)
	{
		cout<<"record not found\n";
		return;
	}
	else
	{
		cout<<"record found\n";
		s[i].print(cout);
		do
		{
			cout<<"\n\t enter your choice of field to  be modified";
			cout<<"\n\n\t urn=>\t"<<s[i].urn
                        <<"\n\n\t 1.name=>\t"<<s[i].name
			<<"\n\n\t 2.semester=>\t"<<s[i].sem
		        <<"\n\n\t3.exit";
			cout<<"\n\n\t choice=>";
			cin>>choice;
			switch(choice)
			{
				case 1:cout<<"enter the name=>";
					cin>>s[i].name;
					break;
				case 2:cout<<"enter the semester=>";
					cin>>s[i].sem;
					break;
				case 3:break;
				default:cout<<"\n\t\t\t invalid entry!"<<endl;
					break;
			}
		}
		while(choice!=3);
		fp1.open("in.txt",ios::out);
		for(i=0;i<cnt;i++)
		{
			s[i].pack();
			s[i].write_f(fp1);
		}
		fp1.close();
	}
}	
	
