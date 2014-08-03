/* 1273216	 Mar 4, 2012 12:26:48 PM	Shark	 68A - Irrational problem	 GNU C++	Accepted	 30 ms	 1300 K */
#include<stdio.h>
int main(){
	int M[4],a,b;
	while(scanf("%d%d%d%d%d%d",&M[0],&M[1],&M[2],&M[3],&a,&b)==6){
		int min=2e9;
		for(int i=0;i<4;i++)
			if(min>M[i])
				min=M[i];
		int count=0;
		for(int i=a;i<=b;i++)
			if(min>i)
				count++;
		printf("%d\n",count);
	}
	return 0;
}
/*

Little Petya was given this problem for homework:

You are given function  (here  represents the operation of taking the remainder). His task is to count the number of integers x in range [a;b] with property f(x) = x.

It is a pity that Petya forgot the order in which the remainders should be taken and wrote down only 4 numbers. Each of 24 possible orders of taking the remainder has equal probability of being chosen. For example, if Petya has numbers 1, 2, 3, 4 then he can take remainders in that order or first take remainder modulo 4, then modulo 2, 3, 1. There also are 22 other permutations of these numbers that represent orders in which remainder can be taken. In this problem 4 numbers wrote down by Petya will be pairwise distinct.

Now it is impossible for Petya to complete the task given by teacher but just for fun he decided to find the number of integers with property that probability that f(x) = x is not less than 31.4159265352718281828459045%. In other words, Petya will pick up the number x if there exist at least 7 permutations of numbers p1, p2, p3, p4, for which f(x) = x.

Input

First line of the input will contain 6 integers, separated by spaces: p1, p2, p3, p4, a, b (1 ≤ p1, p2, p3, p4 ≤ 1000, 0 ≤ a ≤ b ≤ 31415).

It is guaranteed that numbers p1, p2, p3, p4 will be pairwise distinct.

Output

Output the number of integers in the given range that have the given property.

input

2 7 1 8 2 8
20 30 40 50 0 100
31 41 59 26 17 43

output

0
20
9

*/