//
// Created by Valerii.Ovchinnikov on 17.10.23.
//
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> v {1, 2, 3, 4, 5};
    std::vector<int> res;

    std::transform(begin(v), end(v), std::back_inserter(res), [](int i) {return i * i;});

    for (auto el: res){
        std::cout << el << ' ';
    }
    return 0;
}