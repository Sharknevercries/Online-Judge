/* 14216249	1213	Sum of Different Primes	Accepted	C++	0.019	2014-09-17 05:27:37 */
/* 14166343 1195    Calling Extraterrestrial Intelligence Again Accepted    C++ 0.216   2014-09-08 08:44:24 */
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
#define MAX_N 1125
#define MAX_M 15
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
vector<int> prime;
int DP[MAX_N][MAX_M];
void make_prime(){
	prime.push_back(2);
	prime.push_back(3);
	for (int i = 5, gap = 2, j; i <= MAX_N; i += gap, gap = 6 - gap){
		for (j = 0; j < prime.size(); j++)
			if (i % prime[j] == 0)
				break;
		if (j >= prime.size())
			prime.push_back(i);
	}
}
int main(){
	make_prime();
	memset(DP, 0, sizeof(DP));
	DP[0][0] = 1;
	for (int i = 0; i < prime.size(); i++)
		for (int j = MAX_M - 1; j >= 1; j--)
			for (int p = MAX_N - 1; p >= prime[i]; p--)
				DP[p][j] += DP[p - prime[i]][j - 1];
	int n, k;
	while (scanf("%d%d", &n, &k) == 2 && n && k){
		printf("%d\n", DP[n][k]);
	}
	return 0;
}
/*

A positive integer may be expressed as a sum of different prime numbers (primes), in one way or another. Given two positive integers n and k, you should count the number of ways to express n as a sum of k different primes. Here, two ways are considered to be the same if they sum up the same set of the primes. For example, 8 can be expressed as 3 + 5 and 5 + 3 but they are not distinguished.

When n and k are 24 and 3 respectively, the answer is two because there are two sets {2, 3, 19} and {2, 5, 17} whose sums are equal to 24. There are no other sets of three primes that sum up to 24. For n = 24 and k = 2, the answer is three, because there are three sets {5, 19}, {7, 17} and {11, 13}. For n = 2 and k = 1, the answer is one, because there is only one set {2} whose sum is 2. For n = 1 and k = 1, the answer is zero. As 1 is not a prime, you shouldn't count {1}. For n = 4 and k = 2, the answer is zero, because there are no sets of two different primes whose sums are 4.

Your job is to write a program that reports the number of such ways for the given n and k.

Input 

The input is a sequence of datasets followed by a line containing two zeros separated by a space. A dataset is a line containing two positive integers n and k separated by a space. You may assume that n$ \le$1120 and k$ \le$14.

Output 

The output should be composed of lines, each corresponding to an input dataset. An output line should contain one non-negative integer indicating the number of ways for n and k specified in the corresponding dataset. You may assume that it is less than 231.

Sample Input 

24 3 
24 2 
2 1 
1 1 
4 2 
18 3 
17 1 
17 3 
17 4 
100 5 
1000 10 
1120 14 
0 0
Sample Output 

2 
3 
1 
0 
0 
2 
1 
0 
1 
55 
200102899 
2079324314

*/