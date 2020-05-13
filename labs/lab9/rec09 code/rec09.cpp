#include <iostream>
using namespace std;

class PrintedMaterial {
public:
  PrintedMaterial(const string& name, unsigned numberOfPages)
  : name(name), numberOfPages(numberOfPages){}
  void displayNumPages() const { cout << numberOfPages };
protected:
private:
  unsigned numberOfPages;
  const string name;
};

class Magazine : public PrintedMaterial {
public:
  Magazine(const string& name, unsigned numberOfPages)
  :  PrintedMaterial(name, numberOfPages) {}
protected:
private:
};

class Book : public PrintedMaterial {
public:
  Book(const string& name, unsigned numberOfPages)
  :  PrintedMaterial(name, numberOfPages) {}
protected:
private:
};

class TextBook : public Book {
public:
  TextBook(string& name, unsigned numberOfPages)
  : Book(name, numberOfPages) {}
protected:
private:
};

class Novel : public Book {
public:
  Novel(string& name, unsigned numberOfPages)
  : Book(name, numberOfPages) {}
protected:
private:
};

// tester/modeler code
int main()
{
	TextBook t;
	Novel n;
	Magazine m;
}
