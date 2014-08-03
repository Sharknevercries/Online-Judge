/* 7091124	 2014-07-13 19:48:39	Shark	 446A - DZY Loves Sequences	 GNU C++	Accepted	 93 ms	 400 KB */
/*

Template By Shark

*/
// C++
#include<iostream>
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
// const variable
#define MAX_N 1000
#define MAX_M 1000
#define INF 2e9
#define NONE -1
const double PI = 2.0 * acos(0.0);
int main(){
	int n;
	while (scanf("%d", &n) == 1){
		int S[100005] = { 0 };
		int prev = 0, cur = 0, ans = 1, pos = -1;
		for (int i = 1; i <= n; i++)
			scanf("%d", S + i);

		S[0] = S[n + 1] = 0;
		for (int i = 1; i <= n + 1; i++){
			if (S[i] > S[i - 1])	cur++;
			else{
				ans = max(ans, cur);
				if (i <= n)
					ans = max(cur + 1, ans);
				if (pos != -1 && pos + 1 <= n && S[pos - 1] + 1 < S[pos + 1])
					ans = max(ans, cur + prev);
				prev = cur;
				cur = 1;
				pos = i;
			}
		}
		cur = 0, pos = -1, prev = 0;

		S[n + 1] = S[0] = 2e9;
		for (int i = n; i >= 0; i--){
			if (S[i] < S[i + 1])	cur++;
			else{
				ans = max(ans, cur);
				if (i >= 1)
					ans = max(cur + 1, ans);
				if (pos != -1 && pos - 1 >= 1 && S[pos - 1] + 1 < S[pos + 1])
					ans = max(ans, cur + prev);
				prev = cur;
				cur = 1;
				pos = i;
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}
/*

A. DZY Loves Sequences
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
DZY has a sequence a, consisting of n integers.

We'll call a sequence ai, ai + 1, ..., aj (1 ≤ i ≤ j ≤ n) a subsegment of the sequence a. The value (j - i + 1) denotes the length of the subsegment.

Your task is to find the longest subsegment of a, such that it is possible to change at most one number (change one number to any integer you want) from the subsegment to make the subsegment strictly increasing.

You only need to output the length of the subsegment you find.

Input
The first line contains integer n (1 ≤ n ≤ 105). The next line contains n integers a1, a2, ..., an (1 ≤ ai ≤ 109).

Output
In a single line print the answer to the problem — the maximum length of the required subsegment.

Sample test(s)
input
6
7 2 3 1 5 6
output
5
Note
You can choose subsegment a2, a3, a4, a5, a6 and change its 3rd element (that is a4) to 4.

*/