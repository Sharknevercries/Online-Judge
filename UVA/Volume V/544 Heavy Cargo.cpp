/* 9250860 544 Heavy Cargo Accepted C++ 0.028 2011-09-12 06:13:51 */
#include<stdio.h>
#include<string.h>
#define MAX(x,y) ( (x) >= (y) ? (x) : (y) )
#define MIN(x,y) ( (x) >= (y) ? (y) : (x) )
int M[200][200];
char name[200][35];
int n,m;
void floyd(){
	int i,j,k;
	for(k=0;k<n;k++)
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				M[i][j]=MAX(M[i][j],MIN(M[i][k],M[k][j]));
}
int main(){
	int count=1;	
	while(scanf("%d%d",&n,&m)==2){
		if(n==0&&m==0)
			break;
		int i,j,k,d,index;
		char str1[35],str2[35];

		memset(M,0,sizeof(M));
		index=0;

		for(i=0;i<m;i++){
			getchar();
			scanf("%s%s%d",str1,str2,&d);

			for(j=0;j<index;j++)
				if(strcmp(name[j],str1)==0)
					break;
			if(j>=index)
				strcpy(name[index++],str1);
			for(k=0;k<index;k++)
				if(strcmp(name[k],str2)==0)
					break;
			if(k>=index)
				strcpy(name[index++],str2);

			M[j][k]=M[k][j]=d;
		}

		getchar();
		scanf("%s%s",str1,str2);

		for(i=0;i<index;i++)
			if(strcmp(name[i],str1)==0)
				break;
		for(j=0;j<index;j++)
			if(strcmp(name[j],str2)==0)
				break;

		floyd();

		printf("Scenario #%d\n",count++);
		printf("%d tons\n\n",M[i][j]);

	}
	return 0;
}
/*

Big Johnsson Trucks Inc. is a company specialized in manufacturing big trucks. Their latest model, the Godzilla V12, is so big that the amount of cargo you can transport with it is never limited by the truck itself. It is only limited by the weight restrictions that apply for the roads along the path you want to drive.
 
Given start and destination city, your job is to determine the maximum load of the Godzilla V12 so that there still exists a path between the two specified cities.
 
Input 

The input file will contain one or more test cases. The first line of each test case will contain two integers: the number of cities n ( ) and the number of road segments r ( ) making up the street network.
 Then r lines will follow, each one describing one road segment by naming the two cities connected by the segment and giving the weight limit for trucks that use this segment. Names are not longer than 30 characters and do not contain white-space characters. Weight limits are integers in the range 0 - 10000. Roads can always be travelled in both directions.
 
The last line of the test case contains two city names: start and destination. 

Input will be terminated by two values of 0 for n and r. 

Output  

For each test case, print three lines: •a line saying ``Scenario #x" where x is the number of the test case
 •a line saying ``y tons" where y is the maximum possible load 
•a blank line 

Sample Input  

4 3
Karlsruhe Stuttgart 100
Stuttgart Ulm 80
Ulm Muenchen 120
Karlsruhe Muenchen
5 5
Karlsruhe Stuttgart 100
Stuttgart Ulm 80
Ulm Muenchen 120
Karlsruhe Hamburg 220
Hamburg Muenchen 170
Muenchen Karlsruhe
0 0

 Sample Output  
 
Scenario #1
80 tons

Scenario #2
170 tons

--------------------------------------------------------------------------------

Miguel A. Revilla 
1999-01-11

*/