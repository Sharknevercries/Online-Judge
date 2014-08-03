/* 4851506	 Oct 23, 2013 3:51:00 PM	Shark	 253B - Physics Practical	 GNU C++	Accepted	 92 ms	 200 KB */
#include<stdio.h>
#include<algorithm>
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	while( scanf("%d",&n)==1 ){
		int count[5001]={0};
		int S[5001];
		int N=0,min=2e9;
		for(int i=0;i<n;i++){
			int tmp;
			scanf("%d",&tmp);
			if( count[tmp]==0 )
				S[N++]=tmp;
			count[tmp]++;
		}

		std::sort(S,S+N);
		for(int i=0;i<N;i++){
			int sum=0;
			for(int j=S[i]-1;j>=1;j--)
				sum+=count[j];
			for(int j=2*S[i]+1;j<=5000;j++)
				sum+=count[j];
			if( min>sum )
				min=sum;
		}
		printf("%d\n",min);
	}
	return 0;
}
/*

B. Physics Practical
time limit per test1 second
memory limit per test256 megabytes
inputinput.txt
outputoutput.txt
One day Vasya was on a physics practical, performing the task on measuring the capacitance. He followed the teacher's advice and did as much as n measurements, and recorded the results in the notebook. After that he was about to show the results to the teacher, but he remembered that at the last lesson, the teacher had made his friend Petya redo the experiment because the largest and the smallest results differed by more than two times. Vasya is lazy, and he does not want to redo the experiment. He wants to do the task and go home play computer games. So he decided to cheat: before Vasya shows the measurements to the teacher, he will erase some of them, so as to make the largest and the smallest results of the remaining measurements differ in no more than two times. In other words, if the remaining measurements have the smallest result x, and the largest result y, then the inequality y ≤ 2·x must fulfill. Of course, to avoid the teacher's suspicion, Vasya wants to remove as few measurement results as possible from his notes.

Help Vasya, find what minimum number of measurement results he will have to erase from his notes so that the largest and the smallest of the remaining results of the measurements differed in no more than two times.

Input
The first line contains integer n (2 ≤ n ≤ 105) — the number of measurements Vasya made. The second line contains n integers c1, c2, ..., cn (1 ≤ ci ≤ 5000) — the results of the measurements. The numbers on the second line are separated by single spaces.

Output
Print a single integer — the minimum number of results Vasya will have to remove.

Sample test(s)
input
6
4 5 3 8 3 7
output
2
input
4
4 3 2 4
output
0
Note
In the first sample you can remove the fourth and the sixth measurement results (values 8 and 7). Then the maximum of the remaining values will be 5, and the minimum one will be 3. Or else, you can remove the third and fifth results (both equal 3). After that the largest remaining result will be 8, and the smallest one will be 4.

*/