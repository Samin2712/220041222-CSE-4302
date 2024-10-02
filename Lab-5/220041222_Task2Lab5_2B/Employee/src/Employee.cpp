#include "Employee.h"
#include<string>
#include<ctime>
#include<iostream>
using namespace std;
Employee::Employee():name("John Doe"),date_of_birth(def_date_of_birth()),salary(10000.0){}
tm Employee::def_date_of_birth()
{
    tm tmp={};
    tmp.tm_year=102;
    tmp.tm_mon=0;
    tmp.tm_mday=1;
    return tmp;
}
void Employee::setName(const string &nm)
{
   if(nm.size()>2) name=nm;
   else name="John Doe";
}
string Employee::getName() const{return name;}

void Employee::setDateOfBirth(const tm &tmp)
{
   time_t present=time(nullptr);
   tm *curr=localtime(&present);
   int curr_year=curr->tm_year+1900;
   int emp_year=tmp.tm_year+1900;
   if(curr_year-emp_year>18) date_of_birth=tmp;
   else date_of_birth=def_date_of_birth();
}
tm Employee::getDateOfBirth() const{return date_of_birth;}

void Employee::setSalary(double s)
{
    if (s>=10000&&s<=100000) salary=s;
    else salary=10000.0;
}
double Employee::getSalary() const{return salary;}

int Employee::getAge() const
{
    time_t present=time(nullptr);
    tm *current=localtime(&present);
    int currentYear=current->tm_year+1900;
    return currentYear-(date_of_birth.tm_year+1900);
}
const Employee& Employee::compareAge(const Employee &e) const
{
    if(this->getAge()>=e.getAge()) return *this;
    else return e;
}
void Employee::setInfo(const string &name,const tm &tmp,double salary)
{
    setName(name);
    setDateOfBirth(tmp);
    setSalary(salary);
}
void Employee::getInfo() const
{
    cout<<"Name: "<<getName()<<endl;
    cout<<"Date of Birth: "<<(getDateOfBirth().tm_year+1900)<< "-"
              <<(getDateOfBirth().tm_mon+1)<< "-"
              <<getDateOfBirth().tm_mday<<endl;
    cout<<"Salary: "<<getSalary()<< endl;
    cout<< "Age: "<< getAge()<<endl;
}
