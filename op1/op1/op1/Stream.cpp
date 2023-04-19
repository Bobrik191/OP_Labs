#include <iostream>
#include <string>
#include <fstream>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;


string enter_name()
{
	string name;
	cout << "Enter file name: ";
	getline(cin, name);
	return name;
}

void print_file(string filename)
{
	ifstream fin;
	fin.open(filename);
	if (!fin.is_open()) {
		cout << "Error. Cant open file!" << endl;
	}
	else {
		string str;
		cout << "\nFile " << filename << " contents: " << endl;
		while (!fin.eof()) {
			str = "";
			getline(fin, str);
			cout << str << endl;
		}
	}
	fin.close();
}

string read_file(string filename)
{
	ifstream fin;
	fin.open(filename);
	string text = "";

	if (!fin.is_open()) {
		cout << "Unable to open file: " << filename << endl;
	}
	else {
		char ch;
		while (fin.get(ch)) {
			text += ch;
		}
	}
	fin.close();
	return text;
}

void write_to_file(string filename) {
	ofstream fout;
	fout.open(filename, ios::app);

	if (!fout.is_open()) {
		cout << "Error. Cant open file!" << endl;
	}
	else {
		cout << "Enter text to add in file:\n";
		string str;
		while (true) {
			string line;
			getline(cin, line);
			if (line.empty()) {
				break;
			}
			fout << line << endl;
		}
		fout.close();
	}
}


void add_data_to_file(string filename, string sentence) {
	ofstream fout;
	fout.open(filename);

	if (fout.is_open()) {
		fout << sentence << endl;
		fout.close();
	}
	else {
		cout << "Error. Cant open/create file!" << endl;
	}
	fout.close();
}

void work_file(const string& input, const string& filename)
{
	ofstream out(filename);

	string current_line;
	string current_word;
	string longest_word;

	int current_length = 1;
	int longest_length = 1;
	char current_char = '\0';


	for (char c : input) {
		if (c == ' ' || c == '\n' || c == '.' || c == ',') {
			// ѕровер€ем €вл€етс€ ли текущее слово имеет самую длинную последовательность
			if (current_length > longest_length && current_word.find(current_char + string(current_length - 1, current_char)) != std::string::npos) {
				longest_length = current_length;
				longest_word = current_word;
			}
			else if (current_length == longest_length && current_word.find(current_char + string(current_length - 1, current_char)) != std::string::npos) {
				longest_word += " " + current_word;
			}
			current_word = "";
			current_length = 1;
			current_char = '\0';
		}
		else {
			if (c == current_char) {
				current_word += c;
				current_length++;
			}
			else {
				current_word += c;
				current_char = c;
				current_length = 1;
			}
		}
		// ¬ыводим слова дл€ каждой строки
		if (c == '\n') {
			// »щем самую длинную последовательность
			string::size_type pos = 0;
			while (pos < current_line.length()) {
				string::size_type word_pos = current_line.find(longest_word, pos);
				if (word_pos != string::npos) {
					string line_beginning = current_line.substr(0, word_pos);
					string line_ending = current_line.substr(word_pos + longest_word.length());
					current_line = longest_word + " " + line_beginning + line_ending;
					pos = word_pos + longest_word.length() + 1;
				}
				else {
					break;
				}
			}
			out << current_line << endl;
			current_line = "";
			longest_word = "";
			longest_length = 1;
			current_char = '\0';
		}
		else {
			current_line += c;
		}
	}
	out.close();
}

string replaceDuplicatesWithBrackets(string str) {
	int count = 0;
	char lastChar = str[0];
	string result = "";

	for (int i = 1; i < str.length(); i++) {
		if (str[i] == lastChar) {
			count++;
		}
		else {
			if (count > 0) {
				result += "{" + string(1, lastChar) + "}";
				count = 0;
			}
			else {
				result += lastChar;
			}
			lastChar = str[i];
		}
	}

	if (count > 0) {
		result += "{" + string(1, lastChar) + "}";
	}
	else {
		result += lastChar;
	}

	return result;
}
