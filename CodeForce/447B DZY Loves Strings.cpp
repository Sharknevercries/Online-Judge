/* 7076588	 2014-07-13 17:12:06	Shark	 447B - DZY Loves Strings	 GNU C++	Accepted	 31 ms	 0 KB */
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
	char str[1001];
	while (scanf("%s", str) == 1){
		int k, V[26], m = 0;
		lli ans = 0;
		scanf("%d", &k);
		for (int i = 0; i < 26; i++)
			scanf("%d", V + i);
		for (int i = 0; i < 26; i++)
			m = max(V[i], m);
		for (int i = 0; str[i] != '\0'; i++)
			ans += V[(str[i] - 'a')] * (i + 1);
		ans += (long long int)(k + strlen(str) * 2 + 1)*k *m / 2;
		printf("%lld\n", ans);
	}
	return 0;
}
/*

B. DZY Loves Strings
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
DZY loves collecting special strings which only contain lowercase letters. For each lowercase letter c DZY knows its value wc. For each special string s = s1s2... s|s| (|s| is the length of the string) he represents its value with a function f(s), where

Now DZY has a string s. He wants to insert k lowercase letters into this string in order to get the largest possible value of the resulting string. Can you help him calculate the largest possible value he could get?

Input
The first line contains a single string s (1 ≤ |s| ≤ 103).

The second line contains a single integer k (0 ≤ k ≤ 103).

The third line contains twenty-six integers from wa to wz. Each such number is non-negative and doesn't exceed 1000.

Output
Print a single integer — the largest possible value of the resulting string DZY could get.

Sample test(s)
input
abc
3
1 2 2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
output
41
Note
In the test sample DZY can obtain "abcbbc", value = 1·1 + 2·2 + 3·2 + 4·2 + 5·2 + 6·2 = 41.

*/