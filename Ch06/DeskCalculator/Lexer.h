#ifndef LEXER_H
#define LEXER_H
#include<string>
#include<sstream>
namespace Lexer
{
    enum Token_value
    {
        NAME,
        NUMBER,
        END,
        PLUS = '+',
        MINUS = '-',
        MUL = '*',
        DIV = '/',
        PRINT = ';',
        ASSIGN = '=',
        LP = '(',
        RP = ')',
    };

    extern Token_value curr_tok;
    extern double number_value;
    extern std::string string_value;

    Token_value get_token(std::istream&);
}
#endif