#include <iostream>
#include "vector"
#include "map"
#include "set"
#include "fmt/ranges.h"

void groupStrings(auto& vector){
    std::map<int, std::set<std::string>> groupedStrings;
    int length = 1;
    for (int i = 0; i < vector.size(); ++i) {
        std::set<std::string> newSet;
        for (int j = 0; j < vector.size(); ++j) {
            if (vector[j].length() == length){
                newSet.insert(vector[j]);
            }
        }
        length++;
        if (!newSet.empty()){
            groupedStrings[i] = newSet;

        }
    }

    for (int i = 0; i < groupedStrings.size(); ++i) {
        std::cout << i+1 << " words length: ";
        for (auto j = groupedStrings[i].begin(); j != groupedStrings[i].end(); ++j) {
            std::cout << " " << *j;
        }
        std::cout << std::endl;
    }
}

int main() {
    std::vector<std::string> strings;
    auto word = std::string();
    while (word != "stop"){
        std::cin >> word;
        strings.push_back(word);
    }
    strings.pop_back();
    fmt::print("Grouped strings:\n");
    groupStrings(strings);


    return 0;
}
