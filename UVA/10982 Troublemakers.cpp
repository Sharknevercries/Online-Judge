/* 13969931	10982	Troublemakers	Accepted	C++	0.016	2014-07-31 07:18:01 */
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
#define MAX_N 100
#define MAX_M 5000
#define INF 2e9
#define NONE -1
#define MAX(x, y, z) {	return max(max(x,y),z);	}
#define MIN(x, y, z) {	return min(min(x,y),z);	}
const double PI = 2.0 * acos(0.0);
// main
int main(){
	int t;
	scanf("%d", &t);
	for (int c = 1; c <= t; c++){
		int n, m;
		int G[MAX_N + 1] = { 0 };
		pair<int, int> P[MAX_M + 1];
		scanf("%d%d", &n, &m);
		for (int i = 0; i < m; i++)
			scanf("%d%d", &P[i].first, &P[i].second);
		for (int i = 1; i <= n; i++){
			int count[2] = { 0 };
			for (int j = 0; j < m; j++){
				if (P[j].first <= i && P[j].second <= i && (P[j].first == i || P[j].second == i)){
					if (P[j].first == i)
						count[G[P[j].second]]++;
					else
						count[G[P[j].first]]++;
				}
			}
			if (count[0] > count[1])
				G[i] = 1;
		}
		vector<int> T;
		for (int i = 1; i <= n; i++)
			if (G[i] == 1)
				T.push_back(i);
		printf("Case #%d: %d\n", c, T.size());
		for (int i = 0; i < T.size(); i++){
			if (i != 0)	putchar(' ');
			printf("%d", T[i]);
		}
		putchar('\n');
	}
	return 0;
}
/*

Problem A
Troublemakers
Time Limit: 1 second
[after seeing that the room is on fire; Ted has a needle
in his hand while holding the leg of a dead woman; Sara
has a bottle of champagne in her hand, and Juancho is smoking]
Man: Did they misbehave?
Robert Rodrigues, "The Misbehavers."

Every school class has its troublemakers - those kids who can make the teacher's life miserable. On his own, a troublemaker is manageable, but when you put certain pairs of troublemakers together in the same room, teaching a class becomes very hard. There are n kids in Mrs. Shaida's math class, and there are m pairs of troublemakers among them. The situation has gotten so bad that Mrs. Shaida has decided to split the class into two classes. Help her do it in such a way that the number of troublemaker pairs is reduced by at least a half.

Input
The first line of input gives the number of cases, N. N test cases follow. Each one starts with a line containing n (0<=n<=100) and m (0<m<5000). The next m lines will contain a pair of integers u and v meaning that when kids u and v are in the same room, they make a troublemaker pair. Kids are numbered from 1 to n.

Output
For each test case, output one line containing "Case #x:" followed by L - the number of kids who will be moved to a different class (in a different room). The next line should list those kids. The total number of troublemaker pairs in the two rooms must be at most m/2. If that is impossible, print "Impossible." instead of L and an empty line afterwards.

Sample Input	Sample Output
2
4 3
1 2
2 3
3 4
4 6
1 2
1 3
1 4
2 3
2 4
3 4
Case #1: 3
1 3 4
Case #2: 2
1 2
Problemsetter: Igor Naverniouk

*/