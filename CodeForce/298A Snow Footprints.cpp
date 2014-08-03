/* 4745722	 Oct 11, 2013 6:27:57 PM	Shark	 298A - Snow Footprints	 GNU C++	Accepted	30 ms	0 KB */
#include<stdio.h>
#define LEFT 1
#define RIGHT 0
int main(){
	int n;
	while( scanf("%d",&n)==1 ){
		char map[1001];
		bool mark[1001]={false};
		int start,end,pos,direction;

		scanf("%s",map);
		for(int i=0;map[i]!='\0';i++)
			if( map[i]=='.' )
				mark[i]=true;

		for(start=1;map[start]=='.';start++);
		direction= map[start]=='R'?RIGHT:LEFT;
		pos=start;

		while( !mark[pos] ){
			if( direction==RIGHT ){
				for( ;map[pos]!='L'&&!mark[pos];pos++)
					mark[pos]=true;
				for( ;!mark[pos];pos++);
				pos--;
				direction=LEFT;
			}
			else{
				for( ;map[pos]!='R'&&!mark[pos];pos--)
					mark[pos]=true;
				for( ;map[pos]!='.'&&!mark[pos];pos--);
				pos++;
				direction=RIGHT;
			}
		}
		if( direction==RIGHT )
			end=pos-1;
		else
			end=pos+1;
		printf("%d %d\n",start+1,end+1);
	}
	return 0;
}
/*

A. Snow Footprints
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
There is a straight snowy road, divided into n blocks. The blocks are numbered from 1 to n from left to right. If one moves from the i-th block to the (i + 1)-th block, he will leave a right footprint on the i-th block. Similarly, if one moves from the i-th block to the (i - 1)-th block, he will leave a left footprint on the i-th block. If there already is a footprint on the i-th block, the new footprint will cover the old one.


At the beginning, there were no footprints. Then polar bear Alice starts from the s-th block, makes a sequence of moves and ends in the t-th block. It is known that Alice never moves outside of the road.

You are given the description of Alice's footprints. Your task is to find a pair of possible values of s, t by looking at the footprints.

Input
The first line of the input contains integer n (3 ≤ n ≤ 1000).

The second line contains the description of the road — the string that consists of n characters. Each character will be either "." (a block without footprint), or "L" (a block with a left footprint), "R" (a block with a right footprint).

It's guaranteed that the given string contains at least one character not equal to ".". Also, the first and the last character will always be ".". It's guaranteed that a solution exists.

Output
Print two space-separated integers — the values of s and t. If there are several possible solutions you can print any of them.

Sample test(s)
input
9
..RRLL...
output
3 4
input
11
.RRRLLLLL..
output
7 5
Note
The first test sample is the one in the picture.

*/