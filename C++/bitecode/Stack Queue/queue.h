#include<vector>
#include<list>
using namespace std;

namespace joolin
{
    // 容器适配器
    template<class T,class Container = list<T>>
    class queue
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
