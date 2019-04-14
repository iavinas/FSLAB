#include<iostream>
#include<string.h>
#include<fstream>
#include<stdlib.h>

using namespace std;

int main()
{
    string name , rev;
    char infile[30] , outfile[30];
    fstream fpinp , fpoutp;

    int j;
    system("clear");
    cout<<"Enter the input filename\n";
    cin>>infile;
    cout<<"Enter the output filename\n";
    cin>>outfile;
    fpinp.open(infile , ios::in);
    fpoutp.open(outfile , ios::out);
    if(!fpinp || !fpoutp)
    {
        cout<<"FATAL ERROR! Unable to open the files";
        exit(0);
    }

    while(fpinp){
        getline(fpinp , name);
        rev.erase();
        for(j= name.length()-1 ; j>= 0 ; j--)
        {
            rev += name[j];
        }
        fpoutp<<rev<<endl;
    }
    fpinp.close();
    fpoutp.close();
    return 0;
}