/* 14162603	957	Popes	Accepted	C++	0.032	2014-09-07 12:23:50 */
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
#define MAX_N 100005
#define MAX_M 1000
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
int S[MAX_N];
int main(){
	int n, k;
	while (scanf("%d%d", &k, &n) == 2){
		for (int i = 0; i < n; i++)
			scanf("%d", S + i);
		queue<int> Q;
		int maxCount = 0, L, R;
		for (int i = 0; i < n; i++){
			while (!Q.empty() && S[i] - Q.front() + 1 > k)
				Q.pop();
			Q.push(S[i]);
			if (Q.size() > maxCount)
				maxCount = Q.size(), L = Q.front(), R = S[i];
		}
		printf("%d %d %d\n", maxCount, L, R);
	}
	return 0;
}
/*

On the occasion of Pope John Paul II death, the American weekly magazine Time observed the largest
number of Popes to be selected in a 100-year period was 28, from 867 (Adrian II) to 965 (John XIII).
This is a very interesting piece of trivia, but it would be much better to have a program to compute
that number for a period of any length, not necessarily 100 years. Furthermore, the Catholic Church
being an eternal institution, as far as we can predict it, we want to make sure that our program will
remain valid per omnia secula seculorum.
Write a program that given the list of years in which each Pope was elected and a positive number
Y , computes the largest number of Popes that were in office in a Y -year period, and the year of election
for the first and last Popes in that period. Note that, given a year N, the Y -year period that starts in
year N is the time interval from the first day of year N to the last day of year N + Y − 1. In case of a
tie, i.e., if there is more that one Y -year period with the same largest number of Popes, your program
should report only the most ancient one.
Input
The input will contain several test cases, each of them as described below. Consecutive
test cases are separated by a single blank line.
The first line of the input contains a positive integer Y , the number of years of the period we are
interested in. The second line contains another positive integer, the number of Popes, P. Each of
the remaining P lines contains the year of election of a Pope, in chronological order. We know that
P ≤ 5000 and also that the last year L in the file is such L ≤ 1000000, and that Y ≤ L.
Output
For each test case, write to the output contains a single line with three integers, separated by spaces:
the largest number of Popes in a Y -year period, the year of election of the first Pope in that period
and the year of election of the last Pope in the period.
Sample Input
5
20
1
2
3
6
8
12
13
13
15
16
17
18
19
20
20
21
25
26
30
31
Sample Output
6 16 20

*/