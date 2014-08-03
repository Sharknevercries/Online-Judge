/* 5308568	 Nov 30, 2013 4:26:47 AM	Shark	 369B - Valera and Contest	 GNU C++	Accepted	31 ms	0 KB */
#include<stdio.h>
int main(){
	int n, k, L, R, SA, SK;
	while (scanf("%d%d%d%d%d%d", &n, &k, &L, &R, &SA, &SK) == 6){
		int M[1000], ptr = 0, value;
		value = SK / k;
		for (int i = 0; i < SK - k*value; i++)
			M[ptr++] = value + 1;
		for (int i = 0; i < k - (SK - k*value); i++)
			M[ptr++] = value;
		if (n - k>0){
			value = (SA - SK) / (n - k);
			for (int i = 0; i < (SA - SK) - value*(n - k); i++)
				M[ptr++] = value + 1;
			while (ptr < n)
				M[ptr++] = value;
		}
		printf("%d", M[0]);
		for (int i = 1; i < n; i++)
			printf(" %d", M[i]);
		putchar('\n');

		
	}
	return 0;
}
/*

A. Valera and Plates
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Valera is a lazy student. He has m clean bowls and k clean plates.

Valera has made an eating plan for the next n days. As Valera is lazy, he will eat exactly one dish per day. At that, in order to eat a dish, he needs exactly one clean plate or bowl. We know that Valera can cook only two types of dishes. He can eat dishes of the first type from bowls and dishes of the second type from either bowls or plates.

When Valera finishes eating, he leaves a dirty plate/bowl behind. His life philosophy doesn't let him eat from dirty kitchenware. So sometimes he needs to wash his plate/bowl before eating. Find the minimum number of times Valera will need to wash a plate/bowl, if he acts optimally.

Input
The first line of the input contains three integers n, m, k (1 ≤ n, m, k ≤ 1000) — the number of the planned days, the number of clean bowls and the number of clean plates.

The second line contains n integers a1, a2, ..., an (1 ≤ ai ≤ 2). If ai equals one, then on day i Valera will eat a first type dish. If ai equals two, then on day i Valera will eat a second type dish.

Output
Print a single integer — the minimum number of times Valera will need to wash a plate/bowl.

Sample test(s)
input
3 1 1
1 2 1
output
1
input
4 3 1
1 1 1 1
output
1
input
3 1 2
2 2 2
output
0
input
8 2 2
1 2 1 2 1 2 1 2
output
4
Note
In the first sample Valera will wash a bowl only on the third day, so the answer is one.

In the second sample, Valera will have the first type of the dish during all four days, and since there are only three bowls, he will wash a bowl exactly once.

In the third sample, Valera will have the second type of dish for all three days, and as they can be eaten from either a plate or a bowl, he will never need to wash a plate/bowl.

*/