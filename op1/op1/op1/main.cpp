#include <iostream>
#include "Stream.h"
#include "FileP.h"
#include "util.h"

/*16. Створити текстовий файл. Слова у тексті відділені пробілами, комами, крап- ками. 
У кожному рядку даного тексту визначити найдовшу послідовність підряд ідучих однакових символів. 
Переставити слова, що містять знайдені послідовності на початок відповідного рядка. 
Якщо таких слів у рядку декілька, то переставити ці слова на початок у порядку їхнього слідування у рядку. 
Усі змінені рядки вхідного файлу переписати у новий текстовий файл. 
Видалити у словах нового текстового файлу усі символи-дублікати, обмеживши фігурними дужками символ, що повторюється. 
Наприклад, слово abccccd повинно бути змінене на слово ab{c} d. Вивести вміст вхідного і створеного файлів.*/

using namespace std;

int main(int argc, char* argv[]) {
	int mode = set_mode(argc, argv);

	if (mode == -1) {
		cout << "Invalid specified" << endl;
		return 1;
	}
	if (mode == 1) {
		cout << "FilePointer mode" << endl;
		char* filein = FP_enter_name();
		FP_write_to_file(filein);
		char* fileout = FP_enter_name();
	
		FP_print_file(filein);

		char* str1 = FP_read_text(filein);
		FP_work_file(str1, fileout);
		FP_print_file(fileout);

		char* str = FP_read_text(fileout);
		FP_replaceDuplicatesWithBrackets(str, fileout);
		FP_print_file(fileout);
	}
	else if (mode == 2) {
		cout << "FileStream mode" << endl;
		string file1 = enter_name();
		write_to_file(file1);

		string fileout = enter_name();

		print_file(file1);

		string str = read_file(file1);
		work_file(str, fileout);
		print_file(fileout);

		string interm = read_file(fileout);
		string result = replaceDuplicatesWithBrackets(interm);
		add_data_to_file(fileout, result);
		print_file(fileout);
	}
	return 0;
}