/* 13702936	10587	Mayor's posters	Accepted	C++	0.642	2014-06-01 06:39:26 */
#include<cstdio>
#include<stdlib.h>
#include<string.h>
#include<map>
using namespace std;
map<int, int> T;
int n;
struct Node{ // [L,R)
	Node* Left;
	Node* Right;
	int markType;
	int L, R, type;
};

int P[200000], ptr;
bool cover[10000];
Node* root;

Node* newNode(int L, int R){
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->L = L, newNode->R = R;
	newNode->Left = newNode->Right = NULL;
	newNode->type = -1;
	newNode->markType = -1;
	return newNode;
}

void build(Node* cur, int L, int R){
	int mid = (L + R) / 2;
	if (mid != L && mid != R){
		cur->Left = newNode(P[L], P[mid]);
		build(cur->Left, L, mid);
		cur->Right = newNode(P[mid], P[R]);
		build(cur->Right, mid, R);
	}
}

void push(Node* cur){
	if (cur->markType != -1){
		if (cur->Left != NULL)
			cur->Left->markType = cur->markType;
		if (cur->Right != NULL)
			cur->Right->markType = cur->markType;
		cur->type = cur->markType;
		cur->markType = -1;
	}
}

void update(Node* cur, int L, int R, int type){
	int mid = (T[cur->L] + T[cur->R]) / 2;
	push(cur);
	if (cur->L == L && cur->R == R)
		cur->markType = type;
	else if (L >= P[mid])
		update(cur->Right, L, R, type);
	else if (R <= P[mid])
		update(cur->Left, L, R, type);
	else{
		update(cur->Left, L, P[mid], type);
		update(cur->Right, P[mid], R, type);
	}
}

void query(Node* cur, int L, int R){
	int mid = (T[cur->L] + T[cur->R]) / 2;
	push(cur);
	if (cur->Left == NULL && cur->Right == NULL)
		cover[cur->type] = true;
	else if (L >= P[mid])
		query(cur->Right, L, R);
	else if (R <= P[mid])
		query(cur->Left, L, R);
	else{
		query(cur->Left, L, P[mid]);
		query(cur->Right, P[mid], R);
	}
}

int findAns(Node* root, int L, int R){
	memset(cover, false, sizeof(cover));
	if (L < P[0])	L = P[0];
	if (R > P[ptr - 1])	R = P[ptr - 1];
	query(root, L, R);

	int ans = 0;
	for (int i = 0; i < n; i++)
		if (cover[i])
			ans++;
	return ans;
}

void del(Node* cur){
	if (cur->Left != NULL)
		del(cur->Left);
	if (cur->Right != NULL)
		del(cur->Right);
	free(cur);
}

void init(){
	memset(P, 0, sizeof(P));
	ptr = 0;
	T.clear();
}

int main(){
	int t;
	scanf("%d", &t);
	while (t--){
		init();
		scanf("%d", &n);
		int poster[10000][2];
		map<int, int> S;
		for (int i = 0; i < n; i++){
			scanf("%d%d", &poster[i][0], &poster[i][1]);
			S[poster[i][0]]++, S[poster[i][1] + 1]++;
		}
		for (map<int, int>::iterator it = S.begin(); it != S.end(); it++)
			P[ptr++] = it->first;
		for (int i = 0; i < ptr; i++)
			T[P[i]] = i;
		root = newNode(P[0], P[ptr - 1]);
		build(root, 0, ptr - 1);
		for (int i = 0; i < n; i++)
			update(root, poster[i][0], poster[i][1] + 1, i);
		printf("%d\n", findAns(root, P[0], P[ptr - 1]));
		del(root);
	}
	return 0;
}
/*

Problem G: Mayor's posters

The citizens of Bytetown, AB, could not stand that the candidates in the mayoral election campaign have been placing their electoral posters at all places at their whim. The city council has finally decided to build an electoral wall for placing the posters and introduce the following rules:
Every candidate can place exactly one poster on the wall.
All posters are of the same height equal to the height of the wall; the width of a poster can be any integer number of bytes (byte is the unit of length in Bytetown).
The wall is divided into segments and the width of each segment is one byte.
Each poster must completely cover a contiguous number of wall segments.
They have built a wall 10000000 bytes long (such that there is enough place for all candidates). When the electoral campaign was restarted, the candidates were placing their posters on the wall and their posters differed widely in width. Moreover, the candidates started placing their posters on wall segments already occupied by other posters. Everyone in Bytetown was curious whose posters will be visible (entirely or in part) on the last day before elections.
Your task is to find the number of visible posters when all the posters are placed given the information about posters' size, their place and order of placement on the electoral wall.

The first line of input contains a number c giving the number of cases that follow. The first line of data for a single case contains number 1 ≤ n ≤ 10000. The subsequent n lines describe the posters in the order in which they were placed. The i-th line among the n lines contains two integer numbers li and ri which are the number of the wall segment occupied by the left end and the right end of the i-th poster, respectively. We know that for each 1 ≤ i ≤ n, 1 ≤ li ≤ ri ≤ 10000000. After the i-th poster is placed, it entirely covers all wall segments numbered li, li+1 ,... , ri.

For each input data set print the number of visible posters after all the posters are placed.

The picture below illustrates the case of the sample input.

Sample input

1
5
1 4
2 6
8 10
3 4
7 10
Output for sample input

4
Author: Adapted from VI AMPwPZ by P. Rudnicki

*/