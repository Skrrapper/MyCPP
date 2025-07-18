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


