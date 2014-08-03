/* 4803482	 Oct 16, 2013 11:43:21 AM	Shark	 337B - Routine Problem	 GNU C++	Accepted	30 ms	0 KB */
#include<stdio.h>
#include<math.h>
int GCD(int a,int b){
	int r;
	do{
		r=a%b;
		a=b;
		b=r;
	}while( r!=0 );
	return a;
}
int main(){
	int a,b,c,d;
	while( scanf("%d%d%d%d",&a,&b,&c,&d)==4 ){
		int mother,son;
		if( a*d>b*c )
			mother=a*d,son=a*d-b*c;
		else
			mother=b*c,son=b*c-a*d;
		
		if( son==0 ) // screens' ratio are the same
			printf("0/1\n");
		else{
			int gcd=GCD(mother,son);
			mother/=gcd,son/=gcd;
			printf("%d/%d\n",son,mother);
		}
	}
	return 0;
}
/*

B. Routine Problem
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Manao has a monitor. The screen of the monitor has horizontal to vertical length ratio a:b. Now he is going to watch a movie. The movie's frame has horizontal to vertical length ratio c:d. Manao adjusts the view in such a way that the movie preserves the original frame ratio, but also occupies as much space on the screen as possible and fits within it completely. Thus, he may have to zoom the movie in or out, but Manao will always change the frame proportionally in both dimensions.

Calculate the ratio of empty screen (the part of the screen not occupied by the movie) to the total screen size. Print the answer as an irreducible fraction p / q.

Input
A single line contains four space-separated integers a, b, c, d (1 ≤ a, b, c, d ≤ 1000).

Output
Print the answer to the problem as "p/q", where p is a non-negative integer, q is a positive integer and numbers p and q don't have a common divisor larger than 1.

Sample test(s)
input
1 1 3 2
output
1/3
input
4 3 2 2
output
1/4
Note
Sample 1. Manao's monitor has a square screen. The movie has 3:2 horizontal to vertical length ratio. Obviously, the movie occupies most of the screen if the width of the picture coincides with the width of the screen. In this case, only 2/3 of the monitor will project the movie in the horizontal dimension: 

Sample 2. This time the monitor's width is 4/3 times larger than its height and the movie's frame is square. In this case, the picture must take up the whole monitor in the vertical dimension and only 3/4 in the horizontal dimension: 

*/