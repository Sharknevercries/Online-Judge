/* 5832439	 Jan 29, 2014 5:46:01 PM	Shark	 384A - Coder	 GNU C++	Accepted	 62 ms	 0 KB */
#include<cstdio>
int main(){
	int n;
	while (scanf("%d", &n) == 1){
		if (n % 2 == 0){
			printf("%d\n", n*n / 2);
			for (int i = 0; i < n; i++){
				for (int j = 0; j < n; j++){
					printf("%c", (i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1) ? 'C' : '.');
				}
				putchar('\n');
			}
		}
		else if (n == 1){
			puts("1");
			puts("C");
		}
		else{
			printf("%d\n", n*n / 2 + 1);
			for (int i = 0; i < n; i++){
				for (int j = 0; j < n; j++){
					printf("%c", (i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1) ? 'C' : '.');
				}
				putchar('\n');
			}
		}
	}
	return 0;
}
/*

A. Coder
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Iahub likes chess very much. He even invented a new chess piece named Coder. A Coder can move (and attack) one square horizontally or vertically. More precisely, if the Coder is located at position (x, y), he can move to (or attack) positions (x + 1, y), (x–1, y), (x, y + 1) and (x, y–1).

Iahub wants to know how many Coders can be placed on an n × n chessboard, so that no Coder attacks any other Coder.

Input
The first line contains an integer n (1 ≤ n ≤ 1000).

Output
On the first line print an integer, the maximum number of Coders that can be placed on the chessboard.

On each of the next n lines print n characters, describing the configuration of the Coders. For an empty cell print an '.', and for a Coder print a 'C'.

If there are multiple correct answers, you can print any.

Sample test(s)
input
2
output
2
C.
.C

*/