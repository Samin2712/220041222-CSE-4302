#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

class Employee
{
private:
    string name;
    int id;
public:
    Employee(string nm,int id):name(nm),id(id){}
    string getName() const {return name;}
    int getId() const {return id;}
    virtual void display() const
    {
        cout<<"Name: "<<name<<" ";
        cout<<"ID: "<<id<<endl;
    }
};

class FullTimeEmployee:public Employee
{
private:
    set<string>workSchedule;
public:
    FullTimeEmployee():Employee("",0){}
    FullTimeEmployee(string nm, int id):Employee(nm,id){}
    void addSchedule(string shed)
    {
        workSchedule.insert(shed);
    }
    set<string> getShed() const
    {
        return workSchedule;
    }
    void display() const override
    {
        Employee::display();
        cout<<"Working Schedules: ";
        for (auto x : workSchedule) cout << x << " ";
        cout<<endl;
    }
};

class PartTimeEmployee:public Employee
{
private:
    set<string> shifts;
public:
    PartTimeEmployee():Employee("",0) {}
    PartTimeEmployee(string nm, int id):Employee(nm, id){}
    void addShift(string shed)
    {
        shifts.insert(shed);
    }
    set<string> getShift() const
    {
        return shifts;
    }
    void display() const override
    {
        Employee::display();
        cout << "Shift Schedules: ";
        for (auto x : shifts) cout << x << " ";
        cout << endl;
    }
};

class EmpManagement
{
private:
    map<int,FullTimeEmployee>fullTimeEmployees;
    map<int,PartTimeEmployee>partTimeEmployees;
public:
    void addEmployee(int id, string name, string type)
    {
        if(fullTimeEmployees.find(id)!=fullTimeEmployees.end()||partTimeEmployees.find(id)!=partTimeEmployees.end())
        {
            cout<< "Same type of id: "<<id<< " peresent in database"<<endl;
            return;
        }
        if (type=="Full-Time")
        {
            fullTimeEmployees[id]=FullTimeEmployee(name,id);
            cout<< "Employee added successfully!"<<endl;
        }
        else if (type=="Part-Time")
        {
            partTimeEmployees[id]=PartTimeEmployee(name,id);
            cout<< "Employee added successfully!"<<endl;
        }
        else
        {
            cout<<"Invalid employee type!"<<endl;
        }
    }
    void assignSchedule(int id, string shed)
    {
        if(fullTimeEmployees.find(id)!=fullTimeEmployees.end())
        {
            fullTimeEmployees[id].addSchedule(shed);
            cout<< "Work schedule assigned successfully!"<<endl;
        }
        else
        {
            cout<<"Employee not found or not a full-time employee!"<<endl;
        }
    }
    void assignShift(int id, string shed)
    {
        if(partTimeEmployees.find(id)!=partTimeEmployees.end())
        {
            partTimeEmployees[id].addShift(shed);
            cout<< "Shift assigned successfully!"<<endl;
        }
        else
        {
            cout << "Employee not found or not a part-time employee!" << endl;
        }
    }
    void displayData() const
    {
        cout << "Full-Time Employees:" << endl;
        for (const auto& x : fullTimeEmployees)
        {
            x.second.display();
            cout << endl;
        }
        cout << "Part-Time Employees:" << endl;
        for (const auto& x : partTimeEmployees)
        {
            x.second.display();
            cout << endl;
        }
    }
    void saveData() const
    {
        ofstream f_emp_file("fulltime_employees.txt");
        ofstream p_emp_file("parttime_employees.txt");
        for (const auto& x:fullTimeEmployees)
        {
            f_emp_file << x.second.getName() << "|" << x.second.getId();
            for (const auto& y : x.second.getShed())
            {
                f_emp_file << "|" << y;
            }
            f_emp_file << endl;
        }
        f_emp_file.close();
        for (const auto& x : partTimeEmployees)
        {
            p_emp_file << x.second.getName() << "|" << x.second.getId();
            for (const auto& y : x.second.getShift())
            {
                p_emp_file << "|" << y;
            }
            p_emp_file << endl;
        }
        p_emp_file.close();
    }
    void loadData() {
        ifstream f_emp_file("fulltime_employees.txt");
        ifstream p_emp_file("parttime_employees.txt");
        string line;
        while (getline(f_emp_file, line))
        {
            istringstream iss(line);
            string em_name, s_id, shed;
            getline(iss, em_name, '|');
            getline(iss, s_id, '|');
            int emp_id = stoi(s_id);
            fullTimeEmployees[emp_id]=FullTimeEmployee(em_name, emp_id);
            while (getline(iss, shed, '|'))
            {
                fullTimeEmployees[emp_id].addSchedule(shed);
            }
        }
        f_emp_file.close();
        while (getline(p_emp_file, line))
        {
            istringstream iss(line);
            string em_name, s_id, shed;
            getline(iss, em_name, '|');
            getline(iss, s_id, '|');
            int emp_id=stoi(s_id);
            partTimeEmployees[emp_id] = PartTimeEmployee(em_name, emp_id);
            while (getline(iss, shed, '|')) {
                partTimeEmployees[emp_id].addShift(shed);
            }
        }
        p_emp_file.close();
    }
};

int main()
{
    EmpManagement emp;
    int choice, id;
    string name, shed, type;
    do{
        cout << "1. Add Employee\n2. Assign Work Schedule\n3. Assign Shift\n4. Display Data\n5. Save Data\n6. Load Data\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1:
                cout << "Enter employee ID: ";
                cin >> id;
                cin.ignore();
                cout << "Enter employee name: ";
                getline(cin, name);
                cout << "Enter employee type (Full-Time/Part-Time): ";
                getline(cin, type);
                emp.addEmployee(id, name, type);
                break;
            case 2:
                cout << "Enter employee ID: ";
                cin >> id;
                cin.ignore();
                cout << "Enter work schedule: ";
                getline(cin, shed);
                emp.assignSchedule(id, shed);
                break;
            case 3:
                cout << "Enter employee ID: ";
                cin >> id;
                cin.ignore();
                cout << "Enter shift timing: ";
                getline(cin, shed);
                emp.assignShift(id, shed);
                break;
            case 4:
                emp.displayData();
                break;
            case 5:
                emp.saveData();
                cout << "Data saved successfully!" << endl;
                break;
            case 6:
                emp.loadData();
                cout << "Data loaded successfully!" << endl;
                break;
            case 7:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 7);
    return 0;
}