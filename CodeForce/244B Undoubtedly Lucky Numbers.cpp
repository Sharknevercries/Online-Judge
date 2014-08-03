/* 5023812	 Nov 7, 2013 7:29:45 PM	Shark	 B - Undoubtedly Lucky Numbers	 GNU C++	Accepted	30 ms	1424 KB */
#include<stdio.h>
#include<map>
long long int ans;
int n,a,b;
std::map<int,int> S;
void DFS(long long int value,int length){
	if( value>n||length>10 )	return;
	S[value]++;
	DFS(value*10+a,length+1);
	DFS(value*10+b,length+1);
}
int main(){
	while( scanf("%d",&n)==1 ){
		ans=0;
		for(a=0;a<10;a++)
			for(b=a;b<10;b++)
				DFS(0,0);
		printf("%lld\n",S.size()-1); // delete 0
	}
	return 0;
}
/*

B. Undoubtedly Lucky Numbers
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Polycarpus loves lucky numbers. Everybody knows that lucky numbers are positive integers, whose decimal representation (without leading zeroes) contain only the lucky digits x and y. For example, if x = 4, and y = 7, then numbers 47, 744, 4 are lucky.

Let's call a positive integer a undoubtedly lucky, if there are such digits x and y (0 ≤ x, y ≤ 9), that the decimal representation of number a (without leading zeroes) contains only digits x and y.

Polycarpus has integer n. He wants to know how many positive integers that do not exceed n, are undoubtedly lucky. Help him, count this number.

Input
The first line contains a single integer n (1 ≤ n ≤ 109) — Polycarpus's number.

Output
Print a single integer that says, how many positive integers that do not exceed n are undoubtedly lucky.

Sample test(s)
input
10
output
10
input
123
output
113
Note
In the first test sample all numbers that do not exceed 10 are undoubtedly lucky.

In the second sample numbers 102, 103, 104, 105, 106, 107, 108, 109, 120, 123 are not undoubtedly lucky.

*/