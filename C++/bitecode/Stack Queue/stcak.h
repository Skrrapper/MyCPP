#include<list>
#include<vector>
using namespace std;

namespace joolin
{
    // 容器适配器
    template<class T,class Container = vector<T>>
    class stack
    {
        public:
        void push(const &T x)
        {
            _con.push_back(x);
        }
        void pop()
        {
            _con.pop_back();
        }

        T& top()
        {
            return _con.back();
        }

        size_t size()
        {
            return _con.size();
        }

        bool empty()
        {
            return _con.empty();
        }

        private:
        Container _con;
    };
}// namespace joolin
