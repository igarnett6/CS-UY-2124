/*
Isaiah Garnett
  rec07
  Starter Code for required functionality
  Yes, you may add other methods.
 */

//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
//class Student;
//class Course;


//class Course {
//	friend ostream& operator<<(ostream& os, const Course& rhs);
//public:
//	// Course methods needed by Registrar
//	Course(const string& name);
//	const string& getName() const;
//	bool addStudent(Student* newStudent);
//	void removeStudentsFromCourse();
//private:
//	string name;
//	vector<Student*> students;
//};
//class Student {
//	friend ostream& operator<<(ostream& os, const Student& rhs);
//public:
//	// Student methods needed by Registrar
//	Student(const string& name);
//	const string& getName() const;
//	bool addCourse(Course* newCourse);
//
//	// Student method needed by Course
//	void removedFromCourse(Course* removedCourse);
//
//private:
//	string name;
//	vector<Course*> courses;
//};
//class Registrar {
//	friend ostream& operator<<(ostream& os, const Registrar& rhs);
//public:
//	Registrar() {};
//	bool addCourse(const string& courseName);
//	bool addStudent(const string& studentName);
//	bool enrollStudentInCourse(const string& studentName, const string& courseName);
//	bool cancelCourse(const string& courseName);
//	void purge();
//
//private:
//	size_t findStudent(const string& student) const;
//	size_t findCourse(const string& course) const;
//
//	vector<Course*> courses;
//	vector<Student*> students;
//};



//course methods and output op
//ostream& operator<<(ostream& os, const Course& rhs) {
//	os << endl << rhs.name << ": ";
//	if (rhs.students.size() != 0) {
//		for (size_t i = 0; i < rhs.students.size(); i++) {
//			os << rhs.students[i]->getName() << " ";
//		}
//	}
//	else { os << "No students."; }
//	return os;
//}
//Course::Course(const string& name) : name(name) {}
//const string& Course::getName() const { return name; }
//bool Course::addStudent(Student* newStudent) {
//	bool studentIsNew = true;
//	for (size_t i = 0; i < students.size(); i++) {
//		if (newStudent == students[i]) {
//			studentIsNew = false;
//			break;
//		}
//	}
//	if (studentIsNew) {
//		students.push_back(newStudent);
//		newStudent->addCourse(this);
//		return true;
//	}
//	return false;
//}
//void Course::removeStudentsFromCourse() {
//	for (Student* student : students) {
//		student->removedFromCourse(this);
//	}
//	students.clear();
//}
//course methods and output op


//student methods and output op
//ostream& operator<<(ostream& os, const Student& rhs) {
//	os << endl << rhs.name << ": ";
//	if (rhs.courses.size() != 0) {
//		for (size_t i = 0; i < rhs.courses.size(); i++) {
//			os << rhs.courses[i]->getName() << " ";
//		}
//	}
//	else { os << "No courses."; }
//
//	return os;
//};
//Student::Student(const string& name) : name(name), courses(vector<Course*>()) {}
//const string& Student::getName() const { return name; }
//bool Student::addCourse(Course* newCourse) {
//	bool courseIsNew = true;
//	for (size_t i = 0; i < courses.size(); i++) {
//		if (newCourse == courses[i]) {
//			courseIsNew = false;
//			break;
//		}
//	}
//	if (courseIsNew) {
//		courses.push_back(newCourse);
//		return true;
//	}
//	return false;
//}
//void Student::removedFromCourse(Course* removedCourse) {
//	for (size_t i = 0; i < courses.size(); i++) {
//		if (courses[i] == removedCourse) {
//			//size_t lastInd = courses.size() - 1;
//			courses[i] = courses.back();
//			courses.pop_back();
//			break;
//		}
//	}
//}
//student methods and output op


//registrar methods and output op
//ostream& operator<<(ostream& os, const Registrar& rhs) {
//	os << "Registrar's Report" << endl;
//	os << "Courses: ";
//	for (size_t i = 0; i < rhs.courses.size(); i++) {
//		os << *rhs.courses[i];
//	}
//	os << endl;
//	os << "Students: ";
//	for (size_t i = 0; i < rhs.students.size(); i++) {
//		os << *rhs.students[i];
//	}
//	os << endl;
//	return os;
//}
//bool Registrar::addCourse(const string& courseName) {
//	if (findCourse(courseName) != courses.size()) {
//		Course* newCourse = new Course(courseName);
//		courses.push_back(newCourse);
//		return true;
//	}
//	return false;
//}
//bool Registrar::addStudent(const string& studentName) {
//	if (findStudent(studentName) != students.size()) {
//		Student* newStudent = new Student(studentName);
//		students.push_back(newStudent);
//		return true;
//	}
//	return false;
//}
//bool Registrar::enrollStudentInCourse(const string& studentName, const string& courseName) {
//	size_t sInd = findStudent(studentName);
//	size_t cInd = findCourse(courseName);
//	if ((sInd != students.size()) && (cInd != courses.size())) {
//		return courses[cInd]->addStudent(students[sInd]);
//	}
//	else return false;
//}
//bool Registrar::cancelCourse(const string& courseName) {
//	if (findCourse(courseName)) {
//		size_t cInd = findCourse(courseName);
//		courses[cInd]->removeStudentsFromCourse();
//		return true;
//	}
//	return false;
//}
//void Registrar::purge() {
//	for (size_t i = 0; i < courses.size(); i++) {
//		delete courses[i];
//	}
//	courses.clear();
//	for (size_t i = 0; i < students.size(); i++) {
//		delete students[i];
//	}
//	students.clear();
//}
//size_t Registrar::findStudent(const string& student) const {
//	for (size_t i = 0; i < students.size(); i++) {
//		if (students[i]->getName() == student) {
//			return i;
//		}
//	}
//	return students.size();
//}
//size_t Registrar::findCourse(const string& course) const {
//	for (size_t i = 0; i < courses.size(); i++) {
//		if (courses[i]->getName() == course) {
//			return i;
//		}
//	}
//	return courses.size();
//}
//registrar methods and output op




//int main() {
//
//	Registrar registrar;
//
//	cout << "No courses or students added yet\n";
//	cout << registrar << endl;
//
//	cout << "AddCourse CS101.001\n";
//	registrar.addCourse("CS101.001");
//	cout << registrar << endl;
//
//	cout << "AddStudent FritzTheCat\n";
//	registrar.addStudent("FritzTheCat");
//	cout << registrar << endl;
//
//	cout << "AddCourse CS102.001\n";
//	registrar.addCourse("CS102.001");
//	cout << registrar << endl;
//
//	cout << "EnrollStudentInCourse FritzTheCat CS102.001\n";
//	registrar.enrollStudentInCourse("FritzTheCat", "CS102.001");
//	cout << "EnrollStudentInCourse FritzTheCat CS101.001\n";
//	registrar.enrollStudentInCourse("FritzTheCat", "CS101.001");
//	cout << registrar << endl;
//
//	cout << "EnrollStudentInCourse Bullwinkle CS101.001\n";
//	cout << "Should fail, i.e. do nothing, "
//		<< "since Bullwinkle is not a student.\n";
//	registrar.enrollStudentInCourse("Bullwinkle", "CS101.001");
//	cout << registrar << endl;
//
//	cout << "CancelCourse CS102.001\n";
//	registrar.cancelCourse("CS102.001");
//	cout << registrar << endl;
//
//	/*
//	// [OPTIONAL - do later if time]
//	cout << "ChangeStudentName FritzTheCat MightyMouse\n";
//	registrar.changeStudentName("FritzTheCat", "MightyMouse");
//	cout << registrar << endl;
//
//	cout << "DropStudentFromCourse MightyMouse CS101.001\n";
//	registrar.dropStudentFromCourse("MightyMouse", "CS101.001");
//	cout << registrar << endl;
//
//	cout << "RemoveStudent FritzTheCat\n";
//	registrar.removeStudent("FritzTheCat");
//	cout << registrar << endl;
//	*/
//
//	cout << "Purge for start of next semester\n";
//	registrar.purge();
//	cout << registrar << endl;
//}

