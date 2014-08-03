/* 5199107	 Nov 23, 2013 7:52:04 PM	Shark	 85A - Domino	 GNU C++	Accepted	30 ms	0 KB */
#include<stdio.h>
char T[100][101];
int n;
void change(char *c){
	(*c)++;
	if ((*c) > 'z')
		(*c) = 'a';
}
void print(){
	for (int i = 0; i < 4; i++){
		T[i][n] = '\0';
		printf("%s\n", T[i]);
	}
}
int main(){	
	while (scanf("%d", &n) == 1){
		char alpha = 'a';
		if (n == 1){
			T[0][0] = T[1][0] = alpha;
			change(&alpha);
			T[2][0] = T[3][0] = alpha;
			change(&alpha);
			print();
		}
		else if (n == 2){
			for (int i = 0; i < 4; i++){
				T[i][0] = T[i][1] = alpha;
				change(&alpha);
			}
			print();
		}
		else if (n % 2 == 0){
			T[0][0] = T[0][1] = alpha;
			change(&alpha);
			T[1][0] = T[2][0] = alpha;
			change(&alpha);
			T[3][0] = T[3][1] = alpha;
			change(&alpha);
			for (int i = 2; i < n; i += 2){
				T[0][i] = T[0][i + 1] = alpha;
				change(&alpha);
				T[1][i - 1] = T[1][i] = alpha;
				change(&alpha);
				T[2][i - 1] = T[2][i] = alpha;
				change(&alpha);
				T[3][i] = T[3][i + 1] = alpha;
				change(&alpha);
			}
			T[1][n - 1] = T[2][n - 1] = alpha;
			print();
		}
		else{
			T[2][0] = T[3][0] = alpha;
			change(&alpha);
			for (int i = 0; i < n-1; i+=2){
				T[0][i] = T[0][i + 1] = alpha;
				change(&alpha);
				T[1][i] = T[1][i + 1] = alpha;
				change(&alpha);
				T[2][i + 1] = T[2][i + 2] = alpha;
				change(&alpha);
				T[3][i + 1] = T[3][i + 2] = alpha;
				change(&alpha);
			}
			T[0][n - 1] = T[1][n - 1] = alpha;
			change(&alpha);
			print();
		}
	}
	return 0;
}
/*

A. Domino
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
We all know the problem about the number of ways one can tile a 2 × n field by 1 × 2 dominoes. You probably remember that it goes down to Fibonacci numbers. We will talk about some other problem below, there you also are going to deal with tiling a rectangular field with dominoes.

You are given a 4 × n rectangular field, that is the field that contains four lines and n columns. You have to find for it any tiling by 1 × 2 dominoes such that each of the n - 1 potential vertical cuts along the grid lines intersects at least one domino, splitting it in two. No two dominoes in the sought tiling should overlap, each square of the field should be covered by exactly one domino. It is allowed to rotate the dominoes, that is, you can use 2 × 1 as well as 1 × 2 dominoes.

Write a program that finds an arbitrary sought tiling.

Input
The input contains one positive integer n (1 ≤ n ≤ 100) — the number of the field's columns.

Output
If there's no solution, print "-1" (without the quotes). Otherwise, print four lines containing n characters each — that's the description of tiling, where each vertical cut intersects at least one domino. You should print the tiling, having painted the field in no more than 26 colors. Each domino should be painted a color. Different dominoes can be painted the same color, but dominoes of the same color should not be side-neighbouring. To indicate colors you should use lowercase Latin letters. Print any of the acceptable ways of tiling.

Sample test(s)
input
4
output
yyzz
bccd
bxxd
yyaa

*/