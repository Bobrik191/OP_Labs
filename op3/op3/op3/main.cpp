#include <iostream>

#include "equation.h"


int main() {
    Equation all_equations_list[256];

    int equations_length = input_equations(all_equations_list);

    filter_by_disc(all_equations_list, equations_length);
}
