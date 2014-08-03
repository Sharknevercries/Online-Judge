/* 5234303	 Nov 25, 2013 1:24:21 PM	Shark	 366C - Dima and Salad	 GNU C++	Accepted	 15 ms	 0 KB */
#include<stdio.h>
struct data{
	int A, B;
};
int main(){
	int n, k;
	while (scanf("%d%d", &n, &k) == 2){
		struct data T[100];
		int DP[3001]; // DP[1500] => gap=0
		for (int i = 0; i < n; i++)
			scanf("%d", &T[i].A);
		for (int i = 0; i < n; i++)
			scanf("%d", &T[i].B);
		for (int i = 0; i < n; i++)
			T[i].B *= k;
		for (int i = 0; i <= 3000; i++)
			DP[i] = -2e9;
		DP[1500] = 0;
		for (int i = 0; i < n; i++){
			int G = T[i].A - T[i].B; // gap
			if (G>=0){
				for (int j = 0; j + G <= 3000; j++){
					if (DP[j + G] + T[i].A>DP[j])
						DP[j] = DP[j + G] + T[i].A;
				}
			}
			else{
				for (int j = 3000; j + G >= 0; j--){
					if (DP[j + G] + T[i].A > DP[j])
						DP[j] = DP[j + G] + T[i].A;
				}
			}
		}
		printf("%d\n", DP[1500] == 0 ? -1 : DP[1500]);
	}
	return 0;
}
/*

C. Dima and Salad
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Dima, Inna and Seryozha have gathered in a room. That's right, someone's got to go. To cheer Seryozha up and inspire him to have a walk, Inna decided to cook something.

Dima and Seryozha have n fruits in the fridge. Each fruit has two parameters: the taste and the number of calories. Inna decided to make a fruit salad, so she wants to take some fruits from the fridge for it. Inna follows a certain principle as she chooses the fruits: the total taste to the total calories ratio of the chosen fruits must equal k. In other words,  , where aj is the taste of the j-th chosen fruit and bj is its calories.

Inna hasn't chosen the fruits yet, she is thinking: what is the maximum taste of the chosen fruits if she strictly follows her principle? Help Inna solve this culinary problem — now the happiness of a young couple is in your hands!

Inna loves Dima very much so she wants to make the salad from at least one fruit.

Input
The first line of the input contains two integers n, k (1 ≤ n ≤ 100, 1 ≤ k ≤ 10). The second line of the input contains n integers a1, a2, ..., an (1 ≤ ai ≤ 100) — the fruits' tastes. The third line of the input contains n integers b1, b2, ..., bn (1 ≤ bi ≤ 100) — the fruits' calories. Fruit number i has taste ai and calories bi.

Output
If there is no way Inna can choose the fruits for the salad, print in the single line number -1. Otherwise, print a single integer — the maximum possible sum of the taste values of the chosen fruits.

Sample test(s)
input
3 2
10 8 1
2 7 1
output
18
input
5 3
4 4 4 4 4
2 2 2 2 2
output
-1
Note
In the first test sample we can get the total taste of the fruits equal to 18 if we choose fruit number 1 and fruit number 2, then the total calories will equal 9. The condition  fulfills, that's exactly what Inna wants.

In the second test sample we cannot choose the fruits so as to follow Inna's principle.

*/