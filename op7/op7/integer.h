#pragma once
//#include <stdexcept>
using namespace System;
namespace op7 {
    ref class Integer
    {
    private:
        int Value;
    public:
        Integer(int value1);
        int FindGCD(Integer^ other);
    };
}

