/* 13191595	10137	The Trip	Accepted	C++	0.012	2014-02-22 11:44:11 */
#include<cstdio>
#include<cmath>
#include<algorithm>
#define MAX 1000
#define ABS(x) ( (x) >= 0 ? (x) : -(x) )
bool cmp(int a, int b){
	return a > b;
}
int main(){
	int n;
	while (scanf("%d", &n) == 1){
		if (n == 0)
			break;
		int cost[MAX], avg, reminder, ans;
		avg = ans = reminder = 0;
		for (int i = 0; i < n; i++){
			double tmp;
			scanf("%lf", &tmp);
			cost[i] = (tmp + 0.00001) * 100;
		}
		std::sort(cost, cost + n, cmp);
		for (int i = 0; i < n; i++)
			avg += cost[i];
		reminder = avg%n;
		avg /= n;
		for (int i = 0; i < reminder; i++)
			ans += ABS(cost[i] - (avg + 1));
		for (int i = reminder; i < n; i++)
			ans += ABS(cost[i] - avg);
		printf("$%.2lf\n", ans / 200.0 + 0.00001);
	}
	return 0;
}
/*

Problem A: The Trip

A number of students are members of a club that travels annually to exotic locations. Their destinations in the past have included Indianapolis, Phoenix, Nashville, Philadelphia, San Jose, and Atlanta. This spring they are planning a trip to Eindhoven.
The group agrees in advance to share expenses equally, but it is not practical to have them share every expense as it occurs. So individuals in the group pay for particular things, like meals, hotels, taxi rides, plane tickets, etc. After the trip, each student's expenses are tallied and money is exchanged so that the net cost to each is the same, to within one cent. In the past, this money exchange has been tedious and time consuming. Your job is to compute, from a list of expenses, the minimum amount of money that must change hands in order to equalize (within a cent) all the students' costs.

The Input

Standard input will contain the information for several trips. The information for each trip consists of a line containing a positive integer, n, the number of students on the trip, followed by n lines of input, each containing the amount, in dollars and cents, spent by a student. There are no more than 1000 students and no student spent more than $10,000.00. A single line containing 0 follows the information for the last trip.
The Output

For each trip, output a line stating the total amount of money, in dollars and cents, that must be exchanged to equalize the students' costs.
Sample Input

3
10.00
20.00
30.00
4
15.00
15.01
3.00
3.01
0
Output for Sample Input

$10.00
$11.99

*/