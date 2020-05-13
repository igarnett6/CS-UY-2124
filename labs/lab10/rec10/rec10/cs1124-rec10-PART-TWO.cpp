
#include <iostream>
#include <string>
#include <vector>
using namespace std;



class Instrument {
public:
	Instrument() {}
	virtual void makeSound() const = 0;
	virtual void playNormal() const = 0;
private:
};

void Instrument::makeSound() const {
	cout << "To make a sound... ";
}

class MILL {
public:
	MILL() {}
	void receiveInstr(Instrument& newInst) {
		bool added = false;
		newInst.makeSound();
		for (size_t i = 0; i < inventory.size(); i++) {
			if (inventory[i] == nullptr) {
				inventory[i] = &newInst;
				added = true;
				break;
			}
		}
		if (!added) {
			inventory.push_back(&newInst);
		}
	}
	void dailyTestPlay() {
		for (size_t i = 0; i < inventory.size(); i++) {
			if (inventory[i] != nullptr) {
				inventory[i]->makeSound();
			}
		}
	}
	Instrument* loanOut() {
		for (size_t i = 0; i < inventory.size(); i++) {
			if (inventory[i] != nullptr) {
				Instrument* res = inventory[i];
				inventory[i] = nullptr;
				return res;
			}
		}
		return nullptr;
	}
private:
	vector<Instrument*> inventory = { nullptr };
};





class String : public Instrument {
public:
	String(unsigned pitch) : Instrument(), pitch(pitch) {}
	void makeSound() const override {
		Instrument::makeSound();
		cout << "bow a string with pitch " << pitch << endl;
	}
private:
	const unsigned pitch;
};
class Violin : public String {
public:
	Violin(unsigned pitch) : String(pitch) {}
	void playNormal() const override {
		cout << "Screech" << endl;
	}
private:
};
class Cello : public String {
public:
	Cello(unsigned pitch) : String(pitch) {}
	void playNormal() const override {
		cout << "Squawk" << endl;
	}
private:
};


class Percussion : public Instrument {
public:
	Percussion() {}
	void makeSound() const override {
		Instrument::makeSound();
		cout << "hit me!" << endl;
	}
};
class Drum : public Percussion {
public:
	Drum() : Percussion() {}
	void playNormal() const override {
		cout << "Boom" << endl;
	}
};
class Cymbal : public Percussion {
public:
	Cymbal() : Percussion() {}
	void playNormal() const override {
		cout << "Crash" << endl;
	}
};

class Brass : public Instrument {
public:
	Brass(unsigned mp) : mp(mp), Instrument() {
		if (mp == 12) {
			size = "Big";
		}
		else if (mp == 9) {
			size = "Medium";
		}
		else if (mp == 4) {
			size = "Small";
		}
		else { cerr << "Invalid mouthpiece size"; }
	}
	void makeSound() const override {
		Instrument::makeSound();
		cout << "blow on a mouthpiece of size " << mp << endl;
	}
private:
	unsigned mp;
	string size;
};
class Trumpet : public Brass {
public:
	Trumpet(unsigned mp) : Brass(mp) {}
	void playNormal() const override {
		cout << "Toot" << endl;
	}
private:
};
class Trombone : public Brass {
public:
	Trombone(unsigned mp) : Brass(mp) {}
	void playNormal() const override {
		cout << "Blat" << endl;
	}
private:
};



class Musician {
public:
	Musician() : instr(nullptr) {}

	void acceptInstr(Instrument* instPtr) { instr = instPtr; }

	Instrument* giveBackInstr() {
		Instrument* result(instr);
		instr = nullptr;
		return result;
	}

	void testPlay() const {
		if (instr) instr->makeSound();
		else cerr << "have no instr\n";
	}
	void orchPlay() const {
		if (instr) instr->playNormal();
		else cerr << "have no instr\n";
	}

private:
	Instrument* instr;
};


class Orch {
public:
	Orch() {}
	void addPlayer(Musician& newMus) {
		musicians.push_back(&newMus);
	}
	void play() {
		for (size_t i = 0; i < musicians.size(); i++) {
			musicians[i] ->orchPlay();
		}
	}
private:
	vector<Musician*> musicians;
};




// PART TWO
int main() {
    // The initialization phase

    Drum drum;
    Cello cello(673);
    Cymbal cymbal;
    Trombone tbone(4);
    Trumpet trpt(12);
    Violin violin(567);

    MILL mill;
    mill.receiveInstr(trpt);
    mill.receiveInstr(violin);
    mill.receiveInstr(tbone);
    mill.receiveInstr(drum);
    mill.receiveInstr(cello);
    mill.receiveInstr(cymbal);

    Musician bob;
    Musician sue;
    Musician mary;
    Musician ralph;
    Musician jody;
    Musician morgan;

    Orch orch;

    // THE SCENARIO

    //Bob joins the orchestra without an instrument.
    orch.addPlayer(bob);

    //The orchestra performs
    cout << "orch performs\n";
    orch.play();

    //Sue gets an instrument from the MIL2 and joins the orchestra.
    sue.acceptInstr(mill.loanOut());
    orch.addPlayer(sue);

    //Ralph gets an instrument from the MIL2.
    ralph.acceptInstr(mill.loanOut());

    //Mary gets an instrument from the MIL2 and joins the orchestra.
    mary.acceptInstr(mill.loanOut());
    orch.addPlayer(mary);

    //Ralph returns his instrument to the MIL2.
    mill.receiveInstr(*ralph.giveBackInstr());

    //Jody gets an instrument from the MIL2 and joins the orchestra.
    jody.acceptInstr(mill.loanOut());
    orch.addPlayer(jody);

    // morgan gets an instrument from the MIL2
    morgan.acceptInstr(mill.loanOut());

    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();

    //Ralph joins the orchestra.
    orch.addPlayer(ralph);

    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();
	
    // bob gets an instrument from the MIL2
    bob.acceptInstr(mill.loanOut());

    // ralph gets an instrument from the MIL2
    ralph.acceptInstr(mill.loanOut());

    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();

    //Morgan joins the orchestra.
    orch.addPlayer(morgan);

    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();

} // main

