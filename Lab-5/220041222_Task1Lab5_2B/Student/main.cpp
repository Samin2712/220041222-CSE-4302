#include<iostream>
#include<cstdlib>
#include<bits/stdc++.h>
#include<string>
#include "Student.h"
void EditInformationByKeyboard(Student &students)
{
    string name,dept,prog,sec,address;
    int add_year;
    cout<< "Enter student name: ";
    cin>>name;
    students.setStudentName(name);

    cout<< "Enter department name: ";
    cin>>dept;
    students.setDepartmentName(dept);

    cout<< "Enter programmee name: ";
    cin>>prog;
    students.setProgramName(prog);

    cout<< "Enter section name: ";
    cin>>sec;
    students.setSectionName(sec);

    cout<< "Enter Admission year: ";
    cin>>add_year;
    students.setAdmission_year(add_year);
    cin.ignore();
    cout<< "Enter Address: ";
    getline(cin,address);
    students.setAddress(address);
    students.generateid();
    float q1=rand()%5;
    float q2=rand()%5;
    float q3=rand()%5;
    float q4=rand()%5;
    float mid=rand()%25;
    float final_mar=rand()%50;
    float att=rand()%3;
    students.setquiz1(q1);
    students.setquiz2(q2);
    students.setquiz3(q3);
    students.setquiz4(q4);
    students.setmid_tearm(mid);
    students.setfinal_marks(final_mar);
    students.setattendence_mark(att);
    float gp=students.calculateGPA(students.getquiz1(),students.getquiz2(),students.getquiz3(),students.getquiz4(),students.getmid_tearm(),students.getfinal_marks(),students.getattendence_mark());
    students.setgpa(gp);

}
void generateInformaiotnRandom(Student &students)
{
    string departments[] = {"CSE", "ME", "EEE"};
    string programs[] = {"BSc", "MSc", "PhD"};
    string sections[] = {"A", "B", "C"};
    int year=rand()%4+2020;
    string name="random";
    students.setStudentName(name);
    students.setDepartmentName(departments[rand()%3]);
    students.setProgramName(programs[rand()%3]);
    students.setSectionName(sections[rand()%3]);
    string address="Random Address";
    students.setAddress(address);
    students.generateid();
    float q1=rand()%5;
    float q2=rand()%5;
    float q3=rand()%5;
    float q4=rand()%5;
    float mid=rand()%25;
    float final_mar=rand()%50;
    float att=rand()%3;
    students.setquiz1(q1);
    students.setquiz2(q2);
    students.setquiz3(q3);
    students.setquiz4(q4);
    students.setmid_tearm(mid);
    students.setfinal_marks(final_mar);
    students.setattendence_mark(att);
    float gp=students.calculateGPA(students.getquiz1(),students.getquiz2(),students.getquiz3(),students.getquiz4(),students.getmid_tearm(),students.getfinal_marks(),students.getattendence_mark());
    students.setgpa(gp);
}
void ShowAllAlphabetically(Student student[],int n)
{
   sort(student,student+n, [](Student &a, Student &b){
        return a.getStudentID()<b.getStudentID();
        });
        for(int i=0;i<n;i++)
        {
            student[i].displayInfo();
        }
}
using namespace std;
int main()
{
    const int student_num=100;
    Student student[student_num];
    for(int i=0;i<2;i++)
    {
        cout<< "Enter details for student information "<<i+1<<": "<<endl;
        EditInformationByKeyboard(student[i]);
    }
    for(int i=2;i<student_num;i++)
    {
        generateInformaiotnRandom(student[i]);
    }
    ShowAllAlphabetically(student,student_num);
}
