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
