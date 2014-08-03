/* 4655157	 Oct 4, 2013 12:47:12 PM	Shark	 344A - Magnets	 GNU C++	Accepted	30 ms	0 KB */
#include<stdio.h>
int main(){
	int n;
	while( scanf("%d",&n)==1 ){
		(void) getchar();
		int type=-1,ans=0;
		char str[3];
		for(int i=0;i<n;i++){
			gets(str);
			if( str[0]=='0'&&type==0 )
				continue;
			else if( str[0]=='1'&&type==1 )
				continue;
			else if( str[0]=='1' )
				type=1,ans++;
			else
				type=0,ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*

A. Magnets
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Mad scientist Mike entertains himself by arranging rows of dominoes. He doesn't need dominoes, though: he uses rectangular magnets instead. Each magnet has two poles, positive (a "plus") and negative (a "minus"). If two magnets are put together at a close distance, then the like poles will repel each other and the opposite poles will attract each other.

Mike starts by laying one magnet horizontally on the table. During each following step Mike adds one more magnet horizontally to the right end of the row. Depending on how Mike puts the magnet on the table, it is either attracted to the previous one (forming a group of multiple magnets linked together) or repelled by it (then Mike lays this magnet at some distance to the right from the previous one). We assume that a sole magnet not linked to others forms a group of its own.


Mike arranged multiple magnets in a row. Determine the number of groups that the magnets formed.

Input
The first line of the input contains an integer n (1 ≤ n ≤ 100000) — the number of magnets. Then n lines follow. The i-th line (1 ≤ i ≤ n) contains either characters "01", if Mike put the i-th magnet in the "plus-minus" position, or characters "10", if Mike put the magnet in the "minus-plus" position.

Output
On the single line of the output print the number of groups of magnets.

Sample test(s)
input
6
10
10
10
01
10
10
output
3
input
4
01
01
10
10
output
2
Note
The first testcase corresponds to the figure. The testcase has three groups consisting of three, one and two magnets.

The second testcase has two groups, each consisting of two magnets.

*/