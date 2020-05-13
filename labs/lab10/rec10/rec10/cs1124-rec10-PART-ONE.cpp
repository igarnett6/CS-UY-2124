////
////#include <iostream>
////#include <string>
////#include <vector>
////using namespace std;
////
////class Instrument {
////public:
////	Instrument() {}
////	virtual void makeSound() {}
////private:
////};
////
////class MILL {
////public:
////	MILL() {}
////	void receiveInstr(Instrument& newInst) {
////		bool added = false;
////		newInst.makeSound();
////		for (size_t i = 0; i < inventory.size(); i++) {
////			if (inventory[i] == nullptr) {
////				inventory[i] = &newInst;
////				added = true;
////				break;
////			}
////		}
////		if (!added) {
////			inventory.push_back(&newInst);
////		}
////	}
////	void dailyTestPlay() {
////		for (size_t i = 0; i < inventory.size(); i++) {
////			if (inventory[i] != nullptr) {
////				inventory[i]->makeSound();
////			}
////		}
////	}
////	Instrument* loanOut() {
////		for (size_t i = 0; i < inventory.size(); i++) {
////			if (inventory[i] != nullptr) {
////				Instrument* res = inventory[i];
////				inventory[i] = nullptr;
////				return res;
////			}
////		}
////		return nullptr;
////	}
////private:
////	vector<Instrument*> inventory = { nullptr };
////};
////
////
////
////
////
////class String : public Instrument {
////public:
////	String(unsigned pitch) : Instrument(), pitch(pitch) {}
////	void makeSound() override {
////		cout << "To make a sound... bow a string with pitch " << pitch << endl;
////	}
////private:
////	const unsigned pitch;
////};
////class Violin : public String {
////public:
////	Violin(unsigned pitch) : String(pitch) {}
////private:
////};
////class Cello : public String {
////public:
////	Cello(unsigned pitch) : String(pitch) {}
////private:
////};
////
////
////class Percussion : public Instrument {
////public:
////	Percussion() {}
////	void makeSound() override {
////		cout << "To make a sound...hit me!" << endl;
////	}
////};
////class Drum : public Percussion {
////public:
////	Drum() : Percussion() {}
////};
////class Cymbal : public Percussion {
////public:
////	Cymbal() : Percussion() {}
////};
////
////class Brass : public Instrument {
////public:
////	Brass(unsigned mp) : mp(mp), Instrument(){
////		if (mp == 12) {
////			size = "Big";
////		}
////		else if (mp == 9) {
////			size = "Medium";
////		}
////		else if (mp == 4) {
////			size = "Small";
////		}
////		else { cerr << "Invalid mouthpiece size"; }
////	}
////	void makeSound() override{
////		cout << "To make a sound... blow on a mouthpiece of size " << mp << endl;
////	}
////private:
////	unsigned mp;
////	string size;
////};
////class Trumpet : public Brass {
////public:
////	Trumpet(unsigned mp) : Brass(mp) {}
////private:
////};
////class Trombone : public Brass {
////public:
////	Trombone(unsigned mp) : Brass(mp) {}
////private:
////};
////
////
////
////class Musician {
////public:
////    Musician() : instr(nullptr) {}
////
////    void acceptInstr(Instrument* instPtr) { instr = instPtr; }
////
////    Instrument* giveBackInstr() { 
////        Instrument* result(instr); 
////        instr = nullptr;
////        return result;
////    }
////
////    void testPlay() const {
////        if (instr) instr->makeSound(); 
////        else cerr << "have no instr\n";
////    }
////
////private:
////    Instrument* instr;
////};
//
//
//// PART ONE
//int main() {
//
//     cout << "Define some instruments ------------------------------------\n";
//     Drum drum;
//     Cello cello(673);
//     Cymbal cymbal;
//     Trombone tbone(4);
//     Trumpet trpt(12) ;
//     Violin violin(567) ;
//  
//    // // use the debugger to look at the mill
//     cout << "Define the MILL --------------------------------------------\n";
//     MILL mill;
//  
//     cout << "Put the instruments into the MILL --------------------------\n";
//     mill.receiveInstr(trpt);
//     mill.receiveInstr(violin);
//     mill.receiveInstr(tbone);
//     mill.receiveInstr(drum);
//     mill.receiveInstr(cello);
//     mill.receiveInstr(cymbal);
//  
//     cout << "Daily test -------------------------------------------------\n";
//     cout << endl;
//     cout << "dailyTestPlay()" << endl;
//     mill.dailyTestPlay();
//     cout << endl;
//  
//     cout << "Define some Musicians---------------------------------------\n";
//     Musician harpo;
//     Musician groucho;
//  	
//     cout << "TESTING: groucho.acceptInstr(mill.loanOut());---------------\n";
//     groucho.testPlay();	
//     cout << endl;
//     groucho.acceptInstr(mill.loanOut());
//     cout << endl;
//     groucho.testPlay();
//     cout << endl;
//     cout << "dailyTestPlay()" << endl;
//     mill.dailyTestPlay();
//  
//     cout << endl << endl;
//  
//     groucho.testPlay();	
//     cout << endl;
//     mill.receiveInstr(*groucho.giveBackInstr());
//     harpo.acceptInstr(mill.loanOut());
//     groucho.acceptInstr(mill.loanOut());
//     cout << endl;
//     groucho.testPlay();
//     cout << endl;
//     harpo.testPlay();
//     cout << endl;
//     cout << "dailyTestPlay()" << endl;
//     mill.dailyTestPlay();
//  
//     cout << "TESTING: mill.receiveInstr(*groucho.giveBackInstr()); ------\n";
//  
//     // fifth
//     mill.receiveInstr(*groucho.giveBackInstr());
//     cout << "TESTING: mill.receiveInstr(*harpo.giveBackInstr()); ------\n";
//     mill.receiveInstr(*harpo.giveBackInstr());
//
//  
//     cout << endl;
//     cout << "dailyTestPlay()" << endl;
//     mill.dailyTestPlay();
//     cout << endl;
//  
//     cout << endl;
//}
