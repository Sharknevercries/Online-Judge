/* 10069333	2015-02-28 16:24:19	Shark	519C - A and B and Team Training	GNU C++	Accepted	30 ms	0 KB */
#include<bits\stdc++.h>
using namespace std;
int solve(int n, int m){
	if (n >= 2 * m)
		return m;
	if (m >= 2 * n)
		return n;
	if (n > m)
		return solve(n - 2 * (n - m), m - (n - m)) + n - m;
	else if (n < m)
		return solve(n - (m - n), m - 2 * (m - n)) + m - n;
	else
		return (n + m) / 3;
}
int main(){
	int n, m, ans = 0;
	scanf("%d%d", &n, &m);
	printf("%d\n", solve(n, m));
	return 0;
}
/*

C. A and B and Team Training
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
A and B are preparing themselves for programming contests.

An important part of preparing for a competition is sharing programming knowledge from the experienced members to those who are just beginning to deal with the contests. Therefore, during the next team training A decided to make teams so that newbies are solving problems together with experienced participants.

A believes that the optimal team of three people should consist of one experienced participant and two newbies. Thus, each experienced participant can share the experience with a large number of people.

However, B believes that the optimal team should have two experienced members plus one newbie. Thus, each newbie can gain more knowledge and experience.

As a result, A and B have decided that all the teams during the training session should belong to one of the two types described above. Furthermore, they agree that the total number of teams should be as much as possible.

There are n experienced members and m newbies on the training session. Can you calculate what maximum number of teams can be formed?

Input
The first line contains two integers n and m (0 ≤ n, m ≤ 5·105) — the number of experienced participants and newbies that are present at the training session.

Output
Print the maximum number of teams that can be formed.

Sample test(s)
input
2 6
output
2
input
4 5
output
3
Note
Let's represent the experienced players as XP and newbies as NB.

In the first test the teams look as follows: (XP, NB, NB), (XP, NB, NB).

In the second test sample the teams look as follows: (XP, NB, NB), (XP, NB, NB), (XP, XP, NB).

*/