/* 9187179 11764 Jumping Mario Accepted C++ 0.008 2011-08-24 15:19:45 */
#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	for(int t=1;t<=n;t++){
		int s[100];
		int i,j,m;
		scanf("%d",&m);
		for(i=0;i<m;i++)
			scanf("%d",&s[i]);

		int cur=s[0];
		int high,low;
		high=low=0;
		for(i=1;i<m;i++){
			if(cur<s[i])
				high++;
			else if(cur>s[i])
				low++;
			cur=s[i];
		}
		printf("Case %d: %d %d\n",t,high,low);
	}
	return 0;
}
/*

 Mario is in the final castle. He now needs to jump over few walls and then enter the Koopa¡¦s Chamber where he has to defeat the monster in order to save the princess. For this problem, we are only concerned with the ¡§jumping over the wall¡¨ part. You will be given the heights of N walls from left to right. Mario is currently standing on the first wall. He has to jump to the adjacent walls one after another until he reaches the last one. That means, he will make (N-1) jumps. A high jump is one where Mario has to jump to a taller wall, and similarly, a low jump is one where Mario has to jump to a shorter wall. Can you find out the total number of high jumps and low jumps Mario has to make?
 
Input

The first line of input is an integer T (T < 30) that indicates the number of test cases. Each case starts with an integer N (0 < N < 50) that determines the number of walls. The next line gives the height of the N walls from left to right. Each height is a positive integer not exceeding 10.

Output 

For each case, output the case number followed by 2 integers, total high jumps and total low jumps, respectively. Look at the sample for exact format.

Sample Input                            

3
8
1 4 2 2 3 5 3 4
1
9
5
1 2 3 4 5
 
Output for Sample Input

Case 1: 4 2
Case 2: 0 0
Case 3: 4 0
 
--------------------------------------------------------------------------------

Problemsetter: Sohel Hafiz

Special Thanks: Shamim Hafiz 

*/