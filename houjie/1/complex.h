#ifndef __COMPLEX__
#define __COMPLEX__
#include <iostream>
// template<typename T>
class complex
{
public:
    complex(float r = 0, float i = 0):re(r), im(i){}
    // ~complex();
    complex& operator += (const complex& x);

    float real() const {return re;}
    float imag() const {return im;}
private:
    float re, im;
    friend complex& __doapl(complex* ths, const complex& x);
};

inline complex&
__doapl(complex* ths, const complex& x)
{
    ths->re += x.re;
    ths->im += x.im;
    return *ths;
}

inline complex&
complex::operator += (const complex& x){
    // return __doapl(this, x);
    this->re += x.re;
    this->im += x.im;
    return *this;
}

inline complex
operator + (const complex& x, const complex& y)
{
    return complex(x.real() + y.real(), x.imag() + y.imag());
}

inline complex
operator + (const complex& x, float y)
{
    return complex(x.real() + y, x.imag());
}

inline complex
operator + (float x, const complex& y)
{
    return complex(x + y.real(), y.imag());
}

inline std::ostream&
operator << (std::ostream& os, const complex& x)
{  
    return os << "(" << x.real() << "," << x.imag() << ")" << std::endl;
}

inline complex
operator + (const complex& x)
{
    return x;
}

inline complex
operator - (const complex& x)
{
    return complex(x.real(), -x.imag());
}


#endif