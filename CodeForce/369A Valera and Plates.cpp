/* 5271000	 Nov 27, 2013 3:05:55 PM	Shark	 365A - Good Number	 GNU C++	Accepted	 15 ms	 0 KB */
#include<stdio.h>
int main(){
	int n, m, k;
	while (scanf("%d%d%d", &n, &m, &k) == 3){
		int type1, type2, ans;
		type1 = type2 = ans = 0;
		for (int i = 0; i < n; i++){
			int tmp;
			scanf("%d", &tmp);
			if (tmp == 1)
				type1++;
			if (tmp == 2)
				type2++;
		}
		if (type1>m)
			ans += type1 - m, m = 0;
		else
			m -= type1;
		if (type2 > m + k)
			ans += type2 - m - k;
		printf("%d\n", ans);
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