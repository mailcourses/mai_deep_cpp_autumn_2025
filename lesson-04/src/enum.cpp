#include <iostream>

enum class Color
{
    UNKNOWN = 0,
    RED,
    WHITE,
    BLACK
};

enum class HttpCode
{
    UNKNOWN = 0,
    OK = 200,
    NOT_FOUND = 404
};

union Jack
{
    double a;
    bool b;
    int32_t c;
    char d;
};

int main()
{
    Color cat = Color::RED;
    HttpCode code = HttpCode::UNKNOWN;
    std::cout << sizeof(Jack) << std::endl;
    Jack jack;
    jack.a = 134434524.345345345355;
    std::cout << jack.a << std::endl;
    std::cout << std::boolalpha << jack.b << std::endl;
    std::cout << jack.d << std::endl;
    return 0;
}
