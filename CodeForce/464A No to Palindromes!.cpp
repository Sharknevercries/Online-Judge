/* 7719628	2014-09-08 13:09:00	Shark	464A - No to Palindromes!	GNU C++	Accepted	78 ms	0 KB */
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
#define MAX_N 1005
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
int n, p;
char str[MAX_N];
bool check(int pos){
	if (pos == 0)return false;
	for (int i = 1; i <= pos; i++){
		bool res = true;
		for (int p = pos - i, q = pos; p < q; p++, q--){
			if (str[p] != str[q])
				res = false;
		}
		if (res)return true;
	}
	return false;
}
int main(){
	while (scanf("%d%d", &n, &p) == 2){
		bool found = false;
		scanf("%s", str);
		while (true){
			int pos = n - 1;
			for (; pos >= 0 && str[pos] >= 'a' + p - 1; pos--);
			if (pos < 0)break;
			str[pos]++;
			if (check(pos))
				continue;
			else{
				if (pos == n - 1){
					found = true;
					printf("%s\n", str);
					break;
				}
				str[pos + 1] = 'a' - 1;
			}
		}
		if (!found)
			puts("NO");
	}
	return 0;
}
/*

A. No to Palindromes!
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Paul hates palindromes. He assumes that string s is tolerable if each its character is one of the first p letters of the English alphabet and s doesn't contain any palindrome contiguous substring of length 2 or more.

Paul has found a tolerable string s of length n. Help him find the lexicographically next tolerable string of the same length or else state that such string does not exist.

Input
The first line contains two space-separated integers: n and p (1 ≤ n ≤ 1000; 1 ≤ p ≤ 26). The second line contains string s, consisting of n small English letters. It is guaranteed that the string is tolerable (according to the above definition).

Output
If the lexicographically next tolerable string of the same length exists, print it. Otherwise, print "NO" (without the quotes).

Sample test(s)
input
3 3
cba
output
NO
input
3 4
cba
output
cbd
input
4 4
abcd
output
abda
Note
String s is lexicographically larger (or simply larger) than string t with the same length, if there is number i, such that s1 = t1, ..., si = ti, si + 1 > ti + 1.

The lexicographically next tolerable string is the lexicographically minimum tolerable string which is larger than the given one.

A palindrome is a string that reads the same forward or reversed.

*/