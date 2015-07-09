/* 13897148	10465	Homer Simpson	Accepted	C++	0.202	2014-07-17 11:40:12 */
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
#define MAX_N 10001
#define MAX_M 1000
#define INF 2e9
#define NONE -1
#define MAX(x, y, z) {	return max(max(x,y),z);	}
#define MIN(x, y, z) {	return min(min(x,y),z);	}
const double PI = 2.0 * acos(0.0);
int main(){
	int m, n, t;
	while (scanf("%d%d%d", &m, &n, &t) == 3){
		int DP[MAX_N] = { 0 };
		bool OK[MAX_N] = { false };
		OK[0] = true;
		for (int i = m; i <= t; i++)
			if (OK[i - m])
				DP[i] = max(DP[i], DP[i - m] + 1), OK[i] = true;
		for (int i = n; i <= t; i++)
			if (OK[i - n])
				DP[i] = max(DP[i], DP[i - n] + 1), OK[i] = true;
		int pos;
		for (pos = t; pos >= 0; pos--)
			if (DP[pos] > 0)
				break;
		if (pos == t)
			printf("%d\n", DP[pos]);
		else if (pos == -1)
			printf("%d %d\n", 0, t);
		else
			printf("%d %d\n", DP[pos], t - pos);
	}
	return 0;
}
/*

Return of the Aztecs

Problem C:	Homer Simpson

Time Limit: 3 seconds
Memory Limit: 32 MB
Homer Simpson, a very smart guy, likes eating Krusty-burgers. It takes Homer m minutes to eat a Krusty- burger. However, there�s a new type of burger in Apu�s Kwik-e-Mart. Homer likes those too. It takes him n minutes to eat one of these burgers. Given t minutes, you have to find out the maximum number of burgers Homer can eat without wasting any time. If he must waste time, he can have beer.
Input

Input consists of several test cases. Each test case consists of three integers m, n, t (0 < m,n,t < 10000). Input is terminated by EOF.

Output

For each test case, print in a single line the maximum number of burgers Homer can eat without having beer. If homer must have beer, then also print the time he gets for drinking, separated by a single space. It is preferable that Homer drinks as little beer as possible.

Sample Input

3 5 54
3 5 55
Sample Output

18
17
Problem setter: Sadrul Habib Chowdhury
Solution author: Monirul Hasan (Tomal)

Time goes, you say? Ah no!
Alas, Time stays, we go.
-- Austin Dobson

*/