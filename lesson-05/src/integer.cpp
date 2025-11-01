#include <iostream>

class Integer
{
public:
    using int_t = int32_t;
    Integer(int_t num) : num_(num) {}

    // ++x
    Integer& operator++()
    {
        num_ += 1;
        return *this;
    }

    // x++
    Integer operator++(int)
    {
        Integer tmp{num_};
        num_ += 1;
        return tmp;
    }

    Integer operator+(const Integer& rhs)
    {
        Integer tmp{num_ + rhs.num_};
        return tmp;
    }

    friend std::ostream& operator<<(std::ostream& os, const Integer& rhs);
private:
    int_t num_;
};

std::ostream& operator<<(std::ostream& os, const Integer& rhs)
{
    os << rhs.num_;
    return os;
}

int main()
{
    Integer num1{1};
    Integer num2{32};
    ++num1;
    num1++;
    std::cout << num1+num2 << std::endl;
    return 0;
}
