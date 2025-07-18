#include <vector>
#include <functional>
#include <iostream>

template <class T>
class Less
{
public:
    bool operator()(const T &x, const T &y)
    {
        return x < y;
    }
};

template <class T>
class Greater
{
public:
    bool operator()(const T &x, const T &y)
    {
        return x > y;
    }
};

namespace joolin
{
    template <class T, class Container = std::vector<T>, class Compare = std::less<T>>
    class priQueue
    {
    private:
        Container _con;
        Compare _compare;
        /* data */
    public:
        priQueue() = default;
        // 打印队列内容（调试用）
        void print() const
        {
            for (const auto &elem : _con)
            {
                std::cout << elem << " ";
            }
            std::cout << std::endl;
        }

        // 插入
        void push(const &T value)
        {
            _con.push_back(value);
            std::push_heap(_con.begin(), _con.end());
        }

        // 删除优先级最高的元素
        void pop()
        {
            if (!_con.empty())
            {
                std::pop_heap(_con.begin(), _con.end());
                _con.pop_back();
            }
        }

        // 获取优先级最高的元素
        void T &top() const
        {
            if (!_con.empty())
            {
                return _con.front();
            }
            throw std::runtime_error("Priority queue error")
        }

        // 判断是否为空
        bool empty const()
        {
            return _con.empty();
        }

        // 获取元素个数
        size_t size() const()
        {
            return _con.size();
        }
    };

}