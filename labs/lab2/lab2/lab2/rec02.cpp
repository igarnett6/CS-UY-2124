/*Isaiah Garnett
Hydrocarbons with multiple names*/


#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <cctype>
using namespace std;

struct hydrocarbon;
ifstream openfile(string& filename);
vector<hydrocarbon> readfile(ifstream& hc_file);
void sort(vector<hydrocarbon>& hc_vect);
void print_formulae(const vector<hydrocarbon>& hc_vect);[]



int main() {
	string filename;
	vector<hydrocarbon> hc_vect;
	cout << "Enter filename: ";
	cin >> filename;
	ifstream hc_file = openfile(filename);

	//create vector from file
	hc_vect = readfile(hc_file);
	sort(hc_vect);

	//print formulae and names
	print_formulae(hc_vect);
}


struct hydrocarbon {
public:
	hydrocarbon(const string& name, const int& num_carb, const int& num_hydro) : formula_name(name), carbons(num_carb), hydrogens(num_hydro) {
		names.push_back(formula_name);
		formulaID = 'C' + carbons + 'H' + hydrogens;
	}
	string formulaID;
	vector<string> names;
	string formula_name;
	int carbons;
	int hydrogens;


};


ifstream openfile(string& filename) {
	ifstream hc_file(filename);
	while (!hc_file) {
		hc_file.clear();
		cout << "Enter filename: ";
		cin >> filename;
		ifstream hc_file(filename);
	}
	return hc_file;
}


vector<hydrocarbon> readfile(ifstream& hc_file) {
	string name;
	int num_carb;
	char c;
	char h;
	int num_hydro;
	vector<hydrocarbon> hc_vect;
	string curr_id;
	while (hc_file >> name >> c >> num_carb >> h >> num_hydro) {
		bool existed = false;
		curr_id = 'C' + num_carb + 'H' + num_hydro;
		for (size_t i = 0; i < hc_vect.size(); i++) {
			if (hc_vect[i].formulaID == curr_id) {
				hc_vect[i].names.push_back(name);
				existed = true;
			}
		}
		if (!existed) {
			hydrocarbon new_hc(name, num_carb, num_hydro);
			hc_vect.push_back(new_hc);
		}
	}
	return hc_vect;
}


void sort(vector<hydrocarbon>& hc_vect) {
	size_t curr_ind = 0;
	size_t sort_ind = 0;
	while (curr_ind < hc_vect.size()-1) {
		if (hc_vect[curr_ind].carbons > hc_vect[curr_ind + 1].carbons) {
			hydrocarbon temp = hc_vect[curr_ind];
			hc_vect[curr_ind] = hc_vect[curr_ind + 1];
			hc_vect[curr_ind + 1] = temp;
			curr_ind += 1;
		}
		else if ((hc_vect[curr_ind].carbons == hc_vect[curr_ind + 1].carbons)
		&& (hc_vect[curr_ind].hydrogens > hc_vect[curr_ind + 1].hydrogens)) {
			hydrocarbon temp = hc_vect[curr_ind];
			hc_vect[curr_ind] = hc_vect[curr_ind + 1];
			hc_vect[curr_ind + 1] = temp;
			curr_ind += 1;
		}
		else {
			sort_ind += 1;
			curr_ind = sort_ind;
		}
	}
}


void print_formulae(const vector<hydrocarbon>& hc_vect) {
	for (size_t i = 0; i < hc_vect.size(); i++) {
		cout << 'C'<< hc_vect[i].carbons <<'H' <<  hc_vect[i].hydrogens  << " ";
		for (size_t j = 0; j < hc_vect[i].names.size(); j++) {
			cout << hc_vect[i].names[j] << " ";
		}
		cout << endl;
	}
}