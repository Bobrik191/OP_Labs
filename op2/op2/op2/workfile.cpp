#include "workfile.h"

using namespace std;

struct ampule
{
    //string name;
    char name[256];
    int hours;
    int minutes;
    int storageYears;

    int year;
    int month;
    int day;
};

string get_filename() {
    string filename;
    cout << "Please enter name of the file (for example file.bin): ";
    cin >> filename;
    return filename;
}

bool isLeapYear(int year) {
    // Проверка, является ли год високосным
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            return true;
        }
    }
    else {
        return false;
    }
}

int getDaysInMonth(int month, int year) {
    // Определение количества дней в месяце
    if (month == 2) {
        if (isLeapYear(year)) {
            return 29;
        }
        else {
            return 28;
        }
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }
    else {
        return 31;
    }
}

void inputDate(int& day, int& month, int& year) {
    std::cin >> day;
    std::cin.ignore();
    std::cin >> month;
    std::cin.ignore();
    std::cin >> year;

    if (day < 1 || month < 1 || month > 12 || year < 1) {
        std::cout << "Incorrect date" << std::endl;
        exit(1);  // Завершение работы программы с кодом ошибки
    }

    // Проверка, является ли введенный день корректным для выбранного месяца
    if (day > getDaysInMonth(month, year)) {
        std::cout << "Incorrect day" << std::endl;
        exit(1);  // Завершение работы программы с кодом ошибки
    }
}

int currentYear, currentMonth, currentDay;

void append_file(string filename) {
    ofstream fout(filename, ios::binary | ios::app);

    if (!fout.is_open()) {
        std::cout << "Something went wrong!!!" << endl;
        exit;
    }
    //int day, month, year;
    cout << "\nEnter current date: ";
    inputDate(currentDay, currentMonth, currentYear);

    char ch = 'y';
    ampule ampl;


    while (ch == 'y' || ch == 'Y') {
        cout << "\n";
        cout << "Enter name of ampule: ";
        cin.ignore();
        //cin.getline(cin, ampl.name);
        cin.getline(ampl.name, sizeof(ampl.name));

        cout << "Enter expiry after opening(HH:MM): ";
        scanf_s("%d:%d", &ampl.hours, &ampl.minutes);

        cout << "Enter storage period: ";
        cin >> ampl.storageYears;

        cout << "Enter date of ampule opening: ";
        inputDate(ampl.day, ampl.month, ampl.year);

        fout.write((char*)&ampl, sizeof(ampule));

        cout << "If you want to add more workers print \"Y\" else print \"N\": ";
        cin >> ch;
    }

    cout << "\nInformation was successfully added to file!\n" << endl;
    fout.close();
}

void read_data(string filename) 
{
    ifstream fin(filename, ios::binary);
    if (!fin.is_open()) {
        cout << "Something went wrong!!!" << endl;
        exit;
    }

    fin.seekg(0, ios::end);
    int ampulesCount = fin.tellg() / sizeof(ampule);
    fin.seekg(0, ios::beg);

    ampule* ampules = new ampule[ampulesCount];

    ofstream fout(filename + ".bin", std::ios::binary);

    cout << "\nData in \"" << filename << "\":" << endl;
    cout << "\n";

    cout << "Current date: " << currentDay << "." << currentMonth << "." << currentYear << "\n" << endl;

    for (int i = 0; i < ampulesCount; i++) {
        fin.read(reinterpret_cast<char*>(&ampules[i]), sizeof(ampule));

        // Перевірка на прострочений термін дії
        int openingYear = ampules[i].year;
        int openingMonth = ampules[i].month;
        int openingDay = ampules[i].day;

        // Розрахунок різниці у роках між поточною датою та датою відкриття
        int yearsPassed = currentYear - openingYear - ampules[i].storageYears;
        if (currentMonth < openingMonth || (currentMonth == openingMonth && currentDay < openingDay)) {
            yearsPassed--; // Зменшуємо різницю, якщо поточна дата менша за дату відкриття
        }

        if (yearsPassed <= 1) {
            fout.write(reinterpret_cast<char*>(&ampules[i]), sizeof(ampule));

            // Виведення інформації про ампулу
            cout << "----------------------------------------------\n";
            cout << "Name: " << ampules[i].name << std::endl;
            cout << "Expiry after opening: " << ampules[i].hours << ':' << ampules[i].minutes << std::endl;
            cout << "Storage years: " << ampules[i].storageYears << std::endl;
            cout << "----------------------------------------------";
            cout << "\n";
        }
        int expiryYear = openingYear + yearsPassed + ampules[i].storageYears;
        int expiryMonth = openingMonth;
        int expiryDay = openingDay;
        expiryMonth += expiryDay / 30;
        expiryDay %= 30;
        expiryYear += expiryMonth / 12;
        expiryMonth %= 12;


        int daysLeft = expiryDay - currentDay;
        int monthsLeft = expiryMonth - currentMonth;
        int yearsLeft = expiryYear - currentYear;

        if (daysLeft <= 10 && daysLeft > 0 && monthsLeft <= 0 && yearsLeft <= 0) {
            std::cout << "The expiry date is less than 10 days remaining!" << daysLeft << std::endl;
        }
    }


    fin.close();
    fout.close();

    // Видалення вихідного файлу та перейменування тимчасового файлу
    std::remove(filename.c_str());
    std::rename((filename + ".bin").c_str(), filename.c_str());
}
