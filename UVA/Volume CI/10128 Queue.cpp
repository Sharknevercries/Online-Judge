/* 15257380	10128	Queue	Accepted	C++	0.022	2015-04-02 05:17:30 */
#include<bits\stdc++.h>
using namespace std;
long long DP[15][105][105] = { 0 };
int main(){
	DP[1][1][1] = 1;
	for (int i = 1; i <= 13; i++){
		for (int j = 1; j <= 13; j++){
			for (int k = 1; k <= 13; k++){
				DP[i + 1][j + 1][k] += DP[i][j][k];
				DP[i + 1][j][k + 1] += DP[i][j][k];
				if (i - 1 >= 0)
					DP[i + 1][j][k] += DP[i][j][k] * (i - 1);
			}
		}
	}
	int t;
	scanf("%d", &t);
	while (t--){
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		printf("%lld\n", DP[a][b][c]);
	}
	return 0;
}
/*

There is a queue with N people. Every person has a different heigth. We can see P people, when we
are looking from the beginning, and R people, when we are looking from the end. Its because they
are having different height and they are covering each other. How many different permutations of our
queue has such a interesting feature?
Input
The input consists of T test cases. The number of them (1 ≤ T ≤ 10000) is given on the first line of
the input file.
Each test case begins with a line containing a single integer number N that indicates the number
of people in a queue (1 ≤ N ≤ 13). Then follows line containing two integers. The first integer
corresponds to the number of people, that we can see looking from the beginning. The second integer
corresponds to the number of people, that we can see looking from the end.
Output
For every test case your program has to determine one integer. Print how many permutations of N
people we can see exactly P people from the beginning, and R people, when we are looking from the
end.
Sample Input
3
10 4 4
11 3 1
3 1 2
Sample Output
90720
1026576
1

*/