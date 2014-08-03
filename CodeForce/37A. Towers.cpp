/* 1214519	 Feb 21, 2012 6:25:19 PM	Shark	 37A - Towers	 GNU C++	Accepted	 30 ms	 1300 KB */
#include<stdio.h>
#include<algorithm>
int main(){
	int n;
	while(scanf("%d",&n)==1){
		int M[1000];
		for(int i=0;i<n;i++)
			scanf("%d",&M[i]);
		std::sort(M,M+n);
		
		int count=1,max=1,len=1;
		for(int i=1;i<n;i++){
			if(M[i]==M[i-1]){
				len++;
				if(len>max)
					max=len;
			}
			else
				len=1,count++;
		}
		printf("%d %d\n",max,count);
	}
	return 0;
}
/*

Little Vasya has received a young builder’s kit. The kit consists of several wooden bars, the lengths of all of them are known. The bars can be put one on the top of the other if their lengths are the same.

Vasya wants to construct the minimal number of towers from the bars. Help Vasya to use the bars in the best way possible.

Input

The first line contains an integer N (1 ≤ N ≤ 1000) — the number of bars at Vasya’s disposal. The second line contains N space-separated integers li — the lengths of the bars. All the lengths are natural numbers not exceeding 1000.

Output

In one line output two numbers — the height of the largest tower and their total number. Remember that Vasya should use all the bars.

input

3
1 2 3
4
6 5 6 7

output

1 3
2 3

*/