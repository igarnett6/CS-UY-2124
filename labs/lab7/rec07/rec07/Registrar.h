
#pragma once
#include <iostream>
#include <string>
#include <vector>
namespace BrooklynPoly {
	class Student;
	class Course;
	class Registrar {
		friend std::ostream& operator<<(std::ostream& os, const Registrar& rhs);
	public:
		Registrar() {};
		bool addCourse(const std::string& courseName);
		bool addStudent(const std::string& studentName);
		bool enrollStudentInCourse(const std::string& studentName, const std::string& courseName);
		bool cancelCourse(const std::string& courseName);
		void purge();

	private:
		size_t findStudent(const std::string& student) const;
		size_t findCourse(const std::string& course) const;

		std::vector<Course*> courses;
		std::vector<Student*> students;
	};
}