/* 13800439	840502	1639	Accepted	224K	16MS	C++	2667B	2015-01-21 19:03:05 */
#include<bits\stdc++.h>
#define INF 2e9
#define NONE -1
using namespace std;
struct node{
	int u, v, len;
	node(){}
	node(int u, int v, int len) :u(u), v(v), len(len){}
};
node del[30];
int G[30][30];
int DP[30];
int pre[30];
bool V[30];
bool link[30][30];
int n, k, q;
int p; // 子生成樹距點0最近的點
int ans;
void prim(int s){
	memset(pre, NONE, sizeof(pre));
	for (int i = 0; i < q; i++)
		DP[i] = INF;
	DP[s] = 0;
	pre[s] = s;
	while (true){
		int MIN = INF, k = NONE;
		for (int i = 1; i < q; i++)
			if (!V[i] && DP[i] < MIN)
				k = i, MIN = DP[i];
		if (k == NONE)	break;
		if (G[0][k] < G[0][p]) p = k;
		link[pre[k]][k] = link[k][pre[k]] = true;
		V[k] = true, ans += DP[k];
		for (int i = 1; i < q; i++)
			if (!V[i] && DP[i] > G[k][i])
				DP[i] = G[k][i], pre[i] = k;
	}
}
void DFS(int cur, int prev, int u, int v){
	for (int i = 1; i < q; i++)
		if (prev != i && link[cur][i] && i != cur)
			if (prev == NONE || G[cur][i] >= G[u][v])
				del[i] = node(cur, i, G[cur][i]), DFS(i, cur, cur, i);
			else
				del[i] = node(u, v, G[u][v]), DFS(i, cur, u, v);
}
int main(){
	while (scanf("%d", &n) == 1){
		map<string, int> name;
		map<string, int>::iterator ita, itb;
		name.clear();
		q = 0;
		for (int i = 0; i < 30; i++)
			for (int j = i; j < 30; j++)
				G[i][j] = G[j][i] = INF;
		memset(V, false, sizeof(V));
		memset(link, false, sizeof(link));
		name["Park"] = q++;
		for (int i = 0; i < n; i++){
			string a, b;
			int w, u, v;
			cin >> a >> b >> w;
			ita = name.find(a), itb = name.find(b);
			if (ita != name.end())
				u = ita->second;
			else
				name[a] = q, u = q++;
			if (itb != name.end())
				v = itb->second;
			else
				name[b] = q, v = q++;
			if (G[u][v] > w)
				G[u][v] = G[v][u] = w;
		}
		scanf("%d", &k);
		ans = 0;
		for (int i = 1; i < q; i++){
			if (V[i]) continue;
			p = i, k--;
			prim(i);
			ans += G[0][p];
			link[p][0] = link[0][p] = true;
			DFS(p, NONE, NONE, NONE);
		}
		while (k--){
			int c = 0, t = 0;
			for (int i = 1; i < q; i++){
				if (link[0][i] || G[0][i] == INF)	continue;
				if (c < del[i].len - G[0][i])
					t = i, c = del[i].len - G[0][i];
			}
			if (c == 0) break;
			ans -= c;
			link[del[t].u][del[t].v] = link[del[t].v][del[t].u] = false;
			link[0][t] = link[t][0] = true;
			DFS(t, 0, NONE, NONE);
		}
		printf("Total miles driven: %d\n", ans);
	}
}
/*

Picnic Planning
Time Limit: 5000MS		Memory Limit: 10000K
Total Submissions: 9446		Accepted: 3370
Description

The Contortion Brothers are a famous set of circus clowns, known worldwide for their incredible ability to cram an unlimited number of themselves into even the smallest vehicle. During the off-season, the brothers like to get together for an Annual Contortionists Meeting at a local park. However, the brothers are not only tight with regard to cramped quarters, but with money as well, so they try to find the way to get everyone to the party which minimizes the number of miles put on everyone's cars (thus saving gas, wear and tear, etc.). To this end they are willing to cram themselves into as few cars as necessary to minimize the total number of miles put on all their cars together. This often results in many brothers driving to one brother's house, leaving all but one car there and piling into the remaining one. There is a constraint at the park, however: the parking lot at the picnic site can only hold a limited number of cars, so that must be factored into the overall miserly calculation. Also, due to an entrance fee to the park, once any brother's car arrives at the park it is there to stay; he will not drop off his passengers and then leave to pick up other brothers. Now for your average circus clan, solving this problem is a challenge, so it is left to you to write a program to solve their milage minimization problem.
Input

Input will consist of one problem instance. The first line will contain a single integer n indicating the number of highway connections between brothers or between brothers and the park. The next n lines will contain one connection per line, of the form name1 name2 dist, where name1 and name2 are either the names of two brothers or the word Park and a brother's name (in either order), and dist is the integer distance between them. These roads will all be 2-way roads, and dist will always be positive.The maximum number of brothers will be 20 and the maximumlength of any name will be 10 characters.Following these n lines will be one final line containing an integer s which specifies the number of cars which can fit in the parking lot of the picnic site. You may assume that there is a path from every brother's house to the park and that a solution exists for each problem instance.
Output

Output should consist of one line of the form
Total miles driven: xxx
where xxx is the total number of miles driven by all the brothers' cars.
Sample Input

10
Alphonzo Bernardo 32
Alphonzo Park 57
Alphonzo Eduardo 43
Bernardo Park 19
Bernardo Clemenzi 82
Clemenzi Park 65
Clemenzi Herb 90
Clemenzi Eduardo 109
Park Herb 24
Herb Eduardo 79
3
Sample Output

Total miles driven: 183
Source

East Central North America 2000

*/