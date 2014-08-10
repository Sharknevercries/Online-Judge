/* 13930012	435	Block Voting	Accepted	C++	0.016	2014-07-23 07:19:02 */
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
#define MAX(x, y, z) {	return max(max(x,y),z);	}
#define MIN(x, y, z) {	return min(min(x,y),z);	}
const double PI = 2.0 * acos(0.0);
int power[MAX_N];
int W[MAX_N];
int half;
int main(){
	int t;
	scanf("%d", &t);
	while (t--){
		int n;
		scanf("%d", &n);
		half = 0;
		for (int i = 0; i < n; i++)
			scanf("%d", W + i), half += W[i];
		half = half / 2 + 1;
		for (int i = 0; i < n; i++){
			int DP[MAX_M] = { 0 };
			DP[0] = 1;
			for (int j = 0; j < n; j++)
				if (i != j)
					for (int k = half - 1; k >= W[j]; k--)
						DP[k] += DP[k - W[j]];
			power[i] = 0;
			for (int j = max(half - W[i], 0); j < half; j++)
				power[i] += DP[j];
			printf("party %d has power index %d\n", i + 1, power[i]);
		}
		putchar('\n');
	}
	return 0;
}
/*

Block Voting

Different types of electoral systems exist. In a block voting system the members of a party do not vote individually as they like, but instead they must collectively accept or reject a proposal. Although a party with many votes clearly has more power than a party with few votes, the votes of a small party can nevertheless be crucial when they are needed to obtain a majority. Consider for example the following five-party system:

tabular21

Coalition {A,B} has 7 + 4 = 11 votes, which is not a majority. When party C joins coalition {A,B}, however, {A,B,C} becomes a winning coalition with 7+4+2 = 13 votes. So even though C is a small party, it can play an important role.

As a measure of a party's power in a block voting system, John F. Banzhaf III proposed to use the power index. The key idea is that a party's power is determined by the number of minority coalitions that it can join and turn into a (winning) majority coalition. Note that the empty coalition is also a minority coalition and that a coalition only forms a majority when it has more than half of the total number of votes. In the example just given, a majority coalition must have at least 13 votes.

In an ideal system, a party's power index is proportional to the number of members of that party.

Your task is to write a program that, given an input as shown above, computes for each party its power index.

Input Specification

The first line contains a single integer which equals the number of test cases that follow. Each of the following lines contains one test case.

The first number on a line contains an integer P in [1  tex2html_wrap_inline36 20] which equals the number of parties for that test case. This integer is followed by P positive integers, separated by spaces. Each of these integers represents the number of members of a party in the electoral system. The i-th number represents party number i. No electoral system has more than 1000 votes.

Output Specification

For each test case, you must generate P lines of output, followed by one empty line. P is the number of parties for the test case in question. The i-th line (i in [ tex2html_wrap_inline52 ]) contains the sentence:

party i has power index I

where I is the power index of party i.

Sample Input

3
5 7 4 2 6 6
6 12 9 7 3 1 1
3 2 1 1
Sample Output

party 1 has power index 10
party 2 has power index 2
party 3 has power index 2
party 4 has power index 6
party 5 has power index 6

party 1 has power index 18
party 2 has power index 14
party 3 has power index 14
party 4 has power index 2
party 5 has power index 2
party 6 has power index 2

party 1 has power index 3
party 2 has power index 1
party 3 has power index 1

*/