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
