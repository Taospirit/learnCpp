#include <iostream>
#include "complex.h"

int main()
{
    // std::cout << "hello cpp" << std::endl;
    complex c1(1, 1);
    complex c2(2, 2);
    std::cout << c1;
    c1 += c2;
    std::cout << c1;
    std::cout << -c1;
    std::cout << +c1;
    std::cout << (c1 + 7);
    return 0;
}