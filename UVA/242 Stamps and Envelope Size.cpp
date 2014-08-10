/* 13920824	242	Stamps and Envelope Size	Accepted	C++	0.059	2014-07-21 15:38:41 */
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
#define MAX_N 11
#define MAX_M 1005
#define INF 2e9
#define NONE -1
#define MAX(x, y, z) {	return max(max(x,y),z);	}
#define MIN(x, y, z) {	return min(min(x,y),z);	}
const double PI = 2.0 * acos(0.0);
int C[MAX_M];
vector<int> stamp;
int maxCoverage;
int main(){
	int s;
	while (scanf("%d", &s) == 1 && s){
		int n;
		scanf("%d", &n);
		maxCoverage = -1;
		stamp.clear();
		for (int i = 0; i < n; i++){
			for (int j = 0; j < MAX_M; j++)
				C[j] = INF;
			C[0] = 0;
			int m, W[100], coverage;
			scanf("%d", &m);
			for (int j = 0; j < m; j++)
				scanf("%d", W + j);
			for (int i = 0; i < m; i++)
				for (int j = W[i]; j < MAX_M; j++)
					if (C[j - W[i]] != INF && C[j - W[i]] + 1 <= s)
						if (C[j] > C[j - W[i]] + 1)
							C[j] = C[j - W[i]] + 1;
			coverage = 0;
			while (C[coverage] != INF)	coverage++;
			coverage--;
			bool mark = false;
			if (maxCoverage < coverage)
				mark = true;
			else if (maxCoverage == coverage&&stamp.size() > m)
				mark = true;
			else if (maxCoverage == coverage&&stamp.size() == m){
				for (int j = stamp.size() - 1; j >= 0; j--){
					if (stamp[j] > W[j])
						mark = true;
					else if (stamp[j] < W[j])
						break;
				}
			}
			if (mark){
				maxCoverage = coverage;
				stamp.clear();
				for (int j = 0; j < m; j++)
					stamp.push_back(W[j]);
			}
		}
		printf("max coverage =%4d :", maxCoverage);
		for (int i = 0; i < stamp.size(); i++)
			printf("%3d", stamp[i]);
		putchar('\n');
	}
	return 0;
}
/*

Stamps and Envelope Size

Philatelists have collected stamps since long before postal workers were disgruntled. An excess of stamps may be bad news to a country's postal service, but good news to those that collect the excess stamps. The postal service works to minimize the number of stamps needed to provide seamless postage coverage. To this end you have been asked to write a program to assist the postal service.

Envelope size restricts the number of stamps that can be used on one envelope. For example, if 1 cent and 3 cent stamps are available and an envelope can accommodate 5 stamps, all postage from 1 to 13 cents can be ``covered":

tabular21

Although five 3 cent stamps yields an envelope with 15 cents postage, it is not possible to cover an envelope with 14 cents of stamps using at most five 1 and 3 cent stamps. Since the postal service wants maximal coverage without gaps, the maximal coverage is 13 cents.

Input

The first line of each data set contains the integer S, representing the maximum of stamps that an envelope can accommodate. The second line contains the integer N, representing the number of sets of stamp denominations in the data set. Each of the next N lines contains a set of stamp denominations. The first integer on each line is the number of denominations in the set, followed by a list of stamp denominations, in order from smallest to largest, with each denomination separated from the others by one or more spaces. There will be at most S denominations on each of the N lines. The maximum value of S is 10, the largest stamp denomination is 100, the maximum value of N is 10.

The input is terminated by a data set beginning with zero (S is zero).

Output

Output one line for each data set giving the maximal no-gap coverage followed by the stamp denominations that yield that coverage in the following format:

max coverage = <value> : <denominations>

If more than one set of denominations in a set yields the same maximal no-gap coverage, the set with the fewest number of denominations should be printed (this saves on stamp printing costs). If two sets with the same number of denominations yield the same maximal no-gap coverage, then the set with the lower maximum stamp denomination should be printed. For example, if five stamps fit on an envelope, then stamp sets of 1, 4, 12, 21 and 1, 5, 12, 28 both yield maximal no-gap coverage of 71 cents. The first set would be printed because both sets have the same number of denominations but the first set's largest denomination (21) is lower than that of the second set (28). If multiple sets in a sequence yield the same maximal no-gap coverage, have the same number of denominations, and have equal largest denominations, then print the set with the lewer second-maximum stamp denomination, and so on.

Sample Input

5
2
4 1 4 12 21
4 1 5 12 28
10
2
5 1 7 16 31 88
5 1 15 52 67 99
6
2
3 1 5 8
4 1 5 7 8
0
Sample Output

max coverage =  71 :  1  4 12 21
max coverage = 409 :  1  7 16 31 88
max coverage =  48 :  1  5  7  8

*/