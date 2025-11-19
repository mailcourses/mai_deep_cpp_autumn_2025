#include <iostream>
#include <vector>

// std::vector<int> v;
// v[i]
template<class C, class I>
auto authAndAccess(const C& container, I idx) -> decltype(container[idx])
{
    // Проверяем авторизацию.
    return container[idx];
}

class Container
{
public:
    using iterator = int;
    static const int const_iterator = 10;
private:
    int* data_;
};

template<class T>
class Parser
{
    typename T::iterator value;
    //T::const_iterator key;
};

int main()
{
    std::vector<int> v(10, -1);
    const int& elem = authAndAccess(v, 5);
    std::cout << authAndAccess(v, 5) << std::endl;
    std::cout << Container::const_iterator << std::endl;
}
