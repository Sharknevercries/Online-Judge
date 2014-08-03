/* 4676976	 Oct 5, 2013 7:24:07 AM	Shark	 190A - Vasya and the Bus	 GNU C++	Accepted	30 ms	0 KB */
#include<stdio.h>
int main(){
	int n,m;
	while( scanf("%d%d",&n,&m)==2 ){
		if( n==0&&m>0 )
			puts("Impossible");
		else if( n==0&&m==0 )
			puts("0 0");
		else{
			int min,max;
			if( m!=0 )
				if( n>=m )
					min=n,max=n+m-1;
				else
					min=m,max=n+m-1;
			else
				min=max=n;
			printf("%d %d\n",min,max);
		}
	}
	return 0;
}
/*

A. Vasya and the Bus
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
One day Vasya heard a story: "In the city of High Bertown a bus number 62 left from the bus station. It had n grown-ups and m kids..."

The latter events happen to be of no importance to us. Vasya is an accountant and he loves counting money. So he wondered what maximum and minimum sum of money these passengers could have paid for the ride.

The bus fare equals one berland ruble in High Bertown. However, not everything is that easy — no more than one child can ride for free with each grown-up passenger. That means that a grown-up passenger who rides with his k (k > 0) children, pays overall k rubles: a ticket for himself and (k - 1) tickets for his children. Also, a grown-up can ride without children, in this case he only pays one ruble.

We know that in High Bertown children can't ride in a bus unaccompanied by grown-ups.

Help Vasya count the minimum and the maximum sum in Berland rubles, that all passengers of this bus could have paid in total.

Input
The input file consists of a single line containing two space-separated numbers n and m (0 ≤ n, m ≤ 105) — the number of the grown-ups and the number of the children in the bus, correspondingly.

Output
If n grown-ups and m children could have ridden in the bus, then print on a single line two space-separated integers — the minimum and the maximum possible total bus fare, correspondingly.

Otherwise, print "Impossible" (without the quotes).

Sample test(s)
input
1 2
output
2 2
input
0 5
output
Impossible
input
2 2
output
2 3
Note
In the first sample a grown-up rides with two children and pays two rubles.

In the second sample there are only children in the bus, so the situation is impossible.

In the third sample there are two cases:
Each of the two grown-ups rides with one children and pays one ruble for the tickets. In this case the passengers pay two rubles in total.
One of the grown-ups ride with two children's and pays two rubles, the another one rides alone and pays one ruble for himself. So, they pay three rubles in total.

*/