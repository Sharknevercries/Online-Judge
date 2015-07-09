/* 15316290	10039	Railroads	Accepted	C++	0.342	2015-04-13 15:24:57 */
#include<bits\stdc++.h>
using namespace std;
struct Edge{
	int start, end, dest;
	Edge(){}
	Edge(int start, int end, int dest) :start(start), end(end), dest(dest){}
};
int n, m;
vector<Edge> G[105];
int DP[2405][105];
map<string, int> S;
bool sortByEdge(Edge a, Edge b){
	return a.start < b.start;
}
void solve(int beginTime, string source, string target){
	int from = S[source];
	int to = S[target];
	memset(DP, -1, sizeof(DP));
	for (int i = 0; i < G[from].size(); i++){
		Edge &e = G[from][i];
		if (e.start < beginTime)	continue;
		DP[e.end][e.dest] = max(DP[e.end][e.dest], e.start);
	}
	for (int i = 0; i < 2400; i++){
		for (int j = 0; j < n; j++){
			if (DP[i][j] == -1)	continue;
			for (int k = G[j].size() - 1; k >= 0; k--){
				Edge &e = G[j][k];
				if (i > e.start)	break;
				DP[e.end][e.dest] = max(DP[e.end][e.dest], DP[i][j]);
			}
		}
	}
	for (int i = 0; i < 2400; i++){
		if (DP[i][to] != -1){
			printf("Departure %04d %s\n", DP[i][to], source.c_str());
			printf("Arrival   %04d %s\n", i, target.c_str());
			return;
		}
	}
	puts("No connection");
}
int main(){
	int t, c = 1;
	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		S.clear();
		for (int i = 0; i < n; i++)
			G[i].clear();
		for (int i = 0; i < n; i++){
			string tmp;
			cin >> tmp;
			S[tmp] = i;
		}
		scanf("%d", &m);
		for (int i = 0; i < m; i++){
			int station;
			int prevTime, curTime;
			string prevCity, curCity;
			scanf("%d", &station);
			for (int j = 0; j < station; j++){
				cin >> curTime >> curCity;
				if (j > 0)
					G[S[prevCity]].push_back(Edge(prevTime, curTime, S[curCity]));
				prevCity = curCity, prevTime = curTime;
			}
		}
		for (int i = 0; i < n;i++)
			sort(G[i].begin(), G[i].end(), sortByEdge);
		int beginTime;
		string source, target;
		cin >> beginTime >> source >> target;
		printf("Scenario %d\n", c++);
		solve(beginTime, source, target);
		putchar('\n');
	}
	return 0;
}
/*

It’s Friday evening and Jill hates two things which are common to all trains:
1. They are always late.
2. The schedule is always wrong.
Nevertheless, tomorrow in the early morning hours Jill will have to travel from Hamburg to Darmstadt
in order to get to the regional programming contest. Since she is afraid of arriving too late and
being excluded from the contest she is looking for the train which gets her to Darmstadt as early as
possible. However, she dislikes to get to the station too early, so if there are several schedules with the
same arrival time then she will choose the one with the latest departure time.
Jill asks you to help her with her problem. You are given a set of railroad schedules from which you
must compute the train with the earliest arrival time and the fastest connection from one location to
another. One good thing: Jill is very experienced in changing trains. She can do this instantaneously,
i.e., in zero time!!!
Input
The very first line of the input gives the number of scenarios. Each scenario consists of three parts.
Part one lists the names of all cities connected by the railroads. It starts with a number 1 < C ≤ 100,
followed by C lines containing city names. These names consist of letters.
Part two describes all the trains running during a day. It starts with a number T ≤ 1000 followed
by T train descriptions. Each of them consists of one line with a number ti ≤ 100 and ti more lines
with a time and a city name, meaning that passengers can get on or off the train at that time at that
city.
Part three consists of three lines: Line one contains the earliest journey’s starting time, line two
the name of the city where she starts, and line three the destination city. The two cities are always
different.
Output
For each scenario print a line containing “Scenario i”, where i is the number of the scenario starting
at 1.
If a connection exists then print the two lines containing zero padded timestamps and locations as
shown in the sample. Use blanks to achieve the indentation. If no connection exists on the same day
(i.e., arrival before midnight) then print a line containing “No connection”.
After each scenario print a blank line.
Sample Input
2
3
Hamburg
Frankfurt
Darmstadt
3
2
0949 Hamburg
1006 Frankfurt
2
1325 Hamburg
1550 Darmstadt
2
1205 Frankfurt
1411 Darmstadt
0800
Hamburg
Darmstadt
2
Paris
Tokyo
1
2
0100 Paris
2300 Tokyo
0800
Paris
Tokyo
Sample Output
Scenario 1
Departure 0949 Hamburg
Arrival 1411 Darmstadt
Scenario 2
No connection

*/