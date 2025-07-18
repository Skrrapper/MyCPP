#include "string.h"
#include <iostream>
using namespace std;

int main()
{
    MyString::string s1("hello world");
    cout << s1.c_str() << endl;

    // 迭代器实现
    //MyString::string::iterator it = s1.begin();
    // auto it = s1.begin();
    // while (it != s1.end())
    // {
    //     cout << *it << " ";
    //     ++it;
    // }
    // cout << endl;

    // for (auto ch : s1)
    // {
    //     cout << ch << " ";
    // }
    // cout << endl;

    // s1.push_back(' ');
    // s1.push_back('?');
    // s1.append("hello");
    // cout << s1.c_str() << endl;
    // s1+='~';
    // s1+="hello";
    // cout << s1.c_str() << endl;
    // MyString::string s1("hello world");
    // s1.insert(0,3,'#');
    // cout << s1.c_str() << endl;
    // s1.erase(5,3);
    // cout << s1.c_str() << endl;
    // s1.erase(2);
    // cout << s1.c_str() << endl;
    // s1.resize(8);
    //     cout << s1 << endl;
    //     s1.resize(12,'x');
    //     cout << s1 << endl;
    //     s1.resize(15,'y');
    //     cout << s1 << endl;
}