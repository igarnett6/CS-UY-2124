/*Isaiah Garnett
recitaion 3*/
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;




struct BankAcct {
	string name;
	string acctNum;
};

class Transaction {};



class Accounts {
	friend ostream& operator<< (ostream& os, const Accounts& currAcc);
public:
	Accounts() {}
	Accounts(const string& name, const string& accNum) : name(name), accNum(accNum) { }
	
	string getName() const {
		return name;
	}

	string getAccNum() const {
		return accNum;
	}

	void deposit(int amount) {
		transHistory.emplace_back("deposit", amount);
		balance += amount;
		cout << "call to deposit." << endl;
	}
	
	void withdraw(int amount) {
		if (balance - amount >= 0) {
			transHistory.emplace_back("withdraw", amount);
			balance -= amount;
		}
		else {
			cerr << "Insufficient Funds. Transaction cancelled." << endl;
		}
		
	}

	void displayHistory() const {
		if (transHistory.size() > 0) {
			cout << "Transaction history: " << endl;
			for (const Transaction& currTrans : transHistory) {
				cout << "Transaction type: " << currTrans.getType() << endl;
				if (currTrans.getType() == "deposit") {
					cout << "Transaction amount: " << currTrans.getAmount() << endl;
				}
				else {
					cout << "Transaction amount: -" << currTrans.getAmount() << endl;
				}

			}
		}
		
	}

private:
	class Transaction {
	public:
		Transaction(const string& type, int amount) : type(type), amount(amount) {}

		string getType() const {
			return type;
		}
		int getAmount() const {
			return amount;
		}
	private:
		string type;
		int amount;
	};


	string name;
	string accNum;
	int balance= 0;
	vector<Transaction> transHistory;
};




ifstream openfile(const string& filename) {
	ifstream accountsFile(filename);
	if (!accountsFile) {
		cerr << "Something broke. File failed to open. kys loser.";
		exit(1);
	}
	return accountsFile;
}

ifstream openTransFile(const string& filename) {
	ifstream transFile(filename);
	if (!transFile) {
		cerr << "Something broke. File failed to open. kys loser.";
		exit(1);
	}
	return transFile;
}

vector<BankAcct> readfile (ifstream& accountsFile) {
	string firstName;
	string lastName;
	string fullname;
	vector<BankAcct> accList;
	string acctNumber;
	while (accountsFile >> firstName >> lastName >> acctNumber) {
		fullname = firstName + " " + lastName;
		BankAcct newAcct;
		newAcct.name = fullname;
		newAcct.acctNum = acctNumber;
		accList.push_back(newAcct);
	}
	return accList; //does this return result in an additional vector being initialized?
}

void readfile2(vector<BankAcct>& accList, ifstream& accountsFile) {
	string firstName;
	string lastName;
	string fullname;
	string acctNumber;
	while (accountsFile >> firstName >> lastName >> acctNumber) {
		fullname = firstName + " " + lastName;
		BankAcct newAcct{fullname, acctNumber};
		accList.push_back(newAcct);
	}
}

void readfile3(vector<Accounts>& accListClass, ifstream& accountsFile) {
	string firstName;
	string lastName;
	string fullname;
	string acctNumber;
	while (accountsFile >> firstName >> lastName >> acctNumber) {
		fullname = firstName + " " + lastName;
		Accounts newAcct{ fullname, acctNumber };
		accListClass.push_back(newAcct);
	}
}

void readfile4(vector<Accounts>& accListClass, ifstream& accountsFile) {
	string firstName;
	string lastName;
	string fullname;
	string acctNumber;
	while (accountsFile >> firstName >> lastName >> acctNumber) {
		fullname = firstName + " " + lastName;
		accListClass.push_back(Accounts{ fullname, acctNumber });
	}
}

void readfile5(vector<Accounts>& accListClass, ifstream& accountsFile) {
	string firstName;
	string lastName;
	string fullname;
	string acctNumber;
	while (accountsFile >> firstName >> lastName >> acctNumber) {
		fullname = firstName + " " + lastName;
		accListClass.emplace_back(fullname, acctNumber);
	}
}

void readTransFile(ifstream& transFile, vector<Accounts>& accList) {
	cout << endl << "Now reading transaction file..." << endl;
	string firstname;
	string lastname;
	string fullname;
	string accNum;
	string type;
	int amount;
	while (transFile >> firstname >> lastname >> accNum >> type >> amount) {
		for (Accounts& currAcc : accList) {
			if (currAcc.getAccNum() == accNum) {
				if (type == "withdraw") {
					currAcc.withdraw(amount);
				}
				else if (type == "deposit") {
					currAcc.deposit(amount);
				}
				else {
					cerr << "Something broke. Transaction failed due to invalid transaction type." << endl;
				}
			}
		}
	}
	cout << "Finished reading transactions." << endl << endl << endl;
}

void display(vector<BankAcct>& accList) {
	for (BankAcct& currAcc : accList) {
		cout << "Name: " << currAcc.name << endl;
		cout << "Account Number: " << currAcc.acctNum << endl << endl;
	}
}

void displayClass(vector<Accounts>& accListClass) {
	for (Accounts& currAcc : accListClass) {
		//cout << "Name: " << currAcc.getName() << endl;
		//cout << "Account Number: " << currAcc.getAccNum() << endl << endl;
		cout << currAcc;
	}
}

ostream& operator<<(ostream& os, const Accounts& currAcc) {
	os << "Name: " << currAcc.getName() << endl;
	os << "Account Number: " << currAcc.getAccNum() << endl;
	currAcc.displayHistory();
	os << endl << endl;
	return os;
}




int main() {
	ifstream accountsFile = openfile("accounts.txt");			//opens accounts file
	vector<BankAcct> accList = readfile(accountsFile);			//reads accounts into vector 
	accountsFile.close();
	display(accList);												//displays all accounts in vector "accList"
	accList.clear();
	
	
	//repeating processs using {} to initalize BankAcct objects
	accountsFile.open("accounts.txt");
	readfile2(accList, accountsFile);
	accountsFile.close();
	cout << endl << endl << "Now displaying accounts initialized with {}." << endl;
	display(accList);
	accList.clear();



	//repeat using class "Accounts"
	vector<Accounts> accListClass;
	accountsFile.open("accounts.txt");
	readfile3(accListClass, accountsFile);
	accountsFile.close();
	cout << endl << "Now displaying accounts created with Accounts class." << endl;
	displayClass(accListClass);
	accListClass.clear();


	//repeat using class and temp instances of "Accounts" objects
	accountsFile.open("accounts.txt");
	readfile4(accListClass, accountsFile);
	accountsFile.close();
	cout << endl << "Now displaying accounts created with Accounts class and temp instances of \"Accounts\"." << endl;
	displayClass(accListClass);
	accListClass.clear();


	//repeat using emplace back
	accountsFile.open("accounts.txt");
	readfile5(accListClass, accountsFile);
	accountsFile.close();
	cout << endl << "Now displaying accounts created with Accounts class and emplace_back." << endl;
	displayClass(accListClass);
	accListClass.clear();


	//use transactions
	cout << endl << "Now displaying accounts created with Accounts with transaction histories." << endl;
	ifstream transFile = openTransFile("transactions.txt");
	accountsFile.open("accounts.txt");
	readfile5(accListClass, accountsFile);
	accountsFile.close();
	readTransFile(transFile, accListClass);
	transFile.close();
	displayClass(accListClass);
	accListClass.clear();

}