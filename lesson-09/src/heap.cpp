#include <queue>
#include <iostream>

int main()
{
    // n
    std::vector<int32_t> arr_orig = {10, 2, 4, 9, 1, 5, 8};
    const int32_t k = 3;

    {
        auto arr = arr_orig;
        // O(n log n)
        std::sort(std::begin(arr), std::end(arr), std::greater<int32_t>());
        for (size_t i = 0; i < k; ++i)
        {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

    {
        auto arr = arr_orig;
        // O(n log k)

        std::priority_queue<int32_t, std::vector<int32_t>, std::greater<int32_t>> pq;
        for (auto num : arr)
        {
            pq.push(num);
            if (pq.size() > k)
            {
                pq.pop();
            }
        }
        std::cout << "size of heap=" << pq.size() << std::endl;

        auto pq_size = pq.size();
        std::vector<int32_t> tmp;
        for (size_t i = 0; i < pq_size; ++i)
        {
            std::cout << pq.top() << " ";
            tmp.push_back(pq.top());
            pq.pop();
        }
        std::cout << std::endl;
        std::reverse(std::begin(tmp), std::end(tmp));
    }
    return 0;
}

