# Arbitrary Precision Calculator (APC)

## Project Brief
Developed an arbitrary-precision calculator in C to perform operations on very large numbers beyond normal data type limits. Stored numbers using linked lists and implemented arithmetic operations like addition, subtraction, multiplication, division, modulus, and power. Handled carry operations, zero-value optimization, and decimal numbers with dynamic memory management.

## Overview
This project implements a calculator that can handle numbers of arbitrary length, overcoming the limitations of standard data types. It uses linked lists to store and manipulate large numbers, enabling precise calculations on numbers that would otherwise cause overflow.

## Features
- Perform arithmetic operations on very large numbers
- Addition, subtraction, multiplication, division operations
- Modulus and power operations
- Support for decimal numbers
- Dynamic memory management using linked lists
- Carry and borrow handling for accurate calculations
- Zero-value optimization for efficiency

## Project Structure
- `main.c` - Main program entry point
- `fun.c` - Function implementations
- `fun.h` - Function declarations and headers
- `makefile` - Build automation file

## How to Build
```bash
make
```

## How to Run
```bash
./apc.exe
```

## How to Clean
```bash
make clean
```

## Technologies Used
- **Advanced C** - Function pointers, Dynamic memory allocation, String manipulation, Linked lists, Order complexity, Applying Abstract Data Types (ADT)

## Key Challenges & Learnings
✓ Implementing multiplication using double linked lists feels little difficulty in taking carry add to next number and some operations
✓ Implementing arithmetic operations on large numbers stored as strings with manual carry/borrow handling
✓ Optimizing algorithms for speed and accuracy while managing memory efficiency
✓ Improved problem-solving and algorithms design skills for precision-based numerical computations

## GitHub Repository
https://github.com/Khusboo-REC/project-2

## Learning Objectives
- Understanding modular programming in C
- Using Makefiles for build automation
- Implementing complex data structures (linked lists)
- Managing dynamic memory allocation
- Handling large number arithmetic with precision
