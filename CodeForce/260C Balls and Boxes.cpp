/* 4987843	 Nov 4, 2013 9:06:31 PM	Shark	 260C - Balls and Boxes	 GNU C++	Accepted	62 ms	 */
#include<stdio.h>
int main(){
	int n,k;
	while( scanf("%d%d",&n,&k)==2 ){
		long long int M[100000],ptr,count=0,min=2e9;
		for(int i=0;i<n;i++)
			scanf("%lld",&M[i]);
		for(int i=0;i<n;i++)
			if( min>=M[i] )
				min=M[i];
		for(int i=0;i<n;i++)
			M[i]-=min;
		count+=min*n;
		ptr=k-1;

		while( M[ptr]>0 ){
			M[ptr]--,count++;
			ptr--;
			if( ptr<0 )
				ptr=n-1;
		}
		M[ptr]=count;
		printf("%lld",M[0]);
		for(int i=1;i<n;i++)
			printf(" %lld",M[i]);
		putchar('\n');
	}
	return 0;
}
/*

C. Balls and Boxes
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Little Vasya had n boxes with balls in the room. The boxes stood in a row and were numbered with numbers from 1 to n from left to right.

Once Vasya chose one of the boxes, let's assume that its number is i, took all balls out from it (it is guaranteed that this box originally had at least one ball), and began putting balls (one at a time) to the boxes with numbers i + 1, i + 2, i + 3 and so on. If Vasya puts a ball into the box number n, then the next ball goes to box 1, the next one goes to box 2 and so on. He did it until he had no balls left in his hands. It is possible that Vasya puts multiple balls to the same box, and it is also possible that one or more balls will go to the box number i. If i = n, Vasya puts the first ball into the box number 1, then the next ball goes to box 2 and so on.

For example, let's suppose that initially Vasya had four boxes, and the first box had 3 balls, the second one had 2, the third one had 5 and the fourth one had 4 balls. Then, if i = 3, then Vasya will take all five balls out of the third box and put them in the boxes with numbers: 4, 1, 2, 3, 4. After all Vasya's actions the balls will lie in the boxes as follows: in the first box there are 4 balls, 3 in the second one, 1 in the third one and 6 in the fourth one.

At this point Vasya has completely forgotten the original arrangement of the balls in the boxes, but he knows how they are arranged now, and the number x — the number of the box, where he put the last of the taken out balls.

He asks you to help to find the initial arrangement of the balls in the boxes.

Input
The first line of the input contains two integers n and x (2 ≤ n ≤ 105, 1 ≤ x ≤ n), that represent the number of the boxes and the index of the box that got the last ball from Vasya, correspondingly. The second line contains n space-separated integers a1, a2, ..., an, where integer ai (0 ≤ ai ≤ 109, ax ≠ 0) represents the number of balls in the box with index i after Vasya completes all the actions.

Please, do not use the %lld specifier to read or write 64-bit integers in С++. It is preferred to use the cin, cout streams or the %I64d specifier.

Output
Print n integers, where the i-th one represents the number of balls in the box number i before Vasya starts acting. Separate the numbers in the output by spaces. If there are multiple correct solutions, you are allowed to print any of them.

Sample test(s)
input
4 4
4 3 1 6
output
3 2 5 4 
input
5 2
3 2 0 2 7
output
2 1 4 1 6 
input
3 3
2 3 1
output
1 2 3 

*/