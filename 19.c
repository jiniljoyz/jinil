/*
You are given the following information, but you may prefer to do some research for yourself.

1 Jan 1900 was a Monday.
Thirty days has September,
April, June and November.
All the rest have thirty-one,
Saving February alone,
Which has twenty-eight, rain or shine.
And on leap years, twenty-nine.
A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
*/


#include <stdio.h>

static int days(int y, int m);

int main(void)
{
  int year, wday = 0, sun = 0, mon;

  for (year = 1901; year <= 2000; year++) {
    for (mon = 1; mon <= 12; mon++) {
      if (wday == 5) {
        /* 1901-01-01 is Tuesday, so wday == 5 means Sunday */
        sun++;
      }
      wday = (wday + days(year, mon))%7;
    }
  }
  printf("%d\n", sun);

  return 0;
}

int days(int y, int m)
{
  switch (m) {
    case 2:
      if ((y%4 == 0 && y%100 != 0) || y%400 == 0) {
        /* leap year */
        return 29;
      }
      else {
        return 28;
      }
      
    case 4:
    case 6:
    case 9:
    case 11:
      return 30;

    default:
      return 31;
  }
}