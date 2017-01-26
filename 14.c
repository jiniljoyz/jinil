/*
The following iterative sequence is defined for the set of positive integers:

n ? n/2 (n is even)
n ? 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:

13 ? 40 ? 20 ? 10 ? 5 ? 16 ? 8 ? 4 ? 2 ? 1
It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?
*/

#include <stdio.h>

static unsigned collatz_count(unsigned n);

int main(void)
{
  unsigned i, max_c = 0, max_i = 0;

  for (i = 1; i < 1000000; i++) {
    unsigned c = collatz_count(i);
    if (c > max_c) {
      max_c = c;
      max_i = i;
    }
  }
  printf("%u\n", max_i);
  return 0;
}

unsigned collatz_count(unsigned n)
{
  unsigned c = 0;
  while (n > 1) {
    n = n%2==0 ? n/2 : 3*n+1;
    c++;
  }
  return c+1;
}