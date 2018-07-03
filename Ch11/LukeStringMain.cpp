#include"LukeString.h"
#include<iostream>
using std::cout;
using std::cin;
using std::endl;

LukeString f(LukeString a, LukeString b)
{
    a[2] = 'x';
    char c = b[3];
    cout << "in f:" << a << ' ' << b << ' ' << c << endl;   
    return b;
}

int main()
{
    LukeString x;
    LukeString y;
    cout << "Please enter two strings" << endl;
    cin >> x >> y;
    cout << "input: " << x << ' ' << y << endl;
    LukeString z = x;
    cout <<"z is:" << z << endl;
    y = f(x, y);
    cout << "x is:" << x << endl;
    if(x != z)
    {
        cout << "x corrupted!" << endl;
    }

    x[0] = '!';
    if(x == z)
    {
        cout << "write failed" << endl;
    }
    cout << "exit: " << x << ' ' << y << ' ' << z << endl;
    cout << "========================================================" << endl;
    x = "hello";
    y = "world";
    z = x + y;
    cout << z << endl;
    z += "!!!";
    cout << z << endl;



    return 0;
}