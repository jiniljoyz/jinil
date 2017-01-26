/*The Fibonacci sequence is defined by the recurrence relation:

Fn = Fn-1 + Fn-2, where F1 = 1 and F2 = 1.
Hence the first 12 terms will be:

F1 = 1
F2 = 1
F3 = 2
F4 = 3
F5 = 5
F6 = 8
F7 = 13
F8 = 21
F9 = 34
F10 = 55
F11 = 89
F12 = 144
The 12th term, F12, is the first term to contain three digits.

What is the index of the first term in the Fibonacci sequence to contain 1000 digits?
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gmp.h>

int main(void)
{
  mpz_t n;
  int i = 1;

  mpz_init(n);

  for (i = 1;; i++) {
    char *str;
    size_t len;

    mpz_fib_ui(n, i);
    str = mpz_get_str(NULL, 10, n);
    len = strlen(str);
    free(str);
    if (len == 1000) {
      printf("%d\n", i);
      break;
    }
  }

  mpz_clear(n);

  return 0;
}