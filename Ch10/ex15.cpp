#include<iostream>

class A
{
    public:
    A()
    {
        std::cout << "Initialize" << std::endl;
    }

    ~A()
    {
        std::cout << "Clean up" << std:: endl;
    }
};

A a;
int main()
{
    std::cout << "Hello, world!\n";
    return 0;
}