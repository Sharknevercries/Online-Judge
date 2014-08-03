/* 5397160	 Dec 9, 2013 5:20:01 PM	Shark	 E - Subway Innovation	 GNU C++	Accepted	390 ms	7028 KB */
#include<cstdio>
#include<algorithm>
struct data{
	long long int x;
	int ID;
};
bool cmp(struct data A, struct data B){
	return A.x < B.x;
}
struct data M[300001];
long long int sum[300001] = { 0 };
int main(){ // greedy
	int n;
	while (scanf("%d", &n) == 1){
		int k, fix = 2e9;
		for (int i = 1; i <= n; i++){
			scanf("%lld", &M[i].x);
			if (M[i].x < fix)
				fix = M[i].x;
			M[i].ID = i;
		}
		if (fix < 0){
			for (int i = 1; i <= n; i++)
				M[i].x += -(fix);
		}
		scanf("%d", &k);
		std::sort(M + 1, M + n + 1, cmp);
		for (int i = 1; i <= n; i++)
			sum[i] = sum[i - 1] + M[i].x;
		long long int min = 9e18, tmp = 0;
		int pos = -1, p;
		for (int i = 1; i <= n; i++){
			if (i <= k)
				tmp += (i - 1)*M[i].x - sum[i - 1];
			else{
				tmp -= sum[i - 1] - sum[i - k] - M[i - k].x*(k - 1);
				tmp += M[i].x*(k - 1) - (sum[i - 1] - sum[i - k]);
			}
			if (i >= k&&min > tmp)
				min = tmp, p = i - k + 1;
		}
		printf("%d", M[p].ID);
		for (int i = p + 1; i <= p + k - 1; i++)
			printf(" %d", M[i].ID);
		putchar('\n');
	}
	return 0;
}
/*

E. Subway Innovation
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Berland is going through tough times — the dirt price has dropped and that is a blow to the country's economy. Everybody knows that Berland is the top world dirt exporter!

The President of Berland was forced to leave only k of the currently existing n subway stations.

The subway stations are located on a straight line one after another, the trains consecutively visit the stations as they move. You can assume that the stations are on the Ox axis, the i-th station is at point with coordinate xi. In such case the distance between stations i and j is calculated by a simple formula |xi - xj|.

Currently, the Ministry of Transport is choosing which stations to close and which ones to leave. Obviously, the residents of the capital won't be too enthusiastic about the innovation, so it was decided to show the best side to the people. The Ministry of Transport wants to choose such k stations that minimize the average commute time in the subway!

Assuming that the train speed is constant (it is a fixed value), the average commute time in the subway is calculated as the sum of pairwise distances between stations, divided by the number of pairs (that is ) and divided by the speed of the train.

Help the Minister of Transport to solve this difficult problem. Write a program that, given the location of the stations selects such k stations that the average commute time in the subway is minimized.

Input
The first line of the input contains integer n (3 ≤ n ≤ 3·105) — the number of the stations before the innovation. The second line contains the coordinates of the stations x1, x2, ..., xn ( - 108 ≤ xi ≤ 108). The third line contains integer k (2 ≤ k ≤ n - 1) — the number of stations after the innovation.

The station coordinates are distinct and not necessarily sorted.

Output
Print a sequence of k distinct integers t1, t2, ..., tk (1 ≤ tj ≤ n) — the numbers of the stations that should be left after the innovation in arbitrary order. Assume that the stations are numbered 1 through n in the order they are given in the input. The number of stations you print must have the minimum possible average commute time among all possible ways to choose k stations. If there are multiple such ways, you are allowed to print any of them.

Sample test(s)
input
3
1 100 101
2
output
2 3
Note
In the sample testcase the optimal answer is to destroy the first station (with x = 1). The average commute time will be equal to 1 in this way.

*/