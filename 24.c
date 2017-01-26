/*
A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4. If all of the permutations are listed numerically or alphabetically, we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:

012   021   102   120   201   210

What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
*/


#include <iostream>
#include <algorithm>

#define N 1000000

int main(void)
{
  using namespace std;

  int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int i;

  for (i = 0; i <= N; i++) {
    next_permutation(a, a + sizeof a/sizeof *a);
  }
  for (i = 0; i < 10; i++) {
    cout << a[i];
  }
  cout << endl;

  return 0;
}