#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
    string s="There are many people in our country."
               "I love my country";
    ofstream ot("TEST.TXT");
    for(int i=0;i<s.size();i++) ot.put(s[i]);
    cout<< "File is written"<<endl;
}