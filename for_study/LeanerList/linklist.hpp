#ifndef LEANERLIST_LINKLIST_HPP
#define LEANERLIST_LINKLIST_HPP

#include <iostream>

namespace ll {
    template <typename _ty>
    struct _list_node {
        using elemType = _ty;
        _list_node(const elemType& var = _ty())
            : _var(var), _next(nullptr) {}
        elemType _var;
        _list_node<elemType>* _next;
    };

    template <typename _ty, typename _ref, typename _ptr>
    struct _list_iterator {
        using node = _list_node<_ty>;
        using self = _list_iterator<_ty, _ref, _ptr>;
        node* _lnode;
        _list_iterator(node* lnode): _lnode(lnode) {}

        // (*_ty&).xxx
        _ref operator* () { return _lnode->_var; }
        // (_ty*)->xxx
        _ptr operator-> () { return &_lnode->_var; }

        bool operator!= (const self& s) const {
            return _lnode != s._lnode;
        }
        bool operator== (const self& s) const {
            return _lnode == s._lnode;
        }
        self& operator++ () {
            _lnode = _lnode->_next;
            return *this;
        }
        self operator++ (int) {
            self temp(*this);
            _lnode = _lnode->_next;
            return temp;
        }
    };

    template <typename _ty>
    class linklist {
        template <typename __ty>
        friend std::ostream& operator<< (std::ostream& _out, const linklist<__ty>& l);
        using elemType = _ty;
        using node = _list_node<elemType>;
    public:
        using iterator = _list_iterator<elemType, elemType&, elemType*>;
        using const_iterator = _list_iterator<elemType, const elemType&, const elemType*>;
        iterator begin() { return iterator(_head->_next); }
        const_iterator begin() const { return const_iterator(_head->_next); }
        iterator end() {
            node* cur = _head;
            while (cur->_next != nullptr)
                cur = cur->_next;
            return iterator(cur->_next);
        }
        const_iterator end() const {
            node* cur = _head;
            while (cur->_next != nullptr)
                cur = cur->_next;
            return const_iterator(cur->_next);
        }
    public:
        linklist(): _head(new node) {}
        linklist(const linklist<elemType>& l) : _head(new node) {
            for (const auto& item : l)
                push_back(item);
        }
        ~linklist() {
            clear();
            delete _head;
            _head = nullptr;
        }
        linklist<elemType>& operator= (linklist<elemType> l) {
            std::swap(_head, l._head);
            return *this;
        }
    public:
        auto push_back(const elemType& data) -> void {
            insert(end(), data);
        }
        auto push_front(const elemType& data) -> void {
            insert(begin(), data);
        }
        auto pop_back() -> void {
            erase(end());
        }
        auto pop_front() -> void {
            erase(begin());
        }
        auto empty() -> bool {
            return _head->_next == nullptr;
        }
        auto insert(size_t pos, const elemType& data) -> bool {
            if (pos < 0) {
                return false;
            }
            /** 找到pos位置的前驱 */
            node* cur = _head;
            int i = 0;
            while (cur->_next != nullptr && i++ < pos) // 防止pos位置过于离谱
                cur = cur->_next; // cur++
            if (cur == nullptr) // 如果pos离谱，就终止
                return false;
            /** 链接新的节点 */
            node* newnode = new node(data);
            newnode->_next = cur->_next;
            cur->_next = newnode;
            return true;
        }
        auto insert(iterator pos, const elemType& data) -> bool {
            /** 找到pos位置的前驱 */
            node* cur = _head;
            linklist<elemType>::iterator it = begin();
            while (cur->_next != nullptr && it++ != pos) // 防止pos位置过于离谱
                cur = cur->_next;
            if (cur == nullptr) // 如果pos离谱，就终止
                return false;
            /** 链接新的节点 */
            node* newnode = new node(data);
            newnode->_next = cur->_next;
            cur->_next = newnode;
            return true;
        }

        auto erase(size_t pos) -> iterator {
            if (pos < 0)
                return nullptr;
            node* cur = _head;
            int i = 0;
            while (cur->_next != nullptr && i++ < pos)
                cur = cur->_next;
            if (cur == nullptr)
                return nullptr;
            /** 实际上返回被删除的下一个节点比较好，但是此处返回被删除的节点 */
            node* del = cur->_next;
            cur->_next = del->_next;
            node* ref = del;
            delete del;
            return iterator (ref);
        }

        auto erase(iterator pos) -> iterator {
            /** 在迭代器的版本，需要用到双指针，因为end()迭代器指向最后元素的后一个，也就是nullptr
             *  因此，在找到pos的时候，如果是尾删，我们就会找到最后一个元素，那么无法使得前驱链接到最后一个元素的下一个元素
             *  所以，我们需要使用双指针，来保存前驱的位置，实际上和普通位序一致，但是由于普通位序传入的pos不会导致找到最后，所以不需要双指针
             * */
            node* cur = _head;
            node* prev = cur;
            linklist<elemType>::iterator it = begin();
            while (cur->_next != nullptr && it++ != end()) {
                prev = cur;
                cur = cur->_next;
            }
            if (cur == nullptr || prev == nullptr)
                return nullptr;
            /** 实际上返回被删除的下一个节点比较好，但是此处返回被删除的节点 */
            node* del = prev->_next;
            prev->_next = del->_next;
            node* ref = del;
            delete del;
            return iterator (ref);
        }

        auto find_pos(size_t pos) -> iterator {
            if (pos < 0)
                return nullptr;
            node* cur = _head;
            int i = 0;
            while (cur->_next != nullptr && i++ < pos)
                cur = cur->_next;
            return iterator (cur);
        }

        auto find_var(const elemType& data) -> iterator {
            node* cur = _head;
            while (cur->_next != nullptr && cur->_var != data)
                cur = cur->_next;
            return iterator (cur);
        }

        auto size() -> size_t {
            size_t count = 0;
            for (const auto& item : *this)
                count++;
            return count;
        }

        auto clear() -> void {
            node* cur = _head;
            while (cur->_next != nullptr)
                pop_back();
        }
    private:
        node* _head;
    };

    template <typename _ty>
    std::ostream& operator<< (std::ostream& _out, const linklist<_ty>& l) {
        _out << "ll::linklist {\n\t[";
        for (auto it = l.begin(); it != l.end(); it++)
            _out << *it << ", ";
        _out <<  "null]\n};\n";
        return _out;
    }
}

#endif //LEANERLIST_LINKLIST_HPP
