#pragma once
#include <string>
#include "degree.h"

using namespace std;

class Student {

private:

    string StudentID;
    string FirstName;
    string LastName;
    string EmailAddress;
    int Age;
    int DaysInCourse[3];
    DegreeProgram degreeProgram;

public:


    Student(string StudentID, string FirstName, string LastName, string EmailAddress, int Age, int daysInCourse[], DegreeProgram degreeprogram);


    // Accessors
    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmailAddress();
    int getAge();
    int* getDaysInCourse();
    DegreeProgram getDegreeProgram();

    // Mutators
    void setStudentID(string student_id);
    void setFirstName(string first_name);
    void setLastName(string last_name);
    void setEmailAddress(string email);
    void setAge(int age);
    void setDaysInCourse(int, int);
    void setDegreeProgram(DegreeProgram degree);

    void print();


};