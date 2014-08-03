/* 1214439	 Feb 21, 2012 5:58:35 PM	Shark	 127A - Wasted Time	 GNU C++	Accepted	 30 ms	 1300 KB */
#include<stdio.h>
#include<math.h>
struct dot{
	int x,y;
};
double DIST(struct dot A,struct dot B){
	return sqrt((double)(A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));
}
int main(){
	int n,k;
	while(scanf("%d%d",&n,&k)==2){
		struct dot M[100];
		double sum=0;
		for(int i=0;i<n;i++)
			scanf("%d%d",&M[i].x,&M[i].y);
		for(int i=1;i<n;i++)
			sum+=DIST(M[i],M[i-1]);
		printf("%.9lf\n",sum*k/50);
	}
	return 0;
}
/*

Mr. Scrooge, a very busy man, decided to count the time he wastes on all sorts of useless stuff to evaluate the lost profit. He has already counted the time he wastes sleeping and eating. And now Mr. Scrooge wants to count the time he has wasted signing papers.

Mr. Scrooge's signature can be represented as a polyline A1A2... An. Scrooge signs like that: first it places a pen at the point A1, then draws a segment from point A1 to point A2, then he draws a segment from point A2 to point A3 and so on to point An, where he stops signing and takes the pen off the paper. At that the resulting line can intersect with itself and partially repeat itself but Scrooge pays no attention to it and never changes his signing style. As Scrooge makes the signature, he never takes the pen off the paper and his writing speed is constant — 50 millimeters per second.

Scrooge signed exactly k papers throughout his life and all those signatures look the same.

Find the total time Scrooge wasted signing the papers.

Input

The first line contains two integers n and k (2 ≤ n ≤ 100, 1 ≤ k ≤ 1000). Each of the following n lines contains the coordinates of the polyline's endpoints. The i-th one contains coordinates of the point Ai — integers xi and yi, separated by a space.

All points Ai are different. The absolute value of all coordinates does not exceed 20. The coordinates are measured in millimeters.

Output

Print one real number — the total time Scrooges wastes on signing the papers in seconds. The absolute or relative error should not exceed 10 - 6.

input

2 1
0 0
10 0
5 10
3 1
-5 6
-2 -1
3 2
10 0
6 10
5 0
4 0
6 0
3 0
7 0
2 0

output

0.200000000
6.032163204
3.000000000

*/