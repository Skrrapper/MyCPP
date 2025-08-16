#include <iostream>
using namespace std;


//菱形继承与虚拟菱形继承的区别
struct A {
    int x;
    A(int v = 0) : x(v) { cout << "A(" << v << ")\n"; }
    virtual ~A() = default;
    virtual void who() { cout << "A\n"; }
};

// ---- 非虚菱形 ----
struct B1 : public A { B1() : A(1) { cout << "B1\n"; } };
struct C1 : public A { C1() : A(2) { cout << "C1\n"; } };
struct D1 : public B1, public C1 {
    D1() { cout << "D1\n"; }
};

// ---- 虚拟菱形 ----
struct B2 : virtual public A { B2() : A(10) { cout << "B2\n"; } }; // A(10)会被最终类覆盖
struct C2 : virtual public A { C2() : A(20) { cout << "C2\n"; } };
struct D2 : public B2, public C2 {
    D2() : A(42) { cout << "D2\n"; } // 只有这里的 A(42) 生效
};

int main() {
    cout << "=== 非虚菱形 ===\n";
    D1 d1;
    // A* a = &d1; // 编译错误：二义性
    A* a1 = static_cast<A*>(static_cast<B1*>(&d1));
    A* a2 = static_cast<A*>(static_cast<C1*>(&d1));
    cout << "A via B1: " << a1 << "\n";
    cout << "A via C1: " << a2 << "\n"; // 两个地址不同

    cout << "\n=== 虚拟菱形 ===\n";
    D2 d2;
    A* a3 = &d2; // ✅ 唯一
    A* a4 = static_cast<A*>(static_cast<B2*>(&d2));
    A* a5 = static_cast<A*>(static_cast<C2*>(&d2));
    cout << "A via D2:  " << a3 << "\n";
    cout << "A via B2:  " << a4 << "\n";
    cout << "A via C2:  " << a5 << "\n"; // 三个地址相同
}

// struct A {
//     A(int v) { std::cout << "A(" << v << ")\n"; }
// };

// struct B : virtual A {
//     B() : A(1) { std::cout << "B\n"; } // 这行对虚基 A 的初始化在最终对象里会被 D 覆盖
// };

// struct C : virtual A {
//     C() : A(2) { std::cout << "C\n"; }
// };

// struct D : B, C {
//     D() : A(42) { std::cout << "D\n"; } // ✅ 只有这里的 A(42) 生效
// };

// int main() {
//     D d;
//     A* a1 = static_cast<A*>(static_cast<B*>(&d));
//     A* a2 = static_cast<A*>(static_cast>C*>(&d));
//     std::cout << a1 << " vs " << a2 << "\n"; // 两个不同地址
// }
