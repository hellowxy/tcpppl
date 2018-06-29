#include"Parser.h"
#include"Lexer.h"
#include<sstream>
#include<string>
#include"Error.h"
#include"Parser_interface.h"
using namespace Error;
using namespace Lexer;


double Parser::prim(std::istream &in,bool get)
{
    if(get)
    {
        get_token(in);
    }
    switch(curr_tok)
    {
        case Lexer::NUMBER:
        {
            double v = number_value;
            get_token(in);
            return v;
        }
        case Lexer::NAME:
        {
            double& v = table[string_value];
            if(get_token(in) == Lexer::ASSIGN)
            {
                v = expr(in, true);
            }
            return v;
        }
        case Lexer::MINUS:
        {
            return -prim(in, true);
        }
        case Lexer::LP:
        {
            double e = expr(in, true);
            if(curr_tok != Lexer::RP)
            {
                throw Syntax_error(") expected");
            }
            get_token(in); //?????')'
            return e;
        }
        default:
            throw Syntax_error("primary expected");
    }
}

double Parser::term(std::istream &in,bool get)
{
    double left = prim(in, get);
    for(;;)
    {
        switch(curr_tok)
        {
            case Lexer::MUL:
                left *= prim(in, true);
                break;
            case Lexer::DIV:
                if(double d = prim(in, true))
                {
                    left /= d;
                    break;
                }
                throw Syntax_error("divide by 0");
            default:
                return left;
        }
    }
}

double Parser::expr(std::istream &in, bool get)
{
    double left = term(in, get);
    for(;;)
    {
        switch(curr_tok)
        {
            case Lexer::PLUS:
                left += term(in, true);
                break;
            case Lexer::MINUS:
                left -= term(in, true);
                break;
            default:
                return left;
        }
    }
}

double Parser_interface::expr(std::istream& in, bool get)
{
    return Parser::expr(in, get);
}
