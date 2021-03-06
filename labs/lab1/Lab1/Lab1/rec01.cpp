/*Isaiah Garnett
Conway's game of life, simulated for 10 generations*/


#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

ifstream openfile()
{
	ifstream initial_state("life.txt");
	if (!initial_state)
	{
		cerr << "Failed to open life.txt";
		exit(1);
	}
	return initial_state;
}

void print_state(const vector<string>& current_state)
{
	for (size_t i = 0; i < current_state.size(); i++)
	{
		cout << current_state[i];
	}
}

vector<string> update_state(const vector<string>& current_state)
{
	char DEAD = '-';
	char ALIVE = '*';
	char BORDER = '#';
	vector<string> new_state = {current_state[0]};
	for (int i = 1; i < current_state.size()-1; i++)
	{
		
		string curr_line = "#";
		for (int j = 1; j < current_state[i].size() - 2; j++)
		{
			char left = current_state[i][j - 1];
			char top_left = current_state[i - 1][j - 1];
			char top_right = current_state[i - 1][j + 1];
			char right = current_state[i][j + 1];
			char bot_left = current_state[i + 1][j - 1];
			char bot_right = current_state[i + 1][j + 1];
			char above = current_state[i - 1][j];
			char below = current_state[i + 1][j];
			char curr_char = current_state[i][j];
			int living_neighbors = 0;
			if (left == ALIVE)
			{
				living_neighbors += 1;
			}
			if (top_left == ALIVE)
			{
				living_neighbors += 1;
			}
			if (top_right == ALIVE)
			{
				living_neighbors += 1;
			}
			if (bot_left == ALIVE)
			{
				living_neighbors += 1;
			}
			if (bot_right == ALIVE)
			{
				living_neighbors += 1;
			}
			if (right == ALIVE)
			{
				living_neighbors += 1;
			}
			if (above == ALIVE)
			{
				living_neighbors += 1;
			}
			if (below == ALIVE)
			{
				living_neighbors += 1;
			}


			//determine new state for current cell
			if ((curr_char == ALIVE) && (living_neighbors == 2 || living_neighbors == 3))
			{
				curr_line += ALIVE;
			}
			else if ((curr_char == DEAD) && (living_neighbors == 3))
			{
				curr_line += ALIVE;
			}
			else
			{
				curr_line += DEAD; //+ living_neighbors);
			}
		}
		curr_line += "#\n";
		new_state.push_back(curr_line);
	}
	new_state.push_back(current_state[0]);
	return new_state;
}

int main()
{
	int line_length;
	vector<string> lines;
	string line;

	//openfile
	ifstream initial_state = openfile();
	

	//get line len & add first line to vector "lines"
	getline(initial_state, line);
	int line_len = line.size() + 2;
	string header = "";
	for (int i = 0; i < line_len; i++)
	{
		header += "#";
	}
	header += "\n";
	string footer = header;
	lines.push_back(header);
	lines.push_back("#" + line + "#\n");


	//save initial state to vector "lines"
	while (getline(initial_state, line))
	{
		lines.push_back("#" + line + "#\n");
	}
	lines.push_back(footer);
	initial_state.close();


	//print initial state
	int state_number = 1;
	cout << "State " << state_number << ": \n";
	print_state(lines);
	state_number += 1;

	//print 10 additional states
	vector<string> current_state = lines;
	vector<string> updated_state;
	for (int i = 0; i < 10; i++)
	{
		cout << "\n\nState " << state_number << ": \n";
		updated_state = update_state(current_state);
		print_state(updated_state);
		current_state = updated_state;
		state_number += 1;
	}
}


