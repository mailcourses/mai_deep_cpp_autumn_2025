#include <iostream>

namespace my
{

class string
{
private:
    size_t capacity_;
    union
    {
        struct {
            char* data_;
            size_t size_;
        } heap_data;

        char stack_data[sizeof(head_data)];
    };
};

} // namespace my
