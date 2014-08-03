/* 4904638	 Oct 26, 2013 5:00:09 PM	Shark	 358A - Dima and Continuous Line	 GNU C++	Accepted	15 ms	0 KB */
#include<stdio.h>
int main(){
	int n;
	while( scanf("%d",&n)==1 ){
		int S[1000];
		for(int i=0;i<n;i++)
			scanf("%d",&S[i]);
		if( n<=3 )
			puts("no");
		else{
			int i,j;
			bool ans=false;
			for(i=1;i<n;i++)
				for(j=i+2;j<n;j++){
					int x1,x2,x3,x4; // x1<x2 x3<x4
					x1= S[i-1]>S[i]?S[i]:S[i-1];
					x2= S[i-1]<S[i]?S[i]:S[i-1];
					x3= S[j-1]>S[j]?S[j]:S[j-1];
					x4= S[j-1]<S[j]?S[j]:S[j-1];
					if( (x1<x3&&x3<x2&&x2<x4)||(x3<x1&&x1<x4&&x4<x2) )
						ans=true;
				}
			if( ans )
				puts("yes");
			else
				puts("no");
		}
	}
	return 0;
}
/*

A. Dima and Continuous Line
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Dima and Seryozha live in an ordinary dormitory room for two. One day Dima had a date with his girl and he asked Seryozha to leave the room. As a compensation, Seryozha made Dima do his homework.

The teacher gave Seryozha the coordinates of n distinct points on the abscissa axis and asked to consecutively connect them by semi-circus in a certain order: first connect the first point with the second one, then connect the second point with the third one, then the third one with the fourth one and so on to the n-th point. Two points with coordinates (x1, 0) and (x2, 0) should be connected by a semi-circle that passes above the abscissa axis with the diameter that coincides with the segment between points. Seryozha needs to find out if the line on the picture intersects itself. For clarifications, see the picture Seryozha showed to Dima (the left picture has self-intersections, the right picture doesn't have any).


Seryozha is not a small boy, so the coordinates of the points can be rather large. Help Dima cope with the problem.

Input
The first line contains a single integer n (1 ≤ n ≤ 103). The second line contains n distinct integers x1, x2, ..., xn ( - 106 ≤ xi ≤ 106) — the i-th point has coordinates (xi, 0). The points are not necessarily sorted by their x coordinate.

Output
In the single line print "yes" (without the quotes), if the line has self-intersections. Otherwise, print "no" (without the quotes).

Sample test(s)
input
4
0 10 5 15
output
yes
input
4
0 15 5 10
output
no
Note
The first test from the statement is on the picture to the left, the second test is on the picture to the right.

*/