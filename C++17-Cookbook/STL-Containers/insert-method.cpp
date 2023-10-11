//
// Created by Valerii.Ovchinnikov on 08.10.23.
//
#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
void insert_sorted(std::vector<T> &v, const T& el) {
    // Find position in O(logN) where N - number of elements in array
    const auto it = std::lower_bound(std::begin(v), std::end(v), el);
    // insert in O(n+m) where n - number of inserting element and m the number of moved element
    v.insert(it, el);
}

int main() {
    std::vector<std::string> v{"second", "more", "string", "random", "word"};

    // sort array
    std::sort(std::begin(v), std::end(v));

    // now we can insert element and keep it sorted.
    insert_sorted(v, std::string{"new string"});

    for (auto el: v){
        std::cout << el << ", ";
    }
}