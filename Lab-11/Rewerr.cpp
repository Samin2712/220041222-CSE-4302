#include<iostream>
#include<fstream>
#include<string>
#include <process.h> 
using namespace std;
const int MAX = 1000;
int b[MAX];
int main()
{
    for(int i=0;i<MAX;i++) b[i]=i;
    ofstream os;
    os.open("a:edata.dat",ios::trunc|ios::binary);
    if(!os)
    {
        cerr<<"Could not open output file"<<endl;
        exit(1); 
    }
    cout<< "Writing..."<<endl;
    os.write(reinterpret_cast<char*>(b),MAX*sizeof(int));
    if(!os)
    {
        cout<< "Could not write to file"<<endl;
        exit(1);
    }
    os.close();
    for(int i=0;i<MAX;i++) b[i]=0;
    ifstream is;
    is.open("a:edata.dat",ios::trunc|ios::binary);
    if(!is)
    {
        cerr<<"Could not open output file"<<endl;
        exit(1); 
    }
    cout<< "Reading..."<<endl;
    is.read(reinterpret_cast<char*>(b),MAX*sizeof(int));
    if(!is)
    {
        cout<< "Could not write to file"<<endl;
        exit(1);
    }
    for(int j=0;j<MAX;j++)
    {
        if(b[j]!=j) cerr << "Data is incorrect"<<endl;
    }
    cout<< "Data is correct"<<endl;
    is.close();
}