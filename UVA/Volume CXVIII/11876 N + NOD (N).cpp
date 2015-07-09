/* 14162675	11876	N + NOD (N)	Accepted	C++	0.265	2014-09-07 12:52:06 */
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
vector<int> S;
void build(){
	S.push_back(1);
	while (S.back() <= 1000000){
		int res = 1, i, j, k;
		for (i = S.back(), j = 2, k = 0; j <= sqrt((double)i); j++, k = 0){
			while (i % j == 0)
				i /= j, k++;
			res *= (k + 1);
		}
		if (i > 1)
			res *= 2;
		S.push_back(res + S.back());
	}
}
int main(){
	build();
	int t, c = 1;
	scanf("%d", &t);
	while (t--){
		int L, R;
		scanf("%d%d", &L, &R);
		int RL = lower_bound(S.begin(), S.end(), L) - S.begin(), RR = upper_bound(S.begin(), S.end(), R) - S.begin();
		printf("Case %d: %d\n", c++, RR - RL);
	}
	return 0;
}
/*

I
N + NOD (N)
Input
Standard Input
Output
Standard Output

Consider an integer sequence N where,
N0 = 1
Ni = Ni-1 + NOD(Ni-1)- for i > 0
Here, NOD(x) = number of divisors of x.
So the first few terms of this sequence are 1 2 4 7 9 12 18…
Given two integers A and B, find out the number of integers in the above sequence that lies within the range [A, B].
Input
The first line of input is an integer T (T < 100000), that indicates the number of test cases. Each case contains two integers, A followed by B (1 ≤ A ≤ B ≤ 1000000).
Output
For each case, output the case number first followed by the required result.

Sample Input
Sample Output
3
1 18
1 100
3000 4000
Case 1: 7
Case 2: 20
Case 3: 87
Problemsetter: Sohel Hafiz, Special Thanks: Shamim Hafiz

*/