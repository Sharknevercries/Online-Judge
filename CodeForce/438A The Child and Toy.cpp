#include<cstdio>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> E[1001];
int C[1001];
bool V[1001];
struct point{
	int id, cost;
};
bool cmp(point A, point B){
	return A.cost > B.cost;
}
void init(){
	for (int i = 0; i < 1001; i++)
		E[i].clear();
	memset(V, false, sizeof(V));
}
int main(){
	int n, m;
	while (scanf("%d%d", &n, &m) == 2){
		point P[1001];
		init();
		for (int i = 1; i <= n; i++){
			scanf("%d", &C[i]);
			P[i].cost = C[i];
			P[i].id = i;
		}
		for (int i = 1; i <= m; i++){
			int a, b;
			scanf("%d%d", &a, &b);
			E[a].push_back(b);
			E[b].push_back(a);
		}
		sort(P + 1, P + n + 1, cmp);
		int ans = 0;
		for (int i = 1; i <= n; i++){
			int cur = P[i].id;
			for (int j = 0; j < E[cur].size(); j++){
				if (!V[E[cur][j]])
					ans += C[E[cur][j]];
			}
			V[cur] = true;
		}
		printf("%d\n", ans);
	}
	return 0;
}