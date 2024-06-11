/*
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 */

#if 0
/*
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to this part of the project by
editing the collection of functions in this source file.

INTEGER CODING RULES:

  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code
  must conform to the following style:

  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>

  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.


  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc program (described in the spec) to check the legality of
     your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies
     between the maximum ops in the spec and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 *
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *
 *      YOU WILL RECEIVE NO CREDIT IF YOUR CODE DOES NOT PASS THIS CHECK.
 *
 *   2. Use the btest checker to verify that your solutions produce the
 *      correct answers.
 */

#endif

/*
 * isZero - returns 1 if x == 0, and 0 otherwise
 *   Examples: isZero(5) = 0, isZero(0) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int isZero(int x) {
    return !x;
}

/*
 * bitNor - ~(x|y) using only ~ and &
 *   Example: bitNor(0x6, 0x5) = 0xFFFFFFF8
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitNor(int x, int y) {
    return (~x) & (~y);
}

/*
 * distinctNegation - returns 1 if x != -x, and 0 otherwise
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 5
 *   Rating: 2
 */
int distinctNegation(int x) {
    int neg_x = ~x + 1; // Calculate the two's complement of x, which is -x
    return !!(x ^ neg_x); // Check if x is not equal to -x by using XOR and double negation
}

/*
 * dividePower2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: dividePower2(15,1) = 7, dividePower2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int dividePower2(int x, int n) {
    int sign = (x >> 31); // Get the sign bit of x
    int bias = (1 << n) + (~0); // Calculate the bias for rounding
    int biased_x = x + (bias & sign); // Add the bias to the numerator
    return biased_x >> n; // Perform the division with bias and rounding toward zero
}


/*
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (least significant) to 3 (most significant)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
    return (x >> (n << 3)) & 0xFF; // Shift x by n*8 bits and mask with 0xFF to extract the byte
}

/*
 * isPositive - return 1 if x > 0, return 0 otherwise
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 2
 */
int isPositive(int x) {
    return !((x >> 31) | !x); // Check the sign bit and whether x is zero
}

/*
 * floatNegate - Return bit-level equivalent of expression -f for
 * floating point argument f.
 * Both the argument and result are passed as unsigned int's, but
 * they are to be interpreted as the bit-level representations of
 * single-precision floating point values.
 * When the argument is NaN, return the argument.
 * Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 * Max ops: 10
 * Rating: 2
 */
unsigned floatNegate(unsigned uf) {
    // Check if the argument is NaN by comparing the exponent bits and
    // fraction bits to zero.
    unsigned exp = (uf >> 23) & 0xFF;
    unsigned frac = uf & 0x7FFFFF;

    if (exp == 0xFF && frac != 0) {
        // It's NaN, return the argument itself.
        return uf;
    } else {
        // Toggle the sign bit by flipping the most significant bit.
        return uf ^ 0x80000000;
    }
}


/*
 * isLessOrEqual - if x <= y then return 1, else return 0
 * Example: isLessOrEqual(4, 5) = 1.
 * Legal ops: ! ~ & ^ | + << >>
 * Max ops: 24
 * Rating: 3
 */
int isLessOrEqual(int x, int y) {
    // Calculate the difference between y and x
    int diff = y + ((~x) + 1);//y-x > 0
    return !(diff>>31);
}


/*
 * bitMask - Generate a mask consisting of all 1's between
 * lowbit and highbit
 * Examples: bitMask(5,3) = 0x38 = 56 = 0b111000
 * Assume 0 <= lowbit <= 31, and 0 <= highbit <= 31
 * If lowbit > highbit, then the mask should be all 0's
 * Legal ops: ! ~ & ^ | + << >>
 * Max ops: 16
 * Rating: 3
 */
int bitMask(int highbit, int lowbit) {
    // Initialize a base integer with all bits set to 1.
    int base = ~0;

    // Create a mask with 1's from highbit to the most significant bit.
    int re1 = (base << (highbit)) << 1;

    // Create a mask with 1's from the least significant bit to lowbit.
    int re2 = base << (lowbit);

    // Combine the two masks 
    return (~re1 & re2);
}





/*
 * addOK - Determine if can compute x+y without overflow
 * Example: addOK(0x80000000,0x80000000) = 0,
 *          addOK(0x80000000,0x70000000) = 1,
 * Legal ops: ! ~ & ^ | + << >>
 * Max ops: 20
 * Rating: 3
 */
int addOK(int x, int y) {
    int sum = x + y;
    int sign_x = x >> 31; // Get the sign bit of x
    int sign_y = y >> 31; // Get the sign bit of y
    int sign_sum = sum >> 31; // Get the sign bit of the sum

    // Overflow occurs if both x and y have the same sign, but the sum has a different sign.
    return !((sign_x ^ sign_sum) & (sign_y ^ sign_sum));
}


/*
 * floatScale64 - Return bit-level equivalent of expression 64*f for
 * floating point argument f.
 * Both the argument and result are passed as unsigned int's, but
 * they are to be interpreted as the bit-level representation of
 * single-precision floating point values.
 * When the argument is NaN, return the argument.
 * Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 * Max ops: 35
 * Rating: 4
 */
unsigned floatScale64(unsigned uf) {
    // Extract the sign bit, exponent, and fraction from the input.
    unsigned sign = uf & 0x80000000;
    unsigned exponent = (uf & 0x7F800000) >> 23;
    unsigned fraction = uf & 0x007FFFFF;
    int j = 6;

    while (j > 0) {
        j--;

        // Re-calculate the exponent on each iteration.
        exponent = (uf & 0x7F800000) >> 23;

        // Check if the exponent is zero.
        if (!exponent) {
            // Shift the fraction part left by one and retain the sign bit.
            uf = sign | (uf << 1);
        } else {
            // Check if the exponent is not the maximum value (0xFF).
            if (exponent != 0xFF) {
                // Add 64 to the input value by modifying the bits in the exponent.
                uf = uf + 0x800000;

                // Re-calculate the exponent after adding 64.
                exponent = (uf & 0x7F800000) >> 23;

                // If the exponent became the maximum value (0xFF), remove the fraction part.
                if (exponent == 0xFF) {
                    fraction = 0;
                    uf = sign | (exponent<<23) | fraction;
                }
            }
        }
    }
    
    return uf;
}


/*
 * floatPower2 - Return the bit-level equivalent of the expression 2.0^x
 * (2.0 raised to the power x) for any 32-bit integer x.
 *
 * The unsigned value that is returned should have the identical bit
 * representation as the single-precision floating-point number 2.0^x.
 * If the result is too small to be represented as a denorm, return 0.
 * If too large, return +INF.
 * Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while
 * Max ops: 30
 * Rating: 4
 */
unsigned floatPower2(int x) {
    unsigned bias = 127;

    // Calculate the exponent value.
    unsigned exp = x + bias;
    unsigned frac = 0;

    if (x < -149) {
        // If x is too small for a denormalized number, return 0.
        return 0;
    } else if (x < -126) {
        // Calculate the exponent bias and create the result with the adjusted exponent.
        // To represent denormalized numbers, we shift 1 to the right of the implicit 1.
        frac = 1 << (x + 149);
        exp = 0;
        return (exp << 23) | frac;
    } else if (exp >= 255) {
        // If x is too large, return +INF (positive infinity).
        return 0x7F800000;
    } 
    return (exp << 23) | frac;
    
}


