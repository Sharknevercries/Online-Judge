/* 4857186	 Oct 24, 2013 10:22:52 AM	Shark	 250A - Paper Work	 GNU C++	Accepted	30 ms	0 KB */
#include<stdio.h>
int main(){
	int n;
	while( scanf("%d",&n)==1 ){
		int M[100];
		int F[100];
		int file,minus,count;
		file=count=minus=0;
		for(int i=0;i<n;i++)
			scanf("%d",&M[i]);
		for(int i=0;i<n;i++){
			count++;
			if( M[i]<0 )
				minus++;
			if( minus==3 )
				F[file++]=count-1,minus=count=1;
		}
		if( count>0 )
			F[file++]=count;
		printf("%d\n",file);
		printf("%d",F[0]);
		for(int i=1;i<file;i++)
			printf(" %d",F[i]);
		putchar('\n');
	}
	return 0;
}
/*

A. Paper Work
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Polycarpus has been working in the analytic department of the "F.R.A.U.D." company for as much as n days. Right now his task is to make a series of reports about the company's performance for the last n days. We know that the main information in a day report is value ai, the company's profit on the i-th day. If ai is negative, then the company suffered losses on the i-th day.

Polycarpus should sort the daily reports into folders. Each folder should include data on the company's performance for several consecutive days. Of course, the information on each of the n days should be exactly in one folder. Thus, Polycarpus puts information on the first few days in the first folder. The information on the several following days goes to the second folder, and so on.

It is known that the boss reads one daily report folder per day. If one folder has three or more reports for the days in which the company suffered losses (ai < 0), he loses his temper and his wrath is terrible.

Therefore, Polycarpus wants to prepare the folders so that none of them contains information on three or more days with the loss, and the number of folders is minimal.

Write a program that, given sequence ai, will print the minimum number of folders.

Input
The first line contains integer n (1 ≤ n ≤ 100), n is the number of days. The second line contains a sequence of integers a1, a2, ..., an (|ai| ≤ 100), where ai means the company profit on the i-th day. It is possible that the company has no days with the negative ai.

Output
Print an integer k — the required minimum number of folders. In the second line print a sequence of integers b1, b2, ..., bk, where bj is the number of day reports in the j-th folder.

If there are multiple ways to sort the reports into k days, print any of them.

Sample test(s)
input
11
1 2 3 -4 -5 -6 5 -5 -6 -7 6
output
3
5 3 3 
input
5
0 -1 100 -1 0
output
1
5 
Note
Here goes a way to sort the reports from the first sample into three folders:

1 2 3 -4 -5 | -6 5 -5 | -6 -7 6
In the second sample you can put all five reports in one folder.

*/