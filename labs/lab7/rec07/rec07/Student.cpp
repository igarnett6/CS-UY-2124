#include "Student.h"
#include "Course.h"
namespace BrooklynPoly {
	std::ostream& operator<<(std::ostream& os, const Student& rhs) {
		os << std::endl << rhs.name << ": ";
		if (rhs.courses.size() != 0) {
			for (size_t i = 0; i < rhs.courses.size(); i++) {
				os << rhs.courses[i]->getName() << " ";
			}
		}
		else { os << "No courses."; }

		return os;
	};
	Student::Student(const std::string& name) : name(name), courses(std::vector<Course*>()) {}
	const std::string& Student::getName() const { return name; }
	bool Student::addCourse(Course* newCourse) {
		bool courseIsNew = true;
		for (size_t i = 0; i < courses.size(); i++) {
			if (newCourse == courses[i]) {
				courseIsNew = false;
				break;
			}
		}
		if (courseIsNew) {
			courses.push_back(newCourse);
			return true;
		}
		return false;
	}
	void Student::removedFromCourse(Course* removedCourse) {
		for (size_t i = 0; i < courses.size(); i++) {
			if (courses[i] == removedCourse) {
				//size_t lastInd = courses.size() - 1;
				courses[i] = courses.back();
				courses.pop_back();
				break;
			}
		}
	}
}