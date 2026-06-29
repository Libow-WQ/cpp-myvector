#include <iostream>
#include <stdexcept>
#ifdef _WIN32
#include <windows.h>
#endif
#include "MyVector.h"

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    MyVector<int> vec;

    std::cout << "默认构造后: size = " << vec.size()
              << ", capacity = " << vec.capacity() << std::endl;

    // 测试 push_back 和自动扩容
    std::cout << "\n测试 push_back 和扩容:" << std::endl;
    for (int i = 1; i <= 10; ++i) {
        vec.push_back(i * 10);
        std::cout << "插入 " << i * 10
                  << " 后: size = " << vec.size()
                  << ", capacity = " << vec.capacity()
                  << std::endl;
    }

    // 测试 operator[] 下标访问
    std::cout << "\n使用 operator[] 访问:" << std::endl;
    for (int i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    // 测试 at 访问
    std::cout << "\n使用 at(2) 访问第三个元素: " << vec.at(2) << std::endl;

    // 测试迭代器遍历
    std::cout << "\n使用迭代器遍历:" << std::endl;
    for (MyVector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // 测试 pop_back
    vec.pop_back();
    vec.pop_back();
    std::cout << "\n执行两次 pop_back 后: size = " << vec.size()
              << ", capacity = " << vec.capacity() << std::endl;

    std::cout << "当前元素:" << std::endl;
    for (int value : vec) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    // 测试带容量构造函数
    MyVector<int> fixedCapacityVec(5);
    std::cout << "\n带容量构造后: size = " << fixedCapacityVec.size()
              << ", capacity = " << fixedCapacityVec.capacity() << std::endl;

    // 测试拷贝构造
    MyVector<int> copiedVec(vec);
    std::cout << "\n拷贝构造 copiedVec 后:" << std::endl;
    for (int value : copiedVec) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    // 测试越界检查
    try {
        std::cout << "\n尝试访问 vec.at(100):" << std::endl;
        std::cout << vec.at(100) << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "捕获越界异常: " << e.what() << std::endl;
    }

    return 0;
}
