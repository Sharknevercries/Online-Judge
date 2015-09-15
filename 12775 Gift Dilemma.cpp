/* 15850233	12775	Gift Dilemma	Accepted	C++	0.434	2015-07-30 13:01:35 */
#include<bits\stdc++.h>
using namespace std;
// ax + by = g
// x = x0 + t * dx, dx = b / gcd(a, b)
// y = y0 + t * dy, dx = a / gcd(a, b)
void exgcd(long long x, long long y, long long &g, long long &a, long long &b) { 
  if (y == 0)
    g = x, a = 1, b = 0;
  else
    exgcd(y, x%y, g, b, a), b -= (x / y)*a;
}
// ax + by = c
long long calculate(long long a, long long b, long long c) {
  long long x, y, g, dx, dy, k;
  exgcd(a, b, g, x, y);
  if (c % g != 0)  return 0;
  x *= c / g, y *= c / g;
  dx = b / g, dy = a / g;
  if (x < 0) {
    k = -(x / dx) + (x%dx != 0);
    x += k*dx, y -= k*dy;
  }
  if (y < 0) {
    k = -(y / dy) + (y%dy != 0);
    x -= k*dx, y += k*dy;
  }
  if (x < 0 || y < 0)  return 0;
  long long xl, xr, yl, yr;
  k = x / dx;
  x -= k * dx;
  y += k * dy;
  xl = x, yr = y;
  k = y / dy;
  x += k*dx;
  y -= k*dy;
  xr = x, yl = y;
  return (xr - xl) / dx + 1;
}
int main() {
  int t, ca = 1;
  scanf("%d", &t);
  while (t--) {
    long long a, b, c, p, g, ta, tb, res;
    scanf("%lld%lld%lld%lld", &a, &b, &c, &p);
    exgcd(a, b, g, ta, tb);
    exgcd(g, c, g, ta, tb);
    a /= g, b /= g, c /= g, p /= g;
    res = 0;
    for (int i = 0; p - i*c >= 0; i++)
      res += calculate(a, b, p - i*c);
    printf("Case %d: %lld\n", ca++, res);
  }
  return 0;
}
/*

You all know Dr. Sheldon Cooper. Everything Sheldon gets, he must give back the same. He doesn・t
want to be in someone・s debt.
Another friend of Sheldon, Penny has given him a very precious gift for his birthday. What penny
didn・t know, now Sheldon is going over his head to find out some gifts that will exactly match the price
of Penny・s gift. So my first task was to find out the price of the gift. With my super powerful sixth
sense I found out that the price was P.
Now comes the hardest part. Sheldon needs to buy a gift which will cost exactly P. He went
to the nearby shop for this. It is a crazy shop. Because it sells only three types of things: Rubik・s
cubes, mouth organs and chocolates. The prices of them are A, B, C accordingly. Now Sheldon faces
a dilemma. What to buy and how many to buy? Because it turns out he can buy things costing P in
various ways. For example if, A = 202, B = 203, C = 200 and P = 606, then are two different way
to buy gifts costing exactly P. The first way is buying no Rubik・s cubes, two mouth organs and one
chocolate. The second way is buying three Rubik・s cubes, no mouth organs and no chocolates.
Now Sheldon is asking for your help (because I am retired from contests). Given A, B, C and P,
you need to find out in how many ways he can buy gifts costing exactly P.
Input
The first line will contain T (T ? 100), the number of test cases. Next T lines each will have four
integers, A, B, C and P (0 < A, B, C, P ? 100000000) and C/ gcd(A, B, C) ? 200, where gcd(A, B, C)
means the greatest common divisor of A, B and C.
Output
For each case print ．Case C: W・ (without the quotes), where C is the case number and W is the
number of ways Sheldon can buy gifts.
Sample Input
1
202 203 200 606
Sample Output
Case 1: 2

*/