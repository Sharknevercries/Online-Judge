/* 5206101	 Nov 24, 2013 9:57:16 AM	Shark	 43C - Lucky Tickets	 GNU C++	Accepted	30 ms	0 KB */
#include<stdio.h>
#define MIN(x,y)	( (x) >= (y) ? (y) : (x) )
int main(){
	int n;
	while (scanf("%d", &n) == 1){
		int M[3] = { 0 };
		int ans = 0;
		bool V[10000] = { false };
		for (int i = 0; i < n; i++){
			int tmp;
			scanf("%d", &tmp);
			M[tmp % 3]++;
		}
		ans += M[0] / 2;
		ans += MIN(M[1], M[2]);
		printf("%d\n", ans);
	}
	return 0;
}
/*

C. Lucky Tickets
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Vasya thinks that lucky tickets are the tickets whose numbers are divisible by 3. He gathered quite a large collection of such tickets but one day his younger brother Leonid was having a sulk and decided to destroy the collection. First he tore every ticket exactly in two, but he didn’t think it was enough and Leonid also threw part of the pieces away. Having seen this, Vasya got terrified but still tried to restore the collection. He chose several piece pairs and glued each pair together so that each pair formed a lucky ticket. The rest of the pieces Vasya threw away reluctantly. Thus, after the gluing of the 2t pieces he ended up with t tickets, each of which was lucky.

When Leonid tore the tickets in two pieces, one piece contained the first several letters of his number and the second piece contained the rest.

Vasya can glue every pair of pieces in any way he likes, but it is important that he gets a lucky ticket in the end. For example, pieces 123 and 99 can be glued in two ways: 12399 and 99123.

What maximum number of tickets could Vasya get after that?

Input
The first line contains integer n (1 ≤ n ≤ 104) — the number of pieces. The second line contains n space-separated numbers ai (1 ≤ ai ≤ 108) — the numbers on the pieces. Vasya can only glue the pieces in pairs. Even if the number of a piece is already lucky, Vasya should glue the piece with some other one for it to count as lucky. Vasya does not have to use all the pieces. The numbers on the pieces an on the resulting tickets may coincide.

Output
Print the single number — the maximum number of lucky tickets that will be able to be restored. Don't forget that every lucky ticket is made of exactly two pieces glued together.

Sample test(s)
input
3
123 123 99
output
1
input
6
1 1 1 23 10 3
output
1

*/