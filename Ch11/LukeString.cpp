#include"LukeString.h"
#include<cstring>
#include<sstream>
#include<string>
#include<vector>
#include<cctype>
#include<iostream>
using std::strlen;
using std::ostream;
using std::istream;
using std::vector;
using std::isspace;

LukeString::LukeString()
{
    rep = new Srep(0, "");
}

LukeString::LukeString(const char* c)
{
    rep = new Srep(strlen(c), c);
}

LukeString::LukeString(const LukeString& ls)
{
    ls.rep->n++;
    rep = ls.rep;
}

LukeString& LukeString::operator=(const char* c)
{
    if(rep->n == 1)
    {
        rep->assign(strlen(c), c);
    }
    else
    {
        rep->n--;
        rep = new Srep(strlen(c), c);
    }
    return *this;
}

LukeString& LukeString::operator=(const LukeString& ls)
{
    ls.rep->n++;
    if(--rep->n == 0)
    {
        delete rep;
    }
    rep = ls.rep;
    return *this;
}

LukeString::~LukeString()
{
    if(--rep->n == 0)
    {
        delete rep;
    }
}

ostream& operator<<(ostream& os, const LukeString& ls)
{
    os << ls.rep->s;
    return os;
}

istream& operator>>(istream& is, LukeString& ls)
{    
    char c;
    while(is.get(c) && isspace(c)){}//跳过所有前导空格
    if(!isspace(c))
    {
        is.putback(c);
    }
    
    vector<char> vec;
    while(is.get(c))
    {
        if(isspace(c))
        {
            is.putback(c);
            vec.push_back('\0');
            break;
        }  
        else
        {
            vec.push_back(c);
        }
    }
    
    char *p = new char[vec.size()];    
    int i = 0;
    while(i < vec.size())
    {
        p[i] = vec[i];
        i++;
    }
    
    ls = p; //利用赋值运算符
    delete[] p;
    return is;
}

LukeString& LukeString::operator+=(const LukeString& ls)
{
    char *p = new char[ls.rep->sz + rep->sz + 1];
    char *c = p;
    strcpy(c, rep->s);
    c = c + rep->sz;
    strcpy(c, ls.rep->s);
    *this = p;
    return *this;
}

LukeString& LukeString::operator+=(const char* p)
{
    return this->operator+=(LukeString(p));
}

LukeString operator+(const LukeString& x, const LukeString& y)
{
    LukeString temp = x;
    temp += y;
    return temp;
}

LukeString operator+(const LukeString& x, const char* p)
{
    return operator+(x, LukeString(p));
}

LukeString::Cref LukeString::operator[](int i)
{
    check(i);
    return Cref(*this, i);
}
