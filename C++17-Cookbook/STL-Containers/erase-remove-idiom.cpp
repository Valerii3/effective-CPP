#include <iostream>
#include <vector>
#include <algorithm>

const auto odd([](int i){ return i % 2 != 0;});

template <typename T>
void print(const T& v){
    for (auto el: v){
        std::cout << el << ' ';
    }
    std::cout << '\n';
}

int main() {

    {
        std::vector<int> v{1, 2, 3, 2, 5, 2, 6, 2, 4, 8};

        const auto new_end(remove(begin(v), end(v),
                                  2)); // new end is pointing on last element after shifting (so its actual size of v_
        // so now v = 1 3 5 6 4 8 6 2 4 8

        v.erase(new_end, end(v)); // deleting all elements after new_end

        print(v);
    }

    {
        // now lets deleting all even elements
        std::vector<int> v{1, 2, 3, 2, 5, 2, 6, 2, 4, 8};

        v.erase(remove_if(begin(v), end(v), odd), end(v));

        std::cout << "capacity is " << v.capacity() << '\n'; // capacity is still 10

        // if we want to make our capacity is the same as size of vector, we can use:
        v.shrink_to_fit(); // but it can lead that vector code allocates new chunk of memory and moves all the items to the new one

        print(v); // 2 2 2 6 2 4 8
    }

    return 0;
}
