/* 9570591 820 Internet Bandwidth Accepted C++ 0.060 2011-12-18 02:57:50 */
#include<stdio.h>
#include<string.h>
#include<queue>
bool con[100][100];
int C[100][100],R[100][100],F[100][100];
bool visit[100];
int flow[100];
int path[100];
int BFS(int s,int t,int n){
	memset(visit,false,sizeof(visit));
	std::queue<int> Q;
	visit[s]=true,path[s]=s,flow[s]=2e9;
	Q.push(s);
	while(!Q.empty()){
		int i=Q.front();	Q.pop();
		for(int j=0;j<n;j++){
			if(R[i][j]>0&&!visit[j]){
				visit[j]=true;
				path[j]=i;
				if( flow[i]>R[i][j] )
					flow[j]=R[i][j];
				else
					flow[j]=flow[i];
				if(j==t)
					return flow[t];
				else
					Q.push(j);
			}
		}
	}
	return 0;
}
int Flow(int s,int t,int n){
	memset(F,0,sizeof(F));
	memcpy(R,C,sizeof(C));
	int max_f,f;
	for( max_f=0; f=BFS(s,t,n) ; max_f+=f ){
		for(int i=path[t],j=t; i!=j ; j=i,i=path[i] ){
			F[i][j]+=f;
			F[j][i]-=F[i][j];
			R[i][j]=C[i][j]-F[i][j];
			R[j][i]=C[j][i]-F[j][i];
		}
	}
	return max_f;
}
int main(){
	//freopen("input.txt","r",stdin);
	int n;
	int _case=1;
	while(scanf("%d",&n)==1){
		if(n==0)
			break;
		memset(C,0,sizeof(C));
		int s,t,c;
		scanf("%d%d%d",&s,&t,&c);
		for(int i=1;i<=c;i++){
			int a,b,f;
			scanf("%d%d%d",&a,&b,&f);
			C[a-1][b-1]=C[b-1][a-1]+=f;
		}
		int ans=Flow(s-1,t-1,n);
		printf("Network %d\n",_case++);
		printf("The bandwidth is %d.\n\n",ans);
	}
	return 0;
}
/*

On the Internet, machines (nodes) are richly interconnected, and many paths may exist between a given pair of nodes. The total message-carrying capacity (bandwidth) between two given nodes is the maximal amount of data per unit time that can be transmitted from one node to the other. Using a technique called packet switching, this data can be transmitted along several paths at the same time.
 
 For example, the following figure shows a network with four nodes (shown as circles), with a total of five connections among them. Every connection is labeled with a bandwidth that represents its data-carrying capacity per unit time.
 
In our example, the bandwidth between node 1 and node 4 is 25, which might be thought of as the sum of the bandwidths 10 along the path 1-2-4, 10 along the path 1-3-4, and 5 along the path 1-2-3-4. No other combination of paths between nodes 1 and 4 provides a larger bandwidth.
 
You must write a program that computes the bandwidth between two given nodes in a network, given the individual bandwidths of all the connections in the network. In this problem, assume that the bandwidth of a connection is always the same in both directions (which is not necessarily true in the real world).
 
Input  

The input file contains descriptions of several networks. Every description starts with a line containing a single integer n (2 ≤n ≤100), which is the number of nodes in the network. The nodes are numbered from 1 to n. The next line contains three numbers s, t, and c. The numbers s and t are the source and destination nodes, and the number c is the total number of connections in the network. Following this are c lines describing the connections. Each of these lines contains three integers: the first two are the numbers of the connected nodes, and the third number is the bandwidth of the connection. The bandwidth is a non-negative number not greater than 1000.
 
There might be more than one connection between a pair of nodes, but a node cannot be connected to itself. All connections are bi-directional, i.e. data can be transmitted in both directions along a connection, but the sum of the amount of data transmitted in both directions must be less than the bandwidth.
 
A line containing the number 0 follows the last network description, and terminates the input.
 
Output  

For each network description, first print the number of the network. Then print the total bandwidth between the source node s and the destination node t, following the format of the sample output. Print a blank line after each test case.
 
Sample Input

4
1 4 5
1 2 20
1 3 10
2 3 5
2 4 10
3 4 20
0

Output for the Sample Input
 
Network 1The bandwidth is 25. 

--------------------------------------------------------------------------------
ACM World Finals 2000, Problem E 

*/