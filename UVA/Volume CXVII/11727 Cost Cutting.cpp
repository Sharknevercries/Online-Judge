/* 9162189 11727 Cost Cutting Accepted C++ 0.008 2011-08-17 13:45:47 */
#include<stdio.h>
#define SWAP(x,y) { int temp=x; x=y; y=temp; }
int main(){
	int n;
	while(scanf("%d",&n)==1){
		int t;
		for(t=1;t<=n;t++){
			int m[3];
			scanf("%d%d%d",&m[0],&m[1],&m[2]);
			for(int i=0;i<3;i++)
				for(int j=i+1;j<3;j++)
					if(m[i]>m[j])
						SWAP(m[i],m[j]);
			printf("Case %d: %d\n",t,m[1]);
		}
	}
	return 0;
}
/*

 Company XYZ have been badly hit by recession and is taking a lot of cost cutting measures. Some of these measures include giving up office space, going open source, reducing incentives, cutting on luxuries and issuing pink slips.

They have got three (3) employees working in the accounts department and are going to lay-off two (2) of them. After a series of meetings, they have decided to dislodge the person who gets the most salary and the one who gets the least. This is usually the general trend during crisis like this.

You will be given the salaries of these 3 employees working in the accounts department. You have to find out the salary of the person who survives.

Input

The first line of input is an integer T (T<20) that indicates the number of test cases. Each case consists of a line with 3 distinct positive integers. These 3 integers represent the salaries of the three employees. All these integers will be in the range [1000, 10000].

Output

For each case, output the case number followed by the salary of the person who survives.

Sample Input                            

3
1000 2000 3000
3000 2500 1500
1500 1200 1800

Output for Sample Input

Case 1: 2000
Case 2: 2500
Case 3: 1500
  
--------------------------------------------------------------------------------

Problem Setter: Sohel Hafiz, Special Thanks: Md. Arifuzzaman Arif 

*/