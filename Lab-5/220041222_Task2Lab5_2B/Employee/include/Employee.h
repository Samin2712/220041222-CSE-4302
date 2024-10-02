#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include<string>
#include<ctime>
using namespace std;
class Employee
{
    private:
        string name;
        tm date_of_birth;
        double salary;
        static tm def_date_of_birth();

    public:
        Employee();
        //tm def_date_of_birth();
        void setName(const string &nm);
        string getName() const;
        void setDateOfBirth(const tm &tmp);
        tm getDateOfBirth() const;
        void setSalary(double s);
        double getSalary() const;
        int getAge() const;
        const Employee& compareAge(const Employee &e) const;
        void setInfo(const string &name,const tm &tmp,double salary);
        void getInfo() const;
};

#endif // EMPLOYEE_H
