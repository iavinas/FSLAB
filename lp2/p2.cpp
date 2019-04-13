#include<iostream>
#include<string>
#include<fstream>
#include<cstring>
using namespace std;

void search();

class Student
{
	public:
		string urn;
		string name;
		string sem;
		string Buf;
		char buf[46];
		int pack();
		void write_f(fstream &);
		void unpack();
		void print(ostream &);
		void read_f(fstream &);
};

int Student::pack()
{
	
	Buf=urn+"|"+name+"|"+sem+"|";
	if(Buf.length()>45)
		return 0;
	while(Buf.length()<45)
		Buf+="_";
	Buf+="\0";
	return 1;
}

void Student::write_f(fstream &fp)
{
	fp.flush();
	fp<<Buf<<'\n';
	fp.flush();
}

void Student::print(ostream & stream)
{
	stream<<"Student"<<"\t URN"<<urn<<"\n"<<"\t Name:"<<name<<"\n\t Sem:"<<sem;
}
void Student::unpack()
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
		if(count==1)urn=stg;
		if(count==2)name=stg;
		if(count==3)sem=stg;
	}
}

void Student:: read_f(fstream &fp)
{
	char sg[55];
	fp.getline(buf,46,'_');
	fp.getline(sg,50,'\n');
}

int main()
{
	int ch,x;
	Student s;
	fstream fp;
	do
	{
		cout<<"Enter your choice\n";
		cout<<"1.Insert\n2.Search and Modify\n3.Exit\n";
		cin>>ch;
		switch(ch)
		{
			case 1:	fp.open("in.txt",ios::out | ios::app);
				cout<<"Enter URN => ";
				cin>>s.urn;
				cout<<"Enter name => ";
				cin>>s.name;
				cout<<"Enter Sem => ";
				cin>>s.sem;
				int k ;
				k = s.pack();
				if(k==0)
				{
					cout<<"Invalid data\n";
				}
				else
					s.write_f(fp);
				fp.close();
				break;
			case 2:	search();
				break;
			case 3: exit(1);
		}
	}
	while(ch<=3);

	return 0;
}

void search()
{
	int c=0,choice;
	string usn;
	Student s[1100];
	fstream fp1;
	fp1.open("in.txt",ios::in);
	cout<<"Enter the URN to be searched => ";
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
		cout<<"Record not found\n";
		return;
	}
	else
	{
		cout<<"Record found\n";
		s[i].print(cout);
		do
		{
			cout<<"Enter your choice\n";
			cout<<"URN => "<<s[i].urn<<"\n";
			cout<<"1.Name => "<<s[i].name<<"\n2.Sem => "<<s[i].sem<<"\n3.Exit\n";
			cout<<"Enter your choice(1,2,3)";
			cin>>choice;
			switch(choice)
			{
				case 1:	cout<<"Enter new name => ";
					cin>>s[i].name;
					break;
				case 2:	cout<<"Enter new sem => ";
					cin>>s[i].sem;
					break;
				case 3: break;
				default: cout<<"Wrong choice, please enter a valid choice\n";
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
