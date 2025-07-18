#include <iostream>
namespace joolin
{
    template <typename T>
    struct ListNode
    {
        T data;
        // 两个指针
        ListNode<T> *prev;
        ListNode<T> *next;

        // 构造函数
        ListNode(const T &val = T())
            : data(val), prev(nullptr), next(nullptr) {}
    };

    template <typename T>
    class List
    {
    private:
        ListNode<T> *head;
        ListNode<T> *tail;
        size_t size;

    public:
        //迭代器
        class Iterator{
            private:
            ListNode<T>* node;

            public:
            Iterator(ListNode<T>* n = nullptr) : node(n) {}
            T& operator *() { return node->data; }
            
            Iterator& operator++() {
                node = node->next;
                return *this;
            }
            Iterator operator++(int) {
                Iterator temp = *this;
                node = node->next;
                return temp;
            }
            Iterator& operator--() {
                node = node->prev;
                return *this;
            }
            Iterator operator--(int) {
                Iterator temp = *this;
                node = node->prev;
                return temp;
            }
            bool operator==(const Iterator& other) const { return node == other.node; }
            bool operator!=(const Iterator& other) const { return node != other.node; }

        };

        //返回迭代器
        Iterator begin() { return Iterator(head); }
        Iterator end() { return Iterator(nullptr); }

        //反向迭代器
        // 反向迭代器
        class ReverseIterator {
            private:
                ListNode<T>* node;
    
            public:
                ReverseIterator(ListNode<T>* n = nullptr) : node(n) {}
    
                T& operator*() { return node->data; }
                ReverseIterator& operator++() {
                    node = node->prev;
                    return *this;
                }
                ReverseIterator operator++(int) {
                    ReverseIterator temp = *this;
                    node = node->prev;
                    return temp;
                }
                bool operator==(const ReverseIterator& other) const { return node == other.node; }
                bool operator!=(const ReverseIterator& other) const { return node != other.node; }
            };
    
            //返回反向迭代器
            ReverseIterator rbegin() { return ReverseIterator(tail); }
            ReverseIterator rend() { return ReverseIterator(nullptr); }


        // 构造函数
        List()
            : head(nullptr), tail(nullptr), size(0)
        {
        }

        // 析构函数
        ~List()
        {
            while (head)
            {
                ListNode<T> *temp = head;
                head = head->next;
                delete temp;
            }
            tail = nullptr;
            size = 0;
        }

        //清除
        void clear()
        {
            while (head)
            {
                ListNode<T>* temp = head;
                head = head -> next;
                delete temp;
                /* code */
            }
            tail =nullptr;
            size = 0;   
        }

        //排序
        void sort()
        {
            if(size < 2) return;
            for (ListNode<T>* i = head; i != nullptr; i = i->next) {
                for (ListNode<T>* j = i->next; j != nullptr; j = j->next) {
                    if (i->data > j->data) {
                        std::swap(i->data, j->data);
                    }
                }
            }
        }



        // 增加
        void push_back(const T &value)
        {
            ListNode<T> *newNode = new ListNode<T>(value);
            if (!head)
            {
                head = tail = newNode;
            }
            else
            {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
            ++size;
        }

        void push_front(const T &value)
        {
            ListNode<T> *newNode = new ListNode<T>(value);
            if (!head)
            {
                head = tail = newNode;
            }
            else
            {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
            ++size;
        }

        // 删除
        void pop_back()
        {
            if (!tail)
                return;
            if (tail == head)
            {
                delete tail;
                head = tail = nullptr;
            }
            else
            {
                ListNode<T> *temp = tail;
                tail = tail->prev;
                tail->next = nullptr;
                delete temp;
            }
            --size;
        }

        void pop_front()
        {
            if (!head)
                return;
            if (head == tail)
            {
                delete head;
                head = tail = nullptr;
            }
            else
            {
                ListNode<T> *temp = head;
                head = head->next;
                head->prev = nullptr;
                delete temp;
            }
            --size;
        }

        // 返回
        T front() const
        {
            if (!head) {
                throw std::runtime_error("List is empty!");
            }
            return head->data;
        }
        T back() const
        {
            if (!tail) {
                throw std::runtime_error("List is empty!");
            }
            return tail->data;
        }
        size_t get_size() const
        {
            return size;
        }

        // 插入和消除
        void insert(size_t pos, const T &value)
        {
            if (pos > size)
                throw std::out_of_range("Position out of range");
            if (pos == 0)
            {
                push_front(value);
                return;
            }
            if (pos == size)
            {
                push_back(value);
                return;
            }

            ListNode<T> *current = head;
            for (size_t i = 0; i < pos - 1; i++)
            {
                current = current->next;
            }

            ListNode<T> *newNode = new ListNode<T>(value);
            newNode->next = current->next;
            newNode->prev = current;
            current->next->prev = newNode;
            current->next = newNode;

            ++size;
        }

        void erase(size_t pos)
        {
            if (pos >= size) throw std::out_of_range("Position out of range");
            if(pos == 0){
                pop_front();
                return;
            }
            if(pos = size - 1){
                pop_back();
                return;
            }
            
            ListNode<T>* current = head;
            for (size_t i = 0; i < pos; i++)
            {
                current = current -> next;
            }

            current->prev->next = current ->next;
            current->next->prev = current -> prev;

            --size;            
        }
    };

} // namespace joolin
