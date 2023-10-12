//
// Created by Valerii.Ovchinnikov on 11.10.23.
//
#include <iostream>
#include <algorithm>

class num_iterator { // iterator class
    int i;

public:
    explicit num_iterator(int position = 0) : i(position){};

    int operator*() const { return i; }

    num_iterator &operator++() {
        ++i;
        return *this;
    }

    bool operator==(const num_iterator &other) const { return !(*this != other);}

    bool operator!=(const num_iterator &other) const { return i != other.i; }
};

// without this it will not compile because we need to know the type of items we iterate over
template <>
struct std::iterator_traits<num_iterator> {
    using iterator_category = std::forward_iterator_tag;
    using value_type = int;
};


class num_range {
    int a;
    int b;

public:
    explicit num_range(int from, int to) : a(from), b(to){};

    [[nodiscard]] num_iterator begin() const { return num_iterator{a}; }
    [[nodiscard]] num_iterator end() const { return num_iterator{b}; }
};

int main() {
    num_range r{10, 20};
    // returns a pair of iterators to the smallest and largest elements
    auto [min, max] = std::minmax_element(std::begin(r), std::end(r));
    std::cout << *min << ' ' << *max;
    return 0;
}