/* 4968832	 Nov 2, 2013 2:52:07 PM	Shark	 245D - Restoring Table	 GNU C++	Accepted	30 ms	0 KB */
#include<stdio.h>
int main(){
	int n;
	while( scanf("%d",&n)==1 ){
		int M[100][100];
		int ans[100]={0};
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				scanf("%d",&M[i][j]);
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
				ans[i]|=M[i][j],ans[j]|=M[i][j];
		printf("%d",ans[0]);
		for(int i=1;i<n;i++)
			printf(" %d",ans[i]);
		putchar('\n');
	}
	return 0;
}
/*

D. Restoring Table
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Recently Polycarpus has learned the "bitwise AND" operation (which is also called "AND") of non-negative integers. Now he wants to demonstrate the school IT teacher his superb manipulation with the learned operation.

For that Polycarpus came to school a little earlier and wrote on the board a sequence of non-negative integers a1, a2, ..., an. He also wrote a square matrix b of size n × n. The element of matrix b that sits in the i-th row in the j-th column (we'll denote it as bij) equals:

the "bitwise AND" of numbers ai and aj (that is, bij = ai & aj), if i ≠ j;
-1, if i = j.
Having written out matrix b, Polycarpus got very happy and wiped a off the blackboard. But the thing is, the teacher will want this sequence to check whether Polycarpus' calculations were correct. Polycarus urgently needs to restore the removed sequence of integers, or else he won't prove that he can count correctly.

Help Polycarpus, given matrix b, restore the sequence of numbers a1, a2, ..., an, that he has removed from the board. Polycarpus doesn't like large numbers, so any number in the restored sequence mustn't exceed 109.

Input
The first line contains a single integer n (1 ≤ n ≤ 100) — the size of square matrix b. Next n lines contain matrix b. The i-th of these lines contains n space-separated integers: the j-th number represents the element of matrix bij. It is guaranteed, that for all i (1 ≤ i ≤ n) the following condition fulfills: bii = -1. It is guaranteed that for all i, j (1 ≤ i, j ≤ n; i ≠ j) the following condition fulfills: 0 ≤ bij ≤ 109, bij = bji.

Output
Print n non-negative integers a1, a2, ..., an (0 ≤ ai ≤ 109) — the sequence that Polycarpus wiped off the board. Separate the numbers by whitespaces.

It is guaranteed that there is sequence a that satisfies the problem conditions. If there are multiple such sequences, you are allowed to print any of them.

Sample test(s)
input
1
-1
output
0 
input
3
-1 18 0
18 -1 0
0 0 -1
output
18 18 0 
input
4
-1 128 128 128
128 -1 148 160
128 148 -1 128
128 160 128 -1
output
128 180 148 160 
Note
If you do not know what is the "bitwise AND" operation please read: http://en.wikipedia.org/wiki/Bitwise_operation.

*/