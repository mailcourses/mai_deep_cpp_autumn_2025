#include <iostream>

extern "C"
{

int32_t fibonacci(size_t num)
{
    if (num <= 2)
        return 1;
    return fibonacci(num - 1) + fibonacci(num - 2);
}

int32_t sum(int32_t size, int32_t* arr)
{
    int32_t res = 0;
    for (size_t i = 0; i < size; ++i)
    {
        res += arr[i];
    }
    return res;
}
}
