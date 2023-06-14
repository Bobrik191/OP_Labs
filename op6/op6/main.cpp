#include <iostream>
#include "work.h"

int main() {
    std::string type;
    std::cout << "Enter type (int, double, string): ";
    std::cin >> type;
    test_cases(type);

    return 0;
}