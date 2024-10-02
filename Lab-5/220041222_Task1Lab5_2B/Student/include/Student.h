#ifndef STUDENT _H
#define STUDENT _H
#include<string>
using namespace std;

class Student
{
    private:
        string student_name;
        string Department;
        string Program;
        string Section;
        int Admission_year;
        string Address;
        double gpa;
        string student_id;
        float quiz1;
        float quiz2;
        float quiz3;
        float quiz4;
        float mid_tearm_marks;
        float final_marks;
        float attendence_mark;
        float GPA;
        static int idCounter;
    public:
        Student ();
        void setStudentName(const string &name);
        string getStudentName() const;
        void setDepartmentName(const string &dpt);
        string getDepartmentName() const;
        void setProgramName(const string &prog);
        string getProgramName() const;
        void setSectionName(const string &sec);
        string getSectionName() const;
        void setAdmission_year(int year);
        int getAdmission_year() const;
        void setAddress(const string &add);
        string getAddress() const;
        void setquiz1(float qz1);
        float getquiz1() const;
        void setquiz2(float qz2);
        float getquiz2() const;
        void setquiz3(float qz3);
        float getquiz3() const;
        void setquiz4(float qz4);
        float getquiz4() const;
        void setmid_tearm(float mid);
        float getmid_tearm() const;
        void setfinal_marks(float f_mark);
        float getfinal_marks() const;
        void setattendence_mark(float att_mark);
        float getattendence_mark() const;
        void setgpa(float gpa);
        float getgpa() const;
        float calculateGPA(float quiz1,float quiz2,float quiz3,float quiz4,float mid_tearm_marks,float final_marks,float attendence_mark);
        void generateid();
        string getStudentID() const;
        void displayInfo() const;
};

#endif // STUDENT _H
