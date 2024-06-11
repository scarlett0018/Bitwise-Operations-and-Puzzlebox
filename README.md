# Bitwise-Operations-and-Puzzlebox

## Overview

It is the second project of CSCI2021 in University of Minnesota, Twin Cities. This project consists of several bitwise operations and a puzzle-solving component. The project is divided into multiple tasks, each involving different bitwise operations implemented in C, and a puzzlebox challenge.

## Files

- **Makefile**: A file used by the `make` build automation tool to compile and link the project.
- **bitwise**: Contains the implementation of various bitwise operations.
- **metadata.yml**: Contains metadata for the project.
- **puzzlebox**: Contains the implementation of the puzzlebox challenge.

## Tasks

### Bitwise Operations

The following bitwise operations are implemented in the `bitwise` file:

1. **isZero**: Checks if a number is zero.
2. **bitNor**: Computes the bitwise NOR of two numbers.
3. **distinctNegation**: Determines if a number and its negation are distinct.
4. **dividePower2**: Divides a number by a power of 2.
5. **getByte**: Extracts a byte from a word.
6. **isPositive**: Checks if a number is positive.
7. **floatNegate**: Negates a floating-point number.
8. **isLessOrEqual**: Checks if one number is less than or equal to another.
9. **bitMask**: Generates a bitmask.
10. **addOK**: Checks if the addition of two numbers is safe.
11. **floatScale64**: Scales a floating-point number by 64.
12. **floatPower2**: Raises a floating-point number to the power of 2.

### Puzzlebox

The `puzzlebox` file contains the implementation for solving a specific puzzle. The details of the puzzle and the approach used to solve it are encapsulated in this file.

## Usage

To build and run the project, you can use the following commands:

```sh
# To compile the project
make

# To run the bitwise operations (example)
./bitwise

# To run the puzzlebox challenge
./puzzlebox
