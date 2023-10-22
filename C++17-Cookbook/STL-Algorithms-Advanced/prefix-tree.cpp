#include <iostream>
#include <optional>
#include <algorithm>
#include <functional>
#include <iterator>
#include <map>
#include <vector>
#include <string>

template <typename T>
class trie {
    std::map<T, trie> tries;
public:
    template<typename It>
    void insert(It it, It end_it) {
        if (it == end_it) return;
        tries[*it].insert(std::next(it), end_it);


    }

    void insert(const std::initializer_list<T> &il) {
        insert(begin(il), end(il));
    }

    void print(std::vector<T> &v) const {
        if (tries.empty()){
            std::copy(begin(v), end(v),
                      std::ostream_iterator<T>{std::cout, " "});
            std::cout << '\n';
        }
        for (const auto &p: tries){
            v.push_back(p.first);
            p.second.print(v);
            v.pop_back();
        }
    }

    void print() const {
        std::vector<T> v;
        print(v);
    }

    template<typename It>
    std::optional<std::reference_wrapper<const trie>>
    subtrie(It it, It end_it) {
        if (it == end_it) { return std::ref(*this); }
        auto found (tries.find(*it));
        if (found == end(tries)) { return {}; }
        return found->second.subtrie(next(it), end_it);
    }

    template <typename C>
    auto subtrie(const C &c) {
        return subtrie(begin(c), end(c));
    }
};

int main() {
    trie<std::string> t;
    t.insert({"hi", "how", "are", "you"});
    t.insert({"hi", "i", "am", "great", "thanks"});
    t.insert({"what", "are", "you", "doing"});
    t.insert({"i", "am", "watching", "a", "movie"});

    t.print();


    std::cout << "<------>\n";
    if (auto st (t.subtrie(std::initializer_list<std::string>{"hi"}));
            st) {
        st->get().print();
    }
    return 0;
}
