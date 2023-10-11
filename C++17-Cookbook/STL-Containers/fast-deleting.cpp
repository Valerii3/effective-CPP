//
// Created by Valerii.Ovchinnikov on 07.10.23.
//
#include <iostream>
#include <vector>
#include <algorithm>


template <typename T>
void print(const T& v){
    for (auto el: v){
        std::cout << el << ' ';
    }
    std::cout << '\n';
}

template <typename T>
void quick_remove(std::vector<T> &v, std::size_t idx) {
    if (idx < v.size()){
        v[idx] = std::move(v.back()); // we do not need to swap elements due deleting last item anyway
        v.pop_back();
    }
}

template <typename T>
void quick_remove(std::vector<T> &v, typename std::vector<T>::iterator it) {
    if (it != v.end()){
        *it = std::move(v.back());
        v.pop_back();
    }
}

int main() {

    // how to delete item in O(1) time from unsorted array?
    // just swapping it with the last item and then call pop.back()
    std::vector<int> v{1, 11, 3, 7, 4, 6, 9, 10, 2, 10};
    {
        quick_remove(v, 2);
        print(v);
    }

    {
        // if we do not have index of element which we want to delete, we use iterators
        quick_remove(v, std::find(begin(v), end(v), 4));
        print(v);
    }
    return 0;
}
