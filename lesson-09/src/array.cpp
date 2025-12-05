#include <array>
#include <iostream>

namespace my
{
template<class T, size_t n>
class array
{
public:
    array(std::initializer_list<T> init)
    {
        size_t i = 0;
        for (auto it = init.begin(); it != init.end(); ++it, ++i)
        {
            data_[i] = *it;
        }
    }

    const T& operator[](size_t pos) const
    {
        return data_[pos];
    }

    const T& at(size_t pos) const
    {
        if (pos >= size_)
            throw std::out_of_range{"array::at"};
        return data_[pos];
    }
private:
    size_t size_ = n;
    T data_[n];
};
} // namespace my

int main()
{
    {
        std::array<int32_t, 5> arr = {1, 2, 3, 4, 5};
        std::cout << arr[10] << std::endl;
    }
    {
        my::array<int32_t, 5> arr = {1, 2, 3, 4, 5};
        std::cout << arr[10] << std::endl;
        std::cout << arr.at(10) << std::endl;
    }
    return 0;
}
