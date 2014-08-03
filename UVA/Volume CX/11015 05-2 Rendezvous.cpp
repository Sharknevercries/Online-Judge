/* 9088521 11015 05-2 Rendezvous Accepted C++ 0.024 2011-07-28 09:28:55 */
#include<stdio.h>
#define NOT 0
#define INT_MAX 2147483647
void floyd(int table[][22],int n){
	int i,j,k;
	for(k=0;k<n;k++)
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				if(table[i][k]>0&&table[k][j]>0)
					if(table[i][k]+table[k][j]<table[i][j]||table[i][j]==NOT)
						table[i][j]=table[j][i]=table[i][k]+table[k][j];				
}
int main(){
	int count=1;
	int n,m;
	while(scanf("%d%d",&n,&m)==2&&n!=0){
		(void)getchar();
		char name[22][11];
		int table[22][22]={NOT};
		int t,i,j,k;
		for(t=0;t<n;t++)
			gets(name[t]);
		for(t=0;t<m;t++){
			scanf("%d%d%d",&i,&j,&k);
			table[i-1][j-1]=table[j-1][i-1]=k;
		}

		floyd(table,n);

		int min=INT_MAX,num;
		for(i=0;i<n;i++){
			bool all_ac=true;
			int total=0;
			for(j=0;j<n&&all_ac;j++)			
				if(i!=j)
					if(table[i][j]>0)
						total+=table[i][j];
					else
						all_ac=false;			
			if(all_ac&&total<min){
				min=total;
				num=i;
			}
		}
		printf("Case #%d : %s\n",count++,name[num]);
	}
	return 0;
}
/*

Our team wants to meet together in one place to do our homework. Our 05-2 team has 22 members. Because of that we are a bit confused on what the best place is to meet one another. So we have decided to meet in the place that has the least total minimum cost. Total minimum cost is defined as the sum of the distance from all source places to destination place. In this problem you are asked to write a program that determines the possible place that has the least total minimum cost. The house of each member is considered as a place here.

Input

The input consists of at most 105 test cases. 

The first line of each test case consist two integers N (1 ≤ N ≤ 22) and M (1 ≤ M ≤ (N^2-N)/2), specifying the number of members and the number of path. Then it is followed by N lines each consisting of member’s name, each member’s name contains at most 10 lower case characters. It is followed by M lines contains three integers i, j (1≤ i, j ≤ N) and k (1 ≤ k ≤ 1000). It means the distance from place i to place j have k cost. 

If the place i to place j have k cost then from place j to place i have k cost too. The input N = 0 mark as the end of the input.

The member number starts from 1.

Output

For each test cases you should output one line contain like this:

“Case #i : XXX” (without quote)

where i replaced with the case number and XXX replaced with the member name that have the least total minimum cost. If there are two or more members that have the same least total minimum cost you should output the name of member that appear first.

Sample Input                          

4 3
timotius
harry
richard
januar
1 2 10
1 3 8
1 4 6
4 3
rocky
herwin
gaston
jefry
1 2 5
1 3 5
1 4 5
0 0  

Output for Sample Input

Case #1 : timotius
Case #2 : rocky

In the first sample input the first name is timotius, second name is harry. This means place 1 is the house of timotius, place 2 is the house of harry etc.

--------------------------------------------------------------------------------
Problem setter: Timotius Sakti
Moderator: Shahriar Manzoor, EPS

*/