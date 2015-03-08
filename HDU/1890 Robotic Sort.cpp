/* 12790953	2015-01-24 18:27:02	Accepted	1890	483MS	4688K	3216 B	G++	Shark */
#include<bits\stdc++.h>
using namespace std;
struct data{
	int a, b;
	friend bool operator<(data A, data B){ return A.a < B.a || (A.a == B.a && A.b < B.b); }
};
struct node{
	data s;
	int L, R, parent;
	int size;
	bool rev;
	node(){}
	node(data s, int L, int R, int parent) :s(s), L(L), R(R), parent(parent){
		size = 1, rev = false;
	}
	friend bool operator<(node A, node B){ return A.s < B.s; }
}T[100005];
int n;
int cap, root;
data M[100005];
void build(int L, int R, int parent, int &r){
	if (L > R)return;
	int mid = (L + R) / 2;
	r = mid;
	T[mid] = node(M[mid], 0, 0, parent);
	build(L, mid - 1, mid, T[mid].L);
	build(mid + 1, R, mid, T[mid].R);
	T[mid].size = T[T[mid].L].size + T[T[mid].R].size + 1;
}
void pushDown(int x){
	if (T[x].rev){
		T[T[x].L].rev ^= 1;
		T[T[x].R].rev ^= 1;
		swap(T[x].L, T[x].R);
		T[x].rev = 0;
	}
}
void pushUp(int x){
	T[x].size = T[T[x].L].size + T[T[x].R].size + 1;
}
void leftRotate(int x){
	int y;
	y = T[x].parent; T[y].R = T[x].L;
	if (T[x].L != 0)	T[T[x].L].parent = y;
	T[x].parent = T[y].parent;	T[x].L = y;
	if (T[y].parent != 0)
		if (y == T[T[y].parent].L)
			T[T[y].parent].L = x;
		else
			T[T[y].parent].R = x;
	T[y].parent = x;
	pushUp(y);
}
void rightRotate(int x){
	int y;
	y = T[x].parent; T[y].L = T[x].R;
	if (T[x].R != 0)	T[T[x].R].parent = y;
	T[x].parent = T[y].parent;	T[x].R = y;
	if (T[y].parent != 0)
		if (y == T[T[y].parent].L)
			T[T[y].parent].L = x;
		else
			T[T[y].parent].R = x;
	T[y].parent = x;
	pushUp(y);
}
void splay(int x, int goal){
	int y;
	pushDown(x);
	while (T[x].parent != goal){
		y = T[x].parent;
		if (T[y].parent == goal){
			pushDown(y);	pushDown(x);
			if (x == T[y].L)
				rightRotate(x);
			else
				leftRotate(x);
		}
		else{
			pushDown(T[y].parent);	pushDown(y);	pushDown(x);
			if (x == T[y].L){
				if (y == T[T[y].parent].L){
					rightRotate(y);
					rightRotate(x);
				}
				else{
					rightRotate(x);
					leftRotate(x);
				}
			}
			else{
				if (y == T[T[y].parent].R){
					leftRotate(y);
					leftRotate(x);
				}
				else{
					leftRotate(x);
					rightRotate(x);
				}
			}
		}
	}
	pushUp(x);
	if (T[x].parent == 0)
	root = x;
}
int getMax(int x){
	pushDown(x);
	while (T[x].R)
		 x = T[x].R, pushDown(x);
	return x;
}
void remove(){
	if (T[root].L == 0)
		root = T[root].R, T[root].parent = 0;
	else{
		int m = getMax(T[root].L);
		splay(m, root);
		T[m].R = T[root].R;
		T[T[root].R].parent = m;
		root = m;
		T[root].parent = 0;
		pushUp(root);
	}
}
int main(){
	while (scanf("%d", &n) == 1 && n){
		for (int i = 1; i <= n; i++)
			scanf("%d", &M[i].a), M[i].b = i;
		sort(M + 1, M + 1 + n);
		cap = root = 0;
		build(1, n, 0, root);
		for (int i = 1; i < n; i++){
			splay(M[i].b, 0);
			T[T[root].L].rev ^= 1;
			printf("%d ", i + T[T[root].L].size);
			remove();
		}
		printf("%d\n", n);

	}
	return 0;
}
/*

Robotic Sort

Time Limit: 6000/2000 MS (Java/Others)    Memory Limit: 32768/32768 K (Java/Others)
Total Submission(s): 2615    Accepted Submission(s): 1149


Problem Description
Somewhere deep in the Czech Technical University buildings, there are laboratories for examining mechanical and electrical properties of various materials. In one of yesterday’s presentations, you have seen how was one of the laboratories changed into a new multimedia lab. But there are still others, serving to their original purposes.

In this task, you are to write software for a robot that handles samples in such a laboratory. Imagine there are material samples lined up on a running belt. The samples have different heights, which may cause troubles to the next processing unit. To eliminate such troubles, we need to sort the samples by their height into the ascending order.

Reordering is done by a mechanical robot arm, which is able to pick up any number of consecutive samples and turn them round, such that their mutual order is reversed. In other words, one robot operation can reverse the order of samples on positions between A and B.

A possible way to sort the samples is to find the position of the smallest one (P1) and reverse the order between positions 1 and P1, which causes the smallest sample to become first. Then we find the second one on position P and reverse the order between 2 and P2. Then the third sample is located etc.




The picture shows a simple example of 6 samples. The smallest one is on the 4th position, therefore, the robot arm reverses the first 4 samples. The second smallest sample is the last one, so the next robot operation will reverse the order of five samples on positions 2–6. The third step will be to reverse the samples 3–4, etc.

Your task is to find the correct sequence of reversal operations that will sort the samples using the above algorithm. If there are more samples with the same height, their mutual order must be preserved: the one that was given first in the initial order must be placed before the others in the final order too.


Input
The input consists of several scenarios. Each scenario is described by two lines. The first line contains one integer number N , the number of samples, 1 ≤ N ≤ 100 000. The second line lists exactly N space-separated positive integers, they specify the heights of individual samples and their initial order.

The last scenario is followed by a line containing zero.


Output
For each scenario, output one line with exactly N integers P1 , P1 , . . . PN ,separated by a space.
Each Pi must be an integer (1 ≤ Pi ≤ N ) giving the position of the i-th sample just before the i-th reversal operation.

Note that if a sample is already on its correct position Pi , you should output the number Pi anyway, indicating that the “interval between Pi and Pi ” (a single sample) should be reversed.


Sample Input
6
3 4 5 1 6 2
4
3 3 2 1
0


Sample Output
4 6 4 5 6 6
4 2 4 4


Source
2008 “Shun Yu Cup” Zhejiang Collegiate Programming Contest - Warm Up（2）


Recommend
linle   |   We have carefully selected several similar problems for you:  1882 1883 1887 1889 1888 

*/