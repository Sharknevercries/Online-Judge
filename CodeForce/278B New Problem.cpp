/* 4819331	 Oct 18, 2013 4:24:49 PM	Shark	 278B - New Problem	 GNU C++	Accepted	62 ms	0 KB */
#include<stdio.h>
#include<string.h>
#define SWAP(x,y) { int temp=x;	x=y;	y=temp;	}

char str[30][21];
char ans[21];
int len;
bool check(int s){
	int i,j,k;
	for(i=0;str[s][i]!='\0';i++){
		for(j=i,k=len-1;str[s][j]!='\0'&&k>=0;j++,k--)
			if( str[s][j]!=ans[k] )
				break;
		if( k<0 )
			return true;
	}
	return false;
	
}
int main(){
	int n;
	while( scanf("%d",&n)==1 ){
		
		for(int i=0;i<n;i++)
			scanf("%s",str[i]);

		len=1;
		for(int i=0;i<21;i++)
			ans[i]='a'-1;
		while( true ){
			ans[0]++;
			int ptr=0;
			while( ans[ptr]>'z' ){
				ans[ptr++]='a';
				ans[ptr]++;
			}
			if( ptr+1>len )
				len=ptr+1;
			
			bool found=true;
			for(int i=0;i<n;i++)
				if( check(i) )
					found=false;

			if( found ){
				ans[len]='\0';
				for(int i=0,j=len-1;i<j;i++,j--)
					SWAP(ans[i],ans[j])
				break;
			}
		}
		printf("%s\n",ans);
	}
	return 0;
}
/*

B. New Problem
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Coming up with a new problem isn't as easy as many people think. Sometimes it is hard enough to name it. We'll consider a title original if it doesn't occur as a substring in any titles of recent Codeforces problems.

You've got the titles of n last problems — the strings, consisting of lowercase English letters. Your task is to find the shortest original title for the new problem. If there are multiple such titles, choose the lexicographically minimum one. Note, that title of the problem can't be an empty string.

A substring s[l... r] (1 ≤ l ≤ r ≤ |s|) of string s = s1s2... s|s| (where |s| is the length of string s) is string slsl + 1... sr.

String x = x1x2... xp is lexicographically smaller than string y = y1y2... yq, if either p < q and x1 = y1, x2 = y2, ... , xp = yp, or there exists such number r (r < p, r < q), that x1 = y1, x2 = y2, ... , xr = yr and xr + 1 < yr + 1. The string characters are compared by their ASCII codes.

Input
The first line contains integer n (1 ≤ n ≤ 30) — the number of titles you've got to consider. Then follow n problem titles, one per line. Each title only consists of lowercase English letters (specifically, it doesn't contain any spaces) and has the length from 1 to 20, inclusive.

Output
Print a string, consisting of lowercase English letters — the lexicographically minimum shortest original title.

Sample test(s)
input
5
threehorses
goodsubstrings
secret
primematrix
beautifulyear
output
j
input
4
aa
bdefghijklmn
opqrstuvwxyz
c
output
ab
Note
In the first sample the first 9 letters of the English alphabet (a, b, c, d, e, f, g, h, i) occur in the problem titles, so the answer is letter j.

In the second sample the titles contain 26 English letters, so the shortest original title cannot have length 1. Title aa occurs as a substring in the first title.

*/