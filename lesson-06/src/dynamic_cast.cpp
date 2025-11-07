#include <iostream>

struct A
{
    virtual void foo() = 0;
};

struct B : A
{
    virtual void foo() override
    {
        std::cout << "B::foo" << std::endl;
    }

    void secret()
    {
        std::cout << "B::secret" << std::endl;
    }
};

struct C : A
{
    virtual void foo() override
    {
        std::cout << "C::foo" << std::endl;
    }
};

void convert(A* a)
{
    B* b = dynamic_cast<B*>(a);
    if (b == nullptr)
    {
        std::cerr << "Failed to cast to B*" << std::endl;
        return;
    }
    b->secret();
}

void convert(A& a)
{
    B& b = dynamic_cast<B&>(a);
    b.secret();
}

struct Tmp
{
    Tmp(const std::string& data) : data_(const_cast<std::string&>(data))
    {
        std::cout << "Tmp::data_ = " << data_ << std::endl;
    }
    std::string& data_;
};

int main()
{
    Tmp tmp("Hello, world");
    std::cout << tmp.data_ << std::endl;
    {
        A* a = new B;
        convert(a);
        convert(*a);
    }
    {
        A* a = new C;
        convert(a);
        convert(*a);
    }
    return 0;
}

