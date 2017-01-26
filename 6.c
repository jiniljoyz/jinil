/*

The sum of the squares of the first ten natural numbers is, 12 + 22 + ... + 102 = 385

The square of the sum of the first ten natural numbers is, (1 + 2 + ... + 10)2 = 552 = 3025

Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 - 385 = 2640.

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum

*/


#include <stdio.h>
int main(void)
{
  unsigned ss1 = 0, ss2 = 0, si;

  for (si = 1; si <= 100; si++) {
    ss1 += si*si;
    ss2 += si;
  }
  printf("%u\n", ss2*ss2 - ss1);
  return 0;
}