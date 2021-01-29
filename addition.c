#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include "utilities.h"

#define USIZE 32
typedef uint32_t uint;
uint32_t temp;
// Testing Git Change
void printByte() {
    uint32_t max = ipow(2, 32) - 1;
    printf("Well hello there. Let's print a byte in binary.\nEnter an unsigned number between 0 and 2^32 - 1: ");
    uint32_t integer;
    scanf("%u", &integer);

    while (integer >= max) {
        printf("Please stay in range!\n");
        printf("Please re-enter a number between 0 and 2^32 -1: ");
        scanf("%u", &integer);
    }
    printf("Great. Let's see what that is in binary\n");
    printf("Printing %u in binary: ", integer);

    uint32_t mask = 1;
    for (int i = 1; i <= USIZE; i++) {
        temp = integer >> (USIZE - i);  // shift right by USIZE (32) - i
        if (temp & mask > 0) {
            printf("1");
        } else {
            printf("0");
        }
        if (i % 4 == 0) printf(" ");
    }
    printf("\n");
}

// Found this function at https://en.wikipedia.org/wiki/Bitwise_operations_in_C
int adder(void) {
    printf("\nLet's now add two numbers with bitwise operations.\n");
    uint32_t x = 3,
             y = 1, sum, carry;
    printf("Enter another unsigned int (x) between 0 and 2^32 - 1: ");
    scanf("%u", &x);
    printf("And enter a y value as well: ");
    scanf("%u", &y);
    sum = x ^ y;  // X XOR Y  /// XOR can have more than each arg, less than each, equal to or in between. Variable, whereas OR is always gainy.
    // Why is XOR used for adding, as the sum part?
    carry = x & y;  // x AND y

    while (carry != 0) {
        carry = carry << 1;  // left shift carry. Throw off biggest number. I don't think it's possible to have biggest bit (little endian) on with a carry.
        x = sum;             // initilize x as sum
        y = carry;
        sum = x ^ y;    // sum is calculated
        carry = x & y;  //just keep doing this loop until carry = 0.
    }
    printf("The sum of these two numbers is %u and carry is %d\n", sum, carry);
    printf("Isn't that impressive? Wait, you didn't see the source code did you? Just take our word for it then.\n");
    return sum;
}

int main(void) {
    printByte();
    adder();

    return 0;
}

