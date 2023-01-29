#ifndef LEANERLIST_SEQUENCELIST_HPP
#define LEANERLIST_SEQUENCELIST_HPP

#include <iostream>
#include <initializer_list>
namespace sl {
    template <typename _ty>
    class sequnce {
        typedef _ty elemType;
        typedef size_t elemSize;
        typedef _ty* iterator;
        typedef const _ty* const_iterator;
        template <typename __ty>
        friend std::ostream& operator<< (std::ostream& _out, const sequnce<__ty> sl);
#define npos -1

    public:
        sequnce(): _data(nullptr), _size(0), _capacity(0) {}
        explicit sequnce(elemSize size)
            : _data(new elemType[size]), _size(0), _capacity(size << 1) {}
        sequnce(elemSize size, elemType data)
            : _data(new elemType[size]), _size(size), _capacity(size << 1) {
            for (int i = 0; i < size; i++)
                _data[i] = data;
        }
        sequnce(std::initializer_list<elemType> il)
            : _data(new elemType[il.size()]), _size(il.size()), _capacity(il.size() << 1) {
            int i = 0;
            for (auto it = il.begin(); it != il.end(); it++)
                _data[i++] = *it;
        }
        sequnce(const sequnce<elemType>& sl)
            : _data(new elemType[sl._size]), _size(sl._size), _capacity(sl._capacity) {
            std::copy(sl.begin(), sl.end(), _data);
        }
        sequnce(sequnce<elemType>&& sl) noexcept
            : _data(sl._data), _size(sl._size), _capacity(sl._capacity) {
            sl._data = nullptr;
            sl._size = 0;
            sl._capacity = 0;
        }

        ~sequnce() { delete[] _data; }

        sequnce<elemType>& operator= (const sequnce<elemType>& sl) {
            _data = new elemType[sl._size];
            std::copy(sl.bigen(), sl.end(), _data);
            _size = sl._size;
            _capacity = sl._capacity;
            return *this;
        }

        sequnce<elemType>& operator= (sequnce<elemType>&& sl) {
            _data = sl._data;
            _size = sl.size();
            _capacity = sl._capacity;
            return *this;
        }

        auto begin() -> iterator { return &_data[0]; }
        auto begin() const -> const_iterator { return &_data[0]; }
        auto end() -> iterator { return &_data[_size]; }
        auto end() const -> const_iterator { return &_data[_size]; }
    public:
        elemType operator[] (elemSize index) const { return _data[index]; }
    public:
        auto push_back(elemType data) -> void {
            if (_data == nullptr)
                _data = new elemType[16];
            if (check_capacity(_size, _capacity)) {
                auto_capacity();
            }
            _data[_size] = data;
            _size = _size + 1;
        }

        auto pop_back() -> void {
            _data[_size - 1] = 0;
            _size = _size - 1;
        }

        /**
         * 插入的时间复杂度：
         *  最好情况：插入到尾部，复杂度为O(1)
         *  最坏情况：插入到头部，复杂度为O(n)
         *  平均情况：假设插入到每一个位置的概率都相同，那么p = 1 / (n + 1)，则
         *          平均循环次数为：p(n + (n - 1) + ... + 1) = n(n + 1) / 2 * (1 / (n + 1)) = n / 2
         *          故，平均时间复杂度为O(n)
         * */
        auto insert(elemSize index, elemType data) -> iterator {
            if (_size + 1 >= _capacity) {
                auto_capacity();
            }
            if (index > _capacity)
                return nullptr;
            if (index > _size) {
                push_back(data);
                return &_data[_size - 1];
            }
            for (int i = _size - 1; i > index; i--)
                _data[i + 1] = _data[i];
            _data[index] = data;
            _size = _size + 1;
            return &_data[index];
        }

        /**
         * 删除的时间复杂度：
         *  最好情况：删除尾部，复杂度为O(1)
         *  最坏情况：删除头部，复杂度为O(n)
         *  平均情况：假设删除每一个位置的概率都相同，那么p = 1 / n，则
         *          平均循环次数为：p((n - 1) + (n - 2) + ... + 0) = n(n - 1) / 2 * (1 / n) = (n - 1) / 2
         *          故，平均时间复杂度为O(n)
         * */
        auto erase(elemSize index) -> iterator {
            if (index < 0)
                return nullptr;
            if (index > _size) {
                pop_back();
                return &_data[_size - 1];
            }
            for (int i = index - 1; i < _size; i++)
                _data[i] = _data[i + 1];
            _size = _size - 1;
            return &_data[index - 1];
        }

        /**
         * 按位查找的时间复杂度：O(1)
         *  满足随机存取的特性
         * */
        auto find_pos(elemSize pos) -> elemType const {
            if (pos > _size)
                return npos;
            return _data[pos - 1];
        }

        /**
         * 按值查找的时间复杂度：
         *  最好情况：目标元素在首位，复杂度为O(1)
         *  最坏情况：目标元素在末尾，复杂度为O(n)
         *  平均情况：假设删除每一个位置的概率都相同，那么p = 1 / n，则
         *          平均循环次数为：p(1 + 2 + ... + n) = n(n + 1) / 2 * (1 / n) = (n + 1) / 2
         *          故，平均时间复杂度为O(n)
         * */
        auto find_var(elemType data) -> elemSize const {
            for (int i = 0; i < _size; i++)
                if (_data[i] == data)
                    return i + 1;
            return npos;
        }

        auto empty() -> bool {
            return _size == 0;
        }

        auto size() -> elemSize const {
            return _size;
        }
    protected:
        auto check_capacity(elemSize size, elemSize capacity) -> bool {
            return size >= capacity;
        }
        auto auto_capacity() -> void {
            _capacity = _capacity == 0 ? 4 : _capacity << 1;
            elemType* temp = new elemType[_capacity];
            std::copy(_data, _data + _size, temp);
            // delete[] this->_data;
            this->_data = temp;
        }
    public:
        /**
         * 从顺序表中删除具有最小值的元素(假设唯一)，并由函数返回被删除的元素
         * */
        auto work1() -> elemType {
            if (empty())
                return -1;
            elemType last = _data[size() - 1], ref;
            elemSize min_index = 0;
            for (int i = 0; i < size(); i++) {
                if (_data[min_index] > _data[i])
                    min_index = i;
            }
            ref = _data[min_index];
            _data[min_index] = last;
            _size--;
            return ref;
        }

        /**
         * 设计一个高效算法，将顺序表的所有元素逆置，且空间复杂度为O(1)
         * */
        auto work2() -> void {
            for (int i = 0, j = size() - 1; i < j; i++, j--) {
                std::swap(_data[i], _data[j]);
            }
        }

        /**
         * 编写一个时间复杂度为O(n)，空间复杂度为O(1)的算法，删除线性表中所有值为x的元素
         * */
        auto work3(elemType data) -> void {
            /**
             * 此处很巧妙的运用key来计算需要保存的元素个数，同时通过这个移动元素，
             * 因为顺序表的存取是O(1)的，所以只需要遍历一次就能删除完毕且复杂度为O(n)
             * */
            int key = 0;
            for (int i = 0; i < size(); i++) {
                if (_data[i] != data) { // 将需要保存的元素，按照原序排列即可，也就是物理覆盖了需要删除的元素
                    _data[key++] = _data[i];
                }
            }
            _size = key;
        }

        /** 删除其在给定值s与t之间的所有元素(要求s < t)， 若S和T不合理或者顺序表为空，则显示错误信息并返回*/
        auto work4(elemType start, elemType end) -> bool {
            if (start >= end)
                return false;
            if (start < 0 || end > size())
                return false;
            if (empty())
                return false;
            for (int i = size() - 1; i >= 0; i--) { // 注意，此处要警觉迭代器失效的问题，如果从前往后，可能会导致元素位置变化
                if (_data[i] >= start && _data[i] <= end) {
                    for (int j = i; j < size(); j++)
                        _data[j] = _data[j + 1];
                    _size--; // 每删除一个，size就需要减小
                }
            }
            return true;
        }

        /** 从有序顺序表中删除所有其值重复的元素，使表中元素唯一*/
        auto work6() -> void {
            int count = 0;
            int arr[10000] = {0};
            for (int i = 0; i < size(); i++) {
                arr[_data[i]]++;
            }
            for (int i = 0; i < size(); i++) {
                if (arr[i] != 0) {
                    _data[count++] = i;
                }
            }
            _size = count;
        }

        /** 已知在一位数组A[m + n]中依次存放两个线性表(a1, a2,..., am)和(b1, b2,..., bn)
         * 编写一个函数，将数组中两个顺序表的位置互换
         * */
        auto work8(elemSize left, elemSize right) -> void {
            /** 解决的方法为：先整体逆序，再局部逆序
             *  [a1, a2, a3,..., am, b1, b2,..., bn]
             *  [bn, bn-1, bn-2,..., b1, am, am-1,..., a1]
             *  [b1, b2, b3,..., bn, a1, a2,..., am]
             * */
            if (left > right || right > _size)
                return;
            work2(); // 之前写的整体逆置
            std::cout << *this << std::endl;
            // 为什么是0 ~ (r - l - 1)呢，因为整体逆置之后，后一段转移到前一段，而后一段的长度就是r - l - 1
            for (int i = 0, j = right - left - 1; i <= j; i++, j--)
                std::swap(_data[i], _data[j]);
            std::cout << *this << std::endl;
            // 为什么从r - l ~ r呢，因为前一段被移动到了后一段，而前一段的长度是r，从r - l 开始
            for (int i = right - left, j = right; i <= j; i++, j--)
                std::swap(_data[i], _data[j]);
            std::cout << *this << std::endl;
        }

        /** 一个有序递增的顺序表，设计一个算法，完成用最小时间再表中进行查询，如果找到，与其后继元素交换
         * 若找不到，则插入表中使其继续有序
         * 分析：
         *      查找用二分，插入直接插入
         * */
         auto work9(elemType data) -> void { // BUG
             int left = 0, right = size() - 1, mid = 0;
             while (left <= right) {
                 mid = (left + right) / 2;
                 if (_data[mid] == data)
                     break;
                 else if (_data[mid] > data)
                     right = mid - 1;
                 else
                     left = mid + 1;
             }
             if (_data[mid] == data && mid != size() - 1)
                 std::swap(_data[mid], _data[mid + 1]);
             if (left > right) {
                 int i = size() - 1;
                 for (; i > left; i--)
                     _data[i + 1] = _data[i];
                 _data[i + 1] = data;
                 _size = _size + 1;
             }
         }
    private:
        elemType* _data;
        elemSize _size;
        elemSize _capacity;
    };

    template <typename _ty>
    std::ostream& operator<< (std::ostream& _out, const sequnce<_ty> sl) {
        _out << "sl::sequnce {\n\t[";
        for (int i = 0; i < sl._size - 1; i++)
            _out << sl[i] << ", ";
        _out << sl[sl._size - 1] << "]\n};\n";
        return _out;
    }
}



#endif //LEANERLIST_SEQUENCELIST_HPP
