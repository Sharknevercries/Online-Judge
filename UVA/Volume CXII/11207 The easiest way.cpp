/* 9038793 11207 The easiest way Accepted C++ 0.016 2011-07-11 11:44:56 */
#include<stdio.h>
#define SWAP(x,y) { int s=x; x=y; y=s; }
#define MAX 100000
int main(){
	int n;
	while(scanf("%d",&n)==1&&n!=0){
		double max=0,t;
		int num;
		int m[MAX][2];
		for(int i=0;i<n;i++){
			scanf("%d%d",&m[i][0],&m[i][1]);
			if(m[i][0]<m[i][1])
				SWAP(m[i][0],m[i][1]);				
		}
		for(int i=0;i<n;i++){
			double temp1,temp2;
			temp1=((double)m[i][0]/4)>m[i][1]?m[i][1]:(double)m[i][0]/4; // 1*4
			temp2=(double)m[i][1]/2; // 2*2
			if(temp1>max){
				max=temp1;
				num=i+1;
			}
			if(temp2>max){
				max=temp2;
				num=i+1;
			}
		}		
		printf("%d\n",num);
	}
	return 0;
}
/*

Background

As a participant in the Programming Olympiads in Murcia, your purpose is to win as many paper birds as possible. But this year the problems are so difficult... So you decide to take the easiest way: to make the paper birds yourself. 

The Problem

You want to make 4 paper birds of the same size, pretending that you have solved 4 problems --thus classifying for SWERC'2007--. N rectangular pieces of paper of different sizes are available. Each piece of paper, i, has width wi and height hi. Your task is to select one piece in order to maximize the size of the 4 birds. You have to take into account that, to make a bird, a square piece of paper is needed. The paper can be cut off, but not glued.

If more than one optimum piece of paper is possible, you have to indicate the first one.

The Input

The input may contain several test cases. For each test case, the first line indicates the number of pieces of paper, N. The following N lines contain the sizes of the pieces of paper; each line contains two integers: wi and hi. The input ends with a case where N=0.

The Output

For each test case (except for the case with N=0), the output should consist of an integer indicating the number of the piece to make the biggest paper birds. The first piece is 1, the second is 2, and so on. If many solutions are possible, output the first one.

Sample Input

3
10 20
40 8
12 12
3
140 122
122 140
100 170
2
120 170
71 500
0

 Sample Output

2
1
2

*/