/*
A Pythagorean triplet is a set of three natural numbers, a < b < c, for which, a2 + b2 = c2

For example, 32 + 42 = 9 + 16 = 25 = 52.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.

Find the product abc.

*/
#include <stdio.h>

int main(void)
{
  int az, bz;

  for (az = 1; az <= 333; az++) {
    for (bz = az; bz <= 666; bz++) {
      int cz = (1000 - az - bz);
      if (az*az + bz*bz == cz*cz) {
        printf("%d\n", az * bz * cz);
      }
    }
  }
  return 0;
}