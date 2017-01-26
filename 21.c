/*
Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
If d(a) = b and d(b) = a, where a ? b, then a and b are an amicable pair and each of a and b are called amicable numbers.

For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

Evaluate the sum of all the amicable numbers under 10000.

*/


#include <stdio.h>

static int divisors_sum(int n);

int main(void)
{
  int i, d, sum = 0;

  for (i = 2; i < 10000; i++) {
    d = divisors_sum(i);
    if (i < d && i == divisors_sum(d)) {
      sum += i + d;
    }
  }
  printf("%d\n", sum);

  return 0;
}

int divisors_sum(int n)
{
  int sum= 1;
  int i, k = n;

  for (i = 2; i <= k; i++) {
    int p = 1;
    while (k % i == 0) {
      p *= i;
      k /= i;
    }
    sum *= (p*i - 1)/(i-1);
  }
  return sum - n;
}