#include "workfile.h"
#include "ampul.h"

string enter_filename()
{
	string name;
	cout << "Enter file name: ";
	getline(cin, name);
	return name;
}

void enter_ampule(Ampul& ampule) {
    cout << setfill('-') << setw(30) << '-' << endl;
    cout << "Name: ";
    cin >> ampule.name;
    cout << "Enter expiration date after opening(in format HH:MM): ";
    cin >> ampule.validity;
    cout << "Enter the shelf life of unopened ampule(in years): ";
    cin >> ampule.storageYears;
}


void save_ampule_to_file(ofstream& out,Ampul& ampul) {
    out.write((char*)&ampul, sizeof(Ampul));
    //cout << "[INFO] Written bytes: " << out.tellp() << std::endl;
}

void print_ampules(Ampul& ampule) {
    cout << setfill('-') << setw(30) << '-' << endl;
    std::cout << "Name: " << ampule.name << std::endl;
    std::cout << "Validity: " << ampule.validity << std::endl;
    std::cout << "Storage years: " << ampule.storageYears << std::endl;
    cout << setfill('-') << setw(30) << '-' << endl;
}

void print_file(const string& filename) {
    ifstream in(filename, ios::binary);
    if (!in.is_open()) {
        cout << "Can't open file!" << endl;
        return;
    }

    in.seekg(0, ios::end);	
    size_t num = in.tellg();	
    in.seekg(0, ios::beg);
    size_t size = num / sizeof(Ampul);

    Ampul* ampules = new Ampul[size];
    for (size_t i = 0; i < size; i++) {
        in.read((char*)&ampules[i], sizeof(Ampul));
        print_ampules(ampules[i]);
    }
    
    delete[] ampules;
    in.close();
}