#include "utils.hpp"

template<class T>
T square(T num)
{
    return num * num;
}

template int square<int>(int);
template double square<double>(double);
