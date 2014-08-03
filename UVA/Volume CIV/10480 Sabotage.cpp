/* 13680779	10480	Sabotage	Accepted	C++	0.016	2014-05-26 08:00:15 */
#include<cstdio>
#include<vector>
#include<queue>
#include<string.h>
#include<algorithm>
using namespace std;
struct edge{
	int v, capacity, rev;
	// v:目標點, capacity:容量 rev:反向邊的編號
};
vector<edge> connect[51];
void add_edge(int u, int v, int capacity){
	connect[u].push_back(edge{ v, capacity, connect[v].size() });
	connect[v].push_back(edge{ u, 0, connect[u].size() - 1 });
	// add directed edge u to v (capacity)
	// and add converted edge v to u (flow)
}
int level[51]; //紀錄某點到源點s的距離
int iter[51]; //紀錄某點已經流到哪個點了
bool V[51]; // 紀錄此點屬於源側
bool T[51][51]; // 紀錄此邊已被輸出
int n, m;

void BFS(int s){ // fina a way from s to t
	memset(level, -1, sizeof(level));
	queue<int> Q;
	level[s] = 0;
	Q.push(s);
	while (!Q.empty()){
		int u = Q.front(); Q.pop();
		for (int i = 0; i < connect[u].size(); i++){
			edge &e = connect[u][i];
			if (e.capacity>0 && level[e.v] < 0){ // capacity is not full
				level[e.v] = level[u] + 1;
				Q.push(e.v);
			}
		}
	}
}
int DFS(int u, int t, int flow){
	if (u == t) //抵達匯點
		return flow;
	for (int &i = iter[u]; i < connect[u].size(); i++){
		edge &e = connect[u][i];
		if (e.capacity > 0 && level[u] < level[e.v]){ //還能流且還要流向高處
			int d = DFS(e.v, t, min(flow, e.capacity));
			if (d > 0){ //有流到匯點
				e.capacity -= d;
				connect[e.v][e.rev].capacity += d;
				return d;
			}
		}
	}
	return 0; // 流不到匯點
}
int max_flow(int s, int t){
	// Dinic algorithm
	int flow = 0;
	while (true){
		BFS(s);
		if (level[t] < 0) // 無增廣路徑可走
			return flow;
		memset(iter, 0, sizeof(iter));
		while (true){
			int tmp = DFS(s, t, 2e9);
			if (tmp <= 0)
				break;
			flow += tmp;
		}
	}
}
void find(int s){ // 查找某點是否屬於源側
	V[s] = true;
	for (int i = 0; i < connect[s].size(); i++){
		edge &e = connect[s][i];
		if (!V[e.v] && e.capacity > 0) // 此邊不是瓶頸
			find(e.v);
	}
}
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	while (scanf("%d%d", &n, &m) == 2){
		if (n == 0 && m == 0)
			break;
		for (int i = 1; i <= n; i++)
			connect[i].clear();
		for (int i = 0; i < m; i++){
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			add_edge(a, b, c);
			add_edge(b, a, c);
		}
		max_flow(1, 2);
		memset(V, false, sizeof(V));
		find(1);
		memset(T, false, sizeof(T));
		for (int i = 1; i <= n; i++){
			if (V[i]){
				for (int j = 0; j < connect[i].size(); j++){
					edge e = connect[i][j];
					if (!V[e.v] && !T[i][e.v]){ // 因為加邊時會加兩
						printf("%d %d\n", i, e.v);
						T[i][e.v] = T[e.v][i] = true;
					}
				}
			}
		}
		putchar('\n');
	}
	return 0;
}
/*

Sabotage
The regime of a small but wealthy dictatorship has been abruptly overthrown by an unexpected rebellion. Because of the enormous disturbances this is causing in world economy, an imperialist military super power has decided to invade the country and reinstall the old regime.

For this operation to be successful, communication between the capital and the largest city must be completely cut. This is a difficult task, since all cities in the country are connected by a computer network using the Internet Protocol, which allows messages to take any path through the network. Because of this, the network must be completely split in two parts, with the capital in one part and the largest city in the other, and with no connections between the parts.

There are large differences in the costs of sabotaging different connections, since some are much more easy to get to than others.

Write a program that, given a network specification and the costs of sabotaging each connection, determines which connections to cut in order to separate the capital and the largest city to the lowest possible cost.

Input

Input file contains several sets of input. The description of each set is given below.

The first line of each set has two integers, separated by a space: First one the number of cities, n in the network, which is at most 50. The second one is the total number of connections, m, at most 500.

The following m lines specify the connections. Each line has three parts separated by spaces: The first two are the cities tied together by that connection (numbers in the range 1 - n). Then follows the cost of cutting the connection (an integer in the range 1 to 40000000). Each pair of cites can appear at most once in this list.

Input is terminated by a case where values of n and m are zero. This case should not be processed. For every input set the capital is city number 1, and the largest city is number 2.

Output

For each set of input you should produce several lines of output. The description of output for each set of input is given below:

The output for each set should be the pairs of cities (i.e. numbers) between which the connection should be cut (in any order), each pair on one line with the numbers separated by a space. If there is more than one solution, any one of them will do.

Print a blank line after the output for each set of input.

Sample Input

5 8
1 4 30
1 3 70
5 3 20
4 3 5
4 5 15
5 2 10
3 2 25
2 4 50
5 8
1 4 30
1 3 70
5 3 20
4 3 5
4 5 15
5 2 10
3 2 25
2 4 50
0 0
Sample Output

4 1
3 4
3 5
3 2

4 1
3 4
3 5
3 2

Problem setter: Jesper Larsson, Lund University, Sweden

*/