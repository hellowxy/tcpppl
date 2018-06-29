#ifndef PARSER_H
#define PARSER_H
#include<map>
#include<string>
#include<sstream>
namespace Parser
{
    double prim(std::istream &, bool);
    double term(std::istream &,bool);
    double expr(std::istream &,bool);
    
    std::map<std::string, double> table = {{"pi", 3.141592653}, {"e",2.718281828459045}};    
}
#endif