#include "sequencelist.hpp"
#include <algorithm>

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

/**
 * 将n个整数存放到一维数组中，设计一个在时间和空间两方面都尽可能高效的算法，将R中保存的序列
 * 循环左移p个位置，即将R中的数据由(X0, X1,..., Xn-1)变换为(Xp, Xp+1,..., Xn-1, X0, X1,..., Xp-1)
 * */
auto work10(int* r, int len, int p) -> void {
    /**
     * 设计思路为：
     *      假如待循环的是abcdefg，向左循环三个
     *      首先，先将前三个需要循环的，逆置，得到cbadefg -> a-1b
     *      然后，将后面的进行逆置，得到cbagfed -> a-1b-1
     *      最后，将整体逆置，得到defhabc -> (a-1b-1)-1 -> ba
     * 实现的复杂度为：
     *      时间复杂度：
     *          有三段，分别是O(p / 2)、O((n - p) / 2)、O(n / 2) -> O(n)
     *      空间复杂度：
     *          是原地算法，不额外开辟空间，则O(n)
     * */

    // 进行第一步逆置，对想要进行左移的逆置
    for (int i = 0, j = p - 1; i < j; i++, j--)
        std::swap(r[i], r[j]);
    // 进行第二步逆置，对没有进行左移的逆置
    for (int i = p, j = len - 1; i < j; i++, j--)
        std::swap(r[i], r[j]);
    // 进行第三步逆置，对整体逆置，得到结果
    for (int i = 0, j = len - 1; i < j; i++, j--)
        std::swap(r[i], r[j]);
}

/**
 * 一个长度为L(L>=1)的升序序列S，处在第[L/2]个位置的数称为中位数。两个序列的中位数是含它们所有元素的升序
 * 序列的中位数。现有两个等长升序序列A和B，试设计一个在时间和空间两方面都尽可能高效的算法，找出两个序列的中位数
 * */
auto work11(int* A, int* B, int len) -> int {
    /**
     * 设计思路：
     *      假设A、B的中位数分别为a、b
     *      1. 若a == b，即a或b就为所求中位数
     *      2. 若a < b，则舍去A中较小的一半，同时舍去B中较大的一半，且舍去长度相同
     *      3. 若a > b，则舍去A中较大的一半，同时舍去B中较小的一半，且舍去长度相同
     *      4. 重复上述过程，直到两个序列中均只剩下一个元素为止，较小者为所求中位数
     * 解释：
     *      实际上就是步步逼近，中位数的判断实际上是对整体序列大小的判断
     *      为什么当a < b时，A舍去小的，B舍去大的，因为两个都是升序有序序列，当a < b时，A序列整体比B序列小，那么一定所求结果就在区间[a, b]中
     *      为什么当a > b时，A舍去大的，B舍去小的，因为两个都是升序有序序列，当a > b时，A序列整体比B序列大，那么一定所求结果就在区间[b, a]中
     *      为什么如果元素个数是偶数，需要舍去中点呢，如果不考虑偶数的情况，那么会出现一直卡死的情况，所以舍去中点保证了一定会使得元素个数减少，
     *      且是偶数时，中点已经被之前考虑过了，舍去中点对结果无影响。
     * 实现的复杂度：
     *      时间复杂度：O(logn)
     *      空间复杂度：O(1)
     * */
     int a_l = 0, a_r = len - 1, a_mid = 0, b_l = 0, b_r = len - 1, b_mid = 0;
     while (a_l != a_r || b_l != b_r) {
        a_mid = (a_l + a_r) / 2;
        b_mid = (b_l + b_r) / 2;
        if (A[a_mid] == B[b_mid]) // 条件一
            return A[a_mid];
        if (A[a_mid] < B[b_mid]) { // 条件二
            if ((a_l + a_r) % 2 == 0) { // 若元素个数是奇数
                a_l = a_mid; // 舍去A中较小的一半，且保留中点
                b_r = b_mid; // 舍去B中较大的一半，且保留中点
            }else { // 元素个数是偶数
                a_l = a_mid + 1; // 舍去A中较小的一半，且不保留中点
                b_r = b_mid;     // 舍去B中较大的一半，且保留中点
            }
        }else { // 条件三
            if ((b_l + b_r) % 2 == 0) { // 元素个数是奇数
                a_r = a_mid; // 舍去A中较大的一半，且保留中点
                b_l = b_mid; // 舍去B中较小的一半，且保留中点
            }else { // 元素个数是偶数
                a_r = a_mid; // 舍去A中较大的一半，且保留中点
                b_l = a_mid + 1; // 舍去B中较小的一半，且不保留中点
            }
        }
     }
     // 在最后时，A、B中只有一个元素了，所以无论是用r还是l都是可以的
     return A[a_l] < B[b_l] ? A[a_l] : B[b_l];
}

/**
 * 已知一个整数序列A，若存在ap1 = ap2 = ... = apm = x且 m > n/2，则称x为A的主元素。假设
 * A的n个元素保存在一个一维数组中，请设计一个尽可能高效的算法，找出A的主元素，若存在主元素，则输出该元素。
 * 否则输出-1
 * */

auto work12(int* A, int len) -> int {
    /**
     * 设计思路：
     *      从前往后遍历，用一个元素来记录当前主元素，设置计数器，如果该主元素的计数器为0，则
     *      更新主元素，直到：
     *          1. 该主元素个数大于n/2，则是所求结果
     *          2. 遍历结束都未出现，则返回-1
     * 实现的复杂度：
     *      时间复杂度：O(n)
     *      空间复杂度：O(1)
     * */
    int key = A[0], count = 0;
    for (int i = 0; i < len; i++) { // 筛选可能的主元素
        if (key == A[i])
            count++;
        else {
            if (count > 0)
                count--;
            else { // 更新主元素
                key = A[i];
                count = 1;
            }
        }
    }
    if (count > 0) { // 确定主元素实际次数
        count = 0; // 重置计数器
        for (int i = 0; i < len; i++)
            if (A[i] == key)
                count++;
    }
    if (count > len / 2)
        return key;
    return -1;
}

/**
 * 给定一个含n个整数的数组，请设计一个在时间上尽可能高效的算法，找出数组中未出现的
 * 最小正整数。
 * */
auto work13(int* a, int len) -> int {
    /**
     * 设计思路：
     *      需要尽可能在时间上高效，那么就需要使用空间换时间，使用hash，让出现过的内容映射到另一个
     *      有序数组上，然后从这个hash数组上找到最小正整数
     * 实现的复杂度：
     *      时间复杂度：O(n)
     *      空间复杂度：O(n)
     * */
    int max = *std::max_element(a, a + len);
    int* b = new int[max]{0};
    for (int i = 0; i < len; i++) {
        if (a[i] > 0 && a[i] <= max) {
            b[a[i]] = 1; // 对应序列的存在判断从[1~max]
        }
    }
    for (int i = 1; i < max; i++) {
        if (b[i] == 0) // 如果一直没有进入，那么说明前面都是拥有的，最小正整数是max + 1
            return i;
    }
    return max + 1;
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
    // s5.work9(7); TODO BUG
    std::cout << s5 << std::endl;

    /** work 10 */
    int r[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    work10(r, 10, 3);
    for (auto i : r)
        std::cout << i << " ";
    std::cout << "\n";

    /** work 11 */
    int a[5] = {1, 2, 3, 4, 5};
    int b[5] = {9, 8, 7, 6, 5};
    int re = work11(a, b, 5);
    std::cout << re << "\n";

    /** work 12 */
    int c[8] = {0, 5, 5, 3, 5, 7, 5, 5};
    int rre = work12(c, 8);
    std::cout << rre << "\n";

    /** work 13 */
    int d[5] = {-5, 0, 3, 2, 3};
    int e[5] = {1, 2, 4};
    int rrr = work13(e, 5);
    std::cout << rrr << "\n";
    return 0;
}