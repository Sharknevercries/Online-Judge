/* 14528649	840502	2084	Accepted	944K	16MS	C++	3444B	2015-08-02 19:15:08 */
#include<bits\stdc++.h>
using namespace std;
const int bL = 1000;
const int bM = 10000;
struct Bigint {
  int v[bL], l, s;
  Bigint() : l(0), s(1) { memset(v, 0, sizeof(v)); }
  void n() { for (; l; l--) if (v[l - 1]) return; }
  Bigint(long long a) {
    s = 1;
    if (a < 0) { s = -1; a = -a; }
    for (l = 0; a; v[l++] = a%bM, a /= bM);
  }
  Bigint(const char *a) {
    l = 0; s = 1;
    int t = 0, i = strlen(a), q = 1;
    int ls = 0;
    if (a[0] == '-') { ls = 1; s = -1; }
    while (i > ls) {
      t += (a[--i] - '0')*q;
      if ((q *= 10) >= bM) {
        v[l++] = t; t = 0; q = 1;
      }
    }
    if (t) v[l++] = t;
  }
  void print() const {
    if (l == 0) { putchar('0'); return; }
    if (s == -1) putchar('-');
    printf("%d", v[l - 1]);
    for (int i = l - 2; i >= 0; i--)
      printf("%.4d", v[i]);
  }
  int cp3(const Bigint &b)const {
    if (l != b.l) return l > b.l ? 1 : -1;
    for (int i = l - 1; i >= 0; i--)
      if (v[i] != b.v[i])
        return v[i] > b.v[i] ? 1 : -1;
    return 0;
  }
  bool operator < (const Bigint &b)const {
    return cp3(b) == -1;
  }
  bool operator == (const Bigint &b)const {
    return cp3(b) == 0;
  }
  bool operator > (const Bigint &b)const {
    return cp3(b) == 1;
  }
  Bigint operator - () const {
    Bigint r = (*this);
    r.s = -r.s;
    return r;
  }
  Bigint operator + (const Bigint &b) const {
    if (s == -1) return -(-(*this) + (-b));
    if (b.s == -1) return (*this) - (-b);
    Bigint r;
    r.l = max(l, b.l);
    for (int i = 0; i < r.l; i++) {
      r.v[i] += v[i] + b.v[i];
      if (r.v[i] >= bM) {
        r.v[i + 1] += r.v[i] / bM;
        r.v[i] %= bM;
      }
    }
    if (r.v[r.l]) r.l++;
    return r;
  }
  Bigint operator - (const Bigint &b) const {
    if (s == -1) return -(-(*this) - (-b));
    if (b.s == -1) return (*this) + (-b);
    if ((*this) < b) return -(b - (*this));
    Bigint r;
    r.l = l;
    for (int i = 0; i < l; i++) {
      r.v[i] += v[i];
      if (i < b.l) r.v[i] -= b.v[i];
      if (r.v[i] < 0) {
        r.v[i] += bM;
        r.v[i + 1]--;
      }
    }
    r.n();
    return r;
  }
  Bigint operator * (const Bigint &b) {
    Bigint r;
    r.l = l + b.l;
    r.s = s * b.s;
    for (int i = 0; i < l; i++) {
      for (int j = 0; j < b.l; j++) {
        r.v[i + j] += v[i] * b.v[j];
        if (r.v[i + j] >= bM) {
          r.v[i + j + 1] += r.v[i + j] / bM;
          r.v[i + j] %= bM;
        }
      }
    }
    r.n();
    return r;
  }
  Bigint operator / (const Bigint &b) {
    Bigint r;
    r.l = max(1, l - b.l + 1);
    r.s = s * b.s;
    for (int i = r.l - 1; i >= 0; i--) {
      int d = 0, u = bM - 1, m;
      while (d < u) {
        m = (d + u + 1) >> 1;
        r.v[i] = m;
        if ((r*b) >(*this)) u = m - 1;
        else d = m;
      }
      r.v[i] = d;
    }
    r.n();
    return r;
  }
  Bigint operator % (const Bigint &b) {
    return (*this) - (*this) / b*b;
  }
};
Bigint catalan[200];
int main() {
  catalan[0] = Bigint(1);
  for (int i = 0; i <= 105; i++)
    catalan[i + 1] = (catalan[i] * (4 * i + 2)) / (i + 2);
  int n;
  while (scanf("%d", &n) == 1) {
    if (n < 0) break;
    catalan[n].print();
    putchar('\n');
  }
  return 0;
}
/*

Game of Connections
Time Limit: 1000MS		Memory Limit: 30000K
Total Submissions: 7818		Accepted: 3928
Description

This is a small but ancient game. You are supposed to write down the numbers 1, 2, 3, . . . , 2n - 1, 2n consecutively in clockwise order on the ground to form a circle, and then, to draw some straight line segments to connect them into number pairs. Every number must be connected to exactly one another.
And, no two segments are allowed to intersect.
It's still a simple game, isn't it? But after you've written down the 2n numbers, can you tell me in how many different ways can you connect the numbers into pairs? Life is harder, right?
Input

Each line of the input file will be a single positive number n, except the last line, which is a number -1.
You may assume that 1 <= n <= 100.
Output

For each n, print in a single line the number of ways to connect the 2n numbers into pairs.
Sample Input

2
3
-1
Sample Output

2
5
Source

Shanghai 2004 Preliminary

*/