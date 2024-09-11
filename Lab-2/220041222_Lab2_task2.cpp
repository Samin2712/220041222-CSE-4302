#include<bits/stdc++.h>
using namespace std;
enum etype {laborer, secretary, manager, accountant, executive, researcher};
int main()
{
    char s;
    etype a;
     cout << "Enter employee type (first letter only)" << endl;
     cout << "(l=laborer, s=secretary, m=manager,\na=accountant, e=executive, r=researcher): ";
     cin >> s;
     switch (s)
     {
     case 'l':
        a=laborer;
        break;
    case 's':
        a=secretary;
        break;
    case 'm':
        a=manager;
        break;
    case 'a':
        a=accountant;
        break;
    case 'e':
        a=executive;
        break;
    case 'r':
        a=researcher;
        break;
     
     default:
        break;
     }
     cout<< "Employee Type: ";
     switch(a)
     {
     case laborer:
        cout<< "laborer";
        break;
    case secretary:
        cout<< "secretary";
        break;
    case manager:
        cout<< "manager";
        break;
    case accountant:
        cout<< "accountant";
        break;
    case executive:
        cout<< "executive";
        break;
    case researcher:
        cout<< "researcher";
        break;
     
     default:
     cout<< "Invalid Type";
        break;
     }
}