/* 4911578	 Oct 27, 2013 2:21:46 PM	Shark	 140D - New Year Contest	 GNU C++	Accepted	15 ms	0 KB */
#include<stdio.h>
#include<algorithm>
int main(){
	int n;
	while( scanf("%d",&n)==1 ){
		int M[100];
		for(int i=0;i<n;i++)
			scanf("%d",&M[i]);
		std::sort(M,M+n);
		
		int cur=10,count=0,penalty=0;
		for(int i=0;i<n;i++){
			if( M[i]+cur<=720 ){
				count++,cur+=M[i];
				if( cur-360>0 )
					penalty+=cur-360;
			}
			else
				break;
		}
		printf("%d %d\n",count,penalty);
	}
	return 0;
}
/*

D. New Year Contest
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
As Gerald sets the table, Alexander sends the greeting cards, and Sergey and his twins create an army of clone snowmen, Gennady writes a New Year contest.

The New Year contest begins at 18:00 (6.00 P.M.) on December 31 and ends at 6:00 (6.00 A.M.) on January 1. There are n problems for the contest. The penalty time for each solved problem is set as the distance from the moment of solution submission to the New Year in minutes. For example, the problem submitted at 21:00 (9.00 P.M.) gets penalty time 180, as well as the problem submitted at 3:00 (3.00 A.M.). The total penalty time is calculated as the sum of penalty time for all solved problems. It is allowed to submit a problem exactly at the end of the contest, at 6:00 (6.00 A.M.).

Gennady opened the problems exactly at 18:00 (6.00 P.M.) and managed to estimate their complexity during the first 10 minutes of the contest. He believes that writing a solution for the i-th problem will take ai minutes. Gennady can submit a solution for evaluation at any time after he completes writing it. Probably he will have to distract from writing some solution to send the solutions of other problems for evaluation. The time needed to send the solutions can be neglected, i.e. this time can be considered to equal zero. Gennady can simultaneously submit multiple solutions. Besides, he can move at any time from writing one problem to another, and then return to the first problem from the very same place, where he has left it. Thus the total solution writing time of the i-th problem always equals ai minutes. Of course, Gennady does not commit wrong attempts, and his solutions are always correct and are accepted from the first attempt. He can begin to write the solutions starting from 18:10 (6.10 P.M.).

Help Gennady choose from the strategies that help him solve the maximum possible number of problems, the one with which his total penalty time will be minimum.

Input
The first line contains an integer n (1 ≤ n ≤ 100) — the number of the problems. The next line contains n space-separated integers ai (1 ≤ ai ≤ 720) — each number shows how much time in minutes Gennady will spend writing a solution to the problem.

Output
Print two integers — the number of problems Gennady will solve and the total penalty time considering that he chooses the optimal strategy.

Sample test(s)
input
3
30 330 720
output
2 10
Note
In the sample, one of Gennady's possible optimal strategies is as follows. At 18:10 (6:10 PM) he begins to write the first problem and solves it in 30 minutes (18:40 or 6.40 P.M.). At 18:40 (6.40 P.M.) he begins to write the second problem. There are 320 minutes left before the New Year, so Gennady does not have the time to finish writing the second problem before the New Year. At 0:00 (12.00 A.M.) he distracts from the second problem, submits the first one, and returns immediately to writing the second problem. At 0:10 (0.10 A.M.), he completes the solution for the second problem, submits it and gets 10 minute penalty time. Note that as the total duration of the contest is 720 minutes and Gennady has already spent 10 minutes on reading the problems, he will not have time to solve the third problem during the contest. Yes, such problems happen to exist.

Competitions by the given rules are held annually on the site http://b23.ru/3wvc

*/