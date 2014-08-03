/* 5319676	 Dec 1, 2013 11:27:55 AM	Shark	 C - Valera and Elections	 GNU C++	Accepted	78 ms	6572 KB */
#include<stdio.h>
#include<string.h>
#include<queue>
#include<vector>
struct road{
	int end, type;
};
std::vector<struct road> R[100000];
bool V[100000];
bool ans[100000];
int P[100000];
int track(int x){
	ans[x] = false;
	return (x == P[x] ? x : P[x] = track(P[x]));
}
void BFS(int s){
	std::queue<int> Q;
	Q.push(s);
	P[s] = s;
	V[s] = true;

	while (!Q.empty()){
		int start = Q.front();
		Q.pop();
		for (int i = 0; i < R[start].size(); i++){
			int end = R[start][i].end;
			if (!V[end]){
				P[end] = start;
				V[end] = true;
				if (R[start][i].type == 2){
					ans[end] = true;
					(void)track(start);
				}
				Q.push(end);
			}
		}
	}
}
int main(){
	int n;
	while (scanf("%d", &n) == 1){
		memset(V, false, sizeof(V));
		memset(ans, false, sizeof(ans));
		for (int i = 0; i < n; i++)
			R[i].clear();
		for (int i = 0; i < n - 1; i++){
			int a, b;
			struct road tmp;
			scanf("%d%d%d", &a, &b, &tmp.type);
			a--, b--;
			tmp.end = a;
			R[b].push_back(tmp);
			tmp.end = b;
			R[a].push_back(tmp);
		}
		BFS(0);
		std::vector<int> A;
		for (int i = 0; i < n; i++){
			if (ans[i])
				A.push_back(i+1);
		}
		printf("%d\n", A.size());
		if (A.size() > 0){
			printf("%d", A[0]);
			for (int i = 1; i < A.size(); i++)
				printf(" %d", A[i]);
		}
		putchar('\n');
	}
	return 0;
}
/*

C. Valera and Elections
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
The city Valera lives in is going to hold elections to the city Parliament.

The city has n districts and n - 1 bidirectional roads. We know that from any district there is a path along the roads to any other district. Let's enumerate all districts in some way by integers from 1 to n, inclusive. Furthermore, for each road the residents decided if it is the problem road or not. A problem road is a road that needs to be repaired.

There are n candidates running the elections. Let's enumerate all candidates in some way by integers from 1 to n, inclusive. If the candidate number i will be elected in the city Parliament, he will perform exactly one promise — to repair all problem roads on the way from the i-th district to the district 1, where the city Parliament is located.

Help Valera and determine the subset of candidates such that if all candidates from the subset will be elected to the city Parliament, all problem roads in the city will be repaired. If there are several such subsets, you should choose the subset consisting of the minimum number of candidates.

Input
The first line contains a single integer n (2 ≤ n ≤ 105) — the number of districts in the city.

Then n - 1 lines follow. Each line contains the description of a city road as three positive integers xi, yi, ti (1 ≤ xi, yi ≤ n, 1 ≤ ti ≤ 2) — the districts connected by the i-th bidirectional road and the road type. If ti equals to one, then the i-th road isn't the problem road; if ti equals to two, then the i-th road is the problem road.

It's guaranteed that the graph structure of the city is a tree.

Output
In the first line print a single non-negative number k — the minimum size of the required subset of candidates. Then on the second line print k space-separated integers a1, a2, ... ak — the numbers of the candidates that form the required subset. If there are multiple solutions, you are allowed to print any of them.

Sample test(s)
input
5
1 2 2
2 3 2
3 4 2
4 5 2
output
1
5
input
5
1 2 1
2 3 2
2 4 1
4 5 1
output
1
3
input
5
1 2 2
1 3 2
1 4 2
1 5 2
output
4
5 4 3 2

*/