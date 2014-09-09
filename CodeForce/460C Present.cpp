/* 7526047	2014-08-20 20:20:25	Shark	460C - Present	GNU C++	Accepted	31 ms	1700 KB */
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
// template
template<class T> T max(T a, T b, T c){ return max(a, max(b, c)); }
template<class T> T min(T a, T b, T c){ return min(a, min(b, c)); }
// const variable
#define MAX_N 100005
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
int S[MAX_N];
int n, m, w;
bool check(int target){
	queue< pair<int, int> > Q;
	int fix = 0, water = 0;
	for (int i = 0; i < n; i++){
		while (!Q.empty() && Q.front().second <= i)
			fix -= Q.front().first, Q.pop();
		if (S[i] + fix < target){
			int use = target - (S[i] + fix);
			water += use,fix += use;
			Q.push(make_pair(use, i + w));
		}
		if (water > m)	return false;
	}
	return true;
}
int main(){
	scanf("%d%d%d", &n, &m, &w);
	for (int i = 0; i < n; i++)
		scanf("%d", S + i);
	int L = 1, R = 1e9 + 1e6;
	while (R >= L){
		int mid = (L + R) / 2;
		if (check(mid))
			L = mid + 1;
		else
			R = mid - 1;
	}
	printf("%d\n", L - 1);
	return 0;
}
/*

C. Present
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Little beaver is a beginner programmer, so informatics is his favorite subject. Soon his informatics teacher is going to have a birthday and the beaver has decided to prepare a present for her. He planted n flowers in a row on his windowsill and started waiting for them to grow. However, after some time the beaver noticed that the flowers stopped growing. The beaver thinks it is bad manners to present little flowers. So he decided to come up with some solutions.

There are m days left to the birthday. The height of the i-th flower (assume that the flowers in the row are numbered from 1 to n from left to right) is equal to ai at the moment. At each of the remaining m days the beaver can take a special watering and water w contiguous flowers (he can do that only once at a day). At that each watered flower grows by one height unit on that day. The beaver wants the height of the smallest flower be as large as possible in the end. What maximum height of the smallest flower can he get?

Input
The first line contains space-separated integers n, m and w (1 ≤ w ≤ n ≤ 105; 1 ≤ m ≤ 105). The second line contains space-separated integers a1, a2, ..., an (1 ≤ ai ≤ 109).

Output
Print a single integer — the maximum final height of the smallest flower.

Sample test(s)
input
6 2 3
2 2 2 2 1 1
output
2
input
2 5 1
5 8
output
9
Note
In the first sample beaver can water the last 3 flowers at the first day. On the next day he may not to water flowers at all. In the end he will get the following heights: [2, 2, 2, 3, 2, 2]. The smallest flower has height equal to 2. It's impossible to get height 3 in this test.

*/