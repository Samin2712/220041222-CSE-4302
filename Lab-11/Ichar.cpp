#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
    char c;
    ifstream in("TEST.TXT");
    while(in)
    {
        in.get(c);
        cout<<c;
    }
    cout<<endl;
}