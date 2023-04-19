#include <iostream>
//#ifndef LR_3_PRODUCT_H
//#define LR_3_PRODUCT_H


class Equation {
private:
    int a, b, c;
public:
    void setA(int new_a);
    int getA();
    void setB(int new_b);
    int getB();
    void setC(int new_c);
    int getC();
    int findDisc();
    bool hasRealRoot();
};


void enter_equation(Equation& equation, int equation_index_now);

int input_equations(Equation* all_equations_list);

void filter_by_disc(Equation* all_equations_list, int equations_length);

bool check_continue();

//#endif

