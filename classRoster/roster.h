#include <iostream>
#include <cstring>
#include "student.h"
using namespace std;

class Roster {


private:

	int parseCounter; 
	int numStudents = 5;

public: 

	Roster();
	~Roster();




	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1,
		int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeprogram);
	void parse(string studentData[]);

	Student* classRosterArray[5];


};

