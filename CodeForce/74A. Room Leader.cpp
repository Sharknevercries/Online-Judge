/* 1254493	 Mar 1, 2012 6:08:09 PM	Shark	 74A - Room Leader	 GNU C++	Accepted	 30 ms	 1400 K */
#include<stdio.h>
typedef struct data{
	char name[30];
	int a,b,c,d,e,f,g;
}MAKE;
MAKE T[100];
int main(){
	int n;
	while(scanf("%d",&n)==1){
		long long int pos=-1,max=-2e9;
		for(int i=0;i<n;i++)
			scanf("%s%d%d%d%d%d%d%d",T[i].name,&T[i].a,&T[i].b,&T[i].c,&T[i].d,&T[i].e,&T[i].f,&T[i].g);
		for(int i=0;i<n;i++){
			long long int sum=0;
			sum=T[i].a*100-T[i].b*50+T[i].c+T[i].d+T[i].e+T[i].f+T[i].g;
			if(sum>max)
				max=sum,pos=i;
		}
		printf("%s\n",T[pos].name);
	}
	return 0;
}
/*

Let us remind you part of the rules of Codeforces. The given rules slightly simplified, use the problem statement as a formal document.

In the beginning of the round the contestants are divided into rooms. Each room contains exactly n participants. During the contest the participants are suggested to solve five problems, A, B, C, D and E. For each of these problem, depending on when the given problem was solved and whether it was solved at all, the participants receive some points. Besides, a contestant can perform hacks on other contestants. For each successful hack a contestant earns 100 points, for each unsuccessful hack a contestant loses 50 points. The number of points for every contestant is represented by the sum of points he has received from all his problems, including hacks.

You are suggested to determine the leader for some room; the leader is a participant who has maximum points.

Input

The first line contains an integer n, which is the number of contestants in the room (1 ≤ n ≤ 50). The next n lines contain the participants of a given room. The i-th line has the format of "handlei plusi minusi ai bi ci di ei" — it is the handle of a contestant, the number of successful hacks, the number of unsuccessful hacks and the number of points he has received from problems A, B, C, D, E correspondingly. The handle of each participant consists of Latin letters, digits and underscores and has the length from 1 to 20 characters. There are the following limitations imposed upon the numbers:

0 ≤ plusi, minusi ≤ 50;
150 ≤ ai ≤ 500 or ai = 0, if problem A is not solved;
300 ≤ bi ≤ 1000 or bi = 0, if problem B is not solved;
450 ≤ ci ≤ 1500 or ci = 0, if problem C is not solved;
600 ≤ di ≤ 2000 or di = 0, if problem D is not solved;
750 ≤ ei ≤ 2500 or ei = 0, if problem E is not solved.
All the numbers are integer. All the participants have different handles. It is guaranteed that there is exactly one leader in the room (i.e. there are no two participants with the maximal number of points).

Output

Print on the single line the handle of the room leader.

input

5
Petr 3 1 490 920 1000 1200 0
tourist 2 0 490 950 1100 1400 0
Egor 7 0 480 900 950 0 1000
c00lH4x0R 0 10 150 0 0 0 0
some_participant 2 1 450 720 900 0 0

output

tourist

Note

The number of points that each participant from the example earns, are as follows:

Petr — 3860
tourist — 4140
Egor — 4030
c00lH4x0R —  - 350
some_participant — 2220

Thus, the leader of the room is tourist.

*/