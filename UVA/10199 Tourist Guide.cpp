/* 15314383	10199	Tourist Guide	Accepted	C++	0.042	2015-04-13 08:52:55 */
#include<bits\stdc++.h>
using namespace std;
int n, m;
string city[105];
map<string, int> S;
vector<int> G[105];
vector<string> ans;
int V[105], low[105], timer;
void DFS(int x, int p){
	V[x] = low[x] = ++timer;
	int child = 0;
	bool ap = false;
	for (int i = 0; i < G[x].size(); i++){
		int target = G[x][i];
		if (target == p)	continue;
		if (V[target] > 0)
			low[x] = min(low[x], V[target]);
		else{
			child++;
			DFS(target, x);
			low[x] = min(low[x], low[target]);
			if (low[target] >= V[x])	ap = true;
		}
	}
	if ((x == p && child > 1) || (x != p && ap))
		ans.push_back(city[x]);
}
int main(){
	//freopen("input.txt", "r", stdin);
	int c = 1;
	while (scanf("%d", &n) == 1 && n){
		S.clear();
		for (int i = 0; i < n; i++)
			G[i].clear();
		for (int i = 0; i < n; i++){
			cin >> city[i];
			S[city[i]] = i;
		}
		scanf("%d", &m);
		for (int i = 0; i < m; i++){
			string a, b;
			int aa, bb;
			cin >> a >> b;
			aa = S[a], bb = S[b];
			G[aa].push_back(bb);
			G[bb].push_back(aa);
		}
		ans.clear();
		timer = 0;
		memset(V, -1, sizeof(V));
		for (int i = 0; i < n; i++)
			if (V[i] == -1)
				DFS(i, i);
		if (c>1)	putchar('\n');
		printf("City map #%d: %d camera(s) found\n", c++, ans.size());
		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << endl;
	}
	return 0;
}
/*

Rio de Janeiro is a very beautiful city. But there are so many places to visit that sometimes you feel
a bit lost. But don’t worry, because your friend Bruno promised you to be your tourist guide. The
problem is that he is not a very good driver, as he can’t see very well (poor Bruno).
Because of his disabilities, Bruno have a lot of fines to pay and he doesn’t want to have even more
to pay, even though he promised you to be your tourist guide. What he would like to know, however,
is where are all the cameras that help the police to fine the bad drivers, so he can drive more carefully
when passing by them.
Those cameras are strategically distributed over the city, in locations that a driver must pass through
in order to go from one zone of the city to another. In order words, if there are two city locations A
and B such that to go from one to another (A to B or B to A) a driver must pass through a location
C, then C will have a camera.
For instance, suppose that we have 6 locations (A, B, C, D, E and F) and that we have 7 routes
(all of them bidirectonal) B-C, A-B, C-A, D-C, D-E, E-F and F-C. There’s a camera on C because to
go from A to E, for instance, you must pass through C. In this configuration, there’s only one camera
(on C).
Your task is to help Bruno (as he wants to be a musician and he doesn’t want to get even close of
computers) and write a program which will tell him where are all the cameras, given the map of the
city, so he can be your tourist guide and avoid further fines.
Input
The input will consist on an arbitrary number of city maps. Each city map will begin with an integer
N (2 < N ≤ 100) which stands for the total locations of the city. Then will follow N different place
names, one per line. Each place name will have at least one and at most 30 characters (all of them will
be lowercase latin letters). Then will follow a non-negative integer R which stands for the total routes
of the city. Then will follow R lines with the routes. Each route will be represented by the name of
both places that the route connects (remember that the routes are bidirectional). Location names in
route description will always be valid and there will be no route from one place to itself. You must
read until N = 0, and this input should not be processed.
Output
For each city map you must print the line:
City map #d: c camera(s) found
Where d stands for the city map number (starting from 1) and c stands for the total number of
cameras. Then should follow c lines with the location names where are each camera (in alphabetic
order). You should print a blank line between output sets.
Sample Input
6
sugarloaf
maracana
copacabana
ipanema
corcovado
lapa
7
ipanema copacabana
copacabana sugarloaf
ipanema sugarloaf
maracana lapa
sugarloaf maracana
corcovado sugarloaf
lapa corcovado
5
guanabarabay
downtown
botanicgarden
colombo
sambodromo
4
guanabarabay sambodromo
downtown sambodromo
sambodromo botanicgarden
colombo sambodromo
0
Sample Output
City map #1: 1 camera(s) found
sugarloaf
City map #2: 1 camera(s) found
sambodromo

*/