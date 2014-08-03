/* 5410696	 Dec 11, 2013 8:58:00 PM	Shark	 24A - Ring road	 GNU C++	Accepted	30 ms	0 KB */
#include<cstdio>
#include<math.h>
#include<algorithm>
using namespace std;
int main(){
	int n;
	while (scanf("%d", &n) == 1){
		bool in[100] = { false };
		bool out[100] = { false };
		int ans = 0, total = 0;
		for (int i = 0; i < n; i++){
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			a--, b--;
			if (out[a] || in[b]){
				ans += c;
				in[a] = out[b] = true;
			}
			else
				out[a] = in[b] = true;
			total += c;
		}
		if (ans < total - ans)
			printf("%d\n", ans);
		else
			printf("%d\n", total - ans);
	}
	return 0;
}
/*

A. Ring road
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Nowadays the one-way traffic is introduced all over the world in order to improve driving safety and reduce traffic jams. The government of Berland decided to keep up with new trends. Formerly all n cities of Berland were connected by n two-way roads in the ring, i. e. each city was connected directly to exactly two other cities, and from each city it was possible to get to any other city. Government of Berland introduced one-way traffic on all n roads, but it soon became clear that it's impossible to get from some of the cities to some others. Now for each road is known in which direction the traffic is directed at it, and the cost of redirecting the traffic. What is the smallest amount of money the government should spend on the redirecting of roads so that from every city you can get to any other?

Input
The first line contains integer n (3 ≤ n ≤ 100) — amount of cities (and roads) in Berland. Next n lines contain description of roads. Each road is described by three integers ai, bi, ci (1 ≤ ai, bi ≤ n, ai ≠ bi, 1 ≤ ci ≤ 100) — road is directed from city ai to city bi, redirecting the traffic costs ci.

Output
Output single integer — the smallest amount of money the government should spend on the redirecting of roads so that from every city you can get to any other.

Sample test(s)
input
3
1 3 1
1 2 1
3 2 1
output
1
input
3
1 3 1
1 2 5
3 2 1
output
2
input
6
1 5 4
5 3 8
2 4 15
1 6 16
2 3 23
4 6 42
output
39
input
4
1 2 9
2 3 8
3 4 7
4 1 5
output
0

*/