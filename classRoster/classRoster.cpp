// classRoster.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "roster.h"
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;




int main()
{
  //  std::cout << "Hello World!\n";

    //Print out First Info
    cout << endl;
    cout << "Course Title: Scripting and Programming - Applications - C867";
    cout << endl;
    cout << "Programming Language: C++";
    cout << endl;
    cout << "Student ID: 005252042";
    cout << endl;
    cout << "Name: Katherine Caudill";
    cout << endl;

    const int rosterSize = 5;


    //Student data
    string studentData[5] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Katherine,Caudill,kcaud33@wgu.edu,21,40,28,22,SOFTWARE"
    };


    Roster classRoster;


    DegreeProgram degreeProgram;

    classRoster.parse(studentData);


    string studentID;


 //  classRoster.printAll();
    cout << endl << "Stuents in roster:" << endl;
    classRoster.printAll();
    cout << endl;


 //   classRoster.printInvalidEmails();
    classRoster.printInvalidEmails();
    cout << endl;

 //loop through classRosterArray and for each element:

 //classRoster.printAverageDaysInCourse(/*current_object's student id*/);
 // classRoster.printAverageDaysInCourse(classRoster.getStudentID);
    cout << "Avarage Days in course by student ID:";
    cout << endl;
    for (int i = 0; i < 5; ++i) {
        classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
    }
    cout << endl;

 //Note: For the current_object's student id, use an accessor (i.e., getter) for the classRosterArray to access the student id.


 //classRoster.printByDegreeProgram(SOFTWARE);
    classRoster.printByDegreeProgram(SOFTWARE);

//classRoster.remove("A3");
    cout << endl; 
    classRoster.remove("A3");
    cout << endl;
//classRoster.printAll();
    cout << "New roster";
    cout << endl;
    classRoster.printAll();
//classRoster.remove("A3");
    cout << endl;
    classRoster.remove("A3");

//expected: the above line should print a message saying such a student with this ID was not found.
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
