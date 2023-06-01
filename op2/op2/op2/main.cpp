#include "workfile.h"
#define _CRT_SECURE_NO_WARNINGS

/*Створити файл із списком лікарських ампул : назва, термін дії після відкриття(за шаблоном - ГГ:ХХ),
термін зберігання нерозпакованої ампули(в роках).
Вида - лити інформацію про ампули, термін зберігання яких перевищив один рік.
Видати попередження про закінчення терміну зберігання ампули за 10 днів.
*/
using namespace std;

int main() {
	//cout << sizeof(size_t);
	string filename = get_filename();
	append_file(filename);

	read_data(filename);
}
