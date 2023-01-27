#include "sequencelist.hpp"

int main() {
    sl::sequnce<int> s(2, 1);
    s.push_back(2);
    s.push_back(3);
    s.push_back(4);
    auto ref = s.insert(7, 10);
    for (auto i : s) {
        std::cout << i << " ";
    }
    std::cout << "\n";
    std::cout << *ref << std::endl;
    auto ref1 = s.erase(5);
    for (auto i : s) {
        std::cout << i << " ";
    }
    std::cout << "\n";
    std::cout << *ref1 << std::endl;
    return 0;
}