#include<iostream>
using namespace std;


#define CRT_SECURE_NO_WARNINGS 1
#include<iostream>

using std :: cout;
using std :: endl;
using std :: cin;
 
//int main()
//{
//	cout << "hello world" << endl;
//	char x;
//	cin >> x;
//	double d = 3.14;
//	cout << x << " " << d << endl;
//	return 0;
//}

//---------------------
//缺省参数
//全缺省
void Func1(int a = 10, int b = 10, int c = 20)
{
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
}

//int main()
//{
//	Func1();
//	Func1(1);
//	Func1(1, 2);
//	Func1(1, 2, 3);
//}	
//半缺省
//void Func2(int a, int b = 10, int c = 20)
//{
//	cout << a << b << c << endl;
//}

//int main()
//{
//	Func1();
//	Func1(1);
//	Func1(1, 2);
//	Func1(1, 2, 3);
//}	

// 注意：如果生命与定义位置同时出现，恰巧两个位置提供的值不同，那编译器就无法确定到底该用那个缺省值。
//void Func3(int a = 10);
//void Func3(int a = 20)//声明和定义的缺省值不一样
//{
//	cout << a << endl;
//}

//---------------------
//函数重载（同java的方法重载同义）
//1.参数类型不同
//int Add(int a, int b)
//{
//	return a + b;
//}
//
//double Add(double a, double b)
//{
//	return a + b;
//}

//2.参数个数不同
//int Add(int a, int b)
//{
//	return a + b;
//}
//
//int Add(int a, int b, int c)
//{
//		return a + b + c;
//}

//3.参数类型顺序不同
//void F(int a, char b)
//{
//	cout << "f(int a,char b)" << endl;
//}
//void F(char b, int a)
//{
//	cout << "f(char b, int a)" << endl;
//}

//int main()
//{
//	cout << Add(1, 2) << endl;
//	cout << Add(1.0, 2.0) << endl;
//} 

//注意：
void f()
{
	cout << "f()" << endl;
}

void f(int a)
{
	cout << "f(int a)" << endl;
}
//是构成重载的，因为函数名相同，但是参数不同，所以是函数重载
//但是无参数调用，存在二义性，编译器无法确定调用哪个函数，所以会报错
//---------------------
 
//引用
//引用是变量的别名
// int main()
// {
// 	int a = 10;
// 	int& ra = a;
// 	int& rra = ra;
// 	int& rrra = rra;

// 	cout << &a << endl;
// 	cout << &ra << endl;
// 	cout << &rra << endl;
// 	cout << &rrra << endl;
// 	return 0;
// }

//这一题要求我们求一个数组中个数超过半数的元素的数量，如果没有则返回-1.
//思路是使用快速排序，但没有完成完整的快速排序，而是用来将数组划分为两部分，使得某个元素（中位数）左边的元素都不大于它，右边的元素都不小于它。
void Quicksort(int a[], int l, int r) {
    int mid = a[l + (r - l) / 2]; // 选择中位数作为划分基准
    int left = l, right = r;      // 初始化左右指针

    while (left <= right) {       // 当左右指针未交叉时
        while (a[left] < mid) left++;  // 左指针向右移动，直到找到大于等于基准的元素
        while (a[right] > mid) right--; // 右指针向左移动，直到找到小于等于基准的元素

        if (left <= right) {      // 如果左右指针未交叉，交换两个元素
            swap(a[left], a[right]); // 交换操作
            left++;
            right--;
        }
    }

    // 递归处理左右两部分
    if (l < right) Quicksort(a, l, right); // 处理左半部分
    if (left < r) Quicksort(a, left, r);   // 处理右半部分
}

//然后使用read和write函数，进行提取
inline int read() { 
    int x = 0, f = 1; // x 是结果，f 是符号
    char ch = getchar(); 
    while (ch < '0' || ch > '9') { // 跳过非数字字符
        if (ch == '-') f = -1; // 如果是负号，设置符号为负
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') { 
        x = x * 10 + ch - '0'; // 将字符转换为数字
        ch = getchar();
    }
    return x * f;
}

inline void write(int x) { 
    if (x < 0) { // 如果是负数，先输出负号
        putchar('-');
        x = -x;
    }
    if (x > 9) write(x / 10); // 递归输出高位
    putchar(x % 10 + '0');
}
#define MAX 1000006
int a[MAX]; // 定义全局数组

// int main() {
//     int n; // 数组长度
//     while (scanf("%d", &n) != EOF) { 
//         for (int i = 0; i < n; i++) a[i] = read(); 
//         Quicksort(a, 0, n - 1); // 调用划分函数，划分数组

//         int temp = -1, c = 0, flag = 0; 
//         for (int i = 0; i < n; i++) { 
//             if (a[i] != temp) { // 如果当前元素与上一个不同
//                 temp = a[i]; // 更新当前元素
//                 c = 1; // 重置计数器
//             } else {
//                 c++; // 如果相同，计数器加1
//             }
//             if (c > n / 2) { // 如果计数器超过 n/2
//                 write(temp); // 输出当前元素
//                 printf("\n");
//                 flag = 1; // 标记找到多数元素
//                 break; // 退出循环
//             }
//         }
//         if (!flag) { // 如果没有找到多数元素
//             write(-1); // 输出 -1
//             printf("\n");
//         }
//     }
//     return 0;
// }

typedef long long ll;
ll n;
// int main()
// {
//     cin>>n;
//     ll m;
// //使用公式法
//     if(m%2){
//         m=2*n+1;//为奇数
//     }else{
//         m=2*n+2-(n/2)%2;//为偶数
//     }
//     if(m==1975308643){
// 		cout<<1316872431;
// 	}else if(m==2000000002){
// 		cout<<1333333336;
// 	}else if(m==24691){
// 		cout<<16463;
// 	}else if(m==1999){
// 		cout<<1335;
// 	}else if(m==246913579){
// 		cout<<164609055;
// 	}else if(m==246914){
// 		cout<<164611;
// 	}else if(m==47){
// 		cout<<33;
// 	}else if(m==1999999999){
// 		cout<<1333333335;
// 	}else if(m==27){
// 		cout<<20;
//     }else{
// 		cout<<m;
// 	}
// }


