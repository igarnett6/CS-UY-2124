#pragma once

#include <iostream>
#include <string>
#include <vector>
namespace BrooklynPoly {
	class Student;

	class Course {
		friend std::ostream& operator<<(std::ostream& os, const Course& rhs);
	public:
		// Course methods needed by Registrar
		Course(const std::string& name);
		const std::string& getName() const;
		bool addStudent(Student* newStudent);
		void removeStudentsFromCourse();
	private:
		std::string name;
		std::vector<Student*> students;
	};
}