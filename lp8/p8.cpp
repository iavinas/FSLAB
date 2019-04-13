#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class coseq
{
	public:
	string list[4][50];
	string olist[50];
	int c1[4], c2[4];
	void l_list();
	void r_file(int i);
	void s_list(int i);
	void merge();
};
void coseq::r_file(int i)
{
	fstream fp;
	char name[100];
	switch(i)
	{
		case 1: fp.open("n1.txt", ios::in); break;
		case 2: fp.open("n2.txt", ios::in); break;
		case 3: fp.open("n3.txt", ios::in); break;
	}
	while(!fp.eof()){
		fp.getline(name, 100,'\n');
		list[i][++c1[i]] = name;
	}
	fp.close();
}
void coseq::s_list(int k) {
	int i,j;
	string t;
	for(i = 1; i<=c1[k]; i++)
		for(j = i+1; j<=c1[k];j++) 
			if(list[k][i] > list[k][j]) {
				t = list[k][i];
				list[k][i] = list[k][j];
				list[k][j] = t;
			}
}
void coseq::l_list()
{
	for(int i=1; i<=3; i++) {
		c1[i] = 0;
		r_file(i);
		s_list(i);
	}
}
void coseq::merge()
{
	string sml;
	int s_list,i,j;
	int strt = 1;
	int t = -1;
	int av_list = 3;
	int avail[4];
	for(i=1; i<=3; i++){
		avail[i] = 1;
		c2[i] = 1;
	}
	while(av_list > 1) {
		if(!avail[strt]) {
			strt++;
			continue;
		}
		s_list = strt;
		sml = list[strt][c2[strt]];
		for(i= strt+1; i<=3;i++) {
			if(!avail[i]) continue;
			if(list[i][c2[i]] < sml) {
				sml = list[i][c2[i]];
				s_list=1;
			}
		}
		c2[s_list]++;
		if(c2[s_list]>c1[s_list]) {
			avail[s_list] = 0;
			av_list--;
		}
		olist[++t] = sml;
		for(j = 1; j<=3;  j++)
			if(j != s_list)
				if(list[j][c2[j]] == sml)
					c2[j]++;
	}
	for(i=1; i <=3; i++)
		if(avail[i])
			for(j=c2[i]; j <=c1[i];j++)
				olist[++t]=list[i][j];
	cout<<"\nMerged list : \n";
	for(i= 0; i <=t;i++){
		if(olist[i]==olist[i+1]) continue;
		cout<<olist[i]<<"\n";
	}
}
int main()
{
	coseq c;
	c.l_list();
	c.merge();
	return 0;
}

