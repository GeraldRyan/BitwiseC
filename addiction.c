#include <stdio.h>

// From wikipedia https://en.wikipedia.org/wiki/Bitwise_operations_in_C

typedef unsigned int uint;

int main(void){
  uint x = 3, y = 1, sum, carry;
  sum = x ^ y; // X XOR Y  /// XOR can have more than each arg, less than each, equal to or in between. Variable, whereas OR is always gainy. 
  // Why is XOR used for adding, as the sum part?   
  carry = x & y; // x AND y

  while (carry != 0){
    carry = carry << 1; // left shift carry. Throw off biggest number. I don't think it's possible to have biggest bit (little endian) on with a carry. 
    x = sum; // initilize x as sum
    y = carry; 
    sum = x ^ y; // sum is calculated
    carry = x & y; //just keep doing this loop until carry = 0. 

  }

  printf("Sum is %d and carry is %d\n", sum, carry);
  return sum;
}