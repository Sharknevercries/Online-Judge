/* 4568502	 Sep 26, 2013 8:34:24 PM	Shark	 346A - Alice and Bob	 GNU C++	Accepted	30 ms	0 KB */
#include<stdio.h>
int GCD(int a,int b){
	int r;
	do{
		r=a%b;
		a=b;
		b=r;
	}while(r!=0);
	return a;
}
int main(){
	int n;
	int M[100];
	int Big=0;
	int gcd;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&M[i]);
	for(int i=0;i<n;i++)
		if(M[i]>Big)
			Big=M[i];
	gcd=GCD(M[0],M[1]);
	for(int i=1;i<n;i++)
		gcd=GCD(gcd,M[i]);
	if((Big/gcd-n)%2==0)
		puts("Bob");
	else
		puts("Alice");
	return 0;
}
/*

A. Alice and Bob
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
It is so boring in the summer holiday, isn't it? So Alice and Bob have invented a new game to play. The rules are as follows. First, they get a set of n distinct integers. And then they take turns to make the following moves. During each move, either Alice or Bob (the player whose turn is the current) can choose two distinct integers x and y from the set, such that the set doesn't contain their absolute difference |x - y|. Then this player adds integer |x - y| to the set (so, the size of the set increases by one).

If the current player has no valid move, he (or she) loses the game. The question is who will finally win the game if both players play optimally. Remember that Alice always moves first.

Input
The first line contains an integer n (2 ≤ n ≤ 100) — the initial number of elements in the set. The second line contains n distinct space-separated integers a1, a2, ..., an (1 ≤ ai ≤ 109) — the elements of the set.

Output
Print a single line with the winner's name. If Alice wins print "Alice", otherwise print "Bob" (without quotes).

Sample test(s)
input
2
2 3
output
Alice
input
2
5 3
output
Alice
input
3
5 6 7
output
Bob

Note
Consider the first test sample. Alice moves first, and the only move she can do is to choose 2 and 3, then to add 1 to the set. Next Bob moves, there is no valid move anymore, so the winner is Alice.

*/