#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int n;
string usn_list[100];
int addr_list[100];
int cnt;
class student
{
	public:
		string usn,name,sem;
		void add_rec(fstream &);
		void get_data();
};
void student::get_data()
{
	cout<<"\nUSN : ";
	cin>>usn;
	cout<<"\nName : ";
	cin>>name;
	cout<<"\nSem : ";
	cin>>sem;
}
void create_index()
{
	void sort_index();
	int pos;
	string buf,urn;
	fstream fp("inp.txt",ios::in);
	cnt=-1;
	while(fp)
	{
		pos=fp.tellg();
		buf.erase();
		getline(fp,buf);
		int i=0;
		if(buf[i]=='*')
			continue;
		urn.erase();
		while(buf[i]!='|')
			urn+=buf[i++];
		usn_list[++cnt]=urn;
		addr_list[cnt]=pos;
	}
	fp.close();
	sort_index();
	for(int i=0;i<cnt;i++)
		cout<<usn_list[i]<<'|'<<addr_list[i]<<'\n';
}
void sort_index()
{
	int t_addr;
	string t_usn;
	cout<<cnt<<'\n';
	for(int i=0;i<cnt-1;i++)
	{
		for(int j=0;j<cnt-1-i;j++)
		{
			if(usn_list[j]>usn_list[j+1])
			{
				t_usn=usn_list[j];
				usn_list[j]=usn_list[j+1];
				usn_list[j+1]=t_usn;
				t_addr=addr_list[j];
				addr_list[j]=addr_list[j+1];
				addr_list[j+1]=t_addr;
			}
		}
	}
}

void student::add_rec(fstream &fp)
{
	fp.seekp(0,ios::end);
	fp<<usn<<'|'<<name<<'|'<<sem<<"\n";
}

int search( string key)
{
  int pos=0,adr,l=0,h=cnt,mid,flag=0;
  string buffer;
  fstream fp("inp.txt",ios::in);
  while(l<=h)
  {
	mid=(l+h)/2;
	if(usn_list[mid]==key)
	{
		flag=1;
		break;
	}
     	if(usn_list[mid]>key)
		h=mid-1;
	if(usn_list[mid]<key)
		l=mid+1;
  }
	if(flag)
	{
		adr=addr_list[mid];
		fp.seekp(adr,ios::beg);
		getline(fp,buffer);
		cout<<"\nFond the record "<<buffer;
		cout<<' ' <<mid<<"mid\n";
		return mid;
	}
	else
	{
		cout<<"\nNot found";
		return -1;
	}
}

void del_rec(string key)
{
	int pos,adr;
	fstream fp;
	pos=search(key);
	adr=addr_list[pos];
	if(pos !=-1)
	{
		fp.open("inp.txt",ios::out | ios::in);
		fp.seekp(adr,ios::beg);
		fp.put('*');
		cout<<"\nRecord added!";
		fp.close();
		for(int i=pos;i<cnt;i++)
		{
			usn_list[i]=usn_list[i+1];
			addr_list[i]=addr_list[i+1];
		}
		cnt--;

	}
	else
		cout<<"\n Record not found!";
}
int main()
{
	student s[100];
	string key;
	fstream fp;
	for(;;)
	{
	int ch;
		cout<<"\nenter ur choice \n1.add rec\n2. show index\n3.search\n4. delete\n5. exit";
		cin>>ch;
		switch(ch)
		{
			case 1: 
				fp.open("inp.txt", ios::out);
				cout<<"enter how many records\n";
				cin>>n;
				for(int i=0; i<n; i++)
				{
					s[i].get_data();
					s[i].add_rec(fp);
				}
				fp.close();
				break;

			case 2: create_index();
				break;

			case 3: cout<<"enter key of record to searched\n";
				cin>>key;
				search(key);
				break;

			case 4: cout<<"enter key of record to deleted\n";
				cin>>key;
				del_rec(key);
				break;

			case 5: exit(0);
		}
	}
	return 0 ;
}



