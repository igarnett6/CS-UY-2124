
#include "Registrar.h"
#include "Course.h"
#include "Student.h"
namespace BrooklynPoly {

	std::ostream& operator<<(std::ostream& os, const Registrar& rhs) {
		os << "Registrar's Report" << std::endl;
		os << "Courses: ";
		for (size_t i = 0; i < rhs.courses.size(); i++) {
			os << *rhs.courses[i];
		}
		os << std::endl;
		os << "Students: ";
		for (size_t i = 0; i < rhs.students.size(); i++) {
			os << *rhs.students[i];
		}
		os << std::endl;
		return os;
	}
	bool Registrar::addCourse(const std::string& courseName) {
		if (findCourse(courseName) == courses.size()) {
			Course* newCourse = new Course(courseName);
			courses.push_back(newCourse);
			return true;
		}
		return false;
	}
	bool Registrar::addStudent(const std::string& studentName) {
		bool studExists = false;
		size_t sInd = findStudent(studentName);
		if (sInd != this->students.size()) { studExists = true; }
		if (!studExists) {
			Student* newStudent = new Student(studentName);
			students.push_back(newStudent);
			return true;
		}
		return false;
	}
	bool Registrar::enrollStudentInCourse(const std::string& studentName, const std::string& courseName) {
		bool studExists = false;
		bool courseExists = false;
		size_t cInd = findCourse(courseName);
		if (cInd != courses.size()) { courseExists = true; }
		size_t sInd = findStudent(studentName);
		if (sInd != students.size()) { studExists = true; }
		if (studExists && courseExists) {
			size_t sInd = findStudent(studentName);
			if (sInd == students.size()) { return false; }
			size_t cInd = findCourse(courseName);
			if (cInd == courses.size()) { return false; }
			return courses[cInd]->addStudent(students[sInd]);
		}
		return false;
	}
	bool Registrar::cancelCourse(const std::string& courseName) {
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
	size_t Registrar::findStudent(const std::string& student) const {
		for (size_t i = 0; i < students.size(); i++) {
			if (students[i]->getName() == student) {
				return i;
			}
		}
		return students.size();
	}
	size_t Registrar::findCourse(const std::string& course) const {
		for (size_t i = 0; i < courses.size(); i++) {
			if (courses[i]->getName() == course) {
				return i;
			}
		}
		return courses.size();
	}
}