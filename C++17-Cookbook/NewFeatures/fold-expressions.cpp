//
// Created by Valerii.Ovchinnikov on 07.10.23.
//
#include <iostream>

template <typename ... T>
auto sum_right_fold(T ... arg){ // rightfold is ((a +b) + c) + d
    return (arg + ...);
}

template <typename ... T>
auto sum_left_fold(T ... arg){ // leftfold is a +(b + (c + d))
    return (... + arg);
}

template <typename ... T>
auto sum(T ... arg){
    return (arg + ... + 0);
}

int main() {

    std::cout << sum_right_fold(1, 2, 3, 4, 5) << '\n';
    std::string s1 = "String ", s2 = "also ", s3 = "works";
    std::cout << sum_left_fold(s1, s2, s3) << '\n';

    // what will be if we pass the empty args? Compile error
    // Unary fold expression has empty expansion for operator '+' with no fallback value
    // std::cout << sum_right_fold() << '\n';

    // to fix that we should use initial value, and such folds called binary folds.
    std::cout << sum() << '\n';
    return 0;

}