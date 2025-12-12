#include <array>
#include <iostream>
#include <numeric>

namespace my
{

template<class T>
class Iterator
{
public:
    using reference = Iterator<T>&;
    using value_type = T;
public:
    Iterator(T* data) : data_(data) {}

    bool operator==(Iterator<T> rhs)
    {
        return data_ == rhs.data_;
    }

    bool operator!=(Iterator<T> rhs)
    {
        return !(*this == rhs);
    }

    reference operator++()
    {
        data_ += 1;
        return *this;
    }

    value_type operator*()
    {
        return *data_;
    }
private:
    T* data_ = nullptr;
};

template<class T, size_t n>
class array
{
public:
    using iterator = Iterator<T>;
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

    iterator begin()
    {
        return iterator{data_};
    }

    iterator end()
    {
        return iterator{data_+size_};
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
        my::array<int32_t, 5> arr = {1, 4, 2, 3, 5};
        std::cout << arr[10] << std::endl;
        //std::cout << arr.at(10) << std::endl; <-- out_of_range

        for (auto num : arr)
        {
            std::cout << num << " ";
        }
        std::cout << std::endl;

        auto sum = std::accumulate(std::begin(arr), std::end(arr), 0);
        std::cout << "Sum of all array elements is " << sum << std::endl;

        // std::sort(std::begin(arr), std::end(arr)); <-- нужно реализовать методы для итератора произвольного доступа.
    }
    return 0;
}
