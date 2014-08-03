/* 9250997 615 Is It A Tree? Accepted C++ 0.012 2011-09-12 07:33:00 */
#include<stdio.h>
#include<string.h>
bool connect[300][300];
int name[10000];
int count[10000];
int ptr;
void readin(int m1,int m2){
	int i,j;

	for(i=0;i<ptr;i++)
		if(name[i]==m1)
			break;
	if(i>=ptr)
		name[ptr++]=m1;

	for(j=0;j<ptr;j++)
		if(name[j]==m2)
			break;
	if(j>=ptr)
		name[ptr++]=m2;
	count[j]++;

	connect[i][j]=true;
}
void travel(int pos,int *t){
	(*t)++;
	for(int i=0;i<ptr;i++)
		if(connect[pos][i])
			travel(i,t);
}
int main(){
	
	int c=1;
	int i,m1,m2;
	while(scanf("%d%d",&m1,&m2)==2){
		if(m1==-1&&m2==-1)
			break;

		memset(&count,0,sizeof(count));
		memset(&connect,false,sizeof(connect));
		ptr=0;

		if(m1==0&&m2==0)
			printf("Case %d is a tree.\n",c++);
		else{
			readin(m1,m2);
			while(true){
				scanf("%d%d",&m1,&m2);
				if(m1==0&&m2==0)
					break;
				readin(m1,m2);
			}
			
			int zero_count=0,pos;
			for(i=0;i<ptr;i++)
				if(count[i]==0)
					zero_count++,pos=i;
				else if(count[i]>1)
					break;
			if(zero_count==1&&i>=ptr){
				int t=0;
				travel(pos,&t);
				if(t==ptr)
					printf("Case %d is a tree.\n",c++);
				else
					printf("Case %d is not a tree.\n",c++);
			}
			else
				printf("Case %d is not a tree.\n",c++);
		}
	}
	return 0;
}
/*

A tree is a well-known data structure that is either empty (null, void, nothing) or is a set of one or more nodes connected by directed edges between nodes satisfying the following properties.
 
•There is exactly one node, called the root, to which no directed edges point. 
•Every node except the root has exactly one edge pointing to it. 
•There is a unique sequence of directed edges from the root to each node. 

For example, consider the illustrations below, in which nodes are represented by circles and edges are represented by lines with arrowheads. The first two of these are trees, but the last is not.
 
In this problem you will be given several descriptions of collections of nodes connected by directed edges. For each of these you are to determine if the collection satisfies the definition of a tree or not.
 
Input  

The input will consist of a sequence of descriptions (test cases) followed by a pair of negative integers. Each test case will consist of a sequence of edge descriptions followed by a pair of zeroes Each edge description will consist of a pair of integers; the first integer identifies the node from which the edge begins, and the second integer identifies the node to which the edge is directed. Node numbers will always be greater than zero.
 
Output 

For each test case display the line ``Case k is a tree." or the line ``Case k is not a tree.", where k corresponds to the test case number (they are sequentially numbered starting with 1).
 
Sample Input  

6 8  5 3  5 2  6 4
5 6  0 0

8 1  7 3  6 2  8 9  7 5
7 4  7 8  7 6  0 0

3 8  6 8  6 4
5 3  5 6  5 2  0 0
-1 -1

 Sample Output  

Case 1 is a tree.
Case 2 is a tree.
Case 3 is not a tree.

--------------------------------------------------------------------------------

Miguel A. Revilla 
1999-03-24 

*/