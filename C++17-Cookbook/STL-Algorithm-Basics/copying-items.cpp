#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

int main() {
  std::vector<int> v{1, 2, 3, 4, 5};
  std::vector<int> t;
  // copy first 3 element to container t. we use back_inserter so we can copy
  // items to empty vector
  std::copy_n(begin(v), 3, std::back_inserter(t));

  std::map<int, std::string> mp;
  std::vector<std::pair<int, std::string>> vec{{1, "one"}, {2, "two"}};
  // here mp and vector 2 different structures, so inserter is transform our
  // items and we able to copy them
  std::copy_n(begin(vec), 2, std::inserter(mp, begin(mp)));

  std::string s1 = "some string";
  std::string s2;

  std::move(begin(vec), end(vec),
            std::inserter(mp, begin(mp))); // here we moved elements
  // it will print (1 )\n (2 ) because std::string was moved, and called
  // destructor for string in container vec
  for (auto el : vec) {
    std::cout << '(' << el.first << ' ' << el.second << ")\n"; //
  }

  return 0;
}
