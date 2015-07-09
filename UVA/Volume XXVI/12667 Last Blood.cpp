/* 13084747	12667	Last Blood	Accepted	C++	0.018	2014-02-05 01:35:08 */
#include<cstdio>
#include<cstring>
struct problem{
	int team, time;
	bool sovle[101];
};
int main(){
	int n, t, m;
	while (scanf("%d%d%d", &n, &t, &m) == 3){
		struct problem P[12];
		for (int i = 0; i < n; i++){
			P[i].team = P[i].time = -1;
			memset(P[i].sovle, false, sizeof(P[i].sovle));
		}
		for (int i = 0; i < m; i++){
			int time, team;
			char Q, result[5];
			scanf("%d%d %c%s", &time, &team, &Q, result);
			if (strcmp(result, "Yes") == 0 && !P[Q - 'A'].sovle[team - 1]){
				P[Q - 'A'].team = team - 1, P[Q - 'A'].time = time;
				P[Q - 'A'].sovle[team - 1] = true;
			}
		}
		for (int i = 0; i < n; i++){
			if (P[i].time != -1)
				printf("%c %d %d\n", 'A' + i, P[i].time, P[i].team + 1);
			else
				printf("%c - -\n", 'A' + i);
		}
		
	}
	return 0;
}
/*

In many programming contests, special prizes are given to teams who solved a particular problem rst.
We call the rst accepted solution \First Blood".
It's an interesting idea to set prizes for \Last Blood". Then people won't submit their solutions
until the last minute. But this is dangerous: if the solution got "Wrong Answer" or even "Time limit
exceeded", it may be too late to correct the solution.
You may argue that once a submission got \Accepted", the team can send it again, but in this
problem, we only consider the earliest accepted solution of a team for each problem, so re-sending an
accepted solution does NOT help!
Given all the submissions in a contest, your task is to nd out the \Last Blood" prizes for each
problem.
Input
There is only one test case. The rst line contains three integer n, t, m (5  n  12, 10  t  100,
1  m  1000), the number of problems, teams and submissions. Each of the following m lines describes
one submission: time (0  time  300), teamID (1: : : t), problem (A ...L) and verdict(`Yes' or `No').
Submissions are sorted in time order. That means for two submissions of the same \time" eld, the
submission that comes later in the input is received later in the contest (maybe only a few seconds
later). No two submissions are received in exactly the same time.
Output
For each problem, print the last blood's time and teamID.
Sample Input
5 10 18
0 2 B No
11 2 B Yes
20 3 A Yes
35 8 E No
40 8 E No
45 7 E No
50 10 A Yes
100 4 A No
120 6 B Yes
160 2 E Yes
180 2 A Yes
210 3 B Yes
240 10 B No
250 10 B Yes
270 2 B Yes
295 8 E Yes
295 7 E Yes
299 10 D Yes
Sample Output
A 180 2
B 250 10
C - -
D 299 10
E 295 7

*/