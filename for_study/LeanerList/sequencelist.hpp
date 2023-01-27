#ifndef LEANERLIST_SEQUENCELIST_HPP
#define LEANERLIST_SEQUENCELIST_HPP

#include <iostream>
namespace sl {
    template <typename _ty>
    class sequnce {
        typedef _ty elemType;
        typedef size_t elemSize;
        typedef _ty* iterator;
        typedef const _ty* const_iterator;
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
            for (int i = 0; i < il.size(); i++)
                _data[i] = il[i];
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

        /*
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

        /*
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

        /*
         * 按位查找的时间复杂度：O(1)
         *  满足随机存取的特性
         * */
        auto find_pos(elemSize pos) -> elemType const {
            if (pos > _size)
                return npos;
            return _data[pos - 1];
        }

        /*
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
    private:
        elemType* _data;
        elemSize _size;
        elemSize _capacity;
    };
}

#endif //LEANERLIST_SEQUENCELIST_HPP
