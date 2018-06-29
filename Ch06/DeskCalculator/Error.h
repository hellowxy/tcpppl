#ifndef ERROR_H
#define ERROR_H
namespace Error
{
    struct Zero_divide{};

    struct Syntax_error
    {
        const char* p;
        Syntax_error(const char* q)
        {
            p = q;
        }
    };
}
#endif