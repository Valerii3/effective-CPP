//
// Created by Valerii.Ovchinnikov on 07.10.23.
//
#include <iostream>
#include <algorithm>


int main() {
    // It is good style to limit the scope of variables as much as possible

    /* before C++17
     auto var (init_value);
     if (var) {
       ...
     } else {
       ...
    }
    var is still accessible


    after c++17
    if (auto var (init_value), condition){
     ...
    } else {
      ...
    }
    var is not accessible anymore
    */

    std::unordered_map<char, bool> character_map;
    if (auto itr (character_map.find('a')); itr != character_map.end()) {
        // *itr is valid. Do something with it.
    } else {
        // itr is the end-iterator. Don't dereference.
    }
        // itr is not available here at all
    return 0;
}
