/* 1214392	 Feb 21, 2012 5:41:25 PM	Shark	 124A - The number of positions	 GNU C++	Accepted	 30 ms	 1300 KB */
#include<stdio.h>
int main(){
	int n,a,b;
	while(scanf("%d%d%d",&n,&a,&b)==3){
		int ans=n;
		ans-=a;
		if(b+1<ans)
			ans=b+1;
		printf("%d\n",ans);
	}
	return 0;
}
/*

Petr stands in line of n people, but he doesn't know exactly which position he occupies. He can say that there are no less than a people standing in front of him and no more than b people standing behind him. Find the number of different positions Petr can occupy.

Input

The only line contains three integers n, a and b (0 ≤ a, b < n ≤ 100).

Output

Print the single number — the number of the sought positions.

input

3 1 1
5 2 3

output

2
3

Note

The possible positions in the first sample are: 2 and 3 (if we number the positions starting with 1).

In the second sample they are 3, 4 and 5.

*/