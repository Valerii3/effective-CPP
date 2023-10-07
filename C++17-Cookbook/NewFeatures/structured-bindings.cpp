#include <iostream>
#include <algorithm>

struct Book {
    int id;
    std::string name;
    std::string author;

    Book(const std::string &name_, const std::string &author_) : id(0), name(name_), author(author_) {};
};

bool divide_remainder(int dividend, int divisor,
                      int &fraction, int &remainder){
    if (divisor){
        fraction = dividend / divisor;
        remainder = dividend % divisor;
        return true;
    }
    return false;

}

int main() {

    // structured-binding helps us to assign variables from pairs, tuples, structs into individual variables

    std::pair<int, int> my_pair {1, 2};
    {
        int fst = my_pair.first, snd = my_pair.second; // should write the type and using .first / .second to access variables
        std::cout << fst << ' ' << snd << '\n'; // print 1 2
    }
    {
        auto [fst, snd] = my_pair;
        std::cout << fst << ' ' << snd << '\n'; // print 1 2
    }

    {
        Book my_book("C++17 Cookbook", "Jacek Galowicz");
        auto [id, name, author] = my_book;
        std::cout << id << ' ' << name << ' ' << author << '\n'; // 0 C++17 CookBook Jacek Galowicz
    }


    // before C++17

    {
        // benefit: std::ignore acts as a dummy variable
        // disadvantage: we should define all variables we want to assign before using std::tie
        int snd;
        std::tie(std::ignore, snd) = my_pair;
        std::cout << snd << '\n'; // print 2
    }

    {
        // one more way
        int fraction, remainder;
        const bool success {divide_remainder(16, 3, fraction, remainder)};
        if (success) {
            std::cout << "16 / 3 is " << fraction << " with a remainder of "
                      << remainder << '\n';
        }
    }

    return 0;
}
