/* 4862327	 Oct 24, 2013 5:20:21 PM	Shark	 10A - Power Consumption Calculation	 GNU C++	Accepted	30 ms	0 KB */
#include<stdio.h>
struct data{
	int L,R;
};
struct data S[100];
int main(){
	int n,P[3],T[2];
	while( scanf("%d%d%d%d%d%d",&n,&P[0],&P[1],&P[2],&T[0],&T[1])==6 ){
		int cur,ans;
		for(int i=0;i<n;i++)
			scanf("%d%d",&S[i].L,&S[i].R);

		cur=S[0].R;
		ans=(S[0].R-S[0].L)*P[0];
		for(int i=1;i<n;i++){
			if( S[i].L-cur>T[0]+T[1] )
				ans+=P[0]*T[0]+P[1]*T[1]+P[2]*(S[i].L-cur-T[0]-T[1]);
			else if( S[i].L-cur>T[0] )
				ans+=P[0]*T[0]+P[1]*(S[i].L-cur-T[0]);
			else
				ans+=P[0]*(S[i].L-cur);
			ans+=(S[i].R-S[i].L)*P[0];
			cur=S[i].R;
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*

A. Power Consumption Calculation
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Tom is interested in power consumption of his favourite laptop. His laptop has three modes. In normal mode laptop consumes P1 watt per minute. T1 minutes after Tom moved the mouse or touched the keyboard for the last time, a screensaver starts and power consumption changes to P2 watt per minute. Finally, after T2 minutes from the start of the screensaver, laptop switches to the "sleep" mode and consumes P3 watt per minute. If Tom moves the mouse or touches the keyboard when the laptop is in the second or in the third mode, it switches to the first (normal) mode. Tom's work with the laptop can be divided into n time periods [l1, r1], [l2, r2], ..., [ln, rn]. During each interval Tom continuously moves the mouse and presses buttons on the keyboard. Between the periods Tom stays away from the laptop. Find out the total amount of power consumed by the laptop during the period [l1, rn].

Input
The first line contains 6 integer numbers n, P1, P2, P3, T1, T2 (1 ≤ n ≤ 100, 0 ≤ P1, P2, P3 ≤ 100, 1 ≤ T1, T2 ≤ 60). The following n lines contain description of Tom's work. Each i-th of these lines contains two space-separated integers li and ri (0 ≤ li < ri ≤ 1440, ri < li + 1 for i < n), which stand for the start and the end of the i-th period of work.

Output
Output the answer to the problem.

Sample test(s)
input
1 3 2 1 5 10
0 10
output
30
input
2 8 4 2 5 10
20 30
50 100
output
570

*/