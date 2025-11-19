#include <cstdint>

template<class T>
struct BigInt
{
    BigInt() = default;
    BigInt(T value) : value_(value) {}

    BigInt operator+(const BigInt& rhs)
    {
        BigInt tmp;
        tmp.value_ = value_ + rhs.value_;
        return tmp;
    }

    T value_;
};

template<>
struct BigInt<int32_t>
{
    BigInt() = default;
    BigInt(int32_t value) : value_(value) {}

    BigInt operator+(const BigInt& rhs)
    {
        BigInt tmp;
        value_.data();
        return tmp;
    }

    int32_t value_;
};

int main()
{
    BigInt<double> d1(10.0);
    BigInt<double> d2(20.0);
    d1 + d2;
    return 0;
}

