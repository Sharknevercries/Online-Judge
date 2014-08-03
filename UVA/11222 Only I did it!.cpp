/* 12411988	11222	Only I did it!	Accepted	C++	0.025	2013-09-28 06:19:54 */
#include<stdio.h>
int main(){
	int t;
	scanf("%d",&t);
	for(int T=1;T<=t;T++){
		bool P[3][10001]={false};
		bool unique[3][10001]={false};
		int count[3]={0};
		for(int i=0;i<3;i++){
			int n;
			scanf("%d",&n);
			for(int j=0;j<n;j++){
				int p;
				scanf("%d",&p);
				P[i][p]=true;
			}
		}
		for(int i=0;i<10001;i++){
			if( P[0][i]&&!P[1][i]&&!P[2][i] )
				unique[0][i]=true,count[0]++;
			if( P[1][i]&&!P[0][i]&&!P[2][i] )
				unique[1][i]=true,count[1]++;
			if( P[2][i]&&!P[0][i]&&!P[1][i] )
				unique[2][i]=true,count[2]++;
		}
		printf("Case #%d:\n",T);
		int max=0;
		for(int i=0;i<3;i++)
			if( count[i]>max )
				max=count[i];
		for(int i=0;i<3;i++)
			if( count[i]==max ){
				printf("%d %d",i+1,max);
				for(int j=0;j<10001;j++)
					if( unique[i][j] )
						printf(" %d",j);
				putchar('\n');
			}
	}
	return 0;
}
/*


D. Only I did it!

Time limit: 1s

Once upon a time, in the land of Ceeplenty, lived 3 friends that liked to solve problems. They used internet engines to look for problems and they often tried to solve the problems that none of the other 2 had solved. They once met you and you managed to convince them that you were better at problem solving. So they asked you to write a program that tells which of the 3 friends solved more problems that none of the other 2 have solved.

Input

The first line of input gives the number of cases, T (1 ≤ T ≤ 20). T test cases follow. Each test case is composed of three lines corresponding to the problems solved by the first, second and third friend, respectively. Each of these lines has an integer S (0 ≤ S ≤ 1000) followed by the list of S solved problems. A solved problem is identified uniquely by a positive integer smaller or equal than 10000.

Output

The output is comprised a line identifying the test case with the string Case #C: (where C is the number of the current test case). Then print another line with the number of the friend (1, 2 or 3) asked in the description followed by the number of problems that he solved but none of the other 2 did, followed by the sorted list of these problems in one line. When there is a tie, print one such line for each tied friend, sorted by the number of the friend.

Sample input

4
3 1 2 3
4 4 5 6 7
5 8 9 10 11 12
2 1 5
2 2 3
3 2 3 1
6 400 401 402 403 404 405
2 101 100
7 400 401 402 403 404 405 406
1 1
1 2
1 3
Sample output

Case #1:
3 5 8 9 10 11 12
Case #2:
1 1 5
Case #3:
2 2 100 101
Case #4:
1 1 1
2 1 2
3 1 3
Problem setter: Diego Caminha Barbosa de Oliveira.
Universidade Federal do Rio Grande do Norte Qualifying Contest IV, June 9th, 2007.

*/