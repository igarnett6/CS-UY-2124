#include <iostream>
#include <vector>
using namespace std;

class PrintedMaterial {
	friend ostream& operator<< (ostream& os, PrintedMaterial& thisPM) {
		os << thisPM.numberOfPages;
		return os;
	}
public:
	PrintedMaterial(unsigned numberOfPages = 0)
		:  numberOfPages(numberOfPages) {}
	virtual void displayNumPages() const = 0; 
	unsigned getNumPages() const { return numberOfPages; }
protected:
private:
	unsigned numberOfPages;
	const string name;
};
void PrintedMaterial::displayNumPages() const { cout << numberOfPages << endl; }

class Magazine : public PrintedMaterial {
public:
	Magazine(unsigned numberOfPages = 0)
		: PrintedMaterial(numberOfPages) {}
	void displayNumPages() const override { cout << PrintedMaterial::getNumPages() << endl; }
protected:
private:
};

class Book : public PrintedMaterial {
public:
	Book(unsigned numberOfPages = 0)
		: PrintedMaterial(numberOfPages) {}
	void displayNumPages() const override { cout << PrintedMaterial::getNumPages() << endl; }
protected:
private:
};

class TextBook : public Book {
public:
	TextBook(unsigned numIndPages = 0, unsigned numberOfPages = 0)
		: Book(numberOfPages), numIndPages(numIndPages) {}
	void displayNumPages() const override {
		cout << "Number of Index pages: " << numIndPages << endl;
		cout << "Number of pages: ";
		PrintedMaterial::displayNumPages();
		cout << endl;
	}
protected:
private:
	unsigned numIndPages;
};

class Novel : public Book {
public:
	Novel(unsigned numberOfPages = 0)
		: Book(numberOfPages) {}
	void displayNumPages() const override { cout << PrintedMaterial::getNumPages() << endl; }
protected:
private:
};

// tester/modeler code
int main()
{
	TextBook t;
	Novel n;
	Magazine m;
	vector<PrintedMaterial*> pmVect = { &t, &n, &m };

	for (size_t i = 0; i < pmVect.size(); i++) {
		pmVect[i]->displayNumPages();
	}

}
