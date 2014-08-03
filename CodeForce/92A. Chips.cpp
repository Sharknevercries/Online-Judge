/* 1216209	 Feb 22, 2012 6:35:07 PM	Shark	 92A - Chips	 GNU C++	Accepted	 30 ms	 1300 KB */
#include<stdio.h>
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)==2){
		while(true){
			int i;
			for(i=1;i<=n;i++)
				if((i+1)*i/2>m)
					break;
			i--;
			m-=(i+1)*i/2;
			if(i<n)
				break;
		}
		printf("%d\n",m);
	}
	return 0;
}
/*

There are n walruses sitting in a circle. All of them are numbered in the clockwise order: the walrus number 2 sits to the left of the walrus number 1, the walrus number 3 sits to the left of the walrus number 2, ..., the walrus number 1 sits to the left of the walrus number n.

The presenter has m chips. The presenter stands in the middle of the circle and starts giving the chips to the walruses starting from walrus number 1 and moving clockwise. The walrus number i gets i chips. If the presenter can't give the current walrus the required number of chips, then the presenter takes the remaining chips and the process ends. Determine by the given n and m how many chips the presenter will get in the end.

Input

The first line contains two integers n and m (1 ≤ n ≤ 50, 1 ≤ m ≤ 104) — the number of walruses and the number of chips correspondingly.

Output

Print the number of chips the presenter ended up with.

input
4 11
17 107
3 8

output

0
2
1

Note

In the first sample the presenter gives one chip to the walrus number 1, two chips to the walrus number 2, three chips to the walrus number 3, four chips to the walrus number 4, then again one chip to the walrus number 1. After that the presenter runs out of chips. He can't give anything to the walrus number 2 and the process finishes.

In the third sample the presenter gives one chip to the walrus number 1, two chips to the walrus number 2, three chips to the walrus number 3, then again one chip to the walrus number 1. The presenter has one chip left and he can't give two chips to the walrus number 2, that's why the presenter takes the last chip.

*/