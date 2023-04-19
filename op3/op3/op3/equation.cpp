#include <iostream>
#include <utility>

#include "equation.h"


void Equation::setA(int new_a) {
    a = new_a;
}


int Equation::getA() {
    return a;
}


void Equation::setB(int new_b) {
    b = new_b;
}


int Equation::getB() {
    return b;
}


void Equation::setC(int new_c) {
    c = new_c;
}


int Equation::getC() {
    return c;
}


int Equation::findDisc() {
    return b * b - 4 * a * c;
}


bool Equation::hasRealRoot() {
    return findDisc() >= 0;
}


void enter_equation(Equation& equation, int equation_index_now) {
    int new_a, new_b, new_c;
    std::cout << "\nEnter Equation #" << equation_index_now << " information: \n";
    std::cout << "a = ";
    std::cin >> new_a;
    equation.setA(new_a);
    std::cout << "b = ";
    std::cin >> new_b;
    equation.setB(new_b);
    std::cout << "c = ";
    std::cin >> new_c;
    equation.setC(new_c);
}


int input_equations(Equation* all_equations_list) {
    Equation equation;
    int equation_index_now = 1;

    while (true) {
        enter_equation(equation, equation_index_now);

        all_equations_list[equation_index_now - 1] = equation;

        if (check_continue()) {
            std::cout << "\nAll Equations: \n";
            for (int index = 0; index < equation_index_now; index++) {
                std::cout << all_equations_list[index].getA() << "x^2 + " << all_equations_list[index].getB() << "x + " << all_equations_list[index].getC() << " = 0\n";
            }
            break;
        }

        equation_index_now++;
    }

    return equation_index_now;
}


void filter_by_disc(Equation* all_equations_list, int equations_length) {

    for (int index = 0; index < equations_length; index++) {
        if (!all_equations_list[index].hasRealRoot()) {
            std::cout << "\nEquation #" << index+1 << " has no real root" << std::endl;
        }
        //std::cout << "\n" << all_equations_list[index].findDisc();
    }
}


bool check_continue() {
    char continue_flag;

    std::cout << "\nDo you want to add one more Equation [y/n]?: ";
    std::cin >> continue_flag;

    if (continue_flag != 'y' && continue_flag != 'Y') {
        return true;
    }

    return false;
}