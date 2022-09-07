#ifndef __COMPLEX__
#define __COMPLEX__ 

// 防御性声明，结构如下
// #ifndef __xxx__
// #define __xxx__
// ...
// #endif

#include <iostream>
// template<typename T>
class complex
{
public:
    // 构造函数，不需要返回类型。下面是构造函数的独特写法。用:来直接赋值
    complex(float r = 0, float i = 0) : re(r), im(i) {}
    // 下面的构造方式和上面的结果，但是上面这个方式更好。
    // complex (float r = 0, float i = 0)
    // { re = r; im = i;}

    // ~complex();

    float real() const {return re;}
    float imag() const {return im;} // inline的结构，直接return
    // const 常量成员函数
    // 当不改变数据内容（只读）时，建议在函数名后用const修饰。
    // 当声明一个新complex变量前加上 const 时，如果在其实现的函数中没有const，调用会报错。
    // 示例：
    // float real() { return re;}
    // 
    // const complex c1(2, 1);
    // std::cout << c1.real() << std::endl; // 这里会报错，因为real()中没有const修饰 

    complex& operator += (const complex& x);
    // 在数据类型后加上&，是引用传递。如果希望传递的值不被修改，在前面加上const。
    // 在return也可以用引用，即返回引用。


    // 一个完整的函数结构大概如下：
    // 数据类型 函数名 (参数列表) 
    // {
    //     ...
    //     return 相同数据类型
    // }

    int func(const complex& param)
    { return param.re + param.im; }
    // 上面这个函数说明：同一个class的不同object互为友元

private: // 私有数据成员不能直接反问
    float re, im;

    friend complex& __doapl(complex* ths, const complex& x);
    // 友元函数
};

inline complex&
__doapl(complex* ths, const complex& x)
{
    ths->re += x.re;
    ths->im += x.im;
    // 友元函数，可以直接取得private的数据
    return *ths;
}

inline complex&
complex::operator += (const complex& x){
    // return __doapl(this, x);
    this->re += x.re; // this理解成python里的self.
    this->im += x.im;
    return *this;
}

// 下面是 + 操作符的三种情况实现。
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

// 取正和取反操作
inline complex
operator + (const complex& x)
{
    return x;
}

inline complex
operator - (const complex& x)
{
    return complex(-x.real(), -x.imag());
}

inline bool
operator == (const complex& x, const complex& y)
{
    return x.real() == y.real() 
        && x.imag() == y.imag();
}

inline bool 
operator == (const complex& x, float y)
{
    return x.real() == y && x.imag() == 0;
}

inline bool 
operator == (float x, const complex& y)
{
    return x == y.real() && y.imag() == 0;
}

inline complex
conj (const complex& x)
{
    return complex(x.real(), -x.imag());
}

// 重载运算符 << 
inline std::ostream&
operator << (std::ostream& os, const complex& x)
{  
    return os << "(" << x.real() << "," << x.imag() << ")" << std::endl;
}
#endif