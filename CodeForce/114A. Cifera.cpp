/* 1219419	 Feb 23, 2012 5:34:35 PM	Shark	 114A - Cifera	 GNU C++	Accepted	 30 ms	 1300 KB */
#include<stdio.h>
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)==2){
		int count=-1;
		while(m%n==0&&m!=1)
			m/=n,count++;
		if(m==1&&count>=0){
			puts("YES");
			printf("%d\n",count);
		}
		else
			puts("NO");
	}
	return 0;
}
/*

When Petya went to school, he got interested in large numbers and what they were called in ancient times. For instance, he learned that the Russian word "tma" (which now means "too much to be counted") used to stand for a thousand and "tma tmyschaya" (which literally means "the tma of tmas") used to stand for a million.

Petya wanted to modernize the words we use for numbers and invented a word petricium that represents number k. Moreover, petricium la petricium stands for number k2, petricium la petricium la petricium stands for k3 and so on. All numbers of this form are called petriciumus cifera, and the number's importance is the number of articles la in its title.

Petya's invention brought on a challenge that needed to be solved quickly: does some number l belong to the set petriciumus cifera? As Petya is a very busy schoolboy he needs to automate the process, he asked you to solve it.

Input

The first input line contains integer number k, the second line contains integer number l (2 ≤ k, l ≤ 231 - 1).

Output

You should print in the first line of the output "YES", if the number belongs to the set petriciumus cifera and otherwise print "NO". If the number belongs to the set, then print on the seconds line the only number — the importance of number l.

input
5
25
3
8

output

YES
1
NO

*/