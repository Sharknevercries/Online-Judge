/* 7997177	2014-09-28 19:40:12	Shark	472A - Design Tutorial: Learn from Math	GNU C++	Accepted	31 ms	0 KB */
// C++
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<bitset>
#include<algorithm>
#include<functional>
#include<deque>
// C
#include<cstdio>
#include<cstring>
#include<ctime>
#include<cctype>
#include<cmath>
// namespace
using namespace std;
// typedef
typedef long long lli;
typedef unsigned long long ull;
// template
template<class T> T max(T a, T b, T c){ return max(a, max(b, c)); }
template<class T> T min(T a, T b, T c){ return min(a, min(b, c)); }
// const variable
#define MAX_N 1000
#define MAX_M 1000
#define MOD 1000000007
#define INF 1e9
#define NONE -1
#define EPS 1e-6
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3
const double PI = 2.0 * acos(0.0);
const int mx[] = { 0, 1, 0, -1, 1, -1, 1, -1 };
const int my[] = { -1, 0, 1, 0, 1, -1, -1, 1 };
// main
bool check(int s){
	for (int i = 2; i <= sqrt((double)s); i++)
		if (s % i == 0)
			return true;
	return false;
}
int main(){
	int n;
	scanf("%d", &n);
	for (int i = 4; i <= n; i += 2){
		if (check(n - i)){
			printf("%d %d\n", i, n - i);
			break;
		}
	}
	return 0;
}
/*

A. Design Tutorial: Learn from Math
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
One way to create a task is to learn from math. You can generate some random math statement or modify some theorems to get something new and build a new task from that.

For example, there is a statement called the "Goldbach's conjecture". It says: "each even number no less than four can be expressed as the sum of two primes". Let's modify it. How about a statement like that: "each integer no less than 12 can be expressed as the sum of two composite numbers." Not like the Goldbach's conjecture, I can prove this theorem.

You are given an integer n no less than 12, express it as a sum of two composite numbers.

Input
The only line contains an integer n (12 ≤ n ≤ 106).

Output
Output two composite integers x and y (1 < x, y < n) such that x + y = n. If there are multiple solutions, you can output any of them.

Sample test(s)
input
12
output
4 8
input
15
output
6 9
input
23
output
8 15
input
1000000
output
500000 500000
Note
In the first example, 12 = 4 + 8 and both 4, 8 are composite numbers. You can output "6 6" or "8 4" as well.

In the second example, 15 = 6 + 9. Note that you can't output "1 14" because 1 is not a composite number.

*/