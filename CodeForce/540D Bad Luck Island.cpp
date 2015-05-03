/* 10960435	2015-05-01 09:52:25	Shark	540D - Bad Luck Island	GNU C++	Accepted	46 ms	29200 KB */
#include<bits\stdc++.h>
using namespace std;
struct Prob{
	double r, s, p;
	Prob(){}
	Prob(double r, double s, double p) :r(r), s(s), p(p){}
};
Prob DP[105][105][105];
inline double ratio(int a, int b){
	return (double)a / b;
}
int main(){
	
	for (int i = 1; i <= 100; i++){
		DP[0][0][i] = Prob(0, 0, 1);
		DP[0][i][0] = Prob(0, 1, 0);
		DP[i][0][0] = Prob(1, 0, 0);
	}
	for (int i = 1; i <= 100; i++){
		for (int j = 1; j <= 100; j++){
			DP[i][j][0] = Prob(1, 0, 0);
			DP[i][0][j] = Prob(0, 0, 1);
			DP[0][i][j] = Prob(0, 1, 0);
		}
	}
	for (int i = 1; i <= 100; i++){
		for (int j = 1; j <= 100; j++){
			for (int k = 1; k <= 100; k++){
				int mother = i*j + j*k + i*k;
				DP[i][j][k].r = DP[i - 1][j][k].r * ratio(i*k, mother) + DP[i][j - 1][k].r * ratio(i*j, mother) + DP[i][j][k - 1].r * ratio(j*k, mother);
				DP[i][j][k].s = DP[i - 1][j][k].s * ratio(i*k, mother) + DP[i][j - 1][k].s * ratio(i*j, mother) + DP[i][j][k - 1].s * ratio(j*k, mother);
				DP[i][j][k].p = DP[i - 1][j][k].p * ratio(i*k, mother) + DP[i][j - 1][k].p * ratio(i*j, mother) + DP[i][j][k - 1].p * ratio(j*k, mother);
			}
		}
	}
	int r, s, p;
	scanf("%d%d%d", &r, &s, &p);
	printf("%.9lf %.9lf %.9lf\n", DP[r][s][p].r, DP[r][s][p].s, DP[r][s][p].p);
	return 0;
}
/*

D. Bad Luck Island
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
The Bad Luck Island is inhabited by three kinds of species: r rocks, s scissors and p papers. At some moments of time two random individuals meet (all pairs of individuals can meet equiprobably), and if they belong to different species, then one individual kills the other one: a rock kills scissors, scissors kill paper, and paper kills a rock. Your task is to determine for each species what is the probability that this species will be the only one to inhabit this island after a long enough period of time.

Input
The single line contains three integers r, s and p (1 ≤ r, s, p ≤ 100) — the original number of individuals in the species of rock, scissors and paper, respectively.

Output
Print three space-separated real numbers: the probabilities, at which the rocks, the scissors and the paper will be the only surviving species, respectively. The answer will be considered correct if the relative or absolute error of each number doesn't exceed 10 - 9.

Sample test(s)
input
2 2 2
output
0.333333333333 0.333333333333 0.333333333333
input
2 1 2
output
0.150000000000 0.300000000000 0.550000000000
input
1 1 3
output
0.057142857143 0.657142857143 0.285714285714

*/