/* 4031266	2015-08-03 16:22:33	Accepted	2344	C++	20	2244	840502 */
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
Bigint powerOfTwo[500];
Bigint ans; 
int n, m;
int p[5][500];
int getLoop(int la) {
  bool V[500] = { false };
  int res = 0;
  for (int i = 0; i < n*m; i++) {
    if (!V[i]) res++;
    V[i] = true;
    for (int j = p[la][i]; !V[j]; j = p[la][j])
      V[j] = true;
  }
  return res;
}
void solve() {
  int div = 0;
  ans = Bigint();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < n*m; k++) {
        int x = (k%n + i) % n, y = (k / n + j) % m;
        p[0][k] = y*n + x; // 0 degree
        p[1][k] = (m - 1 - y)*n + (n - 1 - x); // 180 degree
        if (n == m) {
          p[2][k] = (m - 1 - x)*n + y; // 90 degree
          p[3][k] = x*n + (n - 1 - y); // 270 degree
        }
      }
      div += 2;
      ans = ans + powerOfTwo[getLoop(0)];
      ans = ans + powerOfTwo[getLoop(1)];
      if (n == m) {
        div += 2;
        ans = ans + powerOfTwo[getLoop(2)];
        ans = ans + powerOfTwo[getLoop(3)];
      }
    }
  }
  ans = ans / div;
  ans.print();
  putchar('\n');
}
int main() {
  powerOfTwo[0] = Bigint(1);
  for (int i = 1; i <= 400; i++)
    powerOfTwo[i] = powerOfTwo[i - 1] * 2;
  while (scanf("%d%d", &n, &m) == 2) {
    if (n < m) swap(n, m);
    solve();
  }
  return 0;
}
/*

Toral Tickets
Time Limit: 5 Seconds      Memory Limit: 32768 KB
On the planet Eisiem passenger tickets for the new mean of transportation are planned to have the form of tores.

Each tore is made of a single rectangular black rubber sheet containing N * M squares. Several squares are marked with white, thus encoding the ticket??s source and destination.

When the passenger buys the ticket, the ticket booking machine takes the rubber sheet, marks some squares to identify the route of the passenger, and then provides it to the passenger. The passenger next must glue the ticket.

The ticket must be clued the following way. First two its sides of greater length are glued together, forming a cylinder. Next cylinder base circles, each of which has the length equal to the length of the short side of the original rubber sheet, are glued together. They must be glued in such a way, that the cells, sides of which are glued, first belonged to the same row of the sheet.

The resulting tore is the valid ticket.

Note that if the original sheet is square, there are two topologically different ways to make a tore out of a rubber sheet.

Ticket material is so perfect and gluing quality is so fine, that no one is able to find the seam, and this leads to some problems. First, the same tore can be obtained using different sheets. More of that, the same sheet can lead to tores that look a bit different.

Now the transport companies of Eisiem wonder, how many different routes they can organize, so that the following conditions are satisfied:

tickets for different routes are represented by different tores;
if some rubber sheet was marked to make the tore for some route, it cannot be used to make the tore for another route.
Help them to calculate the number of routes they can organize.

Input

Each line of the input file contains N and M (1 <= N,M <= 20).

Output

For each case, output the number of routes Eisiem transport companies can organize.

Sample Input

2 2
2 3

Sample Output

6
13

Author: Andrew Stankevich
Source: Andrew Stankevich's Contest #2

*/