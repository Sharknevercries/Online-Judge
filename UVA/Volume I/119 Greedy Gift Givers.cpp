/* 12411868	119	Greedy Gift Givers	Accepted	C++	0.016	2013-09-28 05:37:49 */
#include<stdio.h>
#include<string.h>
int main(){
	int n;
	bool first=true;
	while( scanf("%d",&n)==1 ){
		int ans[1000]={0};
		char name[10][100];
		for(int i=0;i<n;i++)
			scanf("%s",name[i]);
		for(int i=0;i<n;i++){
			char giver[100];
			int ptrGiver,ptrReceiver;
			int money;
			int people;
			scanf("%s%d%d",giver,&money,&people);
			for(int j=0;j<n;j++)
				if( strcmp(giver,name[j])==0 ){
					ptrGiver=j;
					break;
				}
			if( people>0 ){
				ans[ptrGiver]-=money;
				ans[ptrGiver]+=money%people;
			}
			for(int j=0;j<people;j++){
				char Receiver[100];
				scanf("%s",Receiver);
				for(int k=0;k<n;k++)
					if( strcmp(Receiver,name[k])==0 ){
						ptrReceiver=k;
						break;
					}
				ans[ptrReceiver]+=money/people;
			}
		}
		if( !first )
			putchar('\n');
		first=false;
		for(int j=0;j<n;j++)
			printf("%s %d\n",name[j],ans[j]);
	}
	return 0;
}
/*

 Greedy Gift Givers 

The Problem

This problem involves determining, for a group of gift-giving friends, how much more each person gives than they receive (and vice versa for those that view gift-giving with cynicism).

In this problem each person sets aside some money for gift-giving and divides this money evenly among all those to whom gifts are given.

However, in any group of friends, some people are more giving than others (or at least may have more acquaintances) and some people have more money than others.

Given a group of friends, the money each person in the group spends on gifts, and a (sub)list of friends to whom each person gives gifts; you are to write a program that determines how much more (or less) each person in the group gives than they receive.

The Input

The input is a sequence of gift-giving groups. A group consists of several lines:

the number of people in the group,
a list of the names of each person in the group,
a line for each person in the group consisting of the name of the person, the amount of money spent on gifts, the number of people to whom gifts are given, and the names of those to whom gifts are given.
All names are lower-case letters, there are no more than 10 people in a group, and no name is more than 12 characters in length. Money is a non-negative integer less than 2000.

The input consists of one or more groups and is terminated by end-of-file.

The Output

For each group of gift-givers, the name of each person in the group should be printed on a line followed by the net gain (or loss) received (or spent) by the person. Names in a group should be printed in the same order in which they first appear in the input.

The output for each group should be separated from other groups by a blank line. All gifts are integers. Each person gives the same integer amount of money to each friend to whom any money is given, and gives as much as possible. Any money not given is kept and is part of a person's ``net worth'' printed in the output.

Sample Input

5
dave laura owen vick amr
dave 200 3 laura owen vick
owen 500 1 dave
amr 150 2 vick owen
laura 0 2 amr vick
vick 0 0
3
liz steve dave
liz 30 1 steve
steve 55 2 liz dave
dave 0 2 steve liz
Sample Output

dave 302
laura 66
owen -359
vick 141
amr -150

liz -3
steve -24
dave 27

*/