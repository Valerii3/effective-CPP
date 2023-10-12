#include <iostream>

class num_iterator { // iterator class
  int i;

public:
  explicit num_iterator(int position = 0) : i(position){};

  int operator*() const { return i; }

  num_iterator &operator++() {
    ++i;
    return *this;
  }

  bool operator!=(const num_iterator &other) const { return i != other.i; }
};

class num_range {
  int a;
  int b;

public:
  explicit num_range(int from, int to) : a(from), b(to){};

  [[nodiscard]] num_iterator begin() const { return num_iterator{a}; }
  [[nodiscard]] num_iterator end() const { return num_iterator{b}; }
};

/* syntax-sugar ranged-based for:
     auto && __range = array_or_vector_or_map_or_list ;
     auto __begin = std::begin(__range);
     auto __end = std::end(__range);

     for (; __begin != __end; ++__begin){
        int i = *__begin;
        do_smth(i);
     }
*/

int main() {
  for (int i : num_range{10, 20}) {
    std::cout << i << ' ';
  }
  return 0;
}
