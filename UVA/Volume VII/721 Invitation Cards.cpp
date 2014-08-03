/* 13536352	721	Invitation Cards	Accepted	C++	0.388	2014-04-23 08:04:40 */
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#include<string.h>
using namespace std;
vector<pair<int, int> > in[1000000];
vector<pair<int, int> > out[100000];
bool inqueue[1000000];
int D[1000000];
int n, m;
unsigned long long Dijkstra(){
	unsigned long long ans = 0;
	queue<int> Q;

	for (int i = 0; i < n; i++)	D[i] = 2e9;
	memset(inqueue, false, sizeof(inqueue));
	Q.push(0);
	inqueue[0] = true;
	D[0] = 0;

	while (!Q.empty()){
		int cur = Q.front();
		Q.pop();
		inqueue[cur] = false;
		for (int i = 0; i < out[cur].size(); i++){
			if (D[cur] + out[cur][i].second < D[out[cur][i].first]){
				D[out[cur][i].first] = D[cur] + out[cur][i].second;
				if (!inqueue[out[cur][i].first]){
					Q.push(out[cur][i].first);
					inqueue[out[cur][i].first] = true;
				}
			}
		}
	}
	for (int i = 1; i < n; i++)	ans += D[i];

	for (int i = 0; i < n; i++)	D[i] = 2e9;
	memset(inqueue, false, sizeof(inqueue));
	Q.push(0);
	inqueue[0] = true;
	D[0] = 0;

	while (!Q.empty()){
		int cur = Q.front();
		Q.pop();
		inqueue[cur] = false;
		for (int i = 0; i < in[cur].size(); i++){
			if (D[cur] + in[cur][i].second < D[in[cur][i].first]){
				D[in[cur][i].first] = D[cur] + in[cur][i].second;
				if (!inqueue[in[cur][i].first]){
					Q.push(in[cur][i].first);
					inqueue[in[cur][i].first] = true;
				}
			}
		}
	}
	for (int i = 1; i < n; i++)	ans += D[i];
	return ans;
}
int main(){
	int t;
	scanf("%d", &t);
	while (t--){
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++)
			in[i].clear(), out[i].clear();
		for (int i = 0; i < m; i++){
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			a--, b--;
			out[a].push_back(make_pair(b, c));
			in[b].push_back(make_pair(a, c));
		}
		printf("%llu\n", Dijkstra());
	}
	return 0;
}
/*

Invitation Cards
In the age of television, not many people attend theater performances. Antique Comedians of Malidinesia are aware of this fact. They want to propagate theater and, most of all, Antique Comedies. They have printed invitation cards with all the necessary information and with the programme. A lot of students were hired to distribute these invitations among the people. Each student volunteer has assigned exactly one bus stop and he or she stays there the whole day and gives invitation to people travelling by bus. A special course was taken where students learned how to influence people and what is the difference between influencing and robbery.


The transport system is very special: all lines are unidirectional and connect exactly two stops. Buses leave the originating stop with passangers each half an hour. After reaching the destination stop they return empty to the originating stop, where they wait until the next full half an hour, e.g. X:00 or X:30, where `X' denotes the hour. The fee for transport between two stops is given by special tables and is payable on the spot. The lines are planned in such a way, that each round trip (i.e. a journey starting and finishing at the same stop) passes through a Central Checkpoint Stop (CCS) where each passenger has to pass a thorough check including body scan.


All the ACM student members leave the CCS each morning. Each volunteer is to move to one predetermined stop to invite passengers. There are as many volunteers as stops. At the end of the day, all students travel back to CCS. You are to write a computer program that helps ACM to minimize the amount of money to pay every day for the transport of their employees.

Input

The input consists of N cases. The first line of the input contains only positive integer N. Then follow the cases. Each case begins with a line containing exactly two integers P and Q,  $1 \le P,Q \le 1000000$. P is the number of stops including CCS and Q the number of bus lines. Then there are Q lines, each describing one bus line. Each of the lines contains exactly three numbers - the originating stop, the destination stop and the price. The CCS is designated by number 1. Prices are positive integers the sum of which is smaller than 1000000000. You can also assume it is always possible to get from any stop to any other stop.

Output

For each case, print one line containing the minimum amount of money to be paid each day by ACM for the travel costs of its volunteers.

Sample Input

2
2 2
1 2 13
2 1 33
4 6
1 2 10
2 1 60
1 3 20
3 4 10
2 4 5
4 1 50
Sample Output

46
210


Miguel A. Revilla
2000-02-15

*/