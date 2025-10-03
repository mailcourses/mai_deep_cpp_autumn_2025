#include <cstddef>
#include <string>

#include "square.hpp"

void foo(int /*num*/)
{

}

int global = 0;

struct A
{
    A()
    {
//        global = 1;
    }

/*
    ~A()
    {
//        global = -1;
    }
*/
};

int main()
{
    int a;
    // FYI: если расскоменнтировать, то символ square станет
    // не нужен.
    //for (size_t i = 10; i >= 0; --i);

    size_t b = 10;
    if (a > b) {}

    [[maybe_unused]] int c;

    A tmp;
    std::string tmp2;
    while (true)
    {
        square(1);
    }
    return square(2);
}
