/*
n! means n × (n - 1) × ... × 3 × 2 × 1

For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

Find the sum of the digits in the number 100!
*/

#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

int main(void)
{
  mpz_t n;
  char *str;
  int i;
  int sum = 0;

  mpz_init(n);
  mpz_fac_ui(n, 100);
  str = mpz_get_str(NULL, 10, n);
  for (i = 0; str[i]; i++) {
    sum += str[i]-'0';
  }
  printf("%d\n", sum);

  free(str);
  mpz_clear(n);

  return 0;
}
