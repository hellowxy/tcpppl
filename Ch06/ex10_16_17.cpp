#include<iostream>
#include<cctype>
#include<string>
using std::cout;
using std::endl;
using std::string;
namespace luke
{
    int strlen(const char* sz)
    {
        const char *p = sz;
        while(*p++ != '\0');
        return p - sz - 1;
    }

    char *strcpy(char *dest, const char *src)
    {
        char *s = dest;
        while(*s++ = *src++);
        return dest;
    }

    int strcmp(const char *str1, const char *str2)
    {
        int ret = 0;
        unsigned char* ustr1 = (unsigned char*)str1;
        unsigned char* ustr2 = (unsigned char*)str2;
        while(!(ret = (*ustr1 - *ustr2)) && *ustr2)
        {
            ustr1++;
            ustr2++;
        }
        if(ret < 0)
        {
            return -1;
        }
        else if(ret > 0)
        {
            return 1;
        }

        return ret;
    }

    char* cat(const char* s1, const char* s2)
    {
        size_t s1_len = strlen(s1);
        size_t s2_len = strlen(s2);
        char *p = new char[s1_len + s2_len + 1];
        strcpy(p, s1);
        char *p1 = p + s1_len;
        strcpy(p1,s2);
        p[s1_len + s2_len + 1] = '\0';
        return p;
    }

    const char* rev(char* p)
    {
        int len = strlen(p);
        for(int i = 0; i< len/2; ++i)
        {
            char c = p[i];
            p[i] = p[len - i - 1];
            p[len - i - 1] = c;
        }
        return p;
    }

    int char_to_int(char c)
    {
        if(c >='0' && c <='9')
        {
           return (int)c - (int)'0';  
        }
        switch(c)
        {
            case 'a':
            case 'A':
                return 10;
            case 'b':
            case 'B':
                return 11;
            case 'c':
            case 'C':
                return 12;
            case 'd':
            case 'D':
                return 13;
            case 'e':
            case 'E':
                return 14;
            case 'f':
            case 'F':
                return 15;
            default:
                return 0;
        }        
    }

    bool isLeagalChar(char c, int base)
    {
        if(base == 10)
        {
            return c >='0' && c <= '9';
        }

        if(base ==16)
        {
            return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F');
        }

        if(base == 8)
        {
            return c >= '0' && c <= '7';
        }
        return false;
    }

    int atoi(const char* sz)
    {
        //处理所有前导空白字符
        while(std::isspace(*sz))
        {
            sz++;
        }

        //处理正负号
        int factor = 1;
        if(*sz == '+')
        {
            sz++;
        }
        else if(*sz == '-')
        {
            sz++;
            factor = -1;
        }

        int base = 10; // 默认十进制
        //判断是八进制还是十六进制
        if(*sz == '0')
        {
            char next = *(++sz);
            if(next == 'x' || next == 'X')
            {
                ++sz;
                base = 16;
            }
            else if(isLeagalChar(next, 8))
            {
                base = 8;
            }
        }
        int ret = 0;

        while(isLeagalChar(*sz, base))
        {         
            ret = ret * base + char_to_int(*sz);
            sz++;
        }
        return ret * factor;
    }

    int atoi(const string& s)
    {
        return atoi(s.c_str());
    }

    void itoa(int i, char b[])
    {     
        if(i < 0)
        {
            *b++ = '-';
            i = -i;            
        }
        char *dPos = b;  
        int remainder = 0;
        while( (remainder = i % 10) != 0)
        {            
            i = i / 10;
            *b++ = remainder + (int)'0';
        }
        *b = '\0';
        rev(dPos);
    }
    
} // namespace luke

int main()
{
    char sz[] = "just for test";
    char sz1[] = " another string";
    char sz2[] = "just for";
    cout << luke::strlen(sz) << endl;
    cout << luke::strcmp(sz, sz1) << endl;
    char* p = luke::cat(sz, sz1);
    cout << p << endl;
    luke::rev(p);
    cout << p << endl;

    char sz3[] = "100";
    cout << luke::atoi(sz3) << endl;
    char sz4[] = "-100";
    cout << luke::atoi(sz4) << endl;
    char sz5[] = "    +100";
    cout << luke::atoi(sz5) << endl;
    char sz6[] = "    -100a";
    cout << luke::atoi(sz6) << endl;

    char sz7[] = "    -08";
    char sz8[] = "  -0xfff";
    cout << luke::atoi(sz7) << endl;
    cout << luke::atoi(sz8) << endl;
    string s("0x1a");
    cout << luke::atoi(s) << endl;

    char sz9[255] = {0};
    luke::itoa(123, sz9);
    cout << sz9 << endl;
    luke::itoa(-12, sz9);
    cout << sz9 << endl;
}