#include <iostream>
#include <algorithm>
#include <deque>
#include <sstream>

int main() {
    std::istream_iterator<int> it {std::cin};
    std::istream_iterator<int> end;

    std::deque<int> deq;
    // wrap it into std::back_inserter_iterator
    std::copy(it, end, std::back_inserter(deq));

    std::istringstream sstr {"123 456 789"}; // we will insert in the middle of the deq

    auto deq_mid {std::next(std::begin(deq), static_cast<int>(deq.size() / 2))};

    //wrap it into std::insert_iterator
    std::copy(std::istream_iterator<int>{sstr}, {}, std::inserter(deq, deq_mid));

    std::initializer_list<int> il2 {-1, -2, -3}; // we will insert in the beginning
    std::copy(std::rbegin(il2), std::rend(il2), std::front_inserter(deq));

    // output
    std::copy(std::begin(deq), std::end(deq), std::ostream_iterator<int>{std::cout, ", "});

    return 0;
}