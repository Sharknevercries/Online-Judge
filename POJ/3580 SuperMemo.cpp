/* 14345090	840502	3580	Accepted	6440K	922MS	C++	4624B	2015-07-04 18:00:03 */
#include<bits\stdc++.h>
#define MAXN 200005
using namespace std;
struct Node{
	int pri, count, LC, RC;
	int value, min, fix;
	bool rev;
	Node() :pri(-1), value(0), min(2e9), count(0), LC(0), RC(0), fix(0), rev(false){}
	Node(int _value){
		pri = (rand() << 15) + rand();
		value = min = _value;
		count = 1;
		fix = LC = RC = 0;
		rev = false;
	}
};
Node T[MAXN];
int nMem, root;
int getNode(int value){
	T[nMem] = Node(value);
	if (nMem >= MAXN) while (1);
	return nMem++;
}
void pull(int root){
	if (!root)	return;
	T[root].count = T[T[root].LC].count + T[T[root].RC].count + 1;
	T[root].min = T[root].value;
	if (T[root].LC)	T[root].min = min(T[root].min, T[T[root].LC].min);
	if (T[root].RC)	T[root].min = min(T[root].min, T[T[root].RC].min);
}
void push(int root){
	if (!root)	return;
	if (T[root].fix){
		if (T[root].LC) T[T[root].LC].value += T[root].fix, T[T[root].LC].fix += T[root].fix, T[T[root].LC].min += T[root].fix;
		if (T[root].RC)	T[T[root].RC].value += T[root].fix, T[T[root].RC].fix += T[root].fix, T[T[root].RC].min += T[root].fix;
		T[root].fix = 0;
	}
	if (T[root].rev){
		swap(T[root].LC, T[root].RC);
		if (T[root].LC)	T[T[root].LC].rev ^= 1;
		if (T[root].RC)	T[T[root].RC].rev ^= 1;
		T[root].rev = false;
	}
}
int merge(int a, int b){
	push(a);
	push(b);
	if (!a)	return b;
	if (!b)	return a;
	int res = 0;
	if (T[a].pri > T[b].pri)
		res = a, T[res].RC = merge(T[res].RC, b);
	else
		res = b, T[res].LC = merge(a, T[res].LC);
	pull(res);
	return res;
};
pair<int, int> split(int root, int k){
	push(root);
	if (k == 0)	return make_pair(0, root);
	if (k == T[root].count)	return make_pair(root, 0);
	int LC = T[root].LC, RC = T[root].RC;
	pair<int, int> res;
	if (T[LC].count >= k){
		res = split(LC, k);
		T[root].LC = res.second;
		res.second = root;
		pull(res.second);
	}
	else{
		res = split(RC, k - T[LC].count - 1);
		T[root].RC = res.first;
		res.first = root;
		pull(res.first);
	}
	return res;
}
void add(int L, int R, int value){
	pair<int, int> LT = split(root, L - 1);
	pair<int, int> RT = split(LT.second, R - L + 1);
	T[RT.first].fix += value;
	T[RT.first].value += value;
	T[RT.first].min += value;
	root = merge(LT.first, merge(RT.first, RT.second));
}
void reverse(int L, int R){
	pair<int, int> LT = split(root, L - 1);
	pair<int, int> RT = split(LT.second, R - L + 1);
	T[RT.first].rev ^= 1;
	root = merge(LT.first, merge(RT.first, RT.second));
}
void rotate(int L, int R, int time){
	int len = R - L + 1;
	time = (time % len + len) % len;
	pair<int, int> LT = split(root, L - 1);
	pair<int, int> RT = split(LT.second, R - L + 1);
	pair<int, int> MT = split(RT.first, len - time);
	root = merge(merge(LT.first, MT.second), merge(MT.first, RT.second));
}
void insert(int L, int value){
	pair<int, int> LT = split(root, L);
	root = merge(merge(LT.first, getNode(value)), LT.second);
}
void remove(int L){
	pair<int, int> LT = split(root, L - 1);
	pair<int, int> RT = split(LT.second, 1);
	root = merge(LT.first, RT.second);
}
int getMin(int L, int R){
	pair<int, int> LT = split(root, L - 1);
	pair<int, int> RT = split(LT.second, R - L + 1);
	int res = T[RT.first].min;
	root = merge(LT.first, merge(RT.first, RT.second));
	return res;
}
int n, m;
int main(){
	srand(time(NULL));
	nMem = 1, root = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		int a;
		scanf("%d", &a);
		root = merge(root, getNode(a));
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++){
		string command;
		int L, R, value;
		cin >> command;
		if (command == "ADD"){
			scanf("%d%d%d", &L, &R, &value);
			add(L, R, value);
		}
		else if (command == "REVERSE"){
			scanf("%d%d", &L, &R);
			reverse(L, R);
		}
		else if (command == "REVOLVE"){
			scanf("%d%d%d", &L, &R, &value);
			rotate(L, R, value);
		}
		else if (command == "INSERT"){
			scanf("%d%d", &L, &value);
			insert(L, value);
		}
		else if (command == "DELETE"){
			scanf("%d", &L);
			remove(L);
		}
		else if (command == "MIN"){
			scanf("%d%d", &L, &R);
			printf("%d\n", getMin(L, R));
		}
	}
	return 0;
}
/*

SuperMemo
Time Limit: 5000MS		Memory Limit: 65536K
Total Submissions: 11252		Accepted: 3527
Case Time Limit: 2000MS
Description

Your friend, Jackson is invited to a TV show called SuperMemo in which the participant is told to play a memorizing game. At first, the host tells the participant a sequence of numbers, {A1, A2, ... An}. Then the host performs a series of operations and queries on the sequence which consists:

ADD x y D: Add D to each number in sub-sequence {Ax ... Ay}. For example, performing "ADD 2 4 1" on {1, 2, 3, 4, 5} results in {1, 3, 4, 5, 5}
REVERSE x y: reverse the sub-sequence {Ax ... Ay}. For example, performing "REVERSE 2 4" on {1, 2, 3, 4, 5} results in {1, 4, 3, 2, 5}
REVOLVE x y T: rotate sub-sequence {Ax ... Ay} T times. For example, performing "REVOLVE 2 4 2" on {1, 2, 3, 4, 5} results in {1, 3, 4, 2, 5}
INSERT x P: insert P after Ax. For example, performing "INSERT 2 4" on {1, 2, 3, 4, 5} results in {1, 2, 4, 3, 4, 5}
DELETE x: delete Ax. For example, performing "DELETE 2" on {1, 2, 3, 4, 5} results in {1, 3, 4, 5}
MIN x y: query the participant what is the minimum number in sub-sequence {Ax ... Ay}. For example, the correct answer to "MIN 2 4" on {1, 2, 3, 4, 5} is 2
To make the show more interesting, the participant is granted a chance to turn to someone else that means when Jackson feels difficult in answering a query he may call you for help. You task is to watch the TV show and write a program giving the correct answer to each query in order to assist Jackson whenever he calls.

Input

The first line contains n (n ≤ 100000).

The following n lines describe the sequence.

Then follows M (M ≤ 100000), the numbers of operations and queries.

The following M lines describe the operations and queries.

Output

For each "MIN" query, output the correct answer.

Sample Input

5
1
2
3
4
5
2
ADD 2 4 1
MIN 4 5
Sample Output

5
Source

POJ Founder Monthly Contest – 2008.04.13, Yao Jinyu

*/