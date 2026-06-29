#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <stdexcept>

template <typename T>
class MyVector {
private:
    T* data_;       // 动态数组，负责保存元素
    int size_;      // 当前已存放的元素个数
    int capacity_;  // 当前动态数组容量

    // 当容量不足时扩容，新容量扩大为原来的 2 倍
    void expandCapacity() {
        int newCapacity = (capacity_ == 0) ? 1 : capacity_ * 2;
        T* newData = new T[newCapacity];

        // 将旧数组中的元素复制到新数组
        for (int i = 0; i < size_; ++i) {
            newData[i] = data_[i];
        }

        delete[] data_;
        data_ = newData;
        capacity_ = newCapacity;
    }

public:
    // 简单迭代器：直接使用指针
    typedef T* iterator;
    typedef const T* const_iterator;

    // 默认构造函数
    MyVector() : data_(nullptr), size_(0), capacity_(0) {}

    // 带容量参数的构造函数
    explicit MyVector(int capacity) : data_(nullptr), size_(0), capacity_(capacity) {
        if (capacity < 0) {
            throw std::invalid_argument("capacity cannot be negative");
        }

        if (capacity_ > 0) {
            data_ = new T[capacity_];
        }
    }

    // 拷贝构造函数：执行深拷贝
    MyVector(const MyVector& other)
        : data_(nullptr), size_(other.size_), capacity_(other.capacity_) {
        if (capacity_ > 0) {
            data_ = new T[capacity_];
            for (int i = 0; i < size_; ++i) {
                data_[i] = other.data_[i];
            }
        }
    }

    // 拷贝赋值运算符，避免浅拷贝导致重复释放
    MyVector& operator=(const MyVector& other) {
        if (this == &other) {
            return *this;
        }

        T* newData = nullptr;
        if (other.capacity_ > 0) {
            newData = new T[other.capacity_];
            for (int i = 0; i < other.size_; ++i) {
                newData[i] = other.data_[i];
            }
        }

        delete[] data_;
        data_ = newData;
        size_ = other.size_;
        capacity_ = other.capacity_;

        return *this;
    }

    // 析构函数：释放动态内存
    ~MyVector() {
        delete[] data_;
    }

    // 在末尾添加元素，容量不足时自动扩容
    void push_back(const T& value) {
        if (size_ >= capacity_) {
            expandCapacity();
        }

        data_[size_] = value;
        ++size_;
    }

    // 删除末尾元素
    void pop_back() {
        if (size_ > 0) {
            --size_;
        }
    }

    // 返回当前元素个数
    int size() const {
        return size_;
    }

    // 返回当前容量
    int capacity() const {
        return capacity_;
    }

    // 返回指定位置元素，带越界检查
    T& at(int index) {
        if (index < 0 || index >= size_) {
            throw std::out_of_range("index out of range");
        }
        return data_[index];
    }

    const T& at(int index) const {
        if (index < 0 || index >= size_) {
            throw std::out_of_range("index out of range");
        }
        return data_[index];
    }

    // 下标访问，不做越界检查
    T& operator[](int index) {
        return data_[index];
    }

    const T& operator[](int index) const {
        return data_[index];
    }

    // 返回第一个元素位置
    iterator begin() {
        return data_;
    }

    const_iterator begin() const {
        return data_;
    }

    // 返回最后一个元素的下一个位置
    iterator end() {
        return data_ + size_;
    }

    const_iterator end() const {
        return data_ + size_;
    }
};

#endif
