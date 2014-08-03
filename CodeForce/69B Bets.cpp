/* 4876228	 Oct 25, 2013 1:49:19 PM	Shark	 69B - Bets	 GNU C++	Accepted	62 ms	0 KB */
#include<stdio.h>
struct section{
	int profit;
	int time;
};
struct section S[101];
int main(){
	int n,m;
	while( scanf("%d%d",&n,&m)==2 ){
		for(int i=1;i<=n;i++)
			S[i].profit=0,S[i].time=2e9;
		for(int i=0;i<m;i++){
			int L,R,T,C;
			scanf("%d%d%d%d",&L,&R,&T,&C);
			for(int j=L;j<=R;j++)
				if( S[j].time>T )
					S[j].profit=C,S[j].time=T;
		}
		int ans=0;
		for(int i=1;i<=n;i++)
			ans+=S[i].profit;
		printf("%d\n",ans);
	}
	return 0;
}
/*

B. Bets
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
In Chelyabinsk lives a much respected businessman Nikita with a strange nickname "Boss". Once Nikita decided to go with his friend Alex to the Summer Biathlon World Cup. Nikita, as a very important person, received a token which allows to place bets on each section no more than on one competitor.

To begin with friends learned the rules: in the race there are n sections of equal length and m participants. The participants numbered from 1 to m. About each participant the following is known:

li — the number of the starting section,
ri — the number of the finishing section (li ≤ ri),
ti — the time a biathlete needs to complete an section of the path,
ci — the profit in roubles. If the i-th sportsman wins on one of the sections, the profit will be given to the man who had placed a bet on that sportsman.
The i-th biathlete passes the sections from li to ri inclusive. The competitor runs the whole way in (ri - li + 1)·ti time units. It takes him exactly ti time units to pass each section. In case of the athlete's victory on k sections the man who has betted on him receives k·ci roubles.

In each section the winner is determined independently as follows: if there is at least one biathlete running this in this section, then among all of them the winner is the one who has ran this section in minimum time (spent minimum time passing this section). In case of equality of times the athlete with the smaller index number wins. If there are no participants in this section, then the winner in this section in not determined. We have to say that in the summer biathlon all the participants are moving at a constant speed.

We should also add that Nikita can bet on each section and on any contestant running in this section.

Help the friends find the maximum possible profit.

Input
The first line contains two integers n and m (1 ≤ n, m ≤ 100). Then follow m lines, each containing 4 integers li, ri, ti, ci (1 ≤ li ≤ ri ≤ n, 1 ≤ ti, ci ≤ 1000).

Output
Print a single integer, the maximal profit in roubles that the friends can get. In each of n sections it is not allowed to place bets on more than one sportsman.

Sample test(s)
input
4 4
1 4 20 5
1 3 21 10
3 3 4 30
3 4 4 20
output
60
input
8 4
1 5 24 10
2 4 6 15
4 6 30 50
6 7 4 20
output
105
Note
In the first test the optimal bet is: in the 1-2 sections on biathlete 1, in section 3 on biathlete 3, in section 4 on biathlete 4. Total: profit of 5 rubles for 1 section, the profit of 5 rubles for 2 section, profit of 30 rubles for a 3 section, profit of 20 rubles for 4 section. Total profit 60 rubles.

In the second test the optimal bet is: on 1 and 5 sections on biathlete 1, in the 2-4 sections on biathlete 2, in the 6-7 sections on athlete 4. There is no winner in the 8 section. Total: profit of 10 rubles for 1 section, the profit of 15 rubles for 2,3,4 section, profit of 10 rubles for a 5 section, profit of 20 rubles for 6, 7 section. Total profit 105 rubles.

*/