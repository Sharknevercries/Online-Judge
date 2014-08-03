/* 5190080	 Nov 22, 2013 12:13:12 PM	Shark	 277A - Learning Languages	 GNU C++	Accepted	30 ms	0 KB */
#include<stdio.h>
#include<string.h>
int n, m;
bool V[100];
bool G[100][100];
void DFS(int start){
	V[start] = true;
	for (int i = 0; i < n; i++){
		if (!V[i]){
			for (int j = 0; j < m; j++){
				if (G[i][j] && G[start][j]){
					DFS(i);
				}
			}
		}
	}
}
int main(){
	while(scanf("%d%d", &n, &m) == 2){
		int ans = 0;
		bool allZero = true;
		memset(V, false, sizeof(V));
		memset(G, false, sizeof(G));
		for (int i = 0; i < n; i++){
			int k;
			scanf("%d", &k);
			for (int j = 0; j < k; j++){
				int tmp;
				scanf("%d", &tmp);
				G[i][tmp-1] = true;
				allZero = false;
			}
		}
		for (int i = 0; i < n; i++){
			if (!V[i]){
				DFS(i);
				ans++;
			}
		}
		if (allZero){
			printf("%d\n", ans);
		}
		else
			printf("%d\n", ans - 1);
	}
	return 0;
}
/*

A.Learning Languages
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
The "BerCorp" company has got n employees.These employees can use m approved official languages for the formal correspondence.The languages are numbered with integers from 1 to m.For each employee we have the list of languages, which he knows.This list could be empty, i.e.an employee may know no official languages.But the employees are willing to learn any number of official languages, as long as the company pays their lessons.A study course in one language for one employee costs 1 berdollar.

Find the minimum sum of money the company needs to spend so as any employee could correspond to any other one(their correspondence can be indirect, i.e.other employees can help out translating).

Input
The first line contains two integers n and m(2 ≤ n, m ≤ 100) — the number of employees and the number of languages.

Then n lines follow — each employee's language list. At the beginning of the i-th line is integer ki (0 ≤ ki ≤ m) — the number of languages the i-th employee knows. Next, the i-th line contains ki integers — aij (1 ≤ aij ≤ m) — the identifiers of languages the i-th employee knows. It is guaranteed that all the identifiers in one list are distinct. Note that an employee may know zero languages.

The numbers in the lines are separated by single spaces.

Output
Print a single integer — the minimum amount of money to pay so that in the end every employee could write a letter to every other one(other employees can help out translating).

Sample test(s)
input
5 5
1 2
2 2 3
2 3 4
2 4 5
1 5
output
0
input
8 7
0
3 1 2 3
1 1
2 5 4
2 6 7
1 3
2 7 4
1 1
output
2
input
2 2
1 2
0
output
1
Note
In the second sample the employee 1 can learn language 2, and employee 8 can learn language 4.

In the third sample employee 2 must learn language 2.

*/