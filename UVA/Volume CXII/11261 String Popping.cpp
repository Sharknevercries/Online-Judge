/* 14139121	1261	String Popping	Accepted	C++	0.035	2014-09-03 08:59:03 */
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
const int mx[] = { 0, 1, 0, -1 };
const int my[] = { -1, 0, 1, 0 };
// main
map< pair<int, int>, bool> DP;
bool solve(int n, int m){
	if (DP.count(make_pair(n, m)) != 0)
		return DP[make_pair(n, m)];
	else{
		bool &res = DP[make_pair(n, m)];
		for (int i = 0, j = 0; i < n; i = j){
			while (j < n && ((m >> i) & 1) == ((m >> j) & 1))
				j++;
			if (j - i >= 2 && solve(n - (j - i), m ^ (m >> i << i) ^ (m >> j << i))){
				res = true;
				break;
			}
		}
		return res;
	}
}
int main(){
	int t;
	scanf("%d", &t);
	while (t--){
		int n, m;
		DP[make_pair(0, 0)] = true;
		char S[MAX_N];
		scanf("%s", S);
		for (n = 0, m = 0; S[n] != '\0'; n++){
			m <<= 1;
			if (S[n] == 'a')
				m ^= 1;
		}
		printf("%s\n", solve(n, m) ? "1" : "0");
	}
	return 0;
}
/*

We are given a string s of two characters `a' and `b'. Let a group be a maximal consecutive substring of the same character. Any group g of s of length at least two can be removed (or popped) and a new string is constructed by concatenating the remaining left and right substrings of s. We repeat this process until either the string becomes the empty string or there is no more group of length at least two.
For example, string s = babbbaaabb has 5 groups b, a, bbb, aaa, and bb. The string s can be turned into the empty string by popping groups in the following sequence (the underlined group is to be popped in the sequence):

ba$\displaystyle \underline{{bbb}}$aaabb $\displaystyle \rightarrow$ b$\displaystyle \underline{{aaaa}}$bb $\displaystyle \rightarrow$ $\displaystyle \underline{{bbb}}$ $\displaystyle \rightarrow$ emptystring
But the group may not turn to an empty string by a different sequence of pop operations:

babbbaaa$\displaystyle \underline{{bb}}$ $\displaystyle \rightarrow$ ba$\displaystyle \underline{{bbb}}$aaa $\displaystyle \rightarrow$ b$\displaystyle \underline{{aaaa}}$ $\displaystyle \rightarrow$ b
Given a string, write a program to decide whether the string can be turned into the empty string by some sequence of popping operations.

Input

Your program is to read from standard input. The input consists of T test cases. The number of test cases T is given in the first line of the input. Each test case consists of a single line containing a string of two characters `a' and `b'. The minimum and maximum length of the string is 1 and 25, respectively.

Output

Your program is to write to standard output. Print one line for each test case. The line of each test case should contain 0 or 1. Print 1 if the input string can be turned to an empty string by a sequence of popping operations. Otherwise print 0.

The following shows sample input and output for three test cases.

Sample Input

3
babbbaaabb
aabbaabb
abab
Sample Output

1
1
0

*/