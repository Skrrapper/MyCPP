
// #include <iostream> // 添加必要的头文件
#include <assert.h>
namespace bit
{
    template <class T>
    class vector
    {
    public:
        typedef T *iterator;

        iterator begin()
        {
            return _start;
        }
        iterator end()
        {
            return _finish;
        }

        vector()
            : _start(nullptr), _finish(nullptr), _endofstorage(nullptr)
        {
        }

        void swap(vector<T>& v)
        {
            std::swap(_start,v._start);
            std::swap(_finish,v._finish);
            std::swap(_endofstorage,v._endofstorage);
        }

        vector<T>& operator=(vector<T> v)
        {
            swap(v);

            return *this;
        }


        ~vector()
        {
            if (_start)
            {
                delete[] _start;
                _start = _finish = _endofstorage = nullptr;
            }
        }

        // 分配内存空间
        void reserve(size_t n)
        {
            if (n >= capacity())
            {
                size_t sz = size();
                T *tmp = new T[n];
                if (_start)
                {
                    memcpy(tmp, _start, sizeof(T) * size());
                    delete[] _start;
                }
                _start = tmp;
                _finish = _start + sz;
                _endofstorage = _start + n;
            }
        }

        
        void resize(size_t n,const T& val = T())//匿名对象
        {
            if(n < size())
            {
                _finish = _start+n;
            }else{
                reserve(n);

                while(_finish != _start + n){
                    *_finish = val;
                    ++_finish;
                }
            }
        }


        void push_back(const T x)
        {
            if (_finish == _endofstorage)
            {
                size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2; // 修正拼写错误
                reserve(newcapacity);
            }

            *_finish = x;
            ++_finish;
        }

        size_t capacity() const // 修正 size_t 拼写错误
        {
            return _endofstorage - _start;
        }

        size_t size() const // 修正 size_t 拼写错误
        {
            return _finish - _start;
        }

        T &operator[](size_t pos)
        {
            assert(pos < size());

            return _start[pos];
        }
        const T &operator[](size_t pos) const
        {
            assert(pos < size());

            return _start[pos];
        }

        void insert(iterator pos, const T &x)
        {
            assert(pos >= _start && pos <= _finish);
        
            // 如果空间不足，扩容
            if (_finish == _endofstorage)
            {
                size_t len = pos - _start; // 计算插入位置的偏移量
                size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2;
                reserve(newcapacity); // 扩容
                pos = _start + len;   // 更新插入位置，避免迭代器失效
            }
        
            // 从插入位置开始，元素后移
            iterator end = _finish - 1;
            while (end >= pos)
            {
                *(end + 1) = *end;
                --end;
            }
        
            // 插入新元素
            *pos = x;
            ++_finish; // 更新结束位置
        }

        iterator erase(iterator pos)
        {
            assert(pos >= _start && pos < _finish);

            iterator it = pos + 1;
            while(it != _finish)
            {
                *(it-1) = *it;
                ++it;
            }
            --_finish;
        
            return pos;
        }

    private:
        iterator _start;
        iterator _finish;
        iterator _endofstorage;
    };

    void test_vector1()
    {
        vector<int> v1;
        v1.push_back(1);
        v1.push_back(2);
        v1.push_back(3);
        v1.push_back(4);

        for (auto e : v1)
        {
            cout << e << " ";
        }
        cout << endl;

        for (size_t i = 0; i < v1.size(); i++)
        {
            v1[i]++;
        }

        for (auto e : v1)
        {
            cout << e << " ";
        }
        cout << endl;
    }

    void test_vector2()
    {
        vector<int> v1;
        v1.push_back(1);
        v1.push_back(2);
        v1.push_back(2);
        v1.push_back(3);
        v1.push_back(4);
        v1.push_back(5);
        v1.push_back(6);
        for(auto e : v1)
        {
            cout << e << " ";
        }
        cout << endl;
        
        v1.erase(v1.begin());


        for(auto e : v1)
        {
            cout << e << " ";
        }
        cout << endl;
    }
    
    int test_vector3()
    {
        vector<int> v;
        v.resize(10,0);

        for(auto e : v)
        {
            cout << e << " ";
        }
        cout << endl;
    }
    
}