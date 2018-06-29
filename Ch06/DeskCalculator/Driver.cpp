#include"Parser_interface.h"
#include<sstream>
#include"Error.h"
#include"Lexer.h"
#include<iostream>
using std::cin;
using std::cout;
using std::endl;
using namespace Error;
using namespace Lexer;

int main(int argc, char* argv[])
{
    try
    {
        std::istream *input = nullptr;
        switch(argc)
        {
            case 1:
                input = &cin;
                break;
            case 2:
                input = new std::istringstream(argv[1]);
                break;
            default:
                throw Syntax_error("too many arguments");            
        }    
        
        while(*input)//流有效
        {
            get_token(*input);
            //cout << curr_tok << " " << number_value << " " << string_value << endl;
            if(curr_tok == END)
            {
                break;
            }
            if(curr_tok == PRINT)
            {
                continue;
            }
            cout << Parser_interface::expr(*input, false) << std::endl;
        }

        if(input != &cin)
        {
            delete input;
        }
        return 0;
    }
    catch(Error::Zero_divide& e)
    {
        std::cerr << "divided by zero!!" << endl;
        return -1;
    }
    catch(Error::Syntax_error& e)
    {
        std::cerr << e.p << endl;
        return -1;
    }
}
