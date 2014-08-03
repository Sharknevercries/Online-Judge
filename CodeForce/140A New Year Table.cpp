/* 4722311	 Oct 10, 2013 9:25:20 AM	Shark	 A - New Year Table	 GNU C++	Accepted	30 ms	0 KB */
#include<stdio.h>
#include<math.h>
#define PI (2*acos(0.0))
int main(){
	int n,r,R;
	while( scanf("%d%d%d",&n,&R,&r)==3 ){
		if( n==1 )
			if( R>=r )
				puts("YES");
			else
				puts("NO");
		else
			if( (R-r)*sin(3.1415926/n)+1e-7<r )
				puts("NO");
			else
				puts("YES");
	}
	return 0;
}
/*

A. New Year Table
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Gerald is setting the New Year table. The table has the form of a circle; its radius equals R. Gerald invited many guests and is concerned whether the table has enough space for plates for all those guests. Consider all plates to be round and have the same radii that equal r. Each plate must be completely inside the table and must touch the edge of the table. Of course, the plates must not intersect, but they can touch each other. Help Gerald determine whether the table is large enough for n plates.

Input
The first line contains three integers n, R and r (1 ≤ n ≤ 100, 1 ≤ r, R ≤ 1000) — the number of plates, the radius of the table and the plates' radius.

Output
Print "YES" (without the quotes) if it is possible to place n plates on the table by the rules given above. If it is impossible, print "NO".

Remember, that each plate must touch the edge of the table.

Sample test(s)
input
4 10 4
output
YES
input
5 10 4
output
NO
input
1 10 10
output
YES
Note
The possible arrangement of the plates for the first sample is:

*/