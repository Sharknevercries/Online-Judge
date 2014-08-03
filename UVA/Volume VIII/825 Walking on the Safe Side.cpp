/* 825 Walking on the Safe Side Accepted C++ 0.008 2011-02-24 12:25:37 */
#include<stdio.h>
#include<stdlib.h>
#define UNSAFE -1
int main(){
	int n;
	while(scanf("%d",&n)==1){
		while(n--){
			char c;
			char str[100000];
			int W,N;
			int m[201][201];
			int i,j;
			int temp;
			scanf("%d%d",&W,&N);
			for(i=0;i<W+1;i++)
				for(j=0;j<N+1;j++)
					m[i][j]=0;
			c=getchar();
			for(i=1;i<=W;i++){
				gets(str);
				for(j=0;str[j]!='\0'&&str[j]!=' ';j++);				
				while(str[j++]!='\0'){
					for(temp=0;str[j]!='\0'&&str[j]!=' ';j++)
						temp=temp*10+str[j]-'0';	
					m[i][temp]=UNSAFE;}}
			/* DP */
			m[1][1]=1;
			for(i=1;i<W+1;i++)
				for(j=1;j<N+1;j++)
					if(m[i][j]==UNSAFE||(i==1&&j==1))
						continue;
					else
						m[i][j]=(m[i][j-1]==UNSAFE?0:m[i][j-1])+(m[i-1][j]==UNSAFE?0:m[i-1][j]);
			/* DP */
			printf("%d\n",m[W][N]);
			if(n>0)
				putchar('\n');
		}
	}
	return 0;
}
/*

Square City is a very easy place for people to walk around. The two-way streets run North-South or East-West dividing the city into regular blocks. Most street intersections are safe for pedestrians to cross. In some of them, however, crossing is not safe and pedestrians are forced to use the available underground passages. Such intersections are avoided by walkers. The entry to the city park is on the North-West corner of town, whereas the railway station is on the South-East corner. 

Suppose you want to go from the park to the railway station, and do not want to walk more than the required number of blocks. You also want to make your way avoiding the underground passages, that would introduce extra delay. Your task is to determine the number of different paths that you can follow from the park to the station, satisfying both requirements. 

The example in the picture illustrates a city with 4 E-W streets and 5 N-S streets. Three intersections are marked as unsafe. The path from the park to the station is 3 + 4 = 7 blocks long and there are 4 such paths that avoid the underground passages. 

Input  

The input begins with a single positive integer on a line by itself indicating the number of the cases following, each of them as described below. This line is followed by a blank line, and there is also a blank line between two consecutive inputs. 

The first line of the input contains the number of East-West streets W and the number of North-South streets N. Each one of the following W lines starts with the number of an East-West street, followed by zero or more numbers of the North-South crossings which are unsafe. Streets are numbered from 1. 

Output  

For each test case, the output must follow the description below. The outputs of two consecutive cases will be separated by a blank line. 

The number of different minimal paths from the park to the station avoiding underground passages. 

Sample Input  

1

4 5
1
2 2
3 3 5
4

Sample Output  

4
--------------------------------------------------------------------------------

Cristina Ribeiro, MIUP'2001 

*/