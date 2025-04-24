#include <iostream>
#include <cstring>
#include <assert.h>
using namespace std;

namespace MyString
{
    class string
    {
    public:
        // 迭代器的实现
        typedef char *iterator;

        iterator begin()
        {
            return _str;
        }
        iterator end()
        {
            return _str + _size;
        }

        iterator begin() const
        {
            return _str;
        }
        iterator end() const
        {
            return _str + _size;
        }
        // 默认构造函数

        // //无参构造函数
        // string()
        // {
        //     _str = new char[1]; // 分配一个字符的内存
        //     _str[0] = '\0'; // 初始化为空字符串
        //     _size = 0;
        //     _capacity = 1; // 容量为1
        // }

        // //有参构造函数
        // string(const char *str) // 初始化列表
        //     : _str(new char[_capacity + 1]) // 这些使用初始化列表或者直接放在构造函数体内都可以
        //     , _size(strlen(str))
        //     , _capacity(_size)
        // {
        //     strcpy(_str, str); // 复制字符串
        // }

        // 缺省版
        //  string(const char *str = '\0');
        string(const char *str = "")        // 初始化列表
            : _str(new char[_capacity + 1]) // 这些使用初始化列表或者直接放在构造函数体内都可以
              ,
              _size(strlen(str)), _capacity(_size)
        {
            memcpy(_str, str, _size + 1); // 复制字符串
        }

        // 拷贝构造函数
        string(const string &other)
        {
            _size = other._size;                       // 复制大小
            _capacity = other._capacity;               // 复制容量
            _str = new char[_capacity + 1];            // 分配内存
            memcpy(_str, other._str, other._size + 1); // 复制字符串
        }

        // 析构函数
        ~string()
        {
            delete[] _str; // 释放内存
            _str = nullptr;
            _size = 0;
            _capacity = 0;
        }

        // c形式字符串
        const char *c_str()
        {
            return _str; // 返回字符串
        }

        size_t size() const
        {
            return _size;
        }

        char &operator[](size_t pos)
        {
            assert(pos < _size);
            return _str[pos];
        }
        char &operator[](size_t pos) const
        {
            assert(pos < _size);
            return _str[pos];
        }

        // 增删查改
        // 增与改
        // 扩容
        void reserve(size_t n)
        {
            if (n > _capacity)
            {
                char *tmp = new char[n + 1]; // + "\0"
                strcpy(tmp, _str);
                delete[] _str;
                _str = tmp;
                _capacity = n;
            }
        }
        // 调整字符串长度为n，多余部分截断或者填充指定值
        void resize(size_t n, char ch = '\0') // 这里缺省值设为'\0'
        {
            if (n < _size)
            {
                _size = n;
                _str[_size] = '\0';
            }
            else
            {
                reserve(n);

                for (size_t i = _size; i < n; i++)
                {
                    _str[i] = ch;
                }
                _size = n;
                _str[_size] = '\0';
            }
        }
        void push_back(char ch)
        {
            if (_size == _capacity)
            {
                // 2倍扩容
                reserve(_capacity == 0 ? 4 : _capacity * 2);
            }
            _str[_size] = ch;
            ++_size;
            _str[_size] = '\0';
        }

        void append(const char *str)
        {
            size_t len = strlen(str);
            if (_size + len > _capacity)
            {
                // 至少_size + len
                reserve(_size + len);
            }

            strcpy(_str + _size, str);
            _size += len;
        }

        string &operator+=(char ch)
        {
            push_back(ch);
            return *this;
        }
        string &operator+=(const char *str)
        {
            append(str);
            return *this;
        }

        void insert(size_t pos, size_t n, char ch)
        {
            assert(pos <= _size);
            if (_size + n > _capacity)
            {
                // 至少_size + n
                reserve(_size + n);
            }
            // int end = _size;
            size_t end = _size;

            // if(pos = 0)
            // {

            // }
            while (end >= pos && end != npos)
            {
                _str[end + n] = _str[end];
                end--;
            }

            for (size_t i = 0; i < n; i++)
            {
                _str[pos + i] = ch;
            }
            _size += n;
        }

        void insert(size_t pos, const char *str)
        {
            assert(pos <= _size);
            size_t len = strlen(str);
            if (_size + len >= _capacity)
            {
                reserve(_size + len);
            }
            size_t end = _size;
            while (end >= pos && end != npos)
            {
                _str[end + len] = _str[end];
                end--;
            }
            for (size_t i = 0; i < len; i++)
            {
                _str[pos + i] = str[i];
            }
            _size += len;
        }

        // 删
        void erase(size_t pos, size_t len = npos)
        {
            assert(pos <= _size);
            if (len == npos || pos + len >= _size)
            {
                _str[pos] = '\0';
                _size = pos;
                _str[_size] = '\0';
            }
            else
            {
                size_t end = pos + len;
                while (end <= _size)
                {
                    _str[pos++] = _str[end++];
                }
                _size -= len;
            }
        }

        // 查
        size_t find(char ch, size_t pos = 0)
        {
            assert(pos < _size);
            for (size_t i = pos; i < _size; i++)
            {
                if (_str[i] == ch)
                {
                    return i;
                }
            }
            return npos;
        }
        size_t find(const char *str, size_t pos = 0)
        {
            assert(pos < _size);

            const char *ptr = strstr(_str + pos, str);
            if (str)
            {
                return ptr - _str;
            }
            else
            {
                return npos;
            }
        }

        string substr(size_t pos = 0, size_t len = npos)
        {
            assert(pos < _size);
            size_t n = len;
            if (len == npos || pos + len > _size)
            {
                n = _size - pos;
            }
            string tmp;
            tmp.reserve(n);
            // for (size_t i = pos; i < n; i++) i不是从0开始，所以应该是pos+n
            for (size_t i = pos; i < n + pos; i++)
            {
                tmp += _str[i];
            }
            return tmp;
        }

        // 清理操作
        void clear()
        {
            _str[0] = '\0';
            _size = 0;
        }

        bool operator<(const string &s)
        {
            int ret = memcmp(_str , s._str,_size < s._size? _size: s._size);
            return ret == 0 ? _size < s._size : ret< 0;
        //     size_t i1 = 0;
        //     size_t i2 = 0;
        //     while (i1 < _size && i2 < s._size)
        //     {
        //         if (_str[i1] < s._str[i2])
        //         {
        //             return true;
        //         }
        //         else if(_str[i1] > s._str[i2])
        //         {
        //             return false;
        //         }
        //         else{
        //             ++i1;
        //             ++i2;
        //         }
        //     }
        //     // return(_size < s._size);

        //    return(i1 == _size && i2 != s._size);
           
        }

        bool operator==(const string &s)
        {
            return _size == s._size
                && memcmp(_str,s._str,_size)== 0;
        }

        bool operator<=(const string &s)
        {
            return *this < s || *this == s;
        }
        bool operator>(const string &s)
        {
            return !(*this <= s);
        }
        bool operator>=(const string &s)
        {
            return !(*this < s);
        }
        bool operator!=(const string &s)
        {
            return !(*this == s);
        }
        
        void swap(string &s)
        {
            std::swap(_str,s._str);
            std::swap(_size,s._size);
            std::swap(_capacity,s._capacity);
        }

        // string& operator=(const string&s)
        // {
        //     if(this != &s)
        //     {
        //         string tmp(s);

        //         swap(tmp);
        //     }
        //     return *this;
        // }

        string& operator=(string tmp)
        {
            swap(tmp);
            return *this;
        }


    private:
        char *_str;
        size_t _size;
        size_t _capacity;
        static size_t npos;
    };
    size_t string::npos = -1;

    // 流插入和流提取
    ostream &operator<<(ostream &out, const string &s)
    {
        // for (size_t i = 0; i < s.size(); i++)
        // {
        //     /* code */
        //     out << s[i];
        // }
        for (auto ch : s)
        {
            out << ch;
        }
        return out;
    }

    istream &operator>>(istream &in, string &s)
    {
        s.clear();
        char ch = in.get();

        //  处理缓冲区前面的空格或者换行
        while (ch != ' ' && ch != '\n')
        {
            ch = in.get();
        }

        //  建立缓冲区，使空间扩容更加节省
        char buff[128];
        int i = 0;
        // in >> ch;
        while (ch != ' ' && ch != '\n')
        {
            buff[i++] = ch;
            if (i == 127) // 要给\0留一个
            {
                buff[i] = '\0';
                s += buff;
                i = 0;
            }
            // s += ch;
            // in >> ch;
            ch = in.get();
        }

        if (i != 0)
        {
            buff[i] = '\0';
            s += buff;
        }
        return in;
    }

};
