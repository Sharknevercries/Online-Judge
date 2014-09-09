/* 7666367	2014-09-02 12:57:18	Shark	461A - Appleman and Toastman	GNU C++	Accepted	62 ms	1300 KB */
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
#define MAX_N 300005
#define MAX_M 1000
#define INF 1e9
#define NONE -1
#define EPS 1e-6
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3
const double PI = 2.0 * acos(0.0);
const int mx[] = { 0, 1, 0, -1 };
const int my[] = { -1, 0, 1, 0 };
// main
int S[MAX_N];
int main(){
	int n;
	lli ans = 0, sum = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", S + i);
	sort(S, S + n);
	for (int i = 0; i < n; i++)
		sum += S[i];
	for (int i = 0; i < n; i++){
		ans += sum;
		sum -= S[i];
		ans += S[i];
	}
	ans -= S[n - 1];
	printf("%lld\n", ans);
	return 0;
}
/*

A. Appleman and Toastman
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Appleman and Toastman play a game. Initially Appleman gives one group of n numbers to the Toastman, then they start to complete the following tasks:

Each time Toastman gets a group of numbers, he sums up all the numbers and adds this sum to the score. Then he gives the group to the Appleman.
Each time Appleman gets a group consisting of a single number, he throws this group out. Each time Appleman gets a group consisting of more than one number, he splits the group into two non-empty groups (he can do it in any way) and gives each of them to Toastman.
After guys complete all the tasks they look at the score value. What is the maximum possible value of score they can get?

Input
The first line contains a single integer n (1 ≤ n ≤ 3·105). The second line contains n integers a1, a2, ..., an (1 ≤ ai ≤ 106) — the initial group that is given to Toastman.

Output
Print a single integer — the largest possible score.

Sample test(s)
input
3
3 1 5
output
26
input
1
10
output
10
Note
Consider the following situation in the first example. Initially Toastman gets group [3, 1, 5] and adds 9 to the score, then he give the group to Appleman. Appleman splits group [3, 1, 5] into two groups: [3, 5] and [1]. Both of them should be given to Toastman. When Toastman receives group [1], he adds 1 to score and gives the group to Appleman (he will throw it out). When Toastman receives group [3, 5], he adds 8 to the score and gives the group to Appleman. Appleman splits [3, 5] in the only possible way: [5] and [3]. Then he gives both groups to Toastman. When Toastman receives [5], he adds 5 to the score and gives the group to Appleman (he will throws it out). When Toastman receives [3], he adds 3 to the score and gives the group to Appleman (he will throws it out). Finally Toastman have added 9 + 1 + 8 + 5 + 3 = 26 to the score. This is the optimal sequence of actions.

*/