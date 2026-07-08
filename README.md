# MyVector - C++ Vector Template Container

MyVector is a lightweight C++ template container that recreates the core behavior of `std::vector`.
It is designed as a portfolio project for demonstrating C++ templates, dynamic memory management,
deep copy, operator overloading, exception handling, and basic iterator design.

## Highlights

- Implements a reusable template class: `MyVector<T>`
- Uses dynamic arrays to manage contiguous storage
- Supports automatic capacity expansion with a 2x growth strategy
- Provides default construction, capacity-based construction, copy construction, copy assignment, and destruction
- Implements `push_back`, `pop_back`, `size`, `capacity`, `at`, and `operator[]`
- Uses pointer-based iterators through `begin()` and `end()`
- Includes a runnable demo covering insertion, expansion, indexing, iteration, copying, and bounds checking

## Project Structure

```text
.
├── CMakeLists.txt            # CMake build configuration
├── LICENSE                   # MIT license
├── MyVector.h                # Header-only MyVector implementation
├── PROJECT_DESCRIPTION.txt   # Resume-ready project description
├── README.md                 # Project documentation
└── main.cpp                  # Demo and functional test entry
```

## Build And Run

### Option 1: g++

```bash
g++ -std=c++11 main.cpp -o myvector_test
./myvector_test
```

On Windows:

```cmd
g++ -std=c++11 main.cpp -o myvector_test.exe
myvector_test.exe
```

### Option 2: CMake

```bash
cmake -S . -B build
cmake --build build
```

Then run:

```bash
./build/myvector_demo
```

On Windows, the executable may be generated under `build/Debug` or `build/Release` depending on the generator.

## Demo Coverage

The demo program verifies:

- Default constructor
- Capacity constructor
- Copy constructor
- `push_back` insertion
- 2x automatic expansion
- `operator[]` index access
- `at()` bounds checking
- Iterator traversal
- `pop_back` removal

## Example Output

```text
默认构造后: size = 0, capacity = 0

测试 push_back 和扩容:
插入 10 后: size = 1, capacity = 1
插入 20 后: size = 2, capacity = 2
插入 30 后: size = 3, capacity = 4
...

使用迭代器遍历:
10 20 30 40 50 60 70 80 90 100

捕获越界异常: index out of range
```

## Resume Description

Implemented a simplified `std::vector`-like container in C++ using templates and dynamic memory management.
The project supports automatic 2x capacity expansion, element insertion/removal, index access, bounds checking,
deep copy, operator overloading, and pointer-based iterator traversal.

## License

This project is licensed under the MIT License.
