#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <tuple>

using namespace std;

struct ampule;

string get_filename();
void inputDate(int&, int&, int&);
void append_file(string);
void read_data(string);