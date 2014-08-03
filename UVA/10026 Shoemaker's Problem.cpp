/* 13850109	10026	Shoemaker's Problem	Accepted	C++	0.015	2014-07-08 08:39:08 */
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	int t;
	scanf("%d", &t);
	while (t--){
		int n, T[1000], S[1000];
		int ans[1000], day = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d%d", T + i, S + i), ans[i] = i;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n - 1; j++){
				if (T[ans[j]] * S[ans[j + 1]] > S[ans[j]] * T[ans[j + 1]])
					swap(ans[j], ans[j + 1]);
				else if (T[ans[j]] * S[ans[j + 1]] == S[ans[j]] * T[ans[j + 1]] && ans[j] > ans[j + 1])
					swap(ans[j], ans[j + 1]);
			}
		}
		printf("%d", ans[0] + 1);
		for (int i = 1; i < n; i++)
			printf(" %d", ans[i] + 1);
		putchar('\n');
		if (t != 0)
			putchar('\n');
	}
	return 0;
}
/*

Shoemaker's Problem

Shoemaker has N jobs (orders from customers) which he must make. Shoemaker can work on only one job in each day. For each ith job, it is known the integer Ti (1<=Ti<=1000), the time in days it takes the shoemaker to finish the job. For each day of delay before starting to work for the ith job, shoemaker must pay a fine of Si (1<=Si<=10000) cents. Your task is to help the shoemaker, writing a programm to find the sequence of jobs with minimal total fine.

The Input

The input begins with a single positive integer on a line by itself indicating the number of the cases following, each of them as described below. This line is followed by a blank line, and there is also a blank line between two consecutive inputs.
First line of input contains an integer N (1<=N<=1000). The next N lines each contain two numbers: the time and fine of each task in order.

The Output

For each test case, the output must follow the description below. The outputs of two consecutive cases will be separated by a blank line.
You programm should print the sequence of jobs with minimal fine. Each job should be represented by its number in input. All integers should be placed on only one output line and separated by one space. If multiple solutions are possible, print the first lexicographically.

Sample Input

1

4
3 4
1 1000
2 2
5 5
Sample Output

2 1 3 4
Alex Gevak
September 16, 2000(Revised 4-10-00, Antonio Sanchez)

*/