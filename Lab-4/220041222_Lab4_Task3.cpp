#include <iostream>
#include <string>
using namespace std;
class Employee
{
private:
    string EmpName;
    int ID;
    int Age;
    float Salary;
    string getStatus()
    {
        if(Age<=25)
        {
            if(Salary<=20000) return "Low Salaried Person";
            else return "Moderate Salaried Person";
        }
        else
        {
            if(Salary<=21000) return "Low Salaried Person";
            else if(Salary<=60000)return "Moderate Salaried Person";
            else return "High Salaried Person";
        }
    }

public:
    void FeedInfo(string name,int id,int age,int salary)
    {
        EmpName=name;
        ID=id;
        Age=age;
        Salary=salary;
    }
    void ShowInfo()
    {
        cout<<"Employee Name: "<<EmpName<<endl;
        cout<<"Employee ID: "<<ID<<endl;
        cout<<"Employee Age: "<<Age<<endl;
        cout<<"Employee Salary: "<<Salary<<endl;
        cout<<"Status: "<<getStatus()<<endl;
    }
};

int main()
{
    Employee employee;
    string name;
    int id,age,salary;
    cout<<"Enter Employee Name: ";
    getline(cin,name);
    cout<<"Enter Employee ID: ";
    cin>>id;
    cout<<"Enter Employee Age: ";
    cin>>age;
    cout<<"Enter Employee Salary: ";
    cin>>salary;
    cin.ignore(); 
    employee.FeedInfo(name,id,age,salary);
    employee.ShowInfo();
    return 0;
}
