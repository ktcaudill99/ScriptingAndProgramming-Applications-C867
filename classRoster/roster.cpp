#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include "roster.h"


Roster::Roster() {
	classRosterArray[4] = {};
	parseCounter = 0;
	numStudents = 5;
}



Roster::~Roster() { 
	for (int i = 0; i < 5; ++i) {
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}


void Roster::parse(string studentArray[]) {
	for (int i = 0; i < numStudents; ++i) {
		string my_str = studentArray[i];
		vector<string> result;
		DegreeProgram degree;
		istringstream s_stream(my_str);


		while (s_stream.good()) {
			string substr;
			getline(s_stream, substr, ',');
			result.push_back(substr);
		}

		
		if (result.at(8) == "SECURITY") {
			degree = SECURITY;
		}

		else if (result.at(8) == "NETWORK") {
			degree = NETWORK;
		}

		else if (result.at(8) == "SOFTWARE") {
			degree = SOFTWARE;
		}


		this->add(result.at(0), result.at(1), result.at(2), result.at(3), stoi(result.at(4)), stoi(result.at(5)), stoi(result.at(6)), stoi(result.at(7)), degree);
		parseCounter = parseCounter + 1;
	}
}


void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1,
				int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram) {
	int daysInCourse[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	classRosterArray[parseCounter] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeprogram);
}

void Roster::remove(string studentID) {
	cout << "Removing " << studentID << endl;
	for (int i = 0; i < numStudents; ++i) {
		if (classRosterArray[i] == nullptr) {
			cout << "Student " << studentID << " was not found." << endl;
		}

		else if (classRosterArray[i]->getStudentID() == studentID) {
			delete classRosterArray[i];
			classRosterArray[i] = nullptr;
		}
	}
}


void Roster::printAll()
{
	for (int i = 0; i < parseCounter; i++) {
		if (classRosterArray[i] == nullptr) {
		}
		else {
			classRosterArray[i]->print();
		}
	}
}

void Roster::printAverageDaysInCourse(string studentID) {


	for (int i = 0; i < parseCounter; i++) {
		string sID = classRosterArray[i]->getStudentID();

		if (classRosterArray[i]->getStudentID() == studentID) {

			int course1 = classRosterArray[i]->getDaysInCourse()[0];
			int course2 = classRosterArray[i]->getDaysInCourse()[1];
			int course3 = classRosterArray[i]->getDaysInCourse()[2];

			cout << "Student ID: " << classRosterArray[i]->getStudentID() << " average days in courses is : " << (course1 + course2 + course3) / 3;
			cout << endl;
		}

	}

}

void Roster::printInvalidEmails() {

	cout << "Invalid emails: " << endl;

	for (int i = 0; i < parseCounter; ++i) {


		string emailCheck = classRosterArray[i]->getEmailAddress();
		if (emailCheck.find(' ') != string::npos) {
			cout << emailCheck << " - reason: no spaces allowed." << endl;
		}

		else if (emailCheck.find('.') == string::npos) {
			cout << emailCheck << " - reason: missing period." << endl;
		}

		else if (emailCheck.find('@') == string::npos) {
			cout << emailCheck << " - reason: missing @ symbol." << endl;
		}
	}
}


void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {

	string degreeProgramString; //convert degreeprogram into string
	if (degreeProgram == SOFTWARE) {
		degreeProgramString = "SOFTWARE";
	}

	else if (degreeProgram == NETWORK) {
		degreeProgramString = "NETWORK";
	}

	else if (degreeProgram == SECURITY) {
		degreeProgramString = "SECURITY";
	}
	cout << "Showing students in degree program: " << degreeProgramString << endl;

	for (int i = 0; i < 5; ++i) {
		DegreeProgram checkDegree;
		checkDegree = classRosterArray[i]->getDegreeProgram();
		if (checkDegree == degreeProgram) {
			classRosterArray[i]->print();
			
		}
	}

}

