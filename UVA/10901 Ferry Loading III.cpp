/* 13993855	10901	Ferry Loading III	Accepted	C++	0.079	2014-08-05 11:30:23 */
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
#define MAX_N 10005
#define MAX_M 1000
#define INF 2e9
#define NONE -1
#define MAX(x, y, z) {	return max(max(x,y),z);	}
#define MIN(x, y, z) {	return min(min(x,y),z);	}
#define LEFT 0
#define RIGHT 1
const double PI = 2.0 * acos(0.0);
// main
int T[MAX_N + 1];
int arrive[MAX_N + 1];
int main(){ // not AC yet
	int t;
	scanf("%d", &t);
	while (t--){
		queue< pair<int, int> > L, R;
		int n, m, t;
		scanf("%d%d%d", &n, &t, &m);
		for (int i = 1; i <= m; i++){
			char S[50];
			scanf("%d%s", T + i, S);
			if (S[0] == 'l')
				L.push(make_pair(T[i], i));
			else
				R.push(make_pair(T[i], i));
		}
		L.push(make_pair(INF, m + 1));
		R.push(make_pair(INF, m + 2));
		int time = 0, side = LEFT, load = 0;
		while (L.size() > 1 || R.size() > 1){
			load = 0;
			time = max(time, min(L.front().first, R.front().first));
			if (side == LEFT){
				while (!L.empty() && L.front().first <= time && load < n)
					load++, arrive[L.front().second] = time + t, L.pop();
				time += t, side = RIGHT;
			}
			else{
				while (!R.empty() && R.front().first <= time && load < n)
					load++, arrive[R.front().second] = time + t, R.pop();
				time += t, side = LEFT;
			}
		}
		while (!L.empty())	L.pop();
		while (!R.empty())	R.pop();
		for (int i = 1; i <= m; i++)
			printf("%d\n", arrive[i]);
		if (t)	putchar('\n');
	}
	return 0;
}
// ------------------------------------------------------------------
int const MAX = 10000 + 5;
int A[MAX_N];
int res[MAX_N];
bool L[MAX_N];
int main(int argc, char **argv)
{
	int T; cin >> T;
	while (T-- != 0)
	{
		int n; cin >> n;
		int travelTime; cin >> travelTime;
		int cars; cin >> cars;
		int rindx = 0;
		int lindx = 0;
		fill(A, A + MAX, INF);
		for (int i = 0; i < cars; i++)
		{
			cin >> A[i];
			string direction; cin >> direction;
			L[i] = direction[0] == 'l';
		}
		for (; lindx < cars && !L[lindx]; lindx++);
		for (; rindx < cars && L[rindx]; rindx++);
		int time = 0;
		while (lindx < cars || rindx < cars)
		{
			time = max(time, min(A[lindx], A[rindx]));
			for (int i = 0; i < n && A[lindx] <= time; i++)
			{
				res[lindx] = time + travelTime;
				for (++lindx; lindx < cars && !L[lindx]; lindx++);
			}
			time += travelTime;
			time = max(time, min(A[lindx], A[rindx]));
			for (int i = 0; i < n && A[rindx] <= time; i++)
			{
				res[rindx] = time + travelTime;
				for (++rindx; rindx < cars && L[rindx]; rindx++);
			}
			time += travelTime;
		}
		for (int i = 0; i < cars; i++)
			cout << res[i] << endl;
		if (T != 0) cout << endl;
	}
	return 0;
}
/*

Problem B: Ferry Loading III

Before bridges were common, ferries were used to transport cars across rivers. River ferries, unlike their larger cousins, run on a guide line and are powered by the river's current. Cars drive onto the ferry from one end, the ferry crosses the river, and the cars exit from the other end of the ferry.
There is a ferry across the river that can take n cars across the river in t minutes and return in t minutes. A car may arrive at either river bank to be transported by the ferry to the opposite bank. The ferry travels continuously back and forth between the banks so long it is carrying a car or there is at least one car waiting at either bank. Whenever the ferry arrives at one of the banks, it unloads its cargo and loads up to n cars that are waiting to cross. If there are more than n, those that have been waiting the longest are loaded. If there are no cars waiting on either bank, the ferry waits until one arrives, loads it (if it arrives on the same bank of the ferry), and crosses the river. At what time does each car reach the other side of the river?

The first line of input contains c, the number of test cases. Each test case begins with n, t, m. m lines follow, each giving the arrival time for a car (in minutes since the beginning of the day), and the bank at which the car arrives ("left" or "right"). For each test case, output one line per car, in the same order as the input, giving the time at which that car is unloaded at the opposite bank. Output an empty line between cases.

You may assume that 0 < n, t, m ≤ 10000. The arrival times for each test case are strictly increasing. The ferry is initially on the left bank. Loading and unloading time may be considered to be 0.

Sample input

2
2 10 10
0 left
10 left
20 left
30 left
40 left
50 left
60 left
70 left
80 left
90 left
2 10 3
10 right
25 left
40 left
Output for sample input

10
30
30
50
50
70
70
90
90
110

30
40
60
Gordon V. Cormack

*/