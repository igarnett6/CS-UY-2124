#include "Course.h"
#include "Student.h"
namespace BrooklynPoly {
	std::ostream& operator<<(std::ostream& os, const Course& rhs) {
		os << std::endl << rhs.name << ": ";
		if (rhs.students.size() != 0) {
			for (size_t i = 0; i < rhs.students.size(); i++) {
				os << rhs.students[i]->getName() << " ";
			}
		}
		else { os << "No students."; }
		return os;
	}
	Course::Course(const std::string& name) : name(name) {}
	const std::string& Course::getName() const { return name; }
	bool Course::addStudent(Student* newStudent) {
		bool studentIsNew = true;
		for (size_t i = 0; i < students.size(); i++) {
			if (newStudent == students[i]) {
				studentIsNew = false;
				break;
			}
		}
		if (studentIsNew) {
			students.push_back(newStudent);
			newStudent->addCourse(this);
			return true;
		}
		return false;
	}
	void Course::removeStudentsFromCourse() {
		for (Student* student : students) {
			student->removedFromCourse(this);
		}
		students.clear();
	}
}