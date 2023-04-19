#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "ampul.h"

using namespace std;

string enter_filename();
void enter_ampule(Ampul& ampule);
void save_ampule_to_file(ofstream& out, Ampul& ampul);
void print_file(const string& filename);