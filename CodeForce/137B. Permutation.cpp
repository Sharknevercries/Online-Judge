/* 1254426	 Mar 1, 2012 5:46:31 PM	Shark	 137B - Permutation	 GNU C++	Accepted	 30 ms	 1400 KB */
#include<stdio.h>
int main(){
	int n;
	while(scanf("%d",&n)==1){
		int M[10000]={0};
		for(int i=0;i<n;i++){
			int a;
			scanf("%d",&a);
			M[a]++;
		}
		int count=0,i;
		for(i=1;i<=n;i++)
			if(M[i]==0)
				count++;
			else
				count+=M[i]-1;
		for( ;i<=5000;i++)
			count+=M[i];
		printf("%d\n",count/2);
	}
	return 0;
}
/*

"Hey, it's homework time" — thought Polycarpus and of course he started with his favourite subject, IT. Polycarpus managed to solve all tasks but for the last one in 20 minutes. However, as he failed to solve the last task after some considerable time, the boy asked you to help him.

The sequence of n integers is called a permutation if it contains all integers from 1 to n exactly once.

You are given an arbitrary sequence a1, a2, ..., an containing n integers. Each integer is not less than 1 and not greater than 5000. Determine what minimum number of elements Polycarpus needs to change to get a permutation (he should not delete or add numbers). In a single change he can modify any single sequence element (i. e. replace it with another integer).

Input

The first line of the input data contains an integer n (1 ≤ n ≤ 5000) which represents how many numbers are in the sequence. The second line contains a sequence of integers ai (1 ≤ ai ≤ 5000, 1 ≤ i ≤ n).

Output

Print the only number — the minimum number of changes needed to get the permutation.

input

3
3 1 2
2
2 2
5
5 3 3 3 1

output

0
1
2

Note

The first sample contains the permutation, which is why no replacements are required.

In the second sample it is enough to replace the first element with the number 1 and that will make the sequence the needed permutation.

In the third sample we can replace the second element with number 4 and the fourth element with number 2.

*/