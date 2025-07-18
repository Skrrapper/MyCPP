#include <string>
#include <vector>
#include <iostream>
using namespace std;
// // int main()
// // {
// //     string s1;
// //     string s2("张三");
// //     string s3("hello world");
// //     string s4(s3);
// //     string s5(10, 'a');
// //     string s6(s3,6,5);
// //     cout << s1 << endl;
// //     cout << s2 << endl;
// //     cout << s3 << endl;
// //     cout << s4 << endl;
// //     cout << s5 << endl;
// //     cout << s6 << endl;
// //     string url("http://www.cplusplus.com/reference/string/string/");
// //     string sub1(url,0,5);
// //     string sub2(url,7,4);
// //     string sub3(url,12);
// //     cout << sub1 << endl;
// //     cout << sub2 << endl;
// //     cout << sub3 << endl;

// // //第一种方式，使用append()和push_back()方法
// //     s1.append("hello");
// //     s1.push_back('!');
// //     cout << s1 << endl;
// // //第二种方式 ，使用重载的+=运算符
// //     s1 += "world";
// //     s1 += '~';
// //     cout << s1 << endl;

// //     size_t x= 0;
// //     cin >> x;
// //     string xstr ;
// //     while(x)
// //     {
// //         size_t val = x % 10;
// //         xstr += (val + '0');
// //         x/=10;
// //     }
// //     return 0;
// // }

// int main()
// {
//     // 迭代器示例
//     vector<int> numbers = {1, 2, 3, 4, 5};

//     // 使用迭代器遍历容器
//     cout << "使用迭代器遍历容器:" << endl;
//     for (vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it)
//     {
//         cout << *it << " ";
//     }
//     cout << endl;

//     // 使用常量迭代器
//     cout << "使用常量迭代器:" << endl;
//     for (vector<int>::const_iterator it = numbers.cbegin(); it != numbers.cend(); ++it)
//     {
//         cout << *it << " ";
//     }
//     cout << endl;

//     // 使用反向迭代器1
//     cout << "使用反向迭代器1:" << endl;
//     for (vector<int>::reverse_iterator it = numbers.rbegin(); it != numbers.rend(); ++it)
//     {
//         cout << *it << " ";
//     }
//     cout << endl;

//     // 使用反向迭代器2
//     cout << "使用反向迭代器2:" << endl;
//     string s1 = "hello";
//     // string::reverse_iterator rit = s1.rbegin();
//     auto rit = s1.rbegin();
//     cout << "长度是" << s1.length() << endl;
//     cout << "长度是" << s1.size() << endl;
//     while (rit != s1.rend())
//     {
//         cout << *rit << " ";
//         ++rit;
//     }
//     cout << endl;

//     // 使用范围for循环（C++11及以上）
//     cout << "使用范围for循环（C++11及以上）:" << endl;
//     for (int num : numbers)
//     {
//         cout << num << " ";
//     }
//     cout << endl;



//     return 0;
// }

// int main()
// {
//     // string s1 = "hello world";
//     // cout << s1.max_size() << endl;
//     // cout << s1.capacity() << endl;
//     // s1.clear(); // 进行清空操作
//     // cout << s1.size()<< endl;
//     // cout << s1.empty() << endl; // 判断是否为空
//     string s2= "joolin";
//     s2.reserve(100); // 预留100个字符的空间
//     // cout << s2.capacity() << endl; // 输出预留的空间
//     // s2 = "joolin";
//     // cout << s2.size() << endl; // 输出实际的空间
//     // cout << s2.length() << endl; // 输出实际的空间
//     // cout << s2.capacity() << endl; // 输出实际分配的空间
//     // s2.clear(); // 清空字符串
//     // cout << s2.size() << endl; // 输出实际的空间
//     // cout << s2.capacity() << endl; // 输出实际分配的空间
//     char c1=s2[0]; // 访问字符串的第一个字符
//     char c2=s2.at(0); // 访问字符串的第一个字符
//     cout << c1 << endl;
//     cout << c2 << endl;
//     cout << s2.front() << endl; // 访问字符串的第一个字符
//     cout << s2.back() << endl; // 访问字符串的最后一个字符，不包括'\0'
// }

// int main()
// {
//     std::string s1 = "hello world";
//     s1 += "!";
//     std::cout << s1 << std::endl;
//     s1.push_back('!');
//     std::cout << s1 << std::endl;
//     s1.append("joolin");
//     std::cout << s1 << std::endl;
//     s1.append("joolin", 0, 3);
//     std::cout << s1 << std::endl;
//     s1.insert(0, "joolin");
//     std::cout << s1 << std::endl;
// }

// #include <iostream>
// using namespace std;

// int main() {
//     string line;
//     while (getline(cin, line)) {
//         size_t pos = line.rfind(' ');
//         cout << line.size() - pos - 1 << endl;
//     }
//     return 0;
// }

// 64 位输出请用 printf("%lld")

// class Solution {
//     public:
//         int myAtoi(string str) {
//             int res = 0, bianjie = INT_MAX / 10;
//             int i = 0, sign = 1, length = str.size();
//             if (length == 0)
//                 return 0;
//             while (str[i] == ' ')
//                 if (++i = length)
//                     return 0;
//             if (str[i] == '-')
//                 sign = -1;
//             if (str[i] == '-' || str[i] == '+')
//                 i++;
//             for (int j = i; j < length; j++) {
//                 if (str[j] < '0' || str[j] > '9')
//                     break;
//                 if (res > bianjie || res == bianjie && str[j] > '7')
//                     return sign == 1 ? INT_MAX : INT_MIN;
//                 res = res * 10 + (str[j] - '0');
//             }
//             return sign * res;
//         }
//     };

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string multiply(string num1, string num2) {
    int len1 = num1.size();
    int len2 = num2.size();

    // 结果最多不会超过 len1 + len2 位
    vector<int> result(len1 + len2, 0);

    // 逐位相乘（从末尾向前，即低位在后）
    for (int i = len1 - 1; i >= 0; --i) {
        int digit1 = num1[i] - '0';
        for (int j = len2 - 1; j >= 0; --j) {
            int digit2 = num2[j] - '0';

            // 计算乘积
            int mul = digit1 * digit2;

            // 累加到结果的对应位置
            int p1 = i + j;     // 进位位置
            int p2 = i + j + 1; // 当前位
            int sum = mul + result[p2];

            result[p2] = sum % 10;          // 当前位
            result[p1] += sum / 10;         // 进位加到高一位
        }
    }

    // 跳过前导0
    string product = "";
    bool leadingZero = true;
    for (int digit : result) {
        if (leadingZero && digit == 0) continue;
        leadingZero = false;
        product += to_string(digit);
    }

    return product.empty() ? "0" : product;
}

// 测试代码
int main() {
    string num1 = "123";
    string num2 = "456";
    cout << "Product: " << multiply(num1, num2) << endl; // Output: 56088
    return 0;
}
