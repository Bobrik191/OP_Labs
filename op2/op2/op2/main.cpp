#include "workfile.h"
#define _CRT_SECURE_NO_WARNINGS

/*�������� ���� �� ������� ��������� ����� : �����, ����� 䳿 ���� ��������(�� �������� - ��:��),
����� ��������� ������������� ������(� �����).
���� - ���� ���������� ��� ������, ����� ��������� ���� ��������� ���� ��.
������ ������������ ��� ��������� ������ ��������� ������ �� 10 ���.
*/
using namespace std;

int main() {
	//cout << sizeof(size_t);
	string filename = get_filename();
	append_file(filename);

	read_data(filename);
}
