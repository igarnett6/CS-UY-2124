// rec13_test.cpp

#include <iostream>
#include <fstream>
#include <vector>      // task 1
#include <list>        // task 2
#include <algorithm>   // task 3
#include <string>      // task 21
#include <set>         // task 22
#include <map>         // task 23
using namespace std;
void printList(const list<int>& l2) {					// task 9
	list<int>::const_iterator cursor = l2.begin();
	for (cursor; cursor != l2.end(); ++cursor) { 
		cout << *cursor << " "; }
}

void printListRanged(const list<int>& l2) {				// task 10
	for (int elem : l2) {
		cout << elem << " ";
	}
}
list<int>::const_iterator myFind(const list<int>& l1, int target) { // task 12
	list<int>::const_iterator cursor = l1.begin();
	for (cursor; cursor != l1.end(); ++cursor) {
		if (*cursor == target) {
			return cursor;
		}
	}
	return l1.end();
 }
auto find2(const list<int>& l1, int target) { // task 13
	for (auto cursor = l1.begin(); cursor != l1.end(); ++cursor) {
		if (*cursor == target) {
			return cursor;
		}
	}
	return l1.end();
}
bool isEven(int x) { return (x % 2 == 0); } //task 15
class Whatever {							//task 16
public:
	bool operator()(int x) {
		return (x % 2 == 0);
	}
};
list<int>::const_iterator ourFind(list<int>::const_iterator begin, list<int>::const_iterator end, int target) { // task 19
	cout << "Currently using ourFind." << endl;
	list<int>::const_iterator cursor = begin;
	for (cursor; cursor != end; ++cursor) {
		if (*cursor == target) {
			return cursor;
		}
	}
	return end;
}
template <typename T, typename U>
list<int>::const_iterator ourFind(T begin, T end, U target) { // task 20
	cout << "Currently using  templated ourFind." << endl;
	list<int>::const_iterator cursor = begin;
	for (cursor; cursor != end; ++cursor) {
		if (*cursor == target) {
			return cursor;
		}
	}
	return end;
}
int main() {
    // 1. Create a vector with some values and display using ranged for
    cout << "Task 1:\n";
	vector<int> v1 = { 1,4,3,2 };
	for (int i : v1) { cout << i << " "; }
    cout << "\n=======\n";

    // 2. Initalize a list as a copy of values from the vector
    cout << "Task 2:\n";
	list<int>  l1(v1.begin(), v1.end());
	list<int>::iterator cursor = l1.begin();
	for (cursor; cursor != l1.end(); ++cursor) { cout << *cursor << " "; }
    cout << "\n=======\n";

    // 3. Sort the original vector.  Display both the vector and the list
    cout << "Task 3:\n";
	sort(v1.begin(), v1.end());
	cout << "vector: ";
	for (int i : v1) { cout << i << " "; } cout << endl;
	cout << "list: ";
	cursor = l1.begin();
	for (cursor; cursor != l1.end(); ++cursor) { cout << *cursor << " "; }
    cout << "\n=======\n";

    // 4. print every other element of the vector.
    cout << "Task 4:\n";
	for (size_t i = 0; i < v1.size(); ++i) {
		if (i % 2 == 0) { cout << v1[i] << " "; }
	}
    cout << "\n=======\n";

    // 5. Attempt to print every other element of the list using the
    //    same technique.
    cout << "Task 5:\n";
	/*for (size_t i = 0; i < l1.size(); ++i) {
		if (i % 2 == 0) { cout << l1[i] << " "; }
	}*/
    cout << "\n=======\n";

    //
    // Iterators
    //

    // 6. Repeat task 4 using iterators.  Do not use auto;
    cout << "Task 6:\n";
	vector<int>::iterator vcursor = v1.begin();
	for (vcursor; vcursor != v1.end(); vcursor += 2) {
		cout << *vcursor << " ";
	}
    cout << "\n=======\n";

    // 7. Repeat the previous task using the list.  Again, do not use auto.
    //    Note that you cannot use the same simple mechanism to bump
    //    the iterator as in task 6.
    cout << "Task 7:\n";
	cursor = l1.begin();
	for (cursor; cursor != l1.end(); ++++cursor) { //lol wut
		cout << *cursor << " ";
	}
    cout << "\n=======\n";

    // 8. Sorting a list
    cout << "Task 8:\n";
	l1.sort();
	cursor = l1.begin();
	for (cursor; cursor != l1.end(); ++cursor) { cout << *cursor << " "; }
    cout << "\n=======\n";

    // 9. Calling the function to print the list
    cout << "Task 9:\n";
	printList(l1);
    cout << "\n=======\n";

    // 10. Calling the function that prints the list, using ranged-for
    cout << "Task 10:\n";
	printListRanged(l1);
    cout << "\n=======\n";

    //
    // Auto
    //

    // 11. Calling the function that, using auto, prints alternate
    // items in the list
    cout << "Task 11:\n";
	for (auto aCursor = l1.begin(); aCursor != l1.end(); ++++aCursor) { //lol wut
		cout << *aCursor << " ";
	}
    cout << "\n=======\n";

    
    // 12.  Write a function find that takes a list and value to search for.
    //      What should we return if not found
    cout << "Task 12:\n";
	myFind(l1, 3);
    cout << "\n=======\n";

    // 13.  Write a function find that takes a list and value to search for.
    //      What should we return if not found
    cout << "Task 13:\n";
	find2(l1, 3);
    cout << "\n=======\n";

    //
    // Generic Algorithms
    //

    // 14. Generic algorithms: find
    cout << "Task 14:\n";
	list<int>::const_iterator res =  find(l1.begin(), l1.end(), 3);
	if (res != l1.end()) {
		cout << "Target found." << endl;
	}
	else {
		cout << "Target not found." << endl;
	}
    cout << "\n=======\n";

    // 15. Generic algorithms: find_if
    cout << "Task 15:\n";
	list<int>::iterator newCursor = find_if(l1.begin(), l1.end(), isEven);
	vector<int>::iterator newVCursor = find_if(v1.begin(), v1.end(), isEven);
	cout << "List: ";
	if (newCursor != l1.end()) {
		cout << "First even number found: " << *newCursor << endl;
	}
	else {
		cout << "No evens found." << endl;
	}
	cout << "Vector: ";
		if (newVCursor != v1.end()) {
			cout << "First even number found: " << *newVCursor << endl;
		}
		else {
			cout << "No evens found." << endl;
		}
	
    cout << "=======\n";

    // 16. Functor
    cout << "Task 16:\n";
	list<int>::iterator newerCursor = find_if(l1.begin(), l1.end(), Whatever());
	vector<int>::iterator newerVCursor = find_if(v1.begin(), v1.end(),Whatever());
	cout << "List: ";
	if (newerCursor != l1.end()) {
		cout << "First even number found: " << *newerCursor << endl;
	}
	else {
		cout << "No evens found." << endl;
	}
	cout << "Vector: ";
	if (newerVCursor != v1.end()) {
		cout << "First even number found: " << *newerVCursor << endl;
	}
	else {
		cout << "No evens found." << endl;
	}
    cout << "=======\n";
    
    // 17. Lambda
    cout << "Task 17:\n";
	list<int>::iterator newestCursor = find_if(l1.begin(), l1.end(), [] (int x) { return x % 2 == 0; });
	vector<int>::iterator newestVCursor = find_if(v1.begin(), v1.end(), [](int x) { return x % 2 == 0; });
	cout << "List: ";
	if (newestCursor != l1.end()) {
		cout << "First even number found: " << *newestCursor << endl;
	}
	else {
		cout << "No evens found." << endl;
	}
	cout << "Vector: ";
	if (newestVCursor != v1.end()) {
		cout << "First even number found: " << *newestVCursor << endl;
	}
	else {
		cout << "No evens found." << endl;
	}
    cout << "=======\n";

    // 18. Generic algorithms: copy to an array
    cout << "Task 18:\n";
	int arr[4];
	copy(v1.begin(), v1.end(), arr);
	cout << "Array arr: ";
	for (int x : arr) { cout << x << " "; }
    cout << "\n=======\n";

    //
    // Templated Functions
    //

    // 19. Implement find as a function for lists
    cout << "Task 19:\n";
	list<int>::const_iterator res2 = ourFind(l1.begin(), l1.end(), 3);
	if (res2 != l1.end()) {
		cout << "Target found." << endl;
	}
	else {
		cout << "Target not found." << endl;
	}
    cout << "=======\n";
    
    // 20. Implement find as a templated function
    cout << "Task 20:\n";
	list<int>::const_iterator res3 = ourFind(l1.begin(), l1.end(), 3);
	if (res3 != l1.end()) {
		cout << "Target found." << endl;
	}
	else {
		cout << "Target not found." << endl;
	}
	cout << "=======\n";
    cout << "=======\n";

    //
    // Associative collections
    //

    // 21. Using a vector of strings, print a line showing the number
    //     of distinct words and the words themselves.
    cout << "Task 21:\n";
	vector<string> words;
	ifstream ifs ("pooh-nopunc.txt");
	string currWord;
	while (ifs >> currWord) {
		bool found = false;
		for (size_t i = 0; i < words.size(); ++i) {
			if (currWord == words[i]) {
				found = true;
			}
		}
		if (!found) {
			words.push_back(currWord);
		}
	}
	ifs.close();
	cout << "Vector size : " << words.size() << endl;
	for (string word : words) {
		cout << word << endl;
	}
    cout << "\n=======\n";

    // 22. Repeating previous step, but using the set
    cout << "Task 22:\n";
	set<string> setWords;
	ifstream ifs2("pooh-nopunc.txt");
	string thisWord;
	while (ifs2 >> thisWord) {
		setWords.insert(thisWord);
	}
	cout << "Set size : " << setWords.size() << endl;
	for (string word : setWords) {
		cout << word << endl;
	}
    cout << "=======\n";
	ifs2.close();
    // 23. Word co-occurence using map
    cout << "Task 23:\n";
	map<string, vector<int>> wordMap;
	ifstream ifs3("pooh-nopunc.txt");
	int wordPos = 0;
	while (ifs3 >> thisWord) {
		wordMap[thisWord].push_back(wordPos++);
	}
	for (auto& kvp : wordMap) {
		cout << kvp.first << ": ";
		for (int i : kvp.second) { cout << i << " "; }
		cout << endl;
	}
    cout << "=======\n";
}
