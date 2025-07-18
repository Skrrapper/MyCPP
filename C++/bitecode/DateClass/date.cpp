#include <iostream>
using namespace std;

class Date
{
public:
    // 打印函数
    void Print(const Date &d)
    {
        cout << d._year << "-" << d._month << "-" << d._day << endl;
    }

    // 具体实现
    int GetDay(int year, int month)
    {
        static int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int day = days[month];
        if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
        {
            day += 1;
        }
        return day;
    }

    Date(int year = 1900, int month = 1, int day = 1)
    {
        _year = year;
        _month = month;
        _day = day;
    }

    Date(const Date &d) // 拷贝构造函数
    {
        _year = d._year;
        _month = d._month;
        _day = d._day;
    }

    ~Date() {}; // 析构函数

    // 运算符=、+、-重载
    Date &operator=(const Date &d) // 赋值运算符重载，作用是使得类对象可以像基本数据类型一样进行赋值操作
    {
        if (this != &d)
        {
            _year = d._year;
            _month = d._month;
            _day = d._day;
        }
        return *this;
    }

    Date operator+(int days) // 日期加上days天，仅仅返回新的日期，不改变原日期
    {
        Date ret(*this); // 调用拷贝构造函数
        ret._day += days;
        while (ret._day > GetDay(ret._year, ret._month)) // 如果要加的天数超过了一个月的天数，则进入该循环
        {
            ret._day -= GetDay(ret._year, ret._month); // 减去一个月的天数
            ++ret._month;                              // 进入下一个月继续加
            if (ret._month > 12)                       // 假设月份大于12月了，也就说明进入了下一年
            {
                ret._month = 1;
                ++ret._year;
            }
        }
        return ret;
    }

    Date &operator+=(int days) // 日期加上days天，改变原日期
    {
        *this = *this + days; // 调用+运算符重载
        return *this;         // 返回当前对象
    }

    Date operator-(int days) // 日期减去days天
    {
        Date ret(*this); // 调用拷贝构造函数
        ret._day -= days;
        while (ret._day <= 0) // 如果减去的天数小于0，则进入该循环
        {
            --ret._month;        // 进入上一个月
            if (ret._month <= 0) // 如果月份小于等于0，则说明进入了上一年
            {
                ret._month = 12;
                --ret._year;
            }
            ret._day += GetDay(ret._year, ret._month); // 加上上一个月的天数
        }
        return ret;
    }

    Date &operator-=(int days) // 日期减去days天
    {
        *this = *this - days;
        return *this;
    }

    // 运算符==、!=、>、<、>=、<=重载
    bool operator==(const Date &d) // 日期相等，返回true
    {
        return _year == d._year && _month == d._month && _day == d._day;
    }
    bool operator!=(const Date &d) // 日期不相等，返回true
    {
        return !(*this == d);
    }

    bool operator>(const Date &d) //  大于指定日期，返回true
    {
        if (_year > d._year)
        {
            return true;
        }
        else if (_year == d._year)
        {
            if (_month > d._month)
            {
                return true;
            }
            else if (_month == d._month)
            {
                if (_day > d._day)
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool operator<(const Date &d) //  小于指定日期，返回true
    {
        if (_year < d._year)
        {
            return true;
        }
        else if (_year == d._year)
        {
            if (_month < d._month)
            {
                return true;
            }
            else if (_month == d._month)
            {
                if (_day < d._day)
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool operator>=(const Date &d) // 大于或等于指定日期，返回true
    {
        return *this > d || *this == d;
    }
    bool operator<=(const Date &d) // 小于或等于指定日期，返回true
    {
        return *this < d || *this == d;
    }

    // 前置++、--运算符重载
    Date &operator++() // 前置++
    {
        *this += 1;
        return *this;
    }
    Date &operator--() // 前置--
    {
        *this -= 1;
        return *this;
    }

    // 后置++、-=运算符重载，注意，后置++、--运算符重载的参数列表中有一个int型的参数，这个参数是用来区分前置++、--运算符重载的
    Date &operator++(int) // 前置++
    {
        *this += 1;
        return *this;
    }
    Date &operator--(int) // 前置--
    {
        *this -= 1;
        return *this;
    }

    // 日期-日期，返回相差的天数
    int operator-(const Date &d)
    {
        Date max = *this;
        Date min = d;
        if (max < min)
        {
            max = d;
            min = *this;
        }
        int days = 0;
        while (min != max) // 日期不相等，则进入该循环，进行++操作来计算相差天数
        {
            ++min;
            ++days;
        }
        return days;
    }

private:
    int _year;
    int _month;
    int _day;
};

int main()
{
    Date d(2025, 2, 26);
    Date d1;
    Date d2;
    Date d3;
    d1 = d;
    d1.Print(d+50);
    d2.Print(d-50);
    d3.Print(d);
    d.Print(d++);
    d.Print(++d);
}