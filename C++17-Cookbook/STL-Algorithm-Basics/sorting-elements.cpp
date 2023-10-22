//
// Created by Valerii.Ovchinnikov on 13.10.23.
//
#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

struct my_struct {
  int a;
  int b;

  my_struct(int a_, int b_) : a(a_), b(b_){};
};

int main() {
  std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  std::cout << std::is_sorted(begin(v), end(v)); // 1 because true

  std::random_device rd;
  std::mt19937 g{rd()}; // random number

  std::shuffle(begin(v), end(v),
               g); // shake the content inside all vector (begin(v) - end(v))

  std::cout << std::is_sorted(begin(v), end(v)); // 0 because it was shuffled

  std::sort(begin(v), end(v));                   // sort
  std::cout << std::is_sorted(begin(v), end(v)); // 1 because true

  std::shuffle(begin(v), end(v), g);
  std::partition(begin(v), end(v),
                 [](int i) { return i < 5; }); // sort specific values

  std::shuffle(begin(v), end(v), g);
  auto mid(std::next(v.begin(), int(v.size() / 2)));
  std::partial_sort(begin(v), mid, end(v)); // sort only some part of container

  std::vector<my_struct> vs{{1, 2}, {2, 5}, {2, 0}, {2, 4}};
  // lets sort them by member b
  std::sort(
      begin(vs), end(vs),
      [](const my_struct &fst, const my_struct &snd) { return fst.b < snd.b; });

      return 0;
}