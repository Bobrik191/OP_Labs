#pragma once
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Ampul
{
	string name;
	string validity;
	int storageYears;

	/*void ampule_input() {
		cout << "Enter name of ampule: ";
		cin >> name;
		cout << "Enter expiration date after opening(in format HH:MM): ";
		cin >> validity;
		cout << "Enter the shelf life of unopened ampule(in years): ";
		cin >> storageYears;
	}

	void print_ampule() {
		cout << setw(20) << name;
		cout << setw(10) << validity;
		cout << setw(10) << storageYears;
	}*/
};