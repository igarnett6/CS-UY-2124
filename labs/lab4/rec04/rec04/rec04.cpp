/*Isaiah Garnett
rec04 tasks*/

#include<iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
	int x;
	x = 10;
	cout << "x = " << x << endl;
	int* p;
	p = &x;
	//p = 0x012ff740;
	*p = -2763;
	cout << "p = " << p << endl;
	cout << "p points to where " << *p << "is stored\n";
	cout << "*p contatins " << *p << endl;
	int y(13);
	cout << "y contains " << y << endl;
	p = &y;
	cout << "p now points ot where " << *p << " is stored\n";
	cout << "*p now contains " << *p << endl;
	*p = 980;
	cout << "p points to where " << *p << " is stored\n";
	cout << "*p now contains " << *p << endl;
	cout << "y now contains " << y << endl;
	int* q;
	q = p;
	cout << "q points to where " << *q << " is stored\n";
	cout << "*q contains " << *q << endl;

	double d(33.44);
	double* pD(&d);
	*pD = *p;
	*pD = 73.2343;
	//*p = *pD;
	*q = *p;
	//pD = p;
	//p = pD;

	int joe = 24;
	const int sal = 19;
	int*  pI;
	  pI = &joe;  
	 *pI = 234;  
	 // pI = &sal;  cannot change pointer to address of a constant
	 *pI = 7623;    //value stored at a constant pointer can be modified

	const int* pcI;
	 pcI = &joe;  
	//*pcI = 234;  
	  pcI = &sal;  
	// *pcI = 7623;    you can change where it points but not what is within that address, regardless of whether or not the address holds a constant var

	//int* const cpI; cpI doesn't exist, there is no address
	int* const cpI(&joe);
	//int* const cpI(&sal); cpI is a constant, cannot be modified
	 // cpI = &joe;  
	 *cpI = 234;  //should modify joe
	//  cpI = &sal;  
	 *cpI = 7623;    

	//const int* const cpcI; does not exist
	//const int* const cpcI(&joe);
	const int* const cpcI(&sal);
	//  cpcI = &joe;  
	//*cpcI = 234;  
	 //cpcI = &sal;  
	//*cpcI = 7623; 


	struct Complex {
		double real;
		double img;
	};
	Complex c = { 11.23,45.67 };
	Complex* pC(&c);

	cout << "real: " << pC->real << "\nimaginary: " << pC->img << endl;

	class PlainOldClass {
	public:
		PlainOldClass() : x(-72) {}
		int getX() const { return x; }
		void setX(int x) { this->x=x; }
	private:
		int x;
	};

	PlainOldClass poc;
	PlainOldClass* ppoc(&poc);
	cout << ppoc->getX() << endl;
	ppoc->setX(2837);
	cout << ppoc->getX() << endl;

	int* pDyn = new int(3); // p points to an int initialized to 3 on the heap      
	*pDyn = 17;
	cout << "The " << *pDyn
		<< " is stored at address " << pDyn
		<< " which is in the heap\n";

	cout << pDyn << endl;
	delete pDyn;
	cout << pDyn << endl;

	cout << "The 17 might STILL be stored at address " << pDyn << " even though we deleted pDyn\n";
	//cout << "But can we dereference pDyn?  We can try.  This might crash... " << *pDyn << ".  Still here?\n";


	pDyn = nullptr;
	double* pDouble = nullptr;
	//cout << "Can we dereference nullptr?  " << *pDyn << endl;
	//cout << "Can we dereference nullptr?  " << *pDouble << endl;

	double* pTest = new double(12);
	delete pTest;
	pTest = nullptr;
	delete pTest; // safe


	short* pShrt = new short(5);
	delete pShrt;
	//delete pShrt;
	long jumper = 12238743;
	//delete jumper;
	long* ptrTolong = &jumper;
	//delete ptrTolong;
	Complex cmplx;
	//delete cmplx;

	

	




	class SpeakerSystem {
	public:
		void vibrateSpeakerCones(unsigned signal) const {

			cout << "Playing: " << signal << "Hz sound..." << endl;
			cout << "Buzz, buzzy, buzzer, bzap!!!\n";
		}
	};

	class Amplifier {
	public:
		void attachSpeakers(const SpeakerSystem& spkrs) 
		{
			if (attachedSpeakers)
				cout << "already have speakers attached!\n";
			else
				attachedSpeakers = &spkrs;
		}

		void detachSpeakers() { // should there be an "error" message if not attached?
			attachedSpeakers = nullptr;
		}

		void playMusic() const {
			if (attachedSpeakers)
				attachedSpeakers->vibrateSpeakerCones(440);
			else
				cout << "No speakers attached\n";
		}
	private:
		const SpeakerSystem* attachedSpeakers = nullptr;
	};


	class Person {
	public:
		Person(const string& name, string clean, string cleanPref) : name(name), clean(clean), cleanPref(cleanPref) { Person* roomie = nullptr; }
		void movesInWith(Person& newRoomate) {
			if ((cleanPref == newRoomate.checkClean())&&(!roomie)&&(!newRoomate.roomie)&&(&newRoomate!=this)) {
				roomie = &newRoomate;        // now I have a new roomie            
				newRoomate.roomie = this;    // and now they do too    }
			}
			else if(newRoomate.roomie){
				cout << newRoomate.getName() << " already has a roomate." << endl;
			}
			else {
				cout << name << " already has a roomate." << endl;
			}
		}
		const string& getName() const { return name; }
		// Don't need to use getName() below, just there for you to use in debugging.
		const string& getRoomiesName() const { return roomie->getName(); }
		const string checkClean() const {
			return clean;
		}

	private:
		Person* roomie;
		string name;
		const string clean;
		const string cleanPref;
		
	};

	// write code to model two people in this world       
	Person joeBob("Joe Bob", "clean", "clean"), billyJane("Billy Jane", "clean", "clean");

	// now model these two becoming roommates       
	joeBob.movesInWith(billyJane);

	// did this work out?       
	cout << joeBob.getName() << " lives with " << joeBob.getRoomiesName() << endl;
	cout << billyJane.getName() << " lives with " << billyJane.getRoomiesName() << endl;
}