/* 5197293	 Nov 23, 2013 2:53:02 PM	Shark	 82B - Sets	 GNU C++	Accepted	 30 ms	 0 KB */
#include<stdio.h>
#include<algorithm>
struct data{
	int count;
	int time;
};
void print(int T[], int ptr){
	if (ptr > 0){
		printf("%d", ptr);
		for (int i = 0; i < ptr; i++)
			printf(" %d", T[i]);
		putchar('\n');
	}
}
int main(){
	int n;
	while (scanf("%d", &n) == 1){
		struct data V[201];
		int A[200], ptrA;
		int B[200], ptrB;
		for (int i = 1; i <= 200; i++)
			V[i].count = V[i].time = 0 ;
		for (int i = 0; i < n*(n - 1) / 2; i++){
			int k, tmp, timeMark;
			timeMark = -1;
			ptrA = ptrB = 0;
			scanf("%d", &k);
			for (int j = 0; j < k; j++){
				scanf("%d", &tmp);
				if (V[tmp].count == 0)
					V[tmp].time = i;
				V[tmp].count++;
				if (V[tmp].count == 2 ){
					if (timeMark == -1 || timeMark == V[tmp].time){
						A[ptrA++] = tmp;
						timeMark = V[tmp].time;
					}
					else
						B[ptrB++] = tmp;
				}
			}
			print(A, ptrA);
			print(B, ptrB);
		}
		if (n == 2){ // special test
			int T[200], ptr = 0, k;
			for (k = 1; k <= 200; k++){
				if (V[k].count == 1){
					printf("%d %d\n", 1, k);
					break;
				}
			}
			for (++k; k <= 200; k++){
				if (V[k].count == 1)
					T[ptr++] = k;
			}
			print(T, ptr);
		}
	}
	return 0;
}
/*

B. Sets
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Little Vasya likes very much to play with sets consisting of positive integers. To make the game more interesting, Vasya chose n non-empty sets in such a way, that no two of them have common elements.

One day he wanted to show his friends just how interesting playing with numbers is. For that he wrote out all possible unions of two different sets on n·(n - 1) / 2 pieces of paper. Then he shuffled the pieces of paper. He had written out the numbers in the unions in an arbitrary order.

For example, if n = 4, and the actual sets have the following form {1, 3}, {5}, {2, 4}, {7}, then the number of set pairs equals to six. The six pieces of paper can contain the following numbers:

2, 7, 4.
1, 7, 3;
5, 4, 2;
1, 3, 5;
3, 1, 2, 4;
5, 7.
Then Vasya showed the pieces of paper to his friends, but kept the n sets secret from them. His friends managed to calculate which sets Vasya had thought of in the first place. And how about you, can you restore the sets by the given pieces of paper?

Input
The first input file line contains a number n (2 ≤ n ≤ 200), n is the number of sets at Vasya's disposal. Then follow sets of numbers from the pieces of paper written on n·(n - 1) / 2 lines. Each set starts with the number ki (2 ≤ ki ≤ 200), which is the number of numbers written of the i-th piece of paper, and then follow ki numbers aij (1 ≤ aij ≤ 200). All the numbers on the lines are separated by exactly one space. It is guaranteed that the input data is constructed according to the above given rules from n non-intersecting sets.

Output
Print on n lines Vasya's sets' description. The first number on the line shows how many numbers the current set has. Then the set should be recorded by listing its elements. Separate the numbers by spaces. Each number and each set should be printed exactly once. Print the sets and the numbers in the sets in any order. If there are several answers to that problem, print any of them.

It is guaranteed that there is a solution.

Sample test(s)
input
4
3 2 7 4
3 1 7 3
3 5 4 2
3 1 3 5
4 3 1 2 4
2 5 7
output
1 7
2 2 4
2 1 3
1 5
input
4
5 6 7 8 9 100
4 7 8 9 1
4 7 8 9 2
3 1 6 100
3 2 6 100
2 1 2
output
3 7 8 9
2 6 100
1 1
1 2
input
3
2 1 2
2 1 3
2 2 3
output
1 1
1 2
1 3

*/