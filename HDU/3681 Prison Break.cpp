/* 13297579	2015-03-30 23:36:50	Accepted	3681	468MS	5200K	2601 B	G++	Shark
 */
#include<bits\stdc++.h>
using namespace std;
struct Node{
	int x, y;
	Node(){}
	Node(int x, int y) :x(x), y(y){}
};
int mx[] = { 1, -1, 0, 0 };
int my[] = { 0, 0, 1, -1 };
int w, h;
int dist[16][16][16][16];
char T[20][20];
Node S[20];
int Sptr;
int startPoint;
int finalState;
int DP[40000][20];
void BFS(Node start){
	queue<Node> Q;
	Q.push(start);
	dist[start.x][start.y][start.x][start.y] = 0;
	while (!Q.empty()){
		Node cur = Q.front();	Q.pop();
		for (int i = 0; i < 4; i++){
			Node next = Node(cur.x + mx[i], cur.y + my[i]);
			if (next.x < 0 || next.y < 0 || next.x >= h || next.y >= w || T[next.x][next.y] == 'D')	continue;
			if (dist[start.x][start.y][next.x][next.y] == -1){
				dist[start.x][start.y][next.x][next.y] = dist[start.x][start.y][cur.x][cur.y] + 1;
				Q.push(next);
			}
		}
	}
}
bool check(int step){
	memset(DP, -1, sizeof(DP));
	int res = -1;
	DP[(1 << startPoint)][startPoint] = step;
	for (int state = 0; state < (1 << Sptr); state++){
		for (int i = 0; i < Sptr; i++){
			if (!(state & (1 << i)) || DP[state][i] == -1)	continue;
			if ((state & finalState) == finalState)	res = max(res, DP[state][i]);
			for (int j = 0; j < Sptr; j++){
				int cost = dist[S[i].x][S[i].y][S[j].x][S[j].y];
				if (i == j || cost == -1 || state & (1 << j))	continue;
				if (DP[state][i] - cost < 0)	continue;
				int nextState = state | (1 << j);
				DP[nextState][j] = max(DP[nextState][j], DP[state][i] - cost);
				if (T[S[j].x][S[j].y] == 'G')
					DP[nextState][j] = step;
			}
		}
	}
	return res != -1;
}
int main(){
	while (scanf("%d%d", &h, &w) == 2){
		if (w == 0 && h == 0)	break;
		for (int i = 0; i < h;i++)
			scanf("%s", T + i);
		Sptr = finalState = 0;
		for (int i = 0; i < h; i++){
			for (int j = 0; j < w; j++){
				if (T[i][j] == 'F')
					startPoint = Sptr, finalState |= (1 << Sptr), S[Sptr++] = Node(i, j);
				if (T[i][j] == 'G')
					S[Sptr++] = Node(i, j);
				if (T[i][j] == 'Y')
					finalState |= (1 << Sptr), S[Sptr++] = Node(i, j);
			}
		}
		memset(dist, -1, sizeof(dist));
		for (int i = 0; i < Sptr; i++)
			BFS(S[i]);
		int L = 1, R = 300;
		while (L <= R){
			int mid = (L + R) / 2;
			if (check(mid))
				R = mid - 1;
			else
				L = mid + 1;
		}
		if (L == 301)
			L = -1;
		printf("%d\n", L);
	}
	return 0;
}
/*

Prison Break

Time Limit: 5000/2000 MS (Java/Others)    Memory Limit: 32768/32768 K (Java/Others)
Total Submission(s): 3579    Accepted Submission(s): 933


Problem Description
Rompire is a robot kingdom and a lot of robots live there peacefully. But one day, the king of Rompire was captured by human beings. His thinking circuit was changed by human and thus became a tyrant. All those who are against him were put into jail, including our clever Micheal#1. Now it’s time to escape, but Micheal#1 needs an optimal plan and he contacts you, one of his human friends, for help.
The jail area is a rectangle contains n×m little grids, each grid might be one of the following:
1) Empty area, represented by a capital letter ‘S’.
2) The starting position of Micheal#1, represented by a capital letter ‘F’.
3) Energy pool, represented by a capital letter ‘G’. When entering an energy pool, Micheal#1 can use it to charge his battery ONLY ONCE. After the charging, Micheal#1’s battery will become FULL and the energy pool will become an empty area. Of course, passing an energy pool without using it is allowed.
4) Laser sensor, represented by a capital letter ‘D’. Since it is extremely sensitive, Micheal#1 cannot step into a grid with a laser sensor.
5) Power switch, represented by a capital letter ‘Y’. Once Micheal#1 steps into a grid with a Power switch, he will certainly turn it off.

In order to escape from the jail, Micheal#1 need to turn off all the power switches to stop the electric web on the roof—then he can just fly away. Moving to an adjacent grid (directly up, down, left or right) will cost 1 unit of energy and only moving operation costs energy. Of course, Micheal#1 cannot move when his battery contains no energy.

The larger the battery is, the more energy it can save. But larger battery means more weight and higher probability of being found by the weight sensor. So Micheal#1 needs to make his battery as small as possible, and still large enough to hold all energy he need. Assuming that the size of the battery equals to maximum units of energy that can be saved in the battery, and Micheal#1 is fully charged at the beginning, Please tell him the minimum size of the battery needed for his Prison break.


Input
Input contains multiple test cases, ended by 0 0. For each test case, the first line contains two integer numbers n and m showing the size of the jail. Next n lines consist of m capital letters each, which stands for the description of the jail.You can assume that 1<=n,m<=15, and the sum of energy pools and power switches is less than 15.


Output
For each test case, output one integer in a line, representing the minimum size of the battery Micheal#1 needs. If Micheal#1 can’t escape, output -1.


Sample Input
5 5
GDDSS
SSSFS
SYGYS
SGSYS
SSYSS
0 0


Sample Output
4


Source
2010 Asia Hangzhou Regional Contest


Recommend
lcy&zhengfeng   |   We have carefully selected several similar problems for you:  3682 3685 3686 3683 3689

*/