#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

char char_decoder(char current_char, int steps_shifted);
vector<string> create_ef_vector(ifstream& encryptedfile);
string decode_line(string& line, const int& steps_shifted);






int main()
{

	//open encrypted file
	ifstream encryptedfile("encrypted.txt");


	//check that file opened properly
	if (!encryptedfile)
	{
		cerr << "Failed to open encrytped.txt";
		exit(1);
	}

	//create a vector from encrypted file
	vector<string> ef_vector = create_ef_vector(encryptedfile);

	//decrypt and print each line
	int steps_shifted = (ef_vector[0][0] - '0');
	//for (size_t i = ef_vector.size(); i > 0; i--)
	for (string& line : ef_vector)
	{
		cout << decode_line(line, steps_shifted);
	}

}



//char decoder
//change lowercase character to an integer 1-26, then shift left according to the given # of steps
char char_decoder(char current_char, int steps_shifted)
{
	if (islower(current_char) && isalpha(current_char))
	{
		int decoded_char = (current_char - 'a' - steps_shifted) % 26;
		return decoded_char;
	}
	else
	{
		return current_char;
	}
}


vector<string> create_ef_vector(ifstream& encryptedfile)
{
	cout << "entered function";
	string line;
	vector<string> lines;
	while (getline(encryptedfile, line))
	{
		lines.push_back(line);
	}
	return lines;
}


string decode_line(string& line, const int& steps_shifted)
{
	for (size_t i = 0; i < line.size(); i++)
	{
		line[i] = char_decoder(line[i], steps_shifted);
	}
	return line;
}