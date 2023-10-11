//
// Created by Valerii.Ovchinnikov on 09.10.23.
//
#include <iostream>
#include <unordered_map>

// example of struct
struct myStruct {
    int x;
    int y;

    myStruct(int x_, int y_) : x(x_), y(y_) {};
};

// we need to implement comparison operator
bool operator==(const myStruct &a, const myStruct& b) {
    return a.x == b.x && a.y == b.y;
}

// implement our hash function for custom-type
template<>
struct std::hash<myStruct>{
    using argument_type = myStruct;
    using result_type = std::size_t;

    result_type operator()(const argument_type &c) const {
        return static_cast<result_type>(c.x) + // it is bad hashing technique, but for showing how to implement it, it's good enough.
                static_cast<result_type>(c.y);
    }
};

int main() {
    // without our own implementation of hashing function and operator== it will not compile
    std::unordered_map<myStruct, int> m {{{0, 0}, 1}, {{0, 1}, 2},
                                      {{2, 1}, 3}};
    for (const auto & [key, value] : m) {
        std::cout << "{(" << key.x << ", " << key.y
                  << "): " << value << "} ";
    }
    std::cout << '\n';
    return 0;
}