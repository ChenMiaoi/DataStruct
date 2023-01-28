#include "sequencelist.hpp"

/** 将两个有序顺序表合并为一个新的有序顺序表，并由函数返回结果顺序表*/
auto work7(sl::sequnce<int> s1, sl::sequnce<int> s2) -> sl::sequnce<int> {
    sl::sequnce<int> ref;
    int i = 0, j = 0;
    while (i < s1.size() && j < s2.size()){
        if (s1[i] < s2[j]) {
            ref.push_back(s1[i++]);
        }else {
            ref.push_back(s2[j++]);
        }
    }
    while (i < s1.size()) {
        ref.push_back(s1[i++]);
    }
    while (j < s2.size()) {
        ref.push_back(s2[j++]);
    }
    return ref;
}

int main() {
    /** work 1 */
    sl::sequnce<int> s = {1, 2, 3, 4, 5, 6, 7};
    auto ref = s.work1();
    std::cout << ref << std::endl;
    std::cout << s << std::endl;

    /** work 2 */
    s.work2();
    std::cout << s << std::endl;

    /** work 3 */
    s.work3(2);
    std::cout << s << std::endl;

    /** work 4 */
    s.work4(2, 4);
    std::cout << s << std::endl;

    /** work 6 */
    sl::sequnce<int> s1 = {1, 2, 2, 3, 3, 4, 4, 5};
    s1.work6();
    std::cout << s1 << std::endl;

    /** work 7 */
    sl::sequnce<int> s2 = {1, 3, 5, 7, 9};
    sl::sequnce<int> s3 = {2, 4, 6, 8, 10};
    sl::sequnce<int> rr =  work7(s2, s3);
    std::cout << rr << std::endl;

    /** work 8 */
    sl::sequnce<int> s4 = {1, 3, 4, 5, 9, 2, 4, 6};
    s4.work8(4, 7);
    std::cout << s4 << std::endl;

    /** work 9 */
    sl::sequnce<int> s5 = {1, 2, 3, 4, 5, 6};
    s5.work9(4);
    std::cout << s5 << std::endl;
    s5.work9(7);
    std::cout << s5 << std::endl;
    return 0;
}