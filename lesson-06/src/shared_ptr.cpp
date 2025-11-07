#include <iostream>
#include <cstring>

class string
{
public:
    string(const char* text) : size_(strlen(text)), data_(new char[size_])
    {
        for(size_t i = 0; i < size_; ++i)
        {
            data_[i] = text[i];
        }
    }

    string(const string& rhs) = default;
    /*
     *  size_ = rhs.size_;
     *  data_ = rhs.data_;
     */

    ~string()
    {
        std::cout << "~string" << std::endl;
        delete[] data_;
    }
    char* data_;
private:
    size_t size_;
};

void string_usage()
{
    string str1{"Hello world"};
    std::cout << str1.data_ << std::endl;
    /*{
        string str2{str1};
        std::cout << str2.data_ << std::endl;
    }
    std::cout << str1.data_ << std::endl; <-- Segmentation fault!!!*/
}

class shared_ptr
{
public:
    using type = int32_t;
private:
    struct object_
    {
        type* data{nullptr};
        size_t counter{0};
    };
public:
    //! Конструктор по умолчанию.
    shared_ptr() = default;

    //! Пользовательский конструктор.
    shared_ptr(type* raw) : ptr_{new object_}
    {
        ptr_->data = raw;
        ptr_->counter = 1;
    }

    //! Конструктор копирования
    shared_ptr(const shared_ptr& rhs)
    {
        ptr_ = rhs.ptr_;
        if (ptr_)
            ptr_->counter += 1;
    }

    //! Конструктор перемещения
    shared_ptr(shared_ptr&& rhs)
    {
        ptr_ = rhs.ptr_;
        rhs.ptr_ = nullptr;
    }

    //! Оператор перемещения
    shared_ptr& operator=(shared_ptr&& rhs)
    {
        if (this != &rhs)
        {
            destroy();
            ptr_ = rhs.ptr_;
            rhs.ptr_ = nullptr;
        }
        return *this;
    }

    //! Оператор копирования
    shared_ptr& operator=(const shared_ptr& rhs)
    {
        if (this != &rhs)
        {
            destroy();
            ptr_ = rhs.ptr_;
            if (ptr_)
                ptr_->counter += 1;
        }
        return *this;
    }

    void reset(type* raw)
    {
        destroy();
        ptr_ = new object_{raw, 1};
    }

    type& get() const
    {
        return *(ptr_->data);
    }

    ~shared_ptr()
    {
        destroy();
    }
private:
    void destroy()
    {
        if (!ptr_)
            return;
        ptr_->counter -= 1;
        if (ptr_->counter == 0)
        {
            delete ptr_->data;
            delete ptr_;
        }
    }
private:
    object_* ptr_{nullptr};
};

void shared_ptr_usage()
{
    shared_ptr ptr1{new shared_ptr::type{100500}};
    shared_ptr ptr2{ptr1};
    shared_ptr ptr3{new shared_ptr::type{1609}};
    ptr3 = ptr3;
    ptr3 = ptr1;
    shared_ptr ptr4{std::move(ptr2)};
    ptr3 = std::move(ptr4);
    ptr1.reset(new shared_ptr::type{-10});
    std::cout << ptr1.get() << std::endl;
}

struct Z
{
    explicit Z(int) {}
};

int main()
{
    string_usage();
    shared_ptr_usage();
    Z z = Z{1};
    return 0;
}

