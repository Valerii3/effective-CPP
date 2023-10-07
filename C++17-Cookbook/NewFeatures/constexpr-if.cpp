//
// Created by Valerii.Ovchinnikov on 07.10.23.
//
#include <iostream>


template <typename T>
class addable {
    T val;
public:
    addable(T v) : val(v) {};

    template<typename U>
    T add(U el) const {
        if constexpr (std::is_same_v<T, std::vector<U>>) {
            auto copy (val);
            for (auto &n : copy) {
                n += el;
            }
            return copy;
        } else {
            return val + el;
        }
    }
};

int main() {
    // constexpr-if very similar to basic if-else, but the main difference that it evaluateed in compile time
    {
        addable my_addable(5);
        std::cout << my_addable.add(10) << '\n';
    }

    {
        std::vector<int> v{1, 2, 3, 4, 5};
        addable my_addable(v);
        std::vector<int> new_v = my_addable.add(10);
        for (auto el: new_v){
            std::cout << el << ' ';
        }
    }


}
