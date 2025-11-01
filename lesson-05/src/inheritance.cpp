#include <iostream>

class A
{
public:
    int a;
protected:
    int b;
private:
    int c;
};

struct B : A
{
//public:
//int a;
//protected:
//int b;
public:
    B()
    {
        a += 1;
        b += 2;
        //c += 3;
    }
};

int main()
{
    B b;
    b.a += 1;

    A a;
    a.a += 1;
}
