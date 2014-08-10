/* 7248460	2014-07-26 13:06:32	Shark	451B - Sort the Array	GNU C++	Accepted	46 ms	800 KB */
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
#define MAX_N 100000
#define MAX_M 1000
#define INF 2e9
#define NONE -1
#define MAX(x, y, z) {	return max(max(x,y),z);	}
#define MIN(x, y, z) {	return min(min(x,y),z);	}
const double PI = 2.0 * acos(0.0);
int S[MAX_N], T[MAX_N];;
int main(){
	int n;
	while (scanf("%d", &n) == 1){
		bool ok = true;
		int L1, L2, R1, R2;
		for (int i = 0; i < n; i++)
			scanf("%d", S + i), T[i] = S[i];
		sort(T, T + n);
		for (L1 = 0; L1 < n && S[L1] == T[L1]; L1++);
		if (L1 >= n){ puts("yes");	puts("1 1");	continue; }
		for (R1 = L1; R1 < n && S[R1] != T[R1]; R1++);	R1--;
		for (L2 = R1 + 1; L2 < n && S[L2] == T[L2]; L2++);
		for (R2 = L2 + 1; R2 < n && S[R2] != T[R2]; R2++);	R2--;
		int L, R;
		if (R1 - L1 == R2 - L2 && R1 == L2 - 2)
			L = L1, R = R2;
		else
			L = L1, R = R1;
		for (int i = L, j = R; i <= R && ok; i++, j--)
			if (S[i] != T[j])
				ok = false;
		if (ok)
			printf("yes\n%d %d\n", L + 1, R + 1);
		else
			puts("no");
	}
	return 0;
}
/*

B. Sort the Array
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Being a programmer, you like arrays a lot. For your birthday, your friends have given you an array a consisting of n distinct integers.

Unfortunately, the size of a is too small. You want a bigger array! Your friends agree to give you a bigger array, but only if you are able to answer the following question correctly: is it possible to sort the array a (in increasing order) by reversing exactly one segment of a? See definitions of segment and reversing in the notes.

Input
The first line of the input contains an integer n (1 ≤ n ≤ 105) — the size of array a.

The second line contains n distinct space-separated integers: a[1], a[2], ..., a[n] (1 ≤ a[i] ≤ 109).

Output
Print "yes" or "no" (without quotes), depending on the answer.

If your answer is "yes", then also print two space-separated integers denoting start and end (start must not be greater than end) indices of the segment to be reversed. If there are multiple ways of selecting these indices, print any of them.

Sample test(s)
input
3
3 2 1
output
yes
1 3
input
4
2 1 3 4
output
yes
1 2
input
4
3 1 2 4
output
no
input
2
1 2
output
yes
1 1
Note
Sample 1. You can reverse the entire array to get [1, 2, 3], which is sorted.

Sample 3. No segment can be reversed such that the array will be sorted.

Definitions

A segment [l, r] of array a is the sequence a[l], a[l + 1], ..., a[r].

If you have an array a of size n and you reverse its segment [l, r], the array will become:

a[1], a[2], ..., a[l - 2], a[l - 1], a[r], a[r - 1], ..., a[l + 1], a[l], a[r + 1], a[r + 2], ..., a[n - 1], a[n].

*/