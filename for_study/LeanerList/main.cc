#include "linklist.hpp"

int main() {
    ll::linklist<int> l;
    l.insert(0, 2);
    std::cout << l << std::endl;
    l.insert(0, 1);
    std::cout << l << std::endl;
    l.insert(3, 3);
    std::cout << l << std::endl;
    l.push_back(4);
    std::cout << l << std::endl;
    l.push_front(5);
    std::cout << l << std::endl;
    l.erase(0);
    std::cout << l << std::endl;
    l.erase(3);
    std::cout << l << std::endl;
    std::cout << l.size() << std::endl;
    return 0;
}