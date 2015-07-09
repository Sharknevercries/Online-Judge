/* 9095868 10957 So Doku Checker Accepted C++ 1.376 2011-07-30 07:22:05 */
#include<stdio.h>
#define MAX 9
bool check(int table[][MAX]){
	bool repeat[9]={false};
	int row,cul,i;
	// check row
	for(row=0;row<MAX;row++){
		for(i=0;i<MAX;i++)
			repeat[i]=false;
		for(cul=0;cul<MAX;cul++)
			if(table[row][cul]!=0)
				if(!repeat[table[row][cul]-1])
					repeat[table[row][cul]-1]=true;
				else
					return false;
	}
	// check cul
	for(cul=0;cul<MAX;cul++){
		for(i=0;i<MAX;i++)
			repeat[i]=false;
		for(row=0;row<MAX;row++)
			if(table[row][cul]!=0)
				if(!repeat[table[row][cul]-1])
					repeat[table[row][cul]-1]=true;
				else
					return false;
	}
	// check area
	for(i=0;i<MAX;i++)
		repeat[i]=false;
	for(row=0;row<3;row++)
		for(cul=0;cul<3;cul++)
			if(table[row][cul]!=0)
				if(!repeat[table[row][cul]-1])
					repeat[table[row][cul]-1]=true;
				else
					return false;
	// ...
	for(i=0;i<MAX;i++)
		repeat[i]=false;
	for(row=0;row<3;row++)
		for(cul=3;cul<6;cul++)
			if(table[row][cul]!=0)
				if(!repeat[table[row][cul]-1])
					repeat[table[row][cul]-1]=true;
				else
					return false;
	// ...
	for(i=0;i<MAX;i++)
		repeat[i]=false;
	for(row=0;row<3;row++)
		for(cul=6;cul<9;cul++)
			if(table[row][cul]!=0)
				if(!repeat[table[row][cul]-1])
					repeat[table[row][cul]-1]=true;
				else
					return false;
	// ...
	for(i=0;i<MAX;i++)
		repeat[i]=false;
	for(row=3;row<6;row++)
		for(cul=0;cul<3;cul++)
			if(table[row][cul]!=0)
				if(!repeat[table[row][cul]-1])
					repeat[table[row][cul]-1]=true;
				else
					return false;
	// ...
	for(i=0;i<MAX;i++)
		repeat[i]=false;
	for(row=3;row<6;row++)
		for(cul=3;cul<6;cul++)
			if(table[row][cul]!=0)
				if(!repeat[table[row][cul]-1])
					repeat[table[row][cul]-1]=true;
				else
					return false;
	// ...
	for(i=0;i<MAX;i++)
		repeat[i]=false;
	for(row=3;row<6;row++)
		for(cul=6;cul<9;cul++)
			if(table[row][cul]!=0)
				if(!repeat[table[row][cul]-1])
					repeat[table[row][cul]-1]=true;
				else
					return false;
	// ...
	for(i=0;i<MAX;i++)
		repeat[i]=false;
	for(row=6;row<9;row++)
		for(cul=0;cul<3;cul++)
			if(table[row][cul]!=0)
				if(!repeat[table[row][cul]-1])
					repeat[table[row][cul]-1]=true;
				else
					return false;
	// ...
	for(i=0;i<MAX;i++)
		repeat[i]=false;
	for(row=6;row<9;row++)
		for(cul=3;cul<6;cul++)
			if(table[row][cul]!=0)
				if(!repeat[table[row][cul]-1])
					repeat[table[row][cul]-1]=true;
				else
					return false;
	// ...
	for(i=0;i<MAX;i++)
		repeat[i]=false;
	for(row=6;row<9;row++)
		for(cul=6;cul<9;cul++)
			if(table[row][cul]!=0)
				if(!repeat[table[row][cul]-1])
					repeat[table[row][cul]-1]=true;
				else
					return false;
	return true;
}
void DFS(int table[][MAX],int row,int cul,int *count){ // 寫不好 時間花太多判斷
	if(*count<2){
		if(cul>=MAX)
			row++,cul=0;
		if(row>=MAX){
			if(check(table))
				(*count)++;
		}
		else if(table[row][cul]==0){
			bool repeat[9]={false};
			for(int i=0;i<MAX;i++)
				if(table[row][i]!=0)
					repeat[table[row][i]-1]=true;
			for(int i=0;i<MAX;i++)
				if(table[i][cul]!=0)
					repeat[table[i][cul]-1]=true;
			for(int i=1;i<=9;i++){
				table[row][cul]=i;
				if(!repeat[i-1]&&check(table))
					DFS(table,row,cul+1,count);
				table[row][cul]=0;
			}		
		}
		else
			DFS(table,row,cul+1,count);
	}
}
int main(){
	int count=1;
	int table[MAX][MAX];
	while(scanf("%d",&table[0][0])==1){
		int i,j;
		for(i=0;i<MAX;i++)
			for(j=0;j<MAX;j++)
				if(i!=0||j!=0)
					scanf("%d",&table[i][j]);
		if(!check(table))
			printf("Case %d: Illegal.\n",count++);
		else{
			int result=0;
			DFS(table,0,0,&result);
			if(result==0)
				printf("Case %d: Impossible.\n",count++);
			else if(result==1)
				printf("Case %d: Unique.\n",count++);
			else
				printf("Case %d: Ambiguous.\n",count++);
		}
	}
	return 0;
}
/*

The best logical puzzles often are puzzles that are based on a simple idea. So Doku is one such type of puzzle. Although So Dokus have been around for some twenty years, in the last few years they conquered the world exponentially. Hundreds of newspapers and websites are now publishing them on a daily basis. For those of you unfamiliar with these puzzles, let me give a brief introduction.

The picture above contains an example of a Su Doku puzzle. As you can see, we have a 9X9 grid filled with single digits from 1 to 9 and empty places. The grid is further divided into nine 3X3 sub-grids, indicated by the thick lines. To solve the puzzle you have to fill the empty places with digits according to the following rules:

Every row should contain the digits 1 to 9 exactly once;
Every column should contain the digits 1 to 9 exactly once;
Every 3X3 sub-grid should contain the digits 1 to 9 exactly once.
A well formed Su Doku can be solved with paper and pencil using logical deduction only. To be well formed it should be legal (no row, column or sub-grid contains a digit more than once), solvable (the empty places can all be filled while respecting the rules) and unique (there is only one solution). This is what your program is going to check.

Input

The input contains several (partially) filled grids, each representing a Su Doku puzzle. For every puzzle there are 9 lines with 9 digits giving the puzzle in row major order. Empty places in the puzzle are represented by the digit 0 (zero). Digits on a line are separated by one space. The grids are separated by one empty line.

The first grid in the sample input represents the puzzle given in the picture.

Output

For every grid in the input, determine one of the following four verdicts:

"Illegal" if the puzzle violates one of the three rules;
"Unique" if only one solution exists;
"Ambiguous" if more than one solution exists;
"Impossible" if no solution exists;
Print one line per grid, in the format:"Case <N>: <VERDICT>.", where N is the case number, starting from 1, and VERDICT is one of the four words in the list. See the sample output for the exact format.
Note: an "Illegal" puzzle is also "Impossible", of course, but your program should print "Illegal" in that case. Only print "Impossible" if the input doesn't violate one of the three rules, but the puzzle still can't be solved.
 
Sample Input

0 0 3 9 0 0 7 6 0
0 4 0 0 0 6 0 0 9
6 0 7 0 1 0 0 0 4
2 0 0 6 7 0 0 9 0
0 0 4 3 0 5 6 0 0
0 1 0 0 4 9 0 0 7
7 0 0 0 9 0 2 0 1
3 0 0 2 0 0 0 4 0
0 2 9 0 0 8 5 0 0 
 
0 0 3 9 0 0 7 6 0
0 4 0 0 0 6 0 0 9
6 0 0 0 1 0 0 0 4
0 0 0 6 7 0 0 9 0
0 0 4 0 0 5 6 0 0
0 1 0 0 4 9 0 0 0
7 0 0 0 9 0 2 0 1
3 0 0 2 0 0 0 4 0
0 2 0 0 0 8 5 0 0 
 
0 0 3 9 0 0 7 6 0
0 4 0 0 0 6 0 0 9
6 0 7 0 1 0 0 0 4
2 0 0 6 7 0 0 9 0
0 0 4 3 0 5 6 0 0
0 1 0 0 4 9 0 0 7
7 2 0 0 9 0 2 0 1
3 0 0 2 0 0 0 4 0
0 2 9 0 0 8 5 0 0 
 
0 0 3 9 0 0 7 6 0
0 4 0 0 0 6 0 0 9
6 0 7 0 1 0 0 0 4
2 0 0 6 7 0 0 9 0
0 0 4 3 0 5 6 0 0
0 1 0 0 4 9 0 0 7
7 5 0 0 9 0 2 0 1
3 0 0 2 0 0 0 4 0
0 2 9 0 0 8 5 0 0 

 Output for Sample Input

Case 1: Unique.
Case 2: Ambiguous.
Case 3: Illegal.
Case 4: Impossible.
 
Problem setter: Little Joey (Joachim)
Special Thanks: Jimmy Mårdell, EPS
 
Epilogue (not required to solve the problem)
The (unique) solution to the given puzzle is:
 
1 5 3 9 8 4 7 6 2
8 4 2 7 3 6 1 5 9
6 9 7 5 1 2 8 3 4
2 3 8 6 7 1 4 9 5
9 7 4 3 2 5 6 1 8
5 1 6 8 4 9 3 2 7
7 6 5 4 9 3 2 8 1
3 8 1 2 5 7 9 4 6
4 2 9 1 6 8 5 7 3

If you are interested in the fascinating world of Su Dokus and solving them by hand, Google is a good starting point. Also Wikipedia has a nice entry on Su Dokus describing their history and giving some mathematical background.

*/
