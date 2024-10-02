#include <iostream>
#include "Employee.h"
#include<ctime>
#include<bits/stdc++.h>
using namespace std;
void EditInformationByKeyboard(Employee &emp)
{
    string name;
    std::tm dobInput={};
    double salary;
    cout << "Enter employee name: ";
    cin>>name;
    cout << "Enter Date of Birth (yyyy mm dd): ";
    cin>>dobInput.tm_year>>dobInput.tm_mon>>dobInput.tm_mday;
    dobInput.tm_year-=1900;
    dobInput.tm_mon-=1;
    cout << "Enter salary: ";
    cin >> salary;
    emp.setInfo(name,dobInput,salary);
}
string generateRandomString(int length) {
    string randomString;
    const char alphabet[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int alphabetSize = sizeof(alphabet) - 1;

    for (int i=0;i<length;++i) {
        randomString += alphabet[rand()%alphabetSize];
    }

    return randomString;
}
int randomInRange(int mn, int mx)
{
    return rand()%(mx-mn+1)+mn;
}
void generateInformationRandom(Employee &employee)
{
    string randomName=generateRandomString(4)+ " " +generateRandomString(5);
    //employee.setName(randomName);
    std::tm dob={};
    dob.tm_year=randomInRange(1970,2002)-1900;
    dob.tm_mon=randomInRange(1,12)-1;
    dob.tm_mday=randomInRange(1,28);
    //employee.setDateOfBirth(dob);
    double salary = randomInRange(10000,100000);
    //employee.setSalary(salary);
    employee.setInfo(randomName,dob,salary);
}
void ShowAllBasedOnAge(Employee ar[], int n)
{
    sort(ar,ar+n,[](const Employee &a, const Employee &b){
        return a.getAge() > b.getAge();
    });
    for (int i=0;i<n;++i)
    {
        ar[i].getInfo();
        cout<<endl;
    }
}
int main()
{
    srand(static_cast<unsigned int>(time(0)));
     const int EMPLOYEE_NUM= 100;
    Employee employees[EMPLOYEE_NUM];
    for (int i=0;i<2;i++)
    {
        cout<< "Get information for employee "<<i+1<< ": "<<endl;
        EditInformationByKeyboard(employees[i]);
    }
    for (int i=2;i<EMPLOYEE_NUM;i++)
    {
        generateInformationRandom(employees[i]);
    }
    ShowAllBasedOnAge(employees,EMPLOYEE_NUM);
    return 0;
}
