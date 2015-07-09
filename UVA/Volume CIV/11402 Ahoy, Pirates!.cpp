/* 14151259	11402	Ahoy, Pirates!	Accepted	C++	0.548	2014-09-05 11:44:51 */
// C++
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<bitset>
#include<algorithm>
#include<functional>
#include<deque>
// C
#include<cstdio>
#include<cstring>
#include<ctime>
#include<cctype>
#include<cmath>
// namespace
using namespace std;
// typedef
typedef long long lli;
typedef unsigned long long ull;
// template
template<class T> T max(T a, T b, T c){ return max(a, max(b, c)); }
template<class T> T min(T a, T b, T c){ return min(a, min(b, c)); }
// const variable
#define MAX_N 1024005
#define MAX_M 1005
#define INF 1e9
#define NONE -1
#define EPS 1e-6
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3
const double PI = 2.0 * acos(0.0);
const int mx[] = { 0, 1, 0, -1 };
const int my[] = { -1, 0, 1, 0 };
// main
struct command{
	int L, R;
	char com;
};
// 0 for Barbary, 1 for Buccaneer
struct node{
	int L, R;
	int mark;
	int count0;
	int count1;
};
struct segment{
	int L, R;
};
char S[MAX_N];
int n, m, q;
int num[2 * MAX_M];
command com[MAX_M];
segment seg[4 * MAX_M];
int segCount, curL;
node T[32 * MAX_M];
void addSegment(int L, int R){
	if (R > L)
		seg[segCount].L = L, seg[segCount++].R = R - 1;
	seg[segCount].L = seg[segCount++].R = R;
	curL = R + 1;
}
pair<int, int> count01(int L, int R){
	int count0 = 0, count1 = 0;
	for (int i = L; i <= R; i++)
		if (S[i] == '0')
			count0++;
		else
			count1++;
	return make_pair(count0, count1);
}
void build_Segment_Tree(int root, int L, int R){
	T[root].L = seg[L].L;
	T[root].R = seg[R].R;
	T[root].mark = NONE;
	if (R > L){
		int mid = (L + R) / 2;
		build_Segment_Tree(root * 2, L, mid);
		build_Segment_Tree(root * 2 + 1, mid + 1, R);
		T[root].count0 = T[root * 2].count0 + T[root * 2 + 1].count0;
		T[root].count1 = T[root * 2].count1 + T[root * 2 + 1].count1;
	}
	else{
		pair<int, int> res = count01(seg[L].L, seg[L].R);
		T[root].count0 = res.first;
		T[root].count1 = res.second;
	}
}
void deal(int root, int op){
	if (op == 2){
		T[root].mark = 1 - T[root].mark;
		swap(T[root].count0, T[root].count1);
	}
	else{
		if (op == 1)
			T[root].count1 += T[root].count0, T[root].count0 = 0;
		if (op == 0)
			T[root].count0 += T[root].count1, T[root].count1 = 0;
		T[root].mark = op;
	}
}
void update(int root, int L, int R, int op){
	if (T[root].mark != NONE){
		deal(root * 2, T[root].mark);
		deal(root * 2 + 1, T[root].mark);
		T[root].mark = NONE;
	}
	if (T[root].L == L && T[root].R == R)
		deal(root, op);
	else{
		if (R <= T[root * 2].R)
			update(root * 2, L, R, op);
		else if (L >= T[root * 2 + 1].L)
			update(root * 2 + 1, L, R, op);
		else{
			update(root * 2, L, T[root * 2].R, op);
			update(root * 2 + 1, T[root * 2 + 1].L, R, op);
		}
		T[root].count0 = T[root * 2].count0 + T[root * 2 + 1].count0;
		T[root].count1 = T[root * 2].count1 + T[root * 2 + 1].count1;
	}
}
int query(int root, int L, int R){
	if (T[root].mark != NONE){
		deal(root * 2, T[root].mark);
		deal(root * 2 + 1, T[root].mark);
		T[root].mark = NONE;
	}
	if (T[root].L == L && T[root].R == R)
		return T[root].count1;
	if (R <= T[root * 2].R)
		return query(root * 2, L, R);
	else if (L >= T[root * 2 + 1].L)
		return query(root * 2 + 1, L, R);
	else
		return query(root * 2, L, T[root * 2].R) + query(root * 2 + 1, T[root * 2 + 1].L, R);
}
int main(){
	int t, c = 1;
	scanf("%d", &t);
	while (t--){
		n = 0;
		scanf("%d", &m);
		for (int i = 0; i < m; i++){
			int k;
			char str[100];
			scanf("%d%s", &k, str);
			for (int j = 0; j < k; j++)
				for (int p = 0; str[p] != '\0'; p++)
					S[n++] = str[p];
		}
		scanf("%d", &q);
		for (int i = 0; i < q; i++){
			scanf(" %c %d%d", &com[i].com, &com[i].L, &com[i].R);
			if (com[i].R >= n)com[i].R = n - 1;
		}
		for (int i = 0; i < q; i++)
			num[i] = com[i].L, num[i + q] = com[i].R;
		sort(num, num + 2 * q);
		curL = segCount = 0;
		addSegment(curL, num[0]);
		for (int i = 1; i < 2 * q; i++){
			if (num[i] == num[i - 1])continue;
			addSegment(curL, num[i]);
		}
		if (num[2 * q - 1] != n - 1)
			addSegment(curL, n - 1);
		build_Segment_Tree(1, 0, segCount - 1);
		printf("Case %d:\n", c++);
		int s = 1;
		for (int i = 0; i < q; i++){
			if (com[i].com == 'F') update(1, com[i].L, com[i].R, 1);
			if (com[i].com == 'E') update(1, com[i].L, com[i].R, 0);
			if (com[i].com == 'I') update(1, com[i].L, com[i].R, 2);
			if (com[i].com == 'S')printf("Q%d: %d\n", s++, query(1, com[i].L, com[i].R));
		}
	}
	return 0;
}
/*

Problem H
Ahoy, Pirates!
Input: Standard Input
Output: Standard Output


In the ancient pirate ages, the Pirate Land was divided into two teams of pirates, namely, the Buccaneer and the Barbary pirates. Each pirate・s team was not fixed, sometimes the opponent pirates attacked and he was taken away to the other pirate team. All on a sudden a magician appeared in the Pirate Land, where he was making transition of pirates from their team to other team at his own will. Of course, handy spells were used. The process of changing team was known as mutating.

There were N pirates and all of the pirates have a unique id from 0 to N-1. The great magician could mutate a bunch of pirates with consecutive id・s to another one.

Suppose there were 100 pirates in the pirate land and all of them were Barbary pirates, then the magician could cast a spell to change pirates with id・s from 10 to 33 to Buccaneer pirates. Then the whole pirate land would have 24 Buccaneer and 76 Barbary pirates.

The magician was very fast casting the spell. Once, God started to dislike this. God had favor for the Buccaneer pirates and God asked the magician, ：Tell me, how many of the pirates of index from 2 to 30 are Buccaneer pirates?；. Now the magician was puzzled as he was only efficient in casting spells, not in counting J

Being clever enough, the magician captured a clever man from the Earth Land. And unfortunately it・s you! Now you have to answer the God・s questions.

Input

The first line of input will contain number of test cases T.
For each test case:
The first part of the description will be of the pirate land. There could be up to N (1<=N<=1024000) pirates. Each pirate is either assigned to Buccaneer or Barbary Pirate. Buccaneer pirates are described by ．1・ (ONE) and Barbary pirates are described by ．0・ (ZERO). You have to build a string of the pirates・ description. Each case starts with an integer M (M<=100), where M pair lines follow. In each pair of lines (we call it a set), first has an integer T  (T <= 200) and next one has a nonempty string Pirates (consisting of 0 and 1, 0 for Barbary, 1 for Buccaneer, has maximum length of 50). For each pair concatenate the string Pirates, T times. Concatenate all the resulting M sets of strings to build the pirate description. The final concatenated string describes the pirates from index 0 to end (N-1 for N pirates).
Now the next part of the input will contain queries. First line of next part has an integer Q describing number of queries. Each subsequence Q (1<=Q<=1000) lines describe each query. Each query has a string F or E or I or S and two integers, a and b denoting indexes. The meaning of the query string are follows:
F a b, means, mutate the pirates from index a to b to Buccaneer Pirates.
E a b, means, mutate the pirates from index a to b to Barbary Pirates.
I a b, means, mutate the pirates from index a to b to inverse pirates.
S a b, means, ：God・s query； God is asking a question: ：Tell me, how many Buccaneer pirates are there from index a to b?；
(a <= b, 0 <= a < n, 0 <= b < n, index range are inclusive)

Output
For each test print the case number as the sample output suggests. Then for each of ：God・s query；, output the query number, colon (:) and a space and the answer to the query as the sample suggest.

Sample Input                                                  Output for Sample Input
2
2
5
10
2
1000
5
F 0 17
I 0 5
S 1 10
E 4 9
S 2 10
3
3
1
4
0
2
0
2
I 0 2
S 0 8
Case 1:
Q1: 5
Q2: 1
Case 2:
Q1: 0


Explanation:
Case1:
The pirate land is as follows (N = 18)
101010101010001000
Before God・s first query it was as follows
000000111111111111

Case 2:
The pirate land is as follows (N=9)
111000000

Problemsetter: Istiaque Ahmed
Special Thanks to: Mohammad Mahmudur Rahman

*/