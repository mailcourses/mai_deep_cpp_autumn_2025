[[nodiscard("Some reason")]]
inline int square(int num)
{
    return num * num;
}

void foo()
{
    [[maybe_unused]] auto res = square(4);
}

void foo(int num = 10)
{
    [[maybe_unused]] auto res = square(num);
}

[[maybe_unused]] static void boo()
{
    foo(20);
}

namespace {
    [[maybe_unused]] void boo()
    {
    }
}

namespace Boo {
    [[maybe_unused]] void boo()
    {
    }
}
