/* 13849886	10954	Add All	Accepted	C++	0.032	2014-07-08 07:50:20 */
#include<cstdio>
#include<algorithm>
#include<queue>
#include <functional>
using namespace std;
bool cmp(int A, int B){
	return A < B;
}
int main(){
	int n;
	while (scanf("%d", &n) == 1 && n){
		priority_queue<int, vector<int>, greater<int> > Q;
		int S[5000];
		long long int ans = 0;
		for (int i = 0; i < n; i++)
			scanf("%d", S + i);
		for (int i = 0; i < n; i++)
			Q.push(S[i]);
		while (Q.size() > 1){
			int a = Q.top();	Q.pop();
			int b = Q.top();	Q.pop();
			ans += a + b;
			Q.push(a + b);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
/*

Problem F
Add All
Input: standard input
Output: standard output

Yup!! The problem name reflects your task; just add a set of numbers. But you may feel yourselves condescended, to write a C/C++ program just to add a set of numbers. Such a problem will simply question your erudition. So, let’s add some flavor of ingenuity to it.

Addition operation requires cost now, and the cost is the summation of those two to be added. So, to add 1 and 10, you need a cost of 11. If you want to add 1, 2 and 3. There are several ways –

1 + 2 = 3, cost = 3
3 + 3 = 6, cost = 6
Total = 9
1 + 3 = 4, cost = 4
2 + 4 = 6, cost = 6
Total = 10
2 + 3 = 5, cost = 5
1 + 5 = 6, cost = 6
Total = 11

I hope you have understood already your mission, to add a set of integers so that the cost is minimal.

Input
Each test case will start with a positive number, N (2 ≤ N ≤ 5000) followed by N positive integers (all are less than 100000). Input is terminated by a case where the value of N is zero. This case should not be processed.

Output
For each case print the minimum total cost of addition in a single line.

Sample Input                           Output for Sample Input
3
1 2 3
4
1 2 3 4
0

9
19

Problem setter: Md. Kamruzzaman, EPS

*/