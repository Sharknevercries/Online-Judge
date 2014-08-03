/* 9194299 10593 Kites Accepted C++ 0.616 2011-08-27 05:50:59 */
#include<stdio.h>
char table[500][501];
int find[500][500];
int find_square(int n){
	int i,j,D;
	int count;
	bool change;

	count=0;
	D=1;
	while(true){
		change=false;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				if(j+1<n&&i+1<n)
					if( find[i][j]==D && find[i][j+1]==find[i][j] && find[i+1][j]==find[i][j]
					&& find[i+1][j+1]==find[i][j] ){
						find[i][j]++;
						count++;
						change=true;
					}
		if(!change)
			break;
		D++;
	}
	return count;
}
int find_sss(int n){
	int i,j,D;
	int count;
	bool change;

	count=0;
	D=1;
	while(true){
		change=false;
		for(i=1;i<n;i++)
			for(j=1;j<n;j++)
				if(j+1<n&&i+1<n)
					if( find[i][j]==D && find[i][j+1]==find[i][j] && find[i+1][j]==find[i][j]
					&& find[i-1][j]>=find[i][j] && find[i][j-1]>=find[i][j] ){
						find[i][j]++;
						count++;
						change=true;
					}
		if(!change)
			break;
		D++;
	}
	return count;
}
void initial(int n){
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(table[i][j]=='x')
				find[i][j]=1;
			else
				find[i][j]=0;
}
int main(){
	int n;
	while(scanf("%d",&n)==1){
		(void)getchar();
		int i,j,sum;
		for(i=0;i<n;i++)
			gets(table[i]);

		sum=0;
		initial(n);
		sum+=find_square(n);
		initial(n);
		sum+=find_sss(n);
		printf("%d\n",sum);
	}
	return 0;
}
/*

The season of flying kites is well ahead. So what? Let us make an inventory for kites. We are given a square shaped sheet of paper. But many parts of this are already porous. Your challenge here is to count the total number of ways to cut a kite of any size from this sheet. By the way, the kite itself can't be porous :-) AND..................it must be either square shaped or diamond shaped.
                         x           x           xxx           xxx           xxx          xxx         xxxxx          xxx           x.x         x           x           xxx           xxx           xxx                        x
In the above figure first three are valid kites but not next two.

Input

Input contains an integer n (n ≤ 500), which is the size of the sheet. Then follows n lines each of which has n characters ('x' or '.'). Here the dotted parts resemble the porous parts of the sheet. Input is terminated by end of file.

Output

Output is very simple. Only print an integer according to the problem statement for each test case in a new line.

Sample Input
  
4
.xx.
xxxx
.xx.
.x..
3
xxx
xxx
xxx

Output for Sample Input

4
6
 
Problemsetter: Mohammad Sajjad Hossain

Bangladesh University of Engineering and Technology

*/