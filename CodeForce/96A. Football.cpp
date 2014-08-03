/* 1205719	 Feb 20, 2012 5:18:04 PM	Shark	 96A - Football	 GNU C++	Accepted	 30 ms	 1300 KB */
#include<stdio.h>
int main(){
	char str[1000];
	while(scanf("%s",str)==1){
		bool YES=false;
		int count=1;
		for(int i=1;str[i]!='\0'&&!YES;i++){
			if(str[i]==str[i-1])
				count++;
			else
				count=1;
			if(count>=7)
				YES=true;
		}
		if(YES)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
/*

Petya loves football very much. One day, as he was watching a football match, he was writing the players' current positions on a piece of paper. To simplify the situation he depicted it as a string consisting of zeroes and ones. A zero corresponds to players of one team; a one corresponds to players of another team. If there are at least 7 players of some team standing one after another, then the situation is considered dangerous. For example, the situation 00100110111111101 is dangerous and 11110111011101 is not. You are given the current situation. Determine whether it is dangerous or not.

Input
The first input line contains a non-empty string consisting of characters "0" and "1", which represents players. The length of the string does not exceed 100 characters. There's at least one player from each team present on the field.

Output

Print "YES" if the situation is dangerous. Otherwise, print "NO".

input

001001
1000000001

output

NO
YES

*/