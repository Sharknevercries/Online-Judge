/* 12943953	2015-02-13 14:45:22	Accepted	4845	0MS	2568K	2360 B	G++	Shark */
#include<bits\stdc++.h>
#define N 20
#define M 20
#define P 15
using namespace std;
struct Status{
	int x, y, dist;
	bool key[P];
	Status(){}
	Status(int x, int y, int dist, bool key[]) :x(x), y(y), dist(dist){
		for (int i = 0; i < P; i++)
			this->key[i] = key[i];
	}
};
struct KeyStatus{
	bool key[P];
};
int n, m, p, k, s;
int mx[] = { 0, 0, 1, -1 };
int my[] = { 1, -1, 0, 0 };
queue<Status> Q;
KeyStatus tu[N][N];
int door[N][N][N][N];
bool V[N][N][2000];
int hashKey(bool key[]){
	int code = 0;
	for (int i = 1; i <= s; i++)
		if (key[i])
			code += (int)pow(2.0, i - 1);
	return code;
}
int BFS(){
	bool tmp[P] = { false };
	Q.push(Status(1, 1, 0, tmp));
	while (!Q.empty()){
		Status cur = Q.front();	Q.pop();
		if (cur.x == n && cur.y == m)
			return cur.dist;
		for (int i = 0; i < 4; i++){
			Status next = cur;
			next.x = cur.x + mx[i], next.y = cur.y + my[i];
			if (next.x >= 1 && next.y >= 1 && next.x <= n&&next.y <= m){
				int keyCode = hashKey(next.key);
				if (!V[next.x][next.y][keyCode]){
					if (door[cur.x][cur.y][next.x][next.y] == -1 || next.key[door[cur.x][cur.y][next.x][next.y]]){
						for (int j = 1; j <= s; j++)
							if (tu[next.x][next.y].key[j])
								next.key[j] = true;
						next.dist++;
						Q.push(next);
						keyCode = hashKey(next.key);
						V[next.x][next.y][keyCode] = true;
					}
				}
			}
		}
	}
	return -1;
}
int main(){
	while (scanf("%d%d%d", &n, &m, &p) == 3){
		memset(V, false, sizeof(V));
		memset(door, -1, sizeof(door));
		while (!Q.empty())
			Q.pop();
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				memset(tu[i][j].key, false, sizeof(tu[i][j].key));
		scanf("%d", &k);
		for (int i = 1; i <= k; i++){
			int x1, x2, y1, y2;
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			scanf("%d", &door[x1][y1][x2][y2]);
			door[x2][y2][x1][y1] = door[x1][y1][x2][y2];
		}
		scanf("%d", &s);
		for (int i = 1; i <= s; i++){
			int x, y, type;
			scanf("%d%d%d", &x, &y, &type);
			tu[x][y].key[type] = true;
		}
		printf("%d\n", BFS());
	}
	return 0;
}
/*

Problem Description
1944年，特种兵麦克接到国防部的命令，要求立即赶赴太平洋上的一个孤岛，营救被敌军俘虏的大兵瑞恩。瑞恩被关押在一个迷宫里，迷宫地形复杂，但是幸好麦克得到了迷宫的地形图。
迷宫的外形是一个长方形，其在南北方向被划分为N行，在东西方向被划分为M列，于是整个迷宫被划分为N*M个单元。我们用一个有序数对（单元的行号，单元的列号）来表示单元位置。南北或东西方向相邻的两个单元之间可以互通，或者存在一扇锁着的门，又或者存在一堵不可逾越的墙。迷宫中有一些单元存放着钥匙，并且所有的门被分为P类，打开同一类的门的钥匙相同，打开不同类的门的钥匙不同。
大兵瑞恩被关押在迷宫的东南角，即（N,M）单元里，并已经昏迷。迷宫只有一个入口，在西北角，也就是说，麦克可以直接进入(1,1)单元。另外，麦克从一个单元移动到另一个相邻单元的时间为1，拿取所在单元的钥匙的时间以及用钥匙开门的时间忽略不计。
你的任务是帮助麦克以最快的方式抵达瑞恩所在单元，营救大兵瑞恩。

Input
有多组数据对于每一组数据来说：
第一行是三个整数，依次表示N,M,P的值；
第二行是一个整数K，表示迷宫中门和墙的总个数；
第I+2行（1<=I<=K），有5个整数，依次为Xi1,Yi1,Xi2,Yi2,Gi：
当Gi>=1时，表示(Xi1,Yi1)单元与(Xi2,Yi2)单元之间有一扇第Gi类的门，当Gi=0时，表示(Xi1,Yi1)单元与(Xi2,Yi2)单元之间有一堵不可逾越的墙；
（其中，|Xi1-Xi2|+|Yi1-Yi2|=1，0<=Gi<=P）
第K+3行是一个整数S，表示迷宫中存放的钥匙总数；
第K+3+J行(1<=J<=S)，有3个整数，依次为Xi1,Yi1,Qi：表示第J把钥匙存放在(Xi1,Yi1)单元里，并且第J把钥匙是用来开启第Qi类门的。（其中1<=Qi<=P）
注意：输入数据中同一行各相邻整数之间用一个空格分隔。

参数设定：
3<=N,M<=15;
1<=P<=10;

Output
对于每一组数据，输出一行，只包含一个整数T，表示麦克营救到大兵瑞恩的最短时间的值，若不存在可行的营救方案则输出-1。

Sample Input
4 4 9
9
1 2 1 3 2
1 2 2 2 0
2 1 2 2 0
2 1 3 1 0
2 3 3 3 0
2 4 3 4 1
3 2 3 3 0
3 3 4 3 0
4 3 4 4 0
2
2 1 2
4 2 1


Sample Output
14


Source
CTSC1999


Recommend
We have carefully selected several similar problems for you:  5173 5172 5171 5170 5169

*/