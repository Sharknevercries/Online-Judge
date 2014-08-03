/* 4844299	 Oct 22, 2013 5:50:58 PM	Shark	 292B - Network Topology	 GNU C++	Accepted	62 ms	400 KB */
#include<stdio.h>
int main(){
	int n,m;
	while( scanf("%d%d",&n,&m)==2 ){
		int count[100001]={0};
		int one,two;
		for(int i=0;i<m;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			count[a]++,count[b]++;
		}
		one=two=0;
		for(int i=1;i<=n;i++)
			if( count[i]==1 )
				one++;
			else if( count[i]==2 )
				two++;
		if( two==n )
			puts("ring topology");
		else if( two==n-2&&one==2 )
			puts("bus topology");
		else if( one==n-1 )
			puts("star topology");
		else
			puts("unknown topology");
	}
	return 0;
}
/*

B. Network Topology
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
This problem uses a simplified network topology model, please read the problem statement carefully and use it as a formal document as you develop the solution.

Polycarpus continues working as a system administrator in a large corporation. The computer network of this corporation consists of n computers, some of them are connected by a cable. The computers are indexed by integers from 1 to n. It's known that any two computers connected by cable directly or through other computers

Polycarpus decided to find out the network's topology. A network topology is the way of describing the network configuration, the scheme that shows the location and the connections of network devices.

Polycarpus knows three main network topologies: bus, ring and star. A bus is the topology that represents a shared cable with all computers connected with it. In the ring topology the cable connects each computer only with two other ones. A star is the topology where all computers of a network are connected to the single central node.

Let's represent each of these network topologies as a connected non-directed graph. A bus is a connected graph that is the only path, that is, the graph where all nodes are connected with two other ones except for some two nodes that are the beginning and the end of the path. A ring is a connected graph, where all nodes are connected with two other ones. A star is a connected graph, where a single central node is singled out and connected with all other nodes. For clarifications, see the picture.

(1) — bus, (2) — ring, (3) — star
You've got a connected non-directed graph that characterizes the computer network in Polycarpus' corporation. Help him find out, which topology type the given network is. If that is impossible to do, say that the network's topology is unknown.

Input
The first line contains two space-separated integers n and m (4 ≤ n ≤ 105; 3 ≤ m ≤ 105) — the number of nodes and edges in the graph, correspondingly. Next m lines contain the description of the graph's edges. The i-th line contains a space-separated pair of integers xi, yi (1 ≤ xi, yi ≤ n) — the numbers of nodes that are connected by the i-the edge.

It is guaranteed that the given graph is connected. There is at most one edge between any two nodes. No edge connects a node with itself.

Output
In a single line print the network topology name of the given graph. If the answer is the bus, print "bus topology" (without the quotes), if the answer is the ring, print "ring topology" (without the quotes), if the answer is the star, print "star topology" (without the quotes). If no answer fits, print "unknown topology" (without the quotes).

Sample test(s)
input
4 3
1 2
2 3
3 4
output
bus topology
input
4 4
1 2
2 3
3 4
4 1
output
ring topology
input
4 3
1 2
1 3
1 4
output
star topology
input
4 4
1 2
2 3
3 1
1 4
output
unknown topology

*/