#include "Student.h"
#include<iostream>
#include<string>
#include<bits/stdc++.h>
Student ::Student():student_name("unknown"),Department("unknown"),Program("unknown"),Section("unknown"),Admission_year(2020),Address("unknown"),gpa(0.0){}
int Student::idCounter=0;
void Student ::setStudentName(const string &name)
{
    student_name=name;
}
string Student::getStudentName() const{return student_name;}

void Student ::setDepartmentName(const string &dpt)
{
    Department=dpt;
}
string Student::getDepartmentName() const{return Department;}

void Student ::setProgramName(const string &prog)
{
    Program=prog;
}
string Student::getProgramName() const{return Program;}
void Student ::setSectionName(const string &sec)
{
    Section=sec;
}
string Student::getSectionName() const{return Section;}

void Student ::setAdmission_year(int year)
{
    Admission_year=year;
}
int Student::getAdmission_year() const{return Admission_year;}

void Student ::setAddress(const string &add)
{
    Address=add;
}
string Student::getAddress() const{return Address;}

void Student ::setquiz1(float qz1)
{
    quiz1=qz1;
}
float Student::getquiz1() const{return quiz1;}

void Student ::setquiz2(float qz2)
{
    quiz2=qz2;
}
float Student::getquiz2() const{return quiz2;}

void Student ::setquiz3(float qz3)
{
    quiz3=qz3;
}
float Student::getquiz3() const{return quiz3;}

void Student ::setquiz4(float qz4)
{
    quiz4=qz4;
}
float Student::getquiz4() const{return quiz4;}

void Student ::setmid_tearm(float mid)
{
    if(mid<=25) mid_tearm_marks=mid;
    else mid_tearm_marks=25;
}
float Student::getmid_tearm() const{return mid_tearm_marks;}

void Student ::setfinal_marks(float f_mark)
{
    if(f_mark<=50) final_marks=f_mark;
    else final_marks=50;
}
float Student::getfinal_marks() const{return final_marks;}

void Student ::setattendence_mark(float att_mark)
{
    attendence_mark=att_mark;
}
float Student::getattendence_mark() const{return attendence_mark;}
void Student::setgpa(float gpa)
{
    GPA=gpa;
}
float Student::getgpa() const{return GPA;}
float Student::calculateGPA(float quiz1,float quiz2,float quiz3,float quiz4,float mid_tearm_marks,float final_marks,float attendence_mark)
{
    float total_number=0,min_num,gpa;
    min_num=min(quiz1,quiz2);
    min_num=min(min_num,quiz3);
    if(min_num==quiz1) total_number+=max(quiz1,quiz4);
    else total_number+=quiz1;
    if(min_num==quiz2) total_number+=max(quiz2,quiz4);
    else total_number+=quiz2;
    if(min_num==quiz3) total_number+=max(quiz3,quiz4);
    else total_number+=quiz3;
    total_number+=mid_tearm_marks+final_marks+attendence_mark;
    if(total_number>=80) GPA=5.00;
    else if(total_number>=70&&total_number<80)gpa=4.00;
    else if(total_number>=60&&total_number<70)gpa=3.50;
    else if(total_number>=50&&total_number<60)gpa=3.00;
    else if(total_number>=30&&total_number<50)gpa=2.00;
    else gpa=0.00;
    GPA=gpa;
    return gpa;
}
void Student::generateid()
{
    string deptCode,sec;
    if (Department == "CSE")
    {
        deptCode = "41";
    }
    else if (Department == "ME")
    {
        deptCode = "34";
    }
    else if (Department == "EEE")
    {
        deptCode = "42";
    }
    else
    {
        deptCode = "00";
    }
    if(Section=="A") sec="1";
    else if(Section=="B") sec="2";
    else if(Section=="C") sec="3";
    idCounter++;
    string clac_str = (idCounter < 10) ? "0" + to_string(idCounter):to_string(idCounter);
    student_id=to_string(Admission_year).substr(2,2)+"00"+deptCode+sec+clac_str;
}
string Student::getStudentID() const {return student_id;}
void Student::displayInfo() const
{
    cout<<"Student Name: " <<student_name<< endl;
    cout<<"ID: " << student_id << endl;
    cout<<"Department: " << Department << endl;
    cout<<"Program: " << Program << endl;
    cout<<"Section: " << Section << endl;
    cout<<"Admission Year: " << Admission_year << endl;
    cout<<"Address: " << Address << endl;
    cout<<fixed << setprecision(2) << "GPA: " << GPA << endl;
}
