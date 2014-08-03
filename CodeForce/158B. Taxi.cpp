/* 1290740	 Mar 5, 2012 5:20:50 PM	Shark	 158B - Taxi	 GNU C++	Accepted	 60 ms	 1300 KB */
#include<stdio.h>
int main(){
	int n;
	while(scanf("%d",&n)==1){
		int count[4]={0},group;
		for(int i=0;i<n;i++){
			int temp;
			scanf("%d",&temp);
			count[temp-1]++;
		}

		group=0;
		group+=count[3];
		group+=count[2];
		count[0] = count[0]-count[2]>=0 ? count[0]-count[2] : 0 ;
		if((count[1]&1)==1){
			group+=count[1]/2+1;
			count[0] = count[0]-2>=0 ? count[0]-2 : 0 ;
		}
		else
			group+=count[1]/2;
		if(count[0]%4==0)
			group+=count[0]/4;
		else
			group+=count[0]/4+1;
		printf("%d\n",group);
	}
	return 0;
}
/*

After the lessons n groups of schoolchildren went outside and decided to visit Polycarpus to celebrate his birthday. We know that the i-th group consists of si friends (1 ≤ si ≤ 4), and they want to go to Polycarpus together. They decided to get there by taxi. Each car can carry at most four passengers. What minimum number of cars will the children need if all members of each group should ride in the same taxi (but one taxi can take more than one group)?

Input

The first line contains integer n (1 ≤ n ≤ 105) — the number of groups of schoolchildren. The second line contains a sequence of integers s1, s2, ..., sn (1 ≤ si ≤ 4). The integers are separated by a space, si is the number of children in the i-th group.

Output

Print the single number — the minimum number of taxis necessary to drive all children to Polycarpus.

input

5
1 2 4 3 3
8
2 3 4 4 2 1 3 1

output

4
5

Note

In the first test we can sort the children into four cars like this:

the third group (consisting of four children),
the fourth group (consisting of three children),
the fifth group (consisting of three children),
the first and the second group (consisting of one and two children, correspondingly).
There are other ways to sort the groups into four cars.

*/