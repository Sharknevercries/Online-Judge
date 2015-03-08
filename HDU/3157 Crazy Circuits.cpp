/* 12934695	2015-02-11 16:47:34	Accepted	3157	31MS	1680K	2771 B	G++	Shark */
#include<bits\stdc++.h>
#define N 100
#define INF 1e9
#define NONE -1
using namespace std;
struct Edge{
	int v, cap, rev;
	bool mark;
	Edge(){}
	Edge(int v, int cap, int rev, bool mark) :v(v), cap(cap), rev(rev), mark(mark){}
};
vector<Edge> G[N];
void addEdge(int u, int v, int cap){
	G[u].push_back(Edge(v, cap, G[v].size(), true));
	G[v].push_back(Edge(u, 0, G[u].size() - 1, false));
}
int level[N], iter[N];
void BFS(int s){
	memset(level, NONE, sizeof(level));
	queue<int> Q;
	level[s] = 0;
	Q.push(s);
	while (!Q.empty()){
		int u = Q.front();	Q.pop();
		for (int i = 0; i < G[u].size(); i++){
			Edge &e = G[u][i];
			if (e.cap > 0 && level[e.v] == NONE)
				level[e.v] = level[u] + 1, Q.push(e.v);
		}
	}
}
int DFS(int u, int t, int flow){
	if (u == t)	return flow;
	for (int &i = iter[u]; i < G[u].size(); i++){
		Edge &e = G[u][i];
		if (e.cap > 0 && level[u] < level[e.v]){
			int d = DFS(e.v, t, min(flow, e.cap));
			if (d > 0){
				e.cap -= d;
				G[e.v][e.rev].cap += d;
				return d;
			}
		}
	}
	return 0;
}
int maxFlow(int s, int t){
	int flow = 0;
	while (true){
		BFS(s);
		if (level[t] == NONE)
			return flow;
		memset(iter, 0, sizeof(iter));
		while (true){
			int tmp = DFS(s, t, INF);
			if (tmp <= 0)	break;
			flow += tmp;
		}
	}
}
int n, m;
int s, t, newS, newT;
int w[N];
bool judge(){
	for (int i = 0; i < G[newS].size(); i++){
		Edge e = G[newS][i];
		if (!e.mark)	continue;
		if (e.cap)
			return false;
	}
	return true;
}
int main(){
	while (scanf("%d%d", &n, &m) == 2){
		if (n == 0 && m == 0)	break;
		s = 0, t = n + 1, newS = t + 1, newT = newS + 1;
		memset(w, 0, sizeof(w));
		for (int i = 0; i <= newT; i++)
			G[i].clear();
		for (int i = 1; i <= m; i++){
			char str[50];
			int u, v, x;
			scanf("%s", str);
			if (str[0] == '+')
				u = s;
			else
				sscanf(str, "%d", &u);
			scanf("%s", str);
			if (str[0] == '-')
				v = t;
			else
				sscanf(str, "%d", &v);
			addEdge(u, v, INF);
			scanf("%d", &x);
			w[u] -= x, w[v] += x;
		}
		for (int i = s; i <= t; i++){
			if (w[i] > 0)	addEdge(newS, i, w[i]);
			if (w[i] < 0)	addEdge(i, newT, -w[i]);
		}
		maxFlow(newS, newT);
		addEdge(t, s, INF);
		maxFlow(newS, newT);
		if (judge()){
			Edge e;
			for (int i = 0; i < G[t].size(); i++){
				e = G[t][i];
				if (!e.mark)	continue;
				if (e.v == s)
					break;
			}
			printf("%d\n", G[e.v][e.rev].cap);
		}
		else
			puts("impossible");
	}
	return 0;
}
/*

Crazy Circuits

Time Limit: 4000/2000 MS (Java/Others)    Memory Limit: 32768/32768 K (Java/Others)
Total Submission(s): 591    Accepted Submission(s): 298


Problem Description
You¡¦ve just built a circuit board for your new robot, and now you need to power it. Your robot circuit consists of a number of electrical components that each require a certain amount of current to operate. Every component has a + and a - lead, which are connected on the circuit board at junctions. Current flows through the component from + to - (but note that a component does not "use up" the current: everything that comes in through the + end goes out the - end).

The junctions on the board are labeled 1, ..., N, except for two special junctions labeled + and - where the power supply terminals are connected. The + terminal only connects + leads, and the - terminal only connects - leads. All current that enters a junction from the - leads of connected components exits through connected + leads, but you are able to control how much current flows to each connected + lead at every junction (though methods for doing so are beyond the scope of this problem1). Moreover, you know you have assembled the circuit in such a way that there are no feedback loops (components chained in a manner that allows current to flow in a loop).



Figure 1: Examples of two valid circuit diagrams.
In (a), all components can be powered along directed paths from the positive terminal to the negative terminal.
In (b), components 4 and 6 cannot be powered, since there is no directed path from junction 4 to the negative terminal.

In the interest of saving power, and also to ensure that your circuit does not overheat, you would like to use as little current as possible to get your robot to work. What is the smallest amount of current that you need to put through the + terminal (which you can imagine all necessarily leaving through the - terminal) so that every component on your robot receives its required supply of current to function?

Hint
1 For those who are electronics-inclined, imagine that you have the ability to adjust the potential on any componentwithout altering its current requirement, or equivalently that there is an accurate variable potentiometer connected in series with each component that you can adjust. Your power supply will have ample potential for the circuit.


Input
The input file will contain multiple test cases. Each test case begins with a single line containing two integers: N (0 <= N <= 50), the number of junctions not including the positive and negative terminals, and M (1 <= M <= 200), the number of components in the circuit diagram. The next M lines each contain a description of some component in the diagram. The ith component description contains three fields: pi, the positive junction to which the component is connected, ni, the negative junction to which the component is connected, and an integer Ii (1 <= Ii <= 100), the minimum amount of current required for component i to function. The junctions pi and ni are specified as either the character '+' indicating the positive terminal, the character '-' indicating the negative terminal, or an integer (between 1 and N) indicating one of the numbered junctions. No two components have the same positive junction and the same negative junction. The end-of-file is denoted by an invalid test case with N = M = 0 and should not be processed.


Output
For each input test case, your program should print out either a single integer indicating the minimum amount of current that must be supplied at the positive terminal in order to ensure that every component is powered, or the message "impossible" if there is no way to direct a sufficient amount of current to each component simultaneously.


Sample Input
6 10
+ 1 1
1 2 1
1 3 2
2 4 5
+ - 1
4 3 2
3 5 5
4 6 2
5 - 1
6 5 3
4 6
+ 1 8
1 2 4
1 3 5
2 4 6
3 - 1
3 4 3
0 0


Sample Output
9
impossible


Source
2008 ACM-ICPC Pacific Northwest Region


Recommend
chenrui   |   We have carefully selected several similar problems for you:  3395 3155 3154 2883 1853 

*/