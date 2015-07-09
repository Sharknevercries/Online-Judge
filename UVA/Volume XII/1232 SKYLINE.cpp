/* 14157452	1232	SKYLINE	Accepted	C++	0.142	2014-09-06 10:49:49 */
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
#define MAX_N 100005
#define MAX_M 1000
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
struct node{
	int L, R, MaxH, MinH;
	int H;
	bool leaf;
};
node T[4 * MAX_N];
int ans = 0;
void build_Segment_Tree(int root, int L, int R){
	T[root].L = L, T[root].R = R;
	T[root].MaxH = T[root].MinH = 0;
	T[root].leaf = false;
	T[root].H = NONE;
	if (R > L + 1){
		int mid = (L + R) / 2;
		build_Segment_Tree(root * 2, L, mid);
		build_Segment_Tree(root * 2 + 1, mid, R);
	}
	else
		T[root].leaf = true;
}
void push(int root){
	if (T[root].H != NONE){
		T[root * 2].MaxH = T[root * 2].MinH = T[root * 2].H = T[root].H;
		T[root * 2 + 1].MaxH = T[root * 2 + 1].MinH = T[root * 2 + 1].H = T[root].H;
		T[root].H = NONE;
	}
}
void update(int root, int L, int R, int H){
	if (T[root].MinH > H)	return;
	if (!T[root].leaf)push(root);
	if (T[root].L == L && T[root].R == R && T[root].MaxH <= H){
		ans += (T[root].R - T[root].L);
		T[root].MaxH = T[root].MinH = T[root].H = H;
		return;
	}
	if (T[root].leaf)return;
	int mid = (T[root].L + T[root].R) / 2;
	if (mid >= R)
		update(root * 2, L, R, H);
	else if (L >= mid)
		update(root * 2 + 1, L, R, H);
	else{
		update(root * 2, L, mid, H);
		update(root * 2 + 1, mid, R, H);
	}
	T[root].MaxH = max(T[root * 2].MaxH, T[root * 2 + 1].MaxH);
	T[root].MinH = min(T[root * 2].MinH, T[root * 2 + 1].MinH);
}
int main(){
	int t;
	while (scanf("%d", &t) == 1 && t){
		while (t--){
			ans = 0;
			build_Segment_Tree(1, 1, MAX_N - 1);
			int n;
			scanf("%d", &n);
			for (int i = 0; i < n; i++){
				int a, b, h;
				scanf("%d%d%d", &a, &b, &h);
				update(1, a, b, h);
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}
/*

The skyline of Singapore as viewed from the Marina Promenade (shown on the left) is one of the iconic scenes of Singapore. Country X would also like to create an iconic skyline, and it has put up a call for proposals. Each submitted proposal is a description of a proposed skyline and one of the metrics that country X will use to evaluate a proposed skyline is the amount of overlap in the proposed sky-line.

\epsfbox{p4108a.eps}
As the assistant to the chair of the skyline evaluation committee, you have been tasked with determining the amount of overlap in each proposal. Each proposal is a sequence of buildings,  $ \langle$b1, b2,..., bn$ \rangle$ , where a building is specified by its left and right endpoint and its height. The buildings are specified in back to front order, in other words a building which appears later in the sequence appears in front of a building which appears earlier in the sequence.

The skyline formed by the first k buildings is the union of the rectangles of the first k buildings (see Figure 4). The overlap of a building, bi , is defined as the total horizontal length of the parts of bi , whose height is greater than or equal to the skyline behind it. This is equivalent to the total horizontal length of parts of the skyline behind bi which has a height that is less than or equal to hi , where hi is the height of building bi . You may assume that initially the skyline has height zero everywhere.

Input

The input consists of a line containing the number c of datasets, followed by c datasets, followed by a line containing the number `0'.

The first line of each dataset consists of a single positive integer, n (0 < n < 100000) , which is the number of buildings in the proposal. The following n lines of each dataset each contains a description of a single building. The i -th line is a description of building bi . Each building bi is described by three positive integers, separated by spaces, namely, li , ri and hi , where li and rj (0 < li < ri$ \le$100000) represents the left and right end point of the building and hi represents the height of the building.

\epsfbox{p4108b.eps}
Output

The output consists of one line for each dataset. The c -th line contains one single integer, representing the amount of overlap in the proposal for dataset c . You may assume that the amount of overlap for each dataset is at most 2000000.


Note: In this test case, the overlap of building b1 , b2 and b3 are 6, 4 and 4 respectively. Figure 4 shows how to compute the overlap of building b3 . The grey area represents the skyline formed by b1 and b2 and the black rectangle represents b3 . As shown in the figure, the length of the skyline covered by b3 is from position 3 to position 5 and from position 11 to position 13, therefore the overlap of b3 is 4.

Sample Input

1
3
5 11 3
1 10 1
3 13 2
0
Sample Output

14

*/