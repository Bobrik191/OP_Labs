#include "workfile.h"
#include "ampul.h"
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

int main() {
	Ampul ampules;
	string filein = enter_filename();

	char error_buf[255];
	ofstream out(filein, ios::binary | ios::app);

	if (!out.is_open()) {
		cout << "Can't open file " << endl;
		return 0;
	}
	
	int year;
	cout << "Enter start year: ";
	cin >> year;
	
	char check;

	while (true) {
		enter_ampule(ampules);
		save_ampule_to_file(out, ampules);
		cout << "\nDo you want to add one more ampule [y/n]?: ";
		cin >> check;

		if (check != 'y' && check != 'Y') break;
	}
	out.close();

	print_file(filein);
}
