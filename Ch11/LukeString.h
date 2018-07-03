#ifndef LUKE_STRING_H
#define LUKE_STRING_H
#include<cstring>
#include<sstream>
using std::strcpy;
using std::ostream;
using std::istream;
using std::strcmp;
class LukeString
{
    private:
      
        struct Srep
        {
            char *s;
            int sz; //字符个数
            int n; //引用个数

            Srep(int nsz, const char* p):n(1), sz(nsz)
            {
                s = new char[sz + 1];
                strcpy(s, p);
            }

            ~Srep()
            {
                delete[] s;
            }

            Srep* get_own_copy()
            {
                if(n == 1)
                {
                    return this;
                }
                n--;
                return new Srep(sz, s);
            }

            void assign(int nsz, const char* p)
            {
                if(sz != nsz)
                {
                    delete[] s;
                    sz = nsz;
                    s = new char[sz + 1];
                }
                strcpy(s, p);
            }

            private:
                Srep(const Srep&);
                Srep& operator=(const Srep&);
        };
        Srep *rep;        
    public:
      
        LukeString();
        LukeString(const char*);
        LukeString(const LukeString&);
        LukeString& operator=(const char*);
        LukeString& operator=(const LukeString&);
        ~LukeString();

        void check(int i) const
        {
            if(i < 0 || rep->sz <= i)
            {
                throw Range();
            }
        }

        char read(int i) const{return rep->s[i];}

        void write(int i, char c)
        {
            rep = rep->get_own_copy();
            rep->s[i] = c;
        }

        char operator[](int i) const{check(i); return rep->s[i];}

        int size() const{return rep->sz;}
        class Cref;
        class Range{};        
        Cref operator[](int i);

        LukeString& operator+=(const LukeString& ls);
        LukeString& operator+=(const char*);

        friend ostream& operator<<(ostream&, const LukeString&);
        friend istream& operator>>(istream&, LukeString&);

        friend bool operator==(const LukeString& ls, const char* s)
        {
            return strcmp(ls.rep->s, s) == 0;
        }

        friend bool operator!=(const LukeString& ls, const char* s)
        {
            return !(ls == s);
        }

        friend bool operator==(const LukeString& x, const LukeString& y)
        {
            return strcmp(x.rep->s, y.rep->s) == 0;
        }

        friend bool operator!=(const LukeString& x, const LukeString& y)
        {
            return !(x == y);
        }
};

LukeString operator+(const LukeString&, const LukeString&);
LukeString operator+(const LukeString&, const char*);

class LukeString::Cref
{
    friend class LukeString;
    LukeString& s;
    int i;
    Cref(LukeString& ls, int ii):s(ls), i(ii){}
    public:
        operator char() const{return s.read(i);}
        void operator=(char c){s.write(i, c);}
};

#endif