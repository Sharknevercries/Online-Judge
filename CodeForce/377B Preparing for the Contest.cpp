/* 5597271	 Jan 1, 2014 2:04:57 PM	Shark	 B - Preparing for the Contest	 GNU C++	Happy New Year!	312 ms	 */
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
struct bug{
	int index, com, solve;
};
struct person{
	int cost, abi, index;
	
};
bool cmp1(struct bug A, struct bug B){
	return A.com > B.com;
}
bool cmp2(struct bug A, struct bug B){
	return A.index < B.index;
}
bool cmp3(struct person A, struct person B){
	return A.abi > B.abi;
}
bool operator<(struct person A, struct person B){ // sort by increase
	return A.cost > B.cost;
}
struct bug M[100000];
struct bug T[100000];
struct person P[100000];
int n, m, d;
bool solve(int D){
	long long int cost = 0;
	int ptr = 0;
	priority_queue<struct person> Q;
	for (int i = 0; i < m; i += D){
		for (; ptr < n && P[ptr].abi >= T[i].com; ptr++)
			Q.push(P[ptr]);
		if (Q.size() == 0)
			return false;
		cost += Q.top().cost;
		for (int j = i; j < i + D && j < m; j++)
			T[j].solve = Q.top().index;
		Q.pop();
		if (cost > d)
			return false;
	}
	for (int i = 0; i < m; i++)
		M[i] = T[i];
	return true;
}
int main(){
	while (scanf("%d%d%d", &n, &m, &d) == 3){
		for (int i = 0; i < m; i++){
			scanf("%d", &M[i].com);
			M[i].index = i;
			M[i].solve = -1;
		}
		sort(M, M + m, cmp1);
		for (int i = 0; i < m; i++)
			T[i] = M[i];
		for (int i = 0; i < n; i++)
			scanf("%d", &P[i].abi);
		for (int i = 0; i < n; i++)
			scanf("%d", &P[i].cost);
		for (int i = 0; i < n; i++)
			P[i].index = i;
		sort(P, P + n, cmp3);
		int L = 1, R = m;
		while (R >= L){ // cost day
			int mid = (L + R) / 2;
			if (solve(mid))
				R = mid - 1;
			else
				L = mid + 1;
		}
		if (L == m + 1)
			puts("NO");
		else{
			sort(M, M + m, cmp2);
			puts("YES");
			printf("%d", M[0].solve + 1);
			for (int i = 1; i < m; i++)
				printf(" %d", M[i].solve + 1);
			putchar('\n');
		}
	}
	return 0;
}
/*

B. Preparing for the Contest
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Soon there will be held the world's largest programming contest, but the testing system still has m bugs. The contest organizer, a well-known university, has no choice but to attract university students to fix all the bugs. The university has n students able to perform such work. The students realize that they are the only hope of the organizers, so they don't want to work for free: the i-th student wants to get ci 'passes' in his subjects (regardless of the volume of his work).

Bugs, like students, are not the same: every bug is characterized by complexity aj, and every student has the level of his abilities bi. Student i can fix a bug j only if the level of his abilities is not less than the complexity of the bug: bi ≥ aj, and he does it in one day. Otherwise, the bug will have to be fixed by another student. Of course, no student can work on a few bugs in one day. All bugs are not dependent on each other, so they can be corrected in any order, and different students can work simultaneously.

The university wants to fix all the bugs as quickly as possible, but giving the students the total of not more than s passes. Determine which students to use for that and come up with the schedule of work saying which student should fix which bug.

Input
The first line contains three space-separated integers: n, m and s (1 ≤ n, m ≤ 105, 0 ≤ s ≤ 109) — the number of students, the number of bugs in the system and the maximum number of passes the university is ready to give the students.

The next line contains m space-separated integers a1, a2, ..., am (1 ≤ ai ≤ 109) — the bugs' complexities.

The next line contains n space-separated integers b1, b2, ..., bn (1 ≤ bi ≤ 109) — the levels of the students' abilities.

The next line contains n space-separated integers c1, c2, ..., cn (0 ≤ ci ≤ 109) — the numbers of the passes the students want to get for their help.

Output
If the university can't correct all bugs print "NO".

Otherwise, on the first line print "YES", and on the next line print m space-separated integers: the i-th of these numbers should equal the number of the student who corrects the i-th bug in the optimal answer. The bugs should be corrected as quickly as possible (you must spend the minimum number of days), and the total given passes mustn't exceed s. If there are multiple optimal answers, you can output any of them.

Sample test(s)
input
3 4 9
1 3 1 2
2 1 3
4 3 6
output
YES
2 3 2 3
input
3 4 10
2 3 1 2
2 1 3
4 3 6
output
YES
1 3 1 3
input
3 4 9
2 3 1 2
2 1 3
4 3 6
output
YES
3 3 2 3
input
3 4 5
1 3 1 2
2 1 3
5 3 6
output
NO
Note
Consider the first sample.

The third student (with level 3) must fix the 2nd and 4th bugs (complexities 3 and 2 correspondingly) and the second student (with level 1) must fix the 1st and 3rd bugs (their complexity also equals 1). Fixing each bug takes one day for each student, so it takes 2 days to fix all bugs (the students can work in parallel).

The second student wants 3 passes for his assistance, the third student wants 6 passes. It meets the university's capabilities as it is ready to give at most 9 passes.

*/