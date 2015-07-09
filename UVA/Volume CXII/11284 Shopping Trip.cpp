/* 14218964	11284	Shopping Trip	Accepted	C++	0.055	2014-09-17 14:59:31 */
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
#define MAX_N 60
#define MAX_M 15
#define MOD 1000000007
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
int n, m, p;
int ask[MAX_N];
int price[MAX_N];
int dist[MAX_N][MAX_N];
int DP[1 << MAX_M][MAX_M];
int main(){
	int t;
	scanf("%d", &t);
	while (t--){
		scanf("%d%d", &n, &m);
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= n; j++)
				dist[i][j] = INF;
		for (int i = 0; i < m; i++){
			int a, b;
			double d;
			scanf("%d%d%lf", &a, &b, &d);
			dist[a][b] = dist[b][a] = min(dist[a][b], (int)(d * 100 + EPS));
		}
		for (int i = 0; i <= n; i++)
			dist[i][i] = 0;
		for (int k = 0; k <= n; k++)
			for (int i = 0; i <= n; i++)
				for (int j = 0; j <= n; j++)
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
		scanf("%d", &p);
		ask[0] = price[0] = 0;
		for (int i = 1; i <= p; i++){
			double tmp;
			scanf("%d%lf", ask + i, &tmp);
			price[i] = tmp * 100.0 + EPS;
		}
		int maxAns = -INF;
		int maxState = 1 << (p + 1);
		vector<int> S[MAX_M];
		for (int i = 0; i < maxState; i++){
			int digit = 0;
			for (int j = i; j > 0; j >>= 1)
				digit += j & 1;
			S[digit].push_back(i);
		}
		for (int i = 0; i <= maxState; i++)
			for (int j = 0; j <= p; j++)
				DP[i][j] = INF;
		DP[0][0] = 0;
		for (int i = 0; i <= p; i++){
			for (int j = 0; j < S[i].size(); j++){
				int u = S[i][j];
				for (int k = 0; k <= p; k++)
					if ((u & (1 << k)) == 0)
						for (int s = 0; s <= p; s++)
							DP[u | (1 << k)][k] = min(DP[u | (1 << k)][k], DP[u][s] + dist[ask[s]][ask[k]]);
			}
		}
		for (int i = 2; i < maxState; i++){
			int cost = 0;
			for (int j = i, k = 0; j > 0; j >>= 1, k++)
				cost += price[k] * (j & 1);
			if (DP[i][0] != INF && cost - DP[i][0] > 0)
				maxAns = max(maxAns, cost - DP[i][0]);
		}
		if (maxAns == -INF)
			puts("Don't leave the house");
		else
			printf("Daniel can save $%.2lf\n", maxAns / 100.0 + EPS);
	}
	return 0;
}
/*

Problem G

SHOPPING TRIP

For some reason, Daniel loves to collect and watch operas on DVD. He can find and order all the operas he wants from Amazon, and they will even deliver them right to his door, but he can usually find a better price at one of his favourite stores. However, with the cost of gas nowadays, it is hard to tell whether or not one would actually save money by driving to the stores to purchase the DVDs.

Daniel would like to buy some operas today. For each of the operas he wants, he knows exactly one store that is selling it for a lower cost than the Amazon price. He would like to know if it would actually be worth it to go out and buy the operas from the stores.

Daniel only knows the road system connecting his favourite stores, and will only use those roads to get around. He knows at least one route, if only an indirect one, to every store.



An example diagram of Daniel's house, his favourite stores, and the roads connecting them.

In his shopping trip, Daniel begins at his house, drives from store to store in any order to purchase his operas, then drives back to his house. For any particular opera, he can opt not to drive to the store to buy it, since he can just order it from Amazon.

For convenience, Daniel assigned his house the integer 0, and numbered each of his favourite stores with integers starting at 1. You are given a description of the road system and the exact amount it would cost for Daniel to drive each road. For each opera Daniel wants, you are given the number of the store it is available at, and the amount he would save if he bought that particular opera at that store. Your task is to determine the greatest amount of money Daniel can save by making the shopping trip.

Input

The first line of input contains a single number indicating the number of scenarios to process. A blank line precedes each scenario.

Each scenario begins with line containing two numbers: N (1 ≤ N ≤ 50), the number of stores, and M (1 ≤ M ≤ 1000), the number of roads. The following M lines each contain a description of a road. Each road is described by two integers indicating the house or stores it connects, and a real number with two decimal digits indicating the cost in dollars to drive that road. All roads are two-way.

The next line in the scenario contains a number P (1 ≤ P ≤ 12), the number of opera DVDs Daniel wants to buy. For each of the P operas, a line follows containing an integer indicating the store number at which the opera is available, and a real number with two decimal digits indicating the difference between the Amazon price and the price at that store in dollars.

Output

For each scenario in the input, write one line of output indicating the largest amount of money, in dollars and cents, that Daniel can save by making his shopping trip. Follow the format of the sample output; there should always be two digits after the decimal point to indicate the number of cents. If Daniel cannot save any money by going to the stores, output a single line saying "Don't leave the house".

Sample Input

2

4 5
0 1 1.00
1 2 3.00
1 3 2.00
2 4 4.00
3 4 3.25
3
2 1.50
3 7.00
4 9.00

1 1
0 1 1.50
1
1 2.99
Output for the Sample Input

Daniel can save $3.50
Don't leave the house
Sonny Chan
Calgary Collegiate Programming Contest 2006

*/