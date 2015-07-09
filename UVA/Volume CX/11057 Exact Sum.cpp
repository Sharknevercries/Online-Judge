/* 14002477	11057	Exact Sum	Accepted	C++	0.042	2014-08-07 08:09:07 */
/* Template By Shark */
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
#define MAX_N 10000
#define MAX_M 1000
#define INF 2e9
#define NONE -1
#define MAX(x, y, z) {	return max(max(x,y),z);	}
#define MIN(x, y, z) {	return min(min(x,y),z);	}
const double PI = 2.0 * acos(0.0);
// main
int main(){
	int n;
	while (scanf("%d", &n) == 1){
		int S[MAX_N];
		int sum, minGap = INF, a, b;
		for (int i = 0; i < n; i++)
			scanf("%d", S + i);
		scanf("%d", &sum);
		sort(S, S + n);
		for (int i = 0, j = n - 1; i < j;){
			if (S[i] + S[j] == sum){
				if (S[j] - S[i] < minGap)
					minGap = S[j] - S[i], a = S[i], b = S[j];
				if (i < j - 1 && S[j] == S[j - 1])
					j--;
				else if (i + 1 < j && S[i] == S[i + 1])
					i++;
				else
					i++, j--;
			}
			else if (S[i] + S[j]> sum)
				j--;
			else
				i++;
		}
		printf("Peter should buy books whose prices are %d and %d.\n\n", a, b);
	}
	return 0;
}
/*

Problem B - Exact Sum

Time Limit: 1 second

Peter received money from his parents this week and wants to spend it all buying books. But he does not read a book so fast, because he likes to enjoy every single word while he is reading. In this way, it takes him a week to finish a book.

As Peter receives money every two weeks, he decided to buy two books, then he can read them until receive more money. As he wishes to spend all the money, he should choose two books whose prices summed up are equal to the money that he has. It is a little bit difficult to find these books, so Peter asks your help to find them.

Input

Each test case starts with 2 ≤ N ≤ 10000, the number of available books. Next line will have N integers, representing the price of each book, a book costs less than 1000001. Then there is another line with an integer M, representing how much money Peter has. There is a blank line after each test case. The input is terminated by end of file (EOF).

Output

For each test case you must print the message: Peter should buy books whose prices are i and j., where i and j are the prices of the books whose sum is equal do M and i ≤ j. You can consider that is always possible to find a solution, if there are multiple solutions print the solution that minimizes the difference between the prices i and j. After each test case you must print a blank line.

Sample Input

2
40 40
80

5
10 2 6 8 4
10
Sample Output

Peter should buy books whose prices are 40 and 40.

Peter should buy books whose prices are 4 and 6.

Problem setter: Sérgio Queiroz de Medeiros

*/