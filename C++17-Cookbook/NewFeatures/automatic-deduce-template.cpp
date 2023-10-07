//
// Created by Valerii.Ovchinnikov on 07.10.23.
//
#include <iostream>

template <typename T1, typename T2>
class my_wrapper{
    T1 var_a;
    T2 var_b;
public:
    explicit my_wrapper(T1 a, T2 b) : var_a(a), var_b(b) {}

    [[nodiscard]] T1 get_a() const {
        return var_a;
    }

    [[nodiscard]] T2 get_b() const {
        return var_b;
    }
};

template <typename T1, typename T2>
my_wrapper<T1, T2> make_wrapper(T1 t1, T2 t2) {
    return my_wrapper<T1, T2>{t1, t2};
}

int main() {

    // now we can simply write it like that:
    {
        my_wrapper wrapper(2, "something");

        std::cout << wrapper.get_a() << ' ' << wrapper.get_b() << '\n'; // 2 string
    }

    // before c++17 we should write the template types
    {
        my_wrapper<int, std::string> wrapper(2, "something");

        std::cout << wrapper.get_a() << ' ' << wrapper.get_b() << '\n'; // 2 string
    }
    // or like that
    {
        auto wrapper(make_wrapper(2, std::string("something")));

        std::cout << wrapper.get_a() << ' ' << wrapper.get_b() << '\n'; // 2 string

    }
    return 0;
}
