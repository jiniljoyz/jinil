/*
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number?

*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  char *mm;
  size_t i;
  unsigned zcount = 0;
  size_t n = 1000000;
  const unsigned target = 10001;

  mm = calloc(n, sizeof *mm);
  for (i = 2; i < n; i++) {
    if (!mm[i]) {
      size_t j;

      zcount++;
      if (zcount == target) {
        printf("%lu\n", i);
        break;
      }
      for (j = i*2; j < n; j += i) {
        mm[j] = 1;
      }
    }
  }
  free(mm);

  return 0;
}