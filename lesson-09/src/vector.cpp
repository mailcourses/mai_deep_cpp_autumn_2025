#include <iostream>
#include <vector>

namespace my
{

template<class T>
class vector
{
public:
    vector(std::initializer_list<T> init) : size_(init.size()), capacity_(init.size())
    {
        auto it = init.begin();
        auto end = init.end();
        size_t i = 0;
        data_ = new T[size_];
        while (it != end)
        {
            data_[i++] = *it;
            std::cout << "[vector] " << *it << std::endl;
            //auto tmp = std::next(it);
            //std::cout << "[vector] after next it=" << *it << std::endl;
            //std::cout << "[vector] after next tmp=" << *tmp << std::endl;
            ++it;
        }
    }

    void push_back(const T& value)
    {
        if (capacity_ == size_)
        {
            capacity_ *= 2;
            std::cout << "allocate capacity memory" << std::endl;
            T* tmp = new T[capacity_];
            for (size_t i = 0; i < size_; ++i)
            {
                tmp[i] = data_[i];
            }
            delete[] data_;
            data_ = tmp;
        }
        data_[size_] = value;
        size_ += 1;
    }

    size_t size() const
    {
        return size_;
    }

    ~vector()
    {
        delete[] data_;
    }
private:
    T* data_ = nullptr;
    size_t size_ = 0;
    size_t capacity_ = 0;
};

} // namespace my

// n + n/2 + n/4 + n/8+ ... = n(1 + 1/2 + 1/4 + 1/8) = 2n -> O(2n) = O(n)
int main()
{
    {
        my::vector<int32_t> v = {1};
        for (size_t i = 0; i < 10; ++i)
        {
            v.push_back(i);
        }
    }

    {
        std::vector<int32_t> v(50, -1);
        std::cout << v.size() << ":" << v.capacity() << std::endl;
        v.reserve(1);
        std::cout << v.size() << ":" << v.capacity() << std::endl;
        v.clear();
        std::cout << v.size() << ":" << v.capacity() << std::endl;
        //v.shrink_to_fit();
        std::vector<int32_t>{}.swap(v);
        std::cout << v.size() << ":" << v.capacity() << std::endl;
        for (size_t i = 0; i < v.size() && i < 5; ++i)
        {
            std::cout << v[i] << std::endl;
        }
    }
}
