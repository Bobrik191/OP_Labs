#pragma once
#include <iostream>

using namespace std;

char* FP_enter_name();
void FP_is_open(FILE* file, char* filename);
void FP_print_file(char* filename);
void FP_write_to_file(char* filename);
char* FP_read_text(char* filename);
void FP_work_file(const char* filename1, const char* filename2);
void FP_replaceDuplicatesWithBrackets(const char* str, const char* filename);