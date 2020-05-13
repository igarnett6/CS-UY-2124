/*Isaiah Garnett
rec05, student grade tracking*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class Section {
	class TimeSlot {
	public:
		/*friend ostream& operator<<(ostream& os, TimeSlot& thisTimeData);*/
		TimeSlot(const string& weekday, const unsigned& time) : weekday(weekday), time(time) {}


		ostream& display(ostream& os) const {
			unsigned locTime = (this->time % 12);
			string timeOfDay;
			if (this->time > 12) { timeOfDay = "pm"; }
			else { timeOfDay = "am"; }
			os << ", Time Slot: [Day: " << weekday << ", Start Time: " << locTime << timeOfDay << "]";
			return os;
		}

		unsigned getTime() const { return time; }
		string getDay() const { return weekday; }
	private:
		const string weekday;
		const unsigned time;
	};


	class StudentRecord {
	public:
		StudentRecord(const string& name) : name(name), grades({ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,-1,-1,-1,-1 }){}
		ostream& display(ostream& os) const {
			os << "Name: " << name << ", Grades: ";
			for (double grade : grades) {
				os << grade << " ";
			}
			os << endl;
			return os;
		}
		void addGrade(double newGrade, int weekNum) { grades[weekNum] = newGrade; }
		string getName() const { return name; }
		vector<double> getGrades() { return grades; }
	private:
		vector<double> grades;
		const string name;
	};


	
public:
	Section(const Section& existingSection) : name(existingSection.getName()), timeData(existingSection.timeData), students(existingSection.students) {}
	Section(const string& name, const string& weekday, const unsigned& time) : name(name), timeData(weekday, time) {}

	ostream& display(ostream& os) const {
		os << "Section: " << name;
		timeData.display(os);
		os << "Students: ";
		if (students.size() == 0) {
			os << "None";
		}
		else {
			os << endl;
			for (size_t i = 0; i < students.size(); i++) {
				students[i]->display(os);
			}
		}
		return os;
	}

	ostream& displayStudents(ostream& os) const {
		for (size_t i = 0; i < students.size(); i++) {
			os << students[i];
		}
		return os;
	}



	

	void addGrade(const string& studentName, double grade, int week) {
		for (StudentRecord* student : students) {
			if (student->getName() == studentName) {
				student->addGrade(grade, week);
			}
		}
	}

	string getName() const { return name; }

	void addStudent(const string& name) {
		StudentRecord* newStudent;
		newStudent = new StudentRecord(name);
		students.push_back(newStudent);
	}

	TimeSlot getTimeData() const { return timeData; }


	~Section() {
		for (StudentRecord* currStudent : students) {
			delete &currStudent;		}
		students.clear();
	}

private:

	TimeSlot timeData;
	const string name;
	vector<StudentRecord*> students;

};


class LabWorker {
public:
	friend ostream& operator<< (ostream& os, const LabWorker& thisWorker);
	LabWorker(LabWorker& existingWorker) : name(existingWorker.getName()), section(existingWorker.section) {}
	LabWorker(const string& name) : name(name), section(nullptr) {}

	ostream& display(ostream& os) const {
		if (section != nullptr) {
			os << name << " has ";
			section->display(os);
			return os;
		}
		else {
			os << name << " does not have a section." << endl;
			return os;
		}

	}

	void addGrade(const string& studentName, double grade, int week) {
		if (section != nullptr) {
			section->addGrade(studentName, grade, week);
		}
	}


	string getName() const { return name; }
	Section* getSection() const { return section; }
	void addSection(Section& section) { this->section = &section; }
	void clearSection() { this->section = nullptr; }
private:
	const string name;
	Section* section;
};


ostream& operator<< (ostream& os, const LabWorker& thisWorker) {
	return thisWorker.display(os);

}

ostream& operator<< (ostream& os, const Section& thisSection) {
	return thisSection.display(os);
}


 //Test code
void doNothing(Section sec) { cout << sec << endl; }

int main() {

	cout << "Test 1: Defining a section\n";
	Section secA2("A2", "Tuesday", 16);
	cout << secA2 << endl;

	cout << "\nTest 2: Adding students to a section\n";
	 secA2.addStudent("John");
	 secA2.addStudent("George");
	 secA2.addStudent("Paul");
	 secA2.addStudent("Ringo");
	 cout << secA2 << endl;

	cout << "\nTest 3: Defining a lab worker.\n";
	 LabWorker moe( "Moe" );
	 cout << moe << endl;

	cout << "\nTest 4: Adding a section to a lab worker.\n";
	 moe.addSection( secA2 );
	 cout << moe << endl;

	cout << "\nTest 5: Adding a second section and lab worker.\n";
	 LabWorker jane( "Jane" );
	 Section secB3( "B3", "Thursday", 11 );
	 secB3.addStudent("Thorin");
	 secB3.addStudent("Dwalin");
	 secB3.addStudent("Balin");
	 secB3.addStudent("Kili");
	 secB3.addStudent("Fili");
	 secB3.addStudent("Dori");
	 secB3.addStudent("Nori");
	 secB3.addStudent("Ori");
	 secB3.addStudent("Oin");
	 secB3.addStudent("Gloin");
	 secB3.addStudent("Bifur");
	 secB3.addStudent("Bofur");
	 secB3.addStudent("Bombur");
	 jane.addSection( secB3 );
	 cout << jane << endl;

	cout << "\nTest 6: Adding some grades for week one\n";
	 moe.addGrade("John", 17, 1);  
	 moe.addGrade("Paul", 19, 1);  
	 moe.addGrade("George", 16, 1);  
	 moe.addGrade("Ringo", 7, 1);  
	 cout << moe << endl;

	cout << "\nTest 7: Adding some grades for week three (skipping week 2)\n";
	 moe.addGrade("John", 15, 3);  
	 moe.addGrade("Paul", 20, 3);  
	 moe.addGrade("Ringo", 0, 3);  
	 moe.addGrade("George", 16, 3);  
	 cout << moe << endl;

	cout << "\nTest 8: We're done (almost)! \nWhat should happen to all "
		<< "those students (or rather their records?)\n";

	cout << "\nTest 9: Oh, IF you have covered copy constructors in lecture, "
		<< "then make sure the following call works:\n";
	 doNothing(secA2);
	 cout << "Back from doNothing\n\n";

} // main