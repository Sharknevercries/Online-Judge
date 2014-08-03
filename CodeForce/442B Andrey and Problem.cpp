/* 6925925	 2014-06-20 11:19:32	Shark	 442B - Andrey and Problem	 GNU C++	Accepted	 15 ms	 0 KB */

#include<cstdio>
#include<algorithm>
#define MAX(x,y) ( (x) >= (y) ? (x) : (y) )
bool cmp(double a, double b){
	return a > b;
}
int main(){
	int n;
	while (scanf("%d", &n) == 1){
		double S[100];
		double ans = 0;
		for (int i = 0; i < n; i++)
			scanf("%lf", S + i);
		std::sort(S, S + n, cmp);
		double a = 0, b = 1;
		for (int i = 0; i < n; i++){
			a = a * (1.0 - S[i]) + b * S[i];
			b *= (1.0 - S[i]);
			ans = MAX(ans, a);
		}
		printf("%.12lf\n", ans);
	}
	return 0;
}
/*

B. Andrey and Problem
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Andrey needs one more problem to conduct a programming contest. He has n friends who are always willing to help. He can ask some of them to come up with a contest problem. Andrey knows one value for each of his fiends — the probability that this friend will come up with a problem if Andrey asks him.

Help Andrey choose people to ask. As he needs only one problem, Andrey is going to be really upset if no one comes up with a problem or if he gets more than one problem from his friends. You need to choose such a set of people that maximizes the chances of Andrey not getting upset.

Input
The first line contains a single integer n (1 ≤ n ≤ 100) — the number of Andrey's friends. The second line contains n real numbers pi (0.0 ≤ pi ≤ 1.0) — the probability that the i-th friend can come up with a problem. The probabilities are given with at most 6 digits after decimal point.

Output
Print a single real number — the probability that Andrey won't get upset at the optimal choice of friends. The answer will be considered valid if it differs from the correct one by at most 10 - 9.

Sample test(s)
input
4
0.1 0.2 0.3 0.8
output
0.800000000000
input
2
0.1 0.2
output
0.260000000000
Note
In the first sample the best strategy for Andrey is to ask only one of his friends, the most reliable one.

In the second sample the best strategy for Andrey is to ask all of his friends to come up with a problem. Then the probability that he will get exactly one problem is 0.1·0.8 + 0.9·0.2 = 0.26.

*/