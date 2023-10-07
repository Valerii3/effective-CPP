//
// Created by Valerii.Ovchinnikov on 07.10.23.
//
#include <iostream>

int main() {
    auto var {2}; // before c++17 it can be std::initializer_list<int> with only one element

    // now it will make var the same type as variable inside brackets

    auto var_name = {1, 2, 3, 4}; // should all be the same type, otherwise it is an error

    // code below wont compile
    //  auto var_arg {1, 2, 3};

    return 0;
}