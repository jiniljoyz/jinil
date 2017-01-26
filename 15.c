/*
Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.

How many such routes are there through a 20×20 grid?
*/
#include <stdio.h>
#include <gmp.h>

int main(void)
{
  mpz_t n, m;

  /* calculate 40C20 as 40! / (20! * 20!) */
  mpz_init(n); mpz_init(m);
  mpz_fac_ui(n, 40); mpz_fac_ui(m, 20);
  mpz_mul(m, m, m);
  mpz_divexact(n, n, m);

  mpz_out_str(stdout, 10, n);
  putchar('\n');

  mpz_clear(n);
  mpz_clear(m);

  return 0;
}