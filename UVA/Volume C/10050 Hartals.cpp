/* 15054602	10050	Hartals	Accepted	C++	0.009	2015-02-28 06:11:16 */
#include<bits\stdc++.h>
using namespace std;
int main(){
	int t;
	scanf("%d", &t);
	while (t--){
		int d, n, week = 0;
		bool V[5000] = { false };
		scanf("%d%d", &d, &n);
		for (int i = 0; i < n; i++){
			int s;
			scanf("%d", &s);
			for (int j = s; j <= d; j += s)
				V[j] |= true;
		}
		int ans = 0;
		for (int i = 1; i <= d; i++){
			if (V[i] && week != 5 && week != 6)
				ans++;
			week = (week + 1) % 7;
		}
		printf("%d\n", ans);
	}
	return 0;
}
/*

A social research organization has determined a simple set of parameters to simulate the behavior of
the political parties of our country. One of the parameters is a positive integer h (called the hartal
parameter) that denotes the average number of days between two successive hartals (strikes) called by
the corresponding party. Though the parameter is far too simple to be flawless, it can still be used to
forecast the damages caused by hartals. The following example will give you a clear idea:
Consider three political parties. Assume h1 = 3, h2 = 4 and h3 = 8 where hi
is the hartal parameter
for party i (i = 1, 2, 3). Now, we will simulate the behavior of these three parties for N = 14 days.
One must always start the simulation on a Sunday and assume that there will be no hartals on weekly
holidays (on Fridays and Saturdays).
1 2 3 4 5 6 7 8 9 10 11 12 13 14
Days
Su Mo Tu We Th Fr Sa Su Mo Tu We Th Fr Sa
Party 1 x x x x
Party 2 x x x
Party 3 x
Hartals 1 2 3 4 5
The simulation above shows that there will be exactly 5 hartals (on days 3, 4, 8, 9 and 12) in 14
days. There will be no hartal on day 6 since it is a Friday. Hence we lose 5 working days in 2 weeks.
In this problem, given the hartal parameters for several political parties and the value of N, your
job is to determine the number of working days we lose in those N days.
Input
The first line of the input consists of a single integer T giving the number of test cases to follow.
The first line of each test case contains an integer N (7 ≤ N ≤ 3650) giving the number of days over
which the simulation must be run. The next line contains another integer P (1 ≤ P ≤ 100) representing
the number of political parties in this case. The ith of the next P lines contains a positive integer hi
(which will never be a multiple of 7) giving the hartal parameter for party i (1 ≤ i ≤ P).
Output
For each test case in the input output the number of working days we lose. Each output must be on a
separate line.
Sample Input
2
14
3
3
4
8
100
4
12
15
25
40
Sample Output
5
15

*/