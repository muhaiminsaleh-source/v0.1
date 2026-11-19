# Student Grade Calculator

## Introduction
This project is a C++ Student Grade Calculator. It stores student information, homework marks, and exam results. It calculates final grades using either the average or median of homework marks.

## Final Grade Formula

**Average method:**

Final points = 0.4 × Average of Homework + 0.6 × Exam

**Median method:**

Final points = 0.4 × Median of Homework + 0.6 × Exam

## Features
- Person class with constructors and destructor.
- Copy constructor and assignment operator (Rule of Three).
- Input and output operator overloading (`>>` and `<<`).
- Homework marks stored using `vector`.
- Average and median grade calculations.
- Read student data from `Students.txt`.
- Generate random student data.
- Sort students by surname and first name.
- Select the average or median grading method.
- Display formatted student results.

## Input File
The program reads student records from `Students.txt`.

Example:

```text
Name Surname HW1 HW2 HW3 HW4 HW5 Exam
Rahim Ahmed 8 9 10 6 10 9
Karim Hasan 7 10 8 5 4 6
Nadia Islam 9 8 7 10 9 8
```

## Technologies
- C++
- Standard Template Library (STL)
- `vector`, `algorithm`, `fstream`, and `sstream`

## Version
v0.1

---

## Release v0.2 - Speed Rate Analysis (`std::vector`)

| Records | Read Time (s) | Sort Time (s) | Split Time (s) | Write Time (s) |
| :--- | :--- | :--- | :--- | :--- |
| **1,000** | 0.00035 | 0.00014 | 0.00007 | 0.00051 |
| **10,000** | 0.00338 | 0.00127 | 0.00061 | 0.00490 |
| **100,000** | 0.03867 | 0.02322 | 0.00679 | 0.04660 |
| **1,000,000** | 0.41526 | 0.20614 | 0.10138 | 0.56412 |
| **10,000,000** | 6.35384 | 2.50623 | 0.85724 | 5.83822 |

---

## Release v0.25 - Speed Rate Analysis (`std::deque` & `std::list`)

### `std::deque`
| Records | Read Time (s) | Sort Time (s) | Split Time (s) | Write Time (s) |
| :--- | :--- | :--- | :--- | :--- |
| **1,000** | 0.00051 | 0.00013 | 0.00004 | 0.00085 |
| **10,000** | 0.00349 | 0.00182 | 0.00063 | 0.00553 |
| **100,000** | 0.04000 | 0.02014 | 0.00374 | 0.04005 |
| **1,000,000** | 0.39468 | 0.25260 | 0.03899 | 0.47485 |
| **10,000,000** | 3.83483 | 2.70323 | 0.50176 | 5.08801 |

### `std::list`
| Records | Read Time (s) | Sort Time (s) | Split Time (s) | Write Time (s) |
| :--- | :--- | :--- | :--- | :--- |
| **1,000** | 0.00037 | 0.00009 | 0.00006 | 0.00077 |
| **10,000** | 0.00432 | 0.00136 | 0.00123 | 0.01018 |
| **100,000** | 0.04110 | 0.02284 | 0.01526 | 0.10963 |
| **1,000,000** | 0.54437 | 0.41037 | 0.17957 | 0.51539 |
| **10,000,000** | 4.09491 | 8.35362 | 1.68509 | 6.69925 |


## Releases Overview
- **v0.1**: Basic student grade calculator using `Person` class and `std::vector`.
- **v0.2**: Added file generation, sorting, splitting into passed/failed files, and exception handling.
- **v0.25**: Added `std::deque` and `std::list` implementations with speed benchmarks.
- **v1.0**: Added interactive menu, Strategy 1 vs Strategy 2 comparison, `<algorithm>` optimization, `Makefile`, and `CMakeLists.txt`.
## How to Build and Run (v1.0)
### Using Make (Linux / macOS / Codespaces)
1. Compile the program:
   ```bash
   make
   ```
2. Run the application:
   ```bash
   ./app
   ```
3. Clean build and generated files:
   ```bash
   make clean
   ```
### Using CMake (Cross-platform)
```bash
mkdir build && cd build
cmake ..
cmake --build .
./app
```
## v1.0 Benchmark Results (Splitting Speed in Seconds)
### Strategy 1 (Two new containers: `passed` & `failed`)
| Records | `std::vector` | `std::deque` | `std::list` |
| :--- | :--- | :--- | :--- |
| 1,000 | 0.000059 s | 0.000088 s | 0.000096 s |
| 10,000 | 0.000690 s | 0.000505 s | 0.000689 s |
| 100,000 | 0.009029 s | 0.004917 s | 0.006454 s |
| 1,000,000 | 0.099808 s | 0.057785 s | 0.084052 s |
### Strategy 2 (One new container: `failed`, shrink original)
| Records | `std::vector` | `std::deque` | `std::list` |
| :--- | :--- | :--- | :--- |
| 1,000 | 0.000044 s | 0.000029 s | 0.000028 s |
| 10,000 | 0.000624 s | 0.000358 s | 0.000227 s |
| 100,000 | 0.007019 s | 0.003929 s | 0.002086 s |
| 1,000,000 | 0.068535 s | 0.043045 s | 0.020564 s |
### Optimized `std::vector` using `<algorithm>` (`remove_copy_if` + `remove_if`)
| Records | Strategy 1 (Vector) | Strategy 2 (Vector) | Optimized Vector (`<algorithm>`) |
| :--- | :--- | :--- | :--- |
| 1,000 | 0.000059 s | 0.000044 s | 0.000035 s |
| 10,000 | 0.000690 s | 0.000624 s | 0.000522 s |
| 100,000 | 0.009029 s | 0.007019 s | 0.004000 s |
| 1,000,000 | 0.099808 s | 0.068535 s | 0.046224 s |
## Analysis of Results
- **Strategy 1 vs Strategy 2**: Strategy 2 uses less memory because it only creates one new container (`failed`) and shrinks the original container. It was also faster across all containers.
- **Container Performance**: In Strategy 2, `std::list` was the fastest (0.0205 s for 1M records) because erasing elements from a linked list is O(1) without shifting data.
- **Algorithm Optimization**: Refactoring `std::vector` with `std::remove_copy_if` and `std::remove_if` improved its speed significantly (from 0.0998 s in Strategy 1 and 0.0685 s in Strategy 2 down to 0.0462 s for 1M records).