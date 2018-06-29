#include"Lexer.h"
#include"Error.h"
#include<sstream>
#include<iostream>
#include<string>
using namespace Error;
using std::string;

namespace Lexer
{
    
    Token_value curr_tok(NAME);
    double number_value;
    std::string string_value;
    
    /*
        词法分析，分析输入的字符串是哪些token
    */
    Token_value get_token(std::istream& input)
    {
        char ch;
        do
        {
            if(!input.get(ch))
            {
                return curr_tok = END;
            }
        }while(ch != '\n' && isspace(ch));//跳过所有空白字符，但是会读到一个不为空白的字符
    
        switch(ch)
        {
            case '\n':
                return curr_tok = PRINT;
            case ';':
            case '+':
            case '-':
            case '*':
            case '/':
            case '(':
            case ')':
            case '=':
                //std::cout << Token_value(ch) << std::endl;
                return curr_tok = Token_value(ch);
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            case '.':
                input.putback(ch);
                input >> number_value;
                //std::cout << "NUMBER " << number_value << std::endl;
                return curr_tok = NUMBER;
            default:
                if(isalpha(ch))
                {
                    string_value = ch;
                    while(input.get(ch) && isalnum(ch))
                    {
                        string_value.push_back(ch);
                    }
                    //std::cout << "NAME " << string_value << std::endl;
                    input.putback(ch);
                    return curr_tok = NAME;
                }
                throw Syntax_error("bad token");
        }
    }
}
