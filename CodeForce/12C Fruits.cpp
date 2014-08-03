/* 5410491	 Dec 11, 2013 8:17:28 PM	Shark	 12C - Fruits	 GNU C++	Accepted	 30 ms	 100 KB */
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<map>
using namespace std;
int main(){
	int n, m;
	while (scanf("%d%d", &n, &m) == 2){
		std::map<string, int> Q;
		int P[100];
		int C[100], count = 0;
		for (int i = 0; i < n; i++)
			scanf("%d", &P[i]);
		for (int i = 0; i < m; i++){
			string tmp;
			cin >> tmp;
			Q[tmp]++;
		}
		for (map<string, int>::iterator it = Q.begin(); it != Q.end(); it++)
			C[count++] = it->second;
		sort(P, P + n);
		sort(C, C + count);
		int min = 0, max = 0;
		for (int i = 0, j = count - 1; j >= 0; i++, j--)
			min += P[i] * C[j];
		for (int i = n - 1, j = count - 1; j >= 0; i--, j--)
			max += P[i] * C[j];
		printf("%d %d\n", min, max);
	}
	return 0;
}
/*

C. Fruits
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
The spring is coming and it means that a lot of fruits appear on the counters. One sunny day little boy Valera decided to go shopping. He made a list of m fruits he wanted to buy. If Valera want to buy more than one fruit of some kind, he includes it into the list several times.

When he came to the fruit stall of Ashot, he saw that the seller hadn't distributed price tags to the goods, but put all price tags on the counter. Later Ashot will attach every price tag to some kind of fruits, and Valera will be able to count the total price of all fruits from his list. But Valera wants to know now what can be the smallest total price (in case of the most «lucky» for him distribution of price tags) and the largest total price (in case of the most «unlucky» for him distribution of price tags).

Input
The first line of the input contains two integer number n and m (1 ≤ n, m ≤ 100) — the number of price tags (which is equal to the number of different kinds of fruits that Ashot sells) and the number of items in Valera's list. The second line contains n space-separated positive integer numbers. Each of them doesn't exceed 100 and stands for the price of one fruit of some kind. The following m lines contain names of the fruits from the list. Each name is a non-empty string of small Latin letters which length doesn't exceed 32. It is guaranteed that the number of distinct fruits from the list is less of equal to n. Also it is known that the seller has in stock all fruits that Valera wants to buy.

Output
Print two numbers a and b (a ≤ b) — the minimum and the maximum possible sum which Valera may need to buy all fruits from his list.

Sample test(s)
input
5 3
4 2 1 10 5
apple
orange
mango
output
7 19
input
6 5
3 5 1 6 8 1
peach
grapefruit
banana
orange
orange
output
11 30

*/