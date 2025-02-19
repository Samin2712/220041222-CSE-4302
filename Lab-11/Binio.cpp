#include<iostream>
#include<fstream>
#include<string>
using namespace std;
const int MAX=100;
int b[MAX];
int main()
{
    for(int i=0;i<MAX;i++)b[i]=i;
    ofstream ot("FILE.DAT",ios::binary);
    ot.write(reinterpret_cast<char*>(b),MAX*sizeof(int));
    ot.close();
    for(int i=0;i<MAX;i++) b[i]=0;
    ifstream in("FILE.DAT",ios::binary);
    in.read(reinterpret_cast<char*>(b),MAX*sizeof(int));
    in.close();
    for(int i=0;i<MAX;i++)
    {
        if(b[i]!=i)
        {
            cerr<< "Data is incorrect"<<endl;
            return 1;
        }
    }
    cout<< "Data is correct"<<endl;
}