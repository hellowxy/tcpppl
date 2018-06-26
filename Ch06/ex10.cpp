#include<iostream>
#include<cctype>
using std::cout;
using std::endl;
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

        int ret = 0;
        
        while(*sz >= '0' && *sz <= '9')
        {
            ret = ret * 10 + (int)*sz - 48;
            sz++;
        }
        return ret * factor;
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

}