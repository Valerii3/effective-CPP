#include <iostream>

int main() {
  auto lambda_one([]() { return 1; });  // syntax for lambda expression
  auto lambda_second([] { return 2; }); // when 0 arguments - () is optional

  std::cout << lambda_one() << '\n';
  std::cout << lambda_second() << '\n';

  auto lambda_plus([](auto a, auto b) { return a + b; }); // take 2 arguments
  std::cout << lambda_plus(10, 15) << '\n';               // 25

  // in-place usage
  std::cout << [](auto a, auto b) { return a + b; }(10, 2) << '\n';

  // closure that carries an integer counter value around with it
  auto counter([count = 0]() mutable {
    return ++count;
  }); // we use mutable to change the count value
  for (int i = 0; i < 5; i++) {
    std::cout << counter() << ' ';
  }
  std::cout << '\n';

  // we can modify the object inside lambda
  int a = 5;
  auto incrementer([&a] { ++a; });
  incrementer();
  std::cout << a << '\n'; // 6

  // currying
  auto plus_ten([=](int x) { return lambda_plus(10, x); });
  std::cout << plus_ten(5) << '\n'; // 15

  return 0;
}
