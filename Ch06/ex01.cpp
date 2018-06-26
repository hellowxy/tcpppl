#include<iostream>
using std::cout;
int main()
{    
    int i;
    const int max_length = 255;
    char input_line[max_length] = "a fox jump over a red dog ? no!! why? haha.";
    int quest_count = 0;
    for(i=0; i < max_length; i++)
    {
        if(input_line[i] == '?')
        {
            quest_count++;
        }
    }
    cout << quest_count << std::endl;

    i = 0;
    quest_count = 0;
    while(i < max_length)
    {
        if(input_line[i] == '?')
        {
            quest_count++;
        }
        ++i;
    }
    cout << quest_count << std::endl;

    quest_count = 0;
    for(char *p = input_line; *p != '\0'; p++)
    {
        if(*p == '?')
        {
            quest_count++;
        }
    }
    cout << quest_count << std::endl;
    return 0;
}