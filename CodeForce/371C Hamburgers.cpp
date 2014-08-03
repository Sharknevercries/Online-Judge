/* 5386913	 Dec 8, 2013 2:34:31 PM	Shark	 371C - Hamburgers	 GNU C++	Accepted	 15 ms	 0 KB */
#include<stdio.h>
#include<string.h>
int craft[3];
int own[3];
int P[3];
long long int money;
int make(){
	int min = 2e9;
	int ans[3] = { 0 };
	for (int i = 0; i < 3; i++){
		if (own[i] < craft[i] && (craft[i] - own[i])*P[i] <= money){
			money -= (craft[i] - own[i])*P[i];
			own[i] = craft[i];
		}
		ans[i] = craft[i] == 0 ? 2e9 : own[i] / craft[i];
	}
	for (int i = 0; i < 3; i++){
		if (min > ans[i])
			min = ans[i];
	}
	for (int i = 0; i < 3; i++)
		own[i] -= craft[i] * min;
	return min;
}
int main(){
	char S[105];
	while (scanf("%s", S) == 1){
		long long int ans = 0;
		craft[0] = craft[1] = craft[2] = 0;
		for (int i = 0; S[i] != '\0'; i++){
			if (S[i] == 'B')	craft[0]++;
			if (S[i] == 'S')	craft[1]++;
			if (S[i] == 'C')	craft[2]++;
		}
		for (int i = 0; i < 3; i++)
			scanf("%d", &own[i]);
		for (int i = 0; i < 3; i++)
			scanf("%d", &P[i]);
		for (int i = 0; i<3; i++){
			if (craft[i] == 0)
				own[i] = 0;
		}

		scanf("%lld", &money);
		while (!(own[0] == 0 && own[1] == 0 && own[2] == 0)){
			int result = make();
			if (result>0)
				ans += result;
			else
				break;
		}
		ans += money / (craft[0] * P[0] + craft[1] * P[1] + craft[2] * P[2]);
		printf("%lld\n", ans);
	}
	return 0;
}
/*

C. Hamburgers
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Polycarpus loves hamburgers very much. He especially adores the hamburgers he makes with his own hands. Polycarpus thinks that there are only three decent ingredients to make hamburgers from: a bread, sausage and cheese. He writes down the recipe of his favorite "Le Hamburger de Polycarpus" as a string of letters 'B' (bread), 'S' (sausage) и 'C' (cheese). The ingredients in the recipe go from bottom to top, for example, recipe "ВSCBS" represents the hamburger where the ingredients go from bottom to top as bread, sausage, cheese, bread and sausage again.

Polycarpus has nb pieces of bread, ns pieces of sausage and nc pieces of cheese in the kitchen. Besides, the shop nearby has all three ingredients, the prices are pb rubles for a piece of bread, ps for a piece of sausage and pc for a piece of cheese.

Polycarpus has r rubles and he is ready to shop on them. What maximum number of hamburgers can he cook? You can assume that Polycarpus cannot break or slice any of the pieces of bread, sausage or cheese. Besides, the shop has an unlimited number of pieces of each ingredient.

Input
The first line of the input contains a non-empty string that describes the recipe of "Le Hamburger de Polycarpus". The length of the string doesn't exceed 100, the string contains only letters 'B' (uppercase English B), 'S' (uppercase English S) and 'C' (uppercase English C).

The second line contains three integers nb, ns, nc (1 ≤ nb, ns, nc ≤ 100) — the number of the pieces of bread, sausage and cheese on Polycarpus' kitchen. The third line contains three integers pb, ps, pc (1 ≤ pb, ps, pc ≤ 100) — the price of one piece of bread, sausage and cheese in the shop. Finally, the fourth line contains integer r (1 ≤ r ≤ 1012) — the number of rubles Polycarpus has.

Please, do not write the %lld specifier to read or write 64-bit integers in С++. It is preferred to use the cin, cout streams or the %I64d specifier.

Output
Print the maximum number of hamburgers Polycarpus can make. If he can't make any hamburger, print 0.

Sample test(s)
input
BBBSSC
6 4 1
1 2 3
4
output
2
input
BBC
1 10 1
1 10 1
21
output
7
input
BSC
1 1 1
1 1 3
1000000000000
output
200000000001

*/