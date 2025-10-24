#include <iostream>

int getMaxAge()
{
    return 100;
}

class Logger
{
public:
    Logger() = default;
    void log(const std::string& message)
    {
        std::cout << message << std::endl;
    }
};

class Dachshund
{
//private:
   static const int MAX_AGE = 100;
public:
    // конструктор
    Dachshund(uint8_t age, const std::string& name = "temporary") : weight(0), name_(name)
    {
        age_ = age;
    }

    Dachshund(const std::string& name) : name_(name)
    {
    }

    Dachshund& operator=(const Dachshund& rhs) = default;

    ~Dachshund() {} // деструктор

    uint8_t getAge() const
    {
        logger_.log("Hello, Roksy");
        return age_;
    }

    uint8_t getAge()
    {
        logger_.log("Hello, Roksy");
        return age_;
    }

    void changeAge()
    {
        age_ += 1;
    }

    static int getMaxAge() { return MAX_AGE; }
public:
    uint8_t weight = 0;
private:
    uint8_t age_ = 0; // закрытый член класса
    const std::string& name_;
    mutable Logger logger_;
};

int main()
{
    std::string name{"roksy"};
    Dachshund roksy{name};
    [[maybe_unused]]auto weight = roksy.weight;
    roksy.getAge();
    roksy.changeAge();
    Dachshund::getMaxAge();
    const Dachshund shokolad{"shokolad"};
    shokolad.getAge();
    //shokolad.changeAge();
    //Dachshund::MAX_AGE;
}
