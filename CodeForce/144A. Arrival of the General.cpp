/* 1205621	 Feb 20, 2012 4:52:42 PM	Shark	 144A - Arrival of the General	 GNU C++	Accepted	 30 ms	 1300 KB */
#include<stdio.h>
#include<string.h>
int main(){
	int n;
	while(scanf("%d",&n)==1){
		int M[100];
		int max,min;
		for(int i=0;i<n;i++)
			scanf("%d",&M[i]);
		max=0,min=2e9;
		for(int i=0;i<n;i++){
			if(M[i]>max)
				max=M[i];
			if(min>M[i])
				min=M[i];
		}
		int ptr,count=0;
		for(ptr=0;ptr<n;ptr++)
			if(M[ptr]==max){
				count+=ptr;
				memmove(&M[1],&M[0],sizeof(int)*ptr);
				M[0]=max;
				break;
			}
		for(ptr=n-1;ptr>=0;ptr--)
			if(M[ptr]==min){
				count+=n-1-ptr;
				break;
			}
		printf("%d\n",count);
	}
	return 0;
}
/*

A Ministry for Defense sent a general to inspect the Super Secret Military Squad under the command of the Colonel SuperDuper. Having learned the news, the colonel ordered to all n squad soldiers to line up on the parade ground.

By the military charter the soldiers should stand in the order of non-increasing of their height. But as there's virtually no time to do that, the soldiers lined up in the arbitrary order. However, the general is rather short-sighted and he thinks that the soldiers lined up correctly if the first soldier in the line has the maximum height and the last soldier has the minimum height. Please note that the way other solders are positioned does not matter, including the case when there are several soldiers whose height is maximum or minimum. Only the heights of the first and the last soldier are important.

For example, the general considers the sequence of heights (4, 3, 4, 2, 1, 1) correct and the sequence (4, 3, 1, 2, 2) wrong.

Within one second the colonel can swap any two neighboring soldiers. Help him count the minimum time needed to form a line-up which the general will consider correct.

Input

The first input line contains the only integer n (2 ≤ n ≤ 100) which represents the number of soldiers in the line. The second line contains integers a1, a2, ..., an (1 ≤ ai ≤ 100) the values of the soldiers' heights in the order of soldiers' heights' increasing in the order from the beginning of the line to its end. The numbers are space-separated. Numbers a1, a2, ..., an are not necessarily different.

Output

Print the only integer — the minimum number of seconds the colonel will need to form a line-up the general will like.

input

4
33 44 11 22
7
10 10 58 31 63 40 76

output

2
10

Note

In the first sample the colonel will need to swap the first and second soldier and then the third and fourth soldier. That will take 2 seconds. The resulting position of the soldiers is (44, 33, 22, 11).

In the second sample the colonel may swap the soldiers in the following sequence:

(10, 10, 58, 31, 63, 40, 76)
(10, 58, 10, 31, 63, 40, 76)
(10, 58, 10, 31, 63, 76, 40)
(10, 58, 10, 31, 76, 63, 40)
(10, 58, 31, 10, 76, 63, 40)
(10, 58, 31, 76, 10, 63, 40)
(10, 58, 31, 76, 63, 10, 40)
(10, 58, 76, 31, 63, 10, 40)
(10, 76, 58, 31, 63, 10, 40)
(76, 10, 58, 31, 63, 10, 40)
(76, 10, 58, 31, 63, 40, 10)

*/