/* 13892107	624	CD	Accepted	C++	0.032	2014-07-16 12:25:55 */
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
#define MAX_N 100001
#define MAX_M 20
#define INF 2e9
#define NONE -1
#define MAX(x, y, z) {	return max(max(x,y),z);	}
#define MIN(x, y, z) {	return min(min(x,y),z);	}
const double PI = 2.0 * acos(0.0);
bool DP[MAX_N];
bool record[MAX_M][MAX_N];
int P[MAX_M];
int main(){
	int n, m;
	while (scanf("%d%d", &n, &m) == 2){
		memset(DP, false, sizeof(DP));
		memset(P, 0, sizeof(P));
		memset(record, false, sizeof(record));
		for (int i = 0; i < m; i++)
			scanf("%d", P + i);
		DP[0] = true;
		for (int i = 0; i < m; i++)
			for (int j = n; j >= P[i]; j--)
				if (DP[j - P[i]])
					DP[j] = true, record[i][j] = true;
		int max = n;
		while (!DP[max])	max--;
		vector<int> L;
		for (int i = m - 1, j = max; i >= 0; i--)
			if (record[i][j])
				L.push_back(i), j -= P[i];
		for (int i = L.size() - 1; i >= 0; i--)
			printf("%d ", P[L[i]]);
		printf("sum:%d\n", max);
	}
	return 0;
}
/*

CD
You have a long drive by car ahead. You have a tape recorder, but unfortunately your best music is on CDs. You need to have it on tapes so the problem to solve is: you have a tape N minutes long. How to choose tracks from CD to get most out of tape space and have as short unused space as possible.

Assumptions:

number of tracks on the CD. does not exceed 20
no track is longer than N minutes
tracks do not repeat
length of each track is expressed as an integer number
N is also integer
Program should find the set of tracks which fills the tape best and print it in the same sequence as the tracks are stored on the CD

Input

Any number of lines. Each one contains value N, (after space) number of tracks and durations of the tracks. For example from first line in sample data: N=5, number of tracks=3, first track lasts for 1 minute, second one 3 minutes, next one 4 minutes
Output

Set of tracks (and durations) which are the correct solutions and string ``sum:" and sum of duration times.
Sample Input

5 3 1 3 4
10 4 9 8 4 2
20 4 10 5 7 4
90 8 10 23 1 2 3 4 5 7
45 8 4 10 44 43 12 9 8 2
Sample Output

1 4 sum:5
8 2 sum:10
10 5 4 sum:19
10 23 1 2 3 4 5 7 sum:55
4 10 12 9 8 2 sum:45

Miguel A. Revilla
2000-01-10

*/