/* 9198943 10004 Bicoloring Accepted C++ 0.008 2011-08-28 12:33:42 */
#include<stdio.h>
#define EMPTY 0
#define GREEN 1
#define RED 2
#define CHANGE_COLOR(x) ( (x) == RED ? GREEN : RED )
struct data{
	int pos;
	int pat;
};
struct data quene[1000];
bool table[200][200];
bool visited[200];
int color[200];
int head,tail;

void pop(int *pos,int *pat){
	(*pos)=quene[tail].pos;
	(*pat)=quene[tail].pat;
	tail++;
}
void push(int pos,int pat){
	quene[head].pos=pos;
	quene[head].pat=pat;
	head++;
}
int BFS(int n){
	int pos,pat;
	while(head>tail){
		pop(&pos,&pat);
		
		pat=CHANGE_COLOR(pat);
		for(int i=0;i<n;i++)
			if(table[pos][i])
				if(!visited[i]){
					visited[i]=true;
					color[i]=pat;
					push(i,pat);
				}
				else
					if(color[i]!=EMPTY&&color[i]!=pat)
						return false;
	}
	return true;
}
void initial(int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			table[i][j]=false;
		visited[i]=false;
		color[i]=EMPTY;
	}	
	head=tail=0;
}
int main(){
	int n;
	while(scanf("%d",&n)==1&&n!=0){
		int i,j,k;
		int m;
		scanf("%d",&m);

		initial(n);
		for(i=0;i<m;i++){
			scanf("%d%d",&j,&k);
			table[j][k]=table[k][j]=true;
		}

		push(0,RED);
		visited[0]=true;
		color[0]=RED;
		if(BFS(n))
			puts("BICOLORABLE.");
		else
			puts("NOT BICOLORABLE.");
	}
	return 0;
}
/*

 In 1976 the ``Four Color Map Theorem" was proven with the assistance of a computer. This theorem states that every map can be colored using only four colors, in such a way that no region is colored using the same color as a neighbor region.
 Here you are asked to solve a simpler similar problem. You have to decide whether a given arbitrary connected graph can be bicolored. That is, if one can assign colors (from a palette of two) to the nodes in such a way that no two adjacent nodes have the same color. To simplify the problem you can assume:
 
•no node will have an edge to itself. 
•the graph is nondirected. That is, if a node a is said to be connected to a node b, then you must assume that b is connected to a.
 •the graph will be strongly connected. That is, there will be at least one path from any node to any other node.
 
Input  

The input consists of several test cases. Each test case starts with a line containing the number n ( 1 < n < 200) of different nodes. The second line contains the number of edges l. After this, l lines will follow, each containing two numbers that specify an edge between the two nodes that they represent. A node in the graph will be labeled using a number a ( ).
 An input with n = 0 will mark the end of the input and is not to be processed. 
 
Output  

You have to decide whether the input graph can be bicolored or not, and print it as shown below.
 
Sample Input  

3
3
0 1
1 2
2 0
9
8
0 1
0 2
0 3
0 4
0 5
0 6
0 7
0 8
0

 Sample Output 

NOT BICOLORABLE.
BICOLORABLE.

--------------------------------------------------------------------------------

Miguel Revilla 
2000-08-21 

*/