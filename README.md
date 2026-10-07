*This project has been created as part of the 42 curriculum*

# CPP Module 02

## Description

The third module of the 42 C++ series. It introduces **ad-hoc polymorphism**, **operator overloading**, and the **Orthodox Canonical Form** for classes. Over the exercises, a `Fixed` class is built step by step: a **fixed-point number** class that behaves like a native numeric type.

All code is compiled with:

```bash
c++ -Wall -Wextra -Werror -std=c++98
```

## Fixed-point numbers

A fixed-point number stores a value as an integer where a fixed number of low-order bits represent the fractional part. Here the class uses **8 fractional bits**, so a value is stored as the real value multiplied by 2⁸ (256). This gives a cheap way to represent fractions without floating-point hardware, with a precision of 1/256.

## Instructions

Each exercise has its own folder and its own `Makefile`:

```bash
cd ex00        # or ex01, ex02
make           # builds the executable
make clean     # removes object files
make fclean    # removes object files and the executable
make re        # rebuilds everything
```

### Requirements

- A C++ compiler (`c++`, `g++`, or `clang++`) with C++98 support
- `make`

## Exercises

### ex00: My First Class in Orthodox Canonical Form

Creates the first version of the `Fixed` class, with the four members required by the **Orthodox Canonical Form**:

- a default constructor,
- a copy constructor,
- a copy assignment operator,
- a destructor.

The class stores a raw integer value and the constant number of fractional bits (8), and exposes `getRawBits()` and `setRawBits()`. Each special member function prints a message when it is called, to show when copies and assignments happen.

**Focus:** the Orthodox Canonical Form and object lifecycle.

### ex01: Towards a more useful fixed-point number class

Makes `Fixed` actually usable:

- a constructor from an `int` and a constructor from a `float`, both converting to the fixed-point representation,
- `toInt()` and `toFloat()` to convert back,
- an overload of the `<<` operator to print the value as a float.

**Focus:** type conversions and overloading the stream insertion operator.

### ex02: Now we're talking

Gives `Fixed` the behavior of a real number type by overloading operators:

| Category | Operators |
|---|---|
| Comparison | `>`, `<`, `>=`, `<=`, `==`, `!=` |
| Arithmetic | `+`, `-`, `*`, `/` |
| Increment / decrement | pre- and post-increment and decrement (`++a`, `a++`, `--a`, `a--`), which change the value by the smallest representable amount (1/256) |

It also adds static `min` and `max` functions, with `const` and non-`const` overloads.

**Focus:** operator overloading and the difference between pre- and post-increment.

## Project structure

```
.
├── ex00/   # Fixed class in Orthodox Canonical Form
├── ex01/   # Int and float constructors, conversions, << operator
└── ex02/   # Comparison, arithmetic, increment operators, min/max
```

Each folder contains its own `Makefile`, `Fixed.hpp`, `Fixed.cpp`, and a `main.cpp` with tests.

## Resources

- [cppreference: operator overloading](https://en.cppreference.com/w/cpp/language/operators)
- [Fixed-point arithmetic](https://en.wikipedia.org/wiki/Fixed-point_arithmetic)
- [Orthodox Canonical Form](https://en.cppreference.com/w/cpp/language/rule_of_three)
- The 42 CPP Module 02 subject PDF
