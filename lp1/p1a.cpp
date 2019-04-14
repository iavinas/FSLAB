#include<iostream>
#include<string>
#include<stdlib.h>

using namespace std;
int main()
{
    string name , rev;
    int count , i , j;
    system("clear");
    cout<<"\nEneter the number of names: \n";
    cin>>count;
    for( i = 0; i < count; i++)
    {
        cout<<"\n Enter name: ";
        cin>>name;
        rev.erase();
        for( j = name.length()-1; j >= 0; j--)
        {
            rev += name[j];
        }
        cout<<"\n Reversed "<<rev <<endl;
        
    }

    return 0;
    
}