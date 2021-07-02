#ifndef __MYSTRING__
#define __MYSTRING__

#include <cstring>
class String
{
public:
    String(const char* cstr = 0);
    String(const String& str); // 拷贝构造
    String& operator = (const String& str);  // 拷贝赋值
    ~String();
    char* get_c_str() const { return m_data; }

private:
    char* m_data;


};

inline
String::String(const char* cstr)
{
    if (cstr){// c api: strlen, strcpy
        m_data = new char[strlen(cstr)+1];
        strcpy(m_data, cstr);
    } else {
        m_data = new char[1];
        *m_data = '\0'; // 字符串结束符
    }
}

inline
String::String(const String& str)
{
    m_data = new char[strlen(str.m_data) + 1];
    strcpy(m_data, str.m_data);
}

inline String&
String::operator = (const String& str)
{   
    if (this == &str)
        return *this;

    delete[] m_data;
    m_data = new char[strlen(str.m_data) + 1];
    strcpy(m_data, str.m_data);
    return *this;
}

inline 
String::~String()
{
    delete[] m_data;
}

#include <iostream>
inline std::ostream&
operator << (std::ostream& os, const String& str)
{
    os << str.get_c_str();
    return os;
}

#endif