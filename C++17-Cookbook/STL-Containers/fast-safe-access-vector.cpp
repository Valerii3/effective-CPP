//
// Created by Valerii.Ovchinnikov on 08.10.23.
//
#include <iostream>
#include <vector>

// typ: its better to use .at(), but if the solution is too slow and bug-free, we can use []

int main() {
    // vector provide operator [] to access data, or method .at()

    const size_t container_size = 1000;
    std::vector<int> v(container_size, 100); // fill vector with value = 100

    // fast way using []
    std::cout << "Out of range element value: " << v[container_size + 5] << '\n'; // UB and we cant track it

    // safe way
    std::cout << "Out of range element value: " << v.at(container_size + 5) << '\n';
    // it will output stderr uncaught exception of type std::out_of_range
}