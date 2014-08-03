/* 9083833 11581 Grid Successors Accepted C++ 0.008 2011-07-27 05:12:38 */
#include<stdio.h>
#define NOT_FOUND -1
#define THE_SAME 1
#define THE_DEFFERENT 0
int temp[300][3][3]={0};
int index;
int check(){
	int i,j,k;
	bool FOUND=false;
	for(i=0;i<3&&!FOUND;i++)
		for(j=0;j<3&&!FOUND;j++)
			if(temp[index-1][i][j]!=0)
				FOUND=true;
	if(!FOUND)
		return NOT_FOUND;

	
	for(i=0;i<index-1;i++){
		bool same=true;
		for(j=0;j<3&&same;j++)
			for(k=0;k<3&&same;k++)
				if(temp[i][j][k]!=temp[index-1][j][k])
					same=false;
		if(same&&j>=3)
			return THE_SAME;
	}	
	return THE_DEFFERENT;
}
void change(){
	int i=index-1;
	int j,k;
	for(j=0;j<3;j++)
		for(k=0;k<3;k++){
			int sum=0;
			if(j+1<3)	sum+=temp[i][j+1][k];
			if(j-1>=0)	sum+=temp[i][j-1][k];
			if(k+1<3)	sum+=temp[i][j][k+1];
			if(k-1>=0)	sum+=temp[i][j][k-1];
			temp[index][j][k]=sum%2;
		}
	index++;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int t=1;t<=n;t++){
		int i,j;
		index=0;
		for(i=0;i<3;i++)
			for(j=0;j<3;j++)
				scanf("%1d",&temp[index][i][j]);
		index++;

		int result=check();
		int count=0;
		if(result!=NOT_FOUND){			
			while(true){
				change();
				result=check();
				if(result==THE_DEFFERENT)
					count++;
				else
					break;
			}
			printf("%d\n",count);
		}
		else
			puts("-1");
	}
	return 0;
}
/*

Consider a 3 x 3 grid of numbers g where each cell contains either a 0 or a 1. We define a function f that transforms such a grid: each cell of the grid f(g) is the sum (modulo 2) of its adjacent cells in g (two cells are considered adjacent if and only if they share a common side).
 
Furthermore, we define f (i)(g) recursively as f (0)(g) = g and f (i+1)(g)  =  f(f (i)(g)) (where i  ≥  0). Finally, for any grid h, let kg(h) be the number of indices i such that h = f (i)(g) (we may have kg(h) = ∞). Given a grid g, your task is to compute the greatest index i such that kg(f (i)(g)) is finite.
 
Input begins with the number of test cases on its own line. Each case consists of a blank line followed by three lines of three characters, each either 1 or 0. The j'th character of the i'th row of the test case is the value in the j'th cell of the i'th row of the grid g.
 
For each test case, output the greatest index i such that kg(f (i)(g)) is finite. If there is no such index, output -1.
 
Sample input

3

111
100
001

101
000
101

000
000
000

 Sample output

3
0
-1

--------------------------------------------------------------------------------
 Babak Behsaz and Zachary Friggstad 
 
*/