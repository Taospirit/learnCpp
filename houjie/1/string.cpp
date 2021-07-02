#include "string.h"
#include <iostream>
int main()
{
    String s1("aaa");
    String s2("hello");
    
    String s3(s1);
    std::cout << s3 << std::endl;
    s3 = s2;
    std::cout << s3 << std::endl;
}