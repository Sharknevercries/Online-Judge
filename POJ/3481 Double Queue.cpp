/* 14361221	840502	3481	Accepted	4832K	219MS	C++	2864B	2015-07-08 18:49:21 */
#include<bits\stdc++.h>
#define LCH(x) (T[x].LC)
#define RCH(x) (T[x].RC)
#define MAXN 200005
using namespace std;
struct Node{
	int LC, RC, pri;
	int client, value, count;
	Node() :LC(0), RC(0), pri(-1), client(0), value(0), count(0){}
	Node(int _value, int _client){
		LC = RC = 0, count = 1;
		client = _client;
		value = _value;
		pri = (rand() << 15) + rand();
	}
};
Node T[MAXN];
int nMem, root;
int getNode(int value, int client){
	T[nMem] = Node(value, client);
	if (nMem >= MAXN)	while (1);
	return nMem++;
}
void pull(int root){
	if (!root)	return;
	T[root].count = T[LCH(root)].count + T[RCH(root)].count + 1;
}
void push(int root){

}
int merge(int a, int b){
	push(a), push(b);
	if (!a)	return b;
	if (!b)	return a;
	int res = 0;
	if (T[a].pri > T[b].pri)
		RCH(a) = merge(RCH(a), b), res = a;
	else
		LCH(b) = merge(a, LCH(b)), res = b;
	pull(res);
	return res;
}
pair<int, int> split(int root, int k){
	push(root);
	if (k == 0)	return make_pair(0, root);
	if (k == T[root].count)	return make_pair(root, 0);
	pair<int, int> res;
	if (T[LCH(root)].count >= k){
		res = split(LCH(root), k);
		LCH(root) = res.second;
		res.second = root;
		pull(res.second);
	}
	else{
		res = split(RCH(root), k - T[LCH(root)].count - 1);
		RCH(root) = res.first;
		res.first = root;
		pull(res.first);
	}
	return res;
}
int getPosition(int root, int value){
	if (!root)	return 0;
	if (T[root].value < value)
		return T[LCH(root)].count + 1 + getPosition(RCH(root), value);
	else
		return getPosition(LCH(root), value);
}
void insert(int &root, int value, int client){
	pair<int, int> LT = split(root, getPosition(root, value));
	root = merge(merge(LT.first, getNode(value, client)), LT.second);
}
void remove(int &root, int k){
	if (!k || T[root].count < k)	return;
	pair<int, int> LT = split(root, k - 1);
	pair<int, int> RT = split(LT.second, 1);
	root = merge(LT.first, RT.second);
}
int getHighestPri(int root){
	while (RCH(root))
		root = RCH(root);
	return T[root].client;
}
int getLowestPri(int root){
	while (LCH(root))
		root = LCH(root);
	return T[root].client;
}
int main(){
	//freopen("input.txt", "r", stdin);
	int command;
	nMem = 1, root = 0;
	while (scanf("%d", &command) == 1){
		if (command == 0)
			break;
		else if (command == 1){
			pair<int, int> data;
			scanf("%d%d", &data.first, &data.second);
			insert(root, data.second, data.first);
		}
		else if (command == 2){
			int res = getHighestPri(root);
			printf("%d\n", res);
			if (res)	remove(root, T[root].count);
		}
		else if (command == 3){
			int res = getLowestPri(root);
			printf("%d\n", res);
			if (res)	remove(root, 1);
		}
	}
	return 0;
}
/*

Double Queue
Time Limit: 1000MS		Memory Limit: 65536K
Total Submissions: 11594		Accepted: 5260
Description

The new founded Balkan Investment Group Bank (BIG-Bank) opened a new office in Bucharest, equipped with a modern computing environment provided by IBM Romania, and using modern information technologies. As usual, each client of the bank is identified by a positive integer K and, upon arriving to the bank for some services, he or she receives a positive integer priority P. One of the inventions of the young managers of the bank shocked the software engineer of the serving system. They proposed to break the tradition by sometimes calling the serving desk with the lowest priority instead of that with the highest priority. Thus, the system will receive the following types of request:

0	The system needs to stop serving
1 K P	Add client K to the waiting list with priority P
2	Serve the client with the highest priority and drop him or her from the waiting list
3	Serve the client with the lowest priority and drop him or her from the waiting list
Your task is to help the software engineer of the bank by writing a program to implement the requested serving policy.

Input

Each line of the input contains one of the possible requests; only the last line contains the stop-request (code 0). You may assume that when there is a request to include a new client in the list (code 1), there is no other request in the list of the same client or with the same priority. An identifier K is always less than 106, and a priority P is less than 107. The client may arrive for being served multiple times, and each time may obtain a different priority.

Output

For each request with code 2 or 3, the program has to print, in a separate line of the standard output, the identifier of the served client. If the request arrives when the waiting list is empty, then the program prints zero (0) to the output.

Sample Input

2
1 20 14
1 30 3
2
1 10 99
3
2
2
0
Sample Output

0
20
30
10
0
Source

Southeastern Europe 2007

*/