#include <iostream>
#include "MiniList.h" // 确保你的文件名正确

using namespace joolin;

void testList() {
    // 创建一个链表
    List<int> myList;

    // 测试 push_back 和 push_front
    myList.push_back(10);
    myList.push_back(20);
    myList.push_back(30);
    myList.push_front(5);
    myList.push_front(1);

    std::cout << "After push_back and push_front: ";
    for (auto it = myList.begin(); it != myList.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // 测试 front 和 back
    std::cout << "Front: " << myList.front() << std::endl;
    std::cout << "Back: " << myList.back() << std::endl;

    // 测试 pop_back 和 pop_front
    myList.pop_back();
    myList.pop_front();

    std::cout << "After pop_back and pop_front: ";
    for (auto it = myList.begin(); it != myList.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // 测试 insert
    myList.insert(2, 15);
    std::cout << "After insert at position 2: ";
    for (auto it = myList.begin(); it != myList.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // 测试 erase
    myList.erase(2);
    std::cout << "After erase at position 2: ";
    for (auto it = myList.begin(); it != myList.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // 测试 sort
    myList.push_back(25);
    myList.push_back(5);
    myList.sort();
    std::cout << "After sort: ";
    for (auto it = myList.begin(); it != myList.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // 测试 clear
    myList.clear();
    std::cout << "After clear, size: " << myList.get_size() << std::endl;
}

int main() {
    testList();
    return 0;
}