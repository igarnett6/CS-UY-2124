#include "Registrar.h"


ostream& operator<<(ostream& os, const Registrar& rhs) {
	os << "Registrar's Report" << endl;
	os << "Courses: ";
	for (size_t i = 0; i < rhs.courses.size(); i++) {
		os << *rhs.courses[i];
	}
	os << endl;
	os << "Students: ";
	for (size_t i = 0; i < rhs.students.size(); i++) {
		os << *rhs.students[i];
	}
	os << endl;
	return os;
}
bool Registrar::addCourse(const string& courseName) {
	if (findCourse(courseName) != courses.size()) {
		Course* newCourse = new Course(courseName);
		courses.push_back(newCourse);
		return true;
	}
	return false;
}
bool Registrar::addStudent(const string& studentName) {
	if (findStudent(studentName) != students.size()) {
		Student* newStudent = new Student(studentName);
		students.push_back(newStudent);
		return true;
	}
	return false;
}
bool Registrar::enrollStudentInCourse(const string& studentName, const string& courseName) {
	size_t sInd = findStudent(studentName);
	size_t cInd = findCourse(courseName);
	if ((sInd != students.size()) && (cInd != courses.size())) {
		return courses[cInd]->addStudent(students[sInd]);
	}
	else return false;
}
bool Registrar::cancelCourse(const string& courseName) {
	if (findCourse(courseName)) {
		size_t cInd = findCourse(courseName);
		courses[cInd]->removeStudentsFromCourse();
		return true;
	}
	return false;
}
void Registrar::purge() {
	for (size_t i = 0; i < courses.size(); i++) {
		delete courses[i];
	}
	courses.clear();
	for (size_t i = 0; i < students.size(); i++) {
		delete students[i];
	}
	students.clear();
}
size_t Registrar::findStudent(const string& student) const {
	for (size_t i = 0; i < students.size(); i++) {
		if (students[i]->getName() == student) {
			return i;
		}
	}
	return students.size();
}
size_t Registrar::findCourse(const string& course) const {
	for (size_t i = 0; i < courses.size(); i++) {
		if (courses[i]->getName() == course) {
			return i;
		}
	}
	return courses.size();
}