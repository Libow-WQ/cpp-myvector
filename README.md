# MyVector - 简易 C++ Vector 模板类

这是一个使用 C++ 模板实现的简易版 `vector` 容器项目，用于模拟 STL `vector` 的核心功能，适合作为 C++ 基础、模板编程和动态内存管理的练习项目。

## 项目特点

- 使用模板类 `MyVector<T>`，支持不同数据类型
- 使用动态数组管理元素存储
- 支持自动扩容，容量不足时扩大为原来的 2 倍
- 实现默认构造、指定容量构造、拷贝构造和析构函数
- 实现 `push_back`、`pop_back`、`size`、`capacity`、`at` 等常用接口
- 重载 `operator[]`，支持下标访问
- 使用指针实现简单迭代器，支持 `begin()` 和 `end()`
- 包含完整测试程序，覆盖插入、扩容、访问、遍历、删除和越界检查

## 文件结构

```text
.
├── MyVector.h    # MyVector 模板类实现
├── main.cpp      # 测试程序入口
└── README.md     # 项目说明
```

## 编译方式

```bash
g++ -std=c++11 main.cpp -o myvector_test.exe
```

## 运行方式

```bash
./myvector_test.exe
```

Windows 命令行中也可以运行：

```cmd
myvector_test.exe
```

## 测试内容

程序会依次测试：

- 默认构造函数
- `push_back` 插入元素
- 自动扩容
- `operator[]` 下标访问
- `at()` 安全访问和越界异常
- 迭代器遍历
- `pop_back` 删除元素
- 指定容量构造函数
- 拷贝构造函数

## 简历项目描述

使用 C++ 模板和动态内存管理实现简易版 `vector` 容器，支持自动扩容、元素增删、下标访问、越界检查和基础迭代器遍历。项目体现了对模板类、深拷贝、资源释放、运算符重载和 STL 容器底层思想的理解。
