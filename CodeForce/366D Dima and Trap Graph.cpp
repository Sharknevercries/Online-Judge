/* 5269947	 Nov 27, 2013 1:16:57 PM	Shark	 366D - Dima and Trap Graph	 GNU C++	Accepted	 156 ms	 0 KB */
#include<stdio.h>
#include<algorithm>
#define MAX(x,y) ( (x) >= (y) ? (x) : (y) )
struct data{
	int a, b;
	int L, R;
};
int P[1000];
bool cmp(struct data A, struct data B){
	return A.L < B.L;
}
int find(int x){
	return x == P[x] ? x : P[x] = find(P[x]);
}
void connect(int a, int b){
	a = find(a);
	b = find(b);
	P[a] = b;
}
int main(){
	int n, m;
	while (scanf("%d%d", &n, &m) == 2){
		struct data T[3000];
		for (int i = 0; i < m; i++){
			scanf("%d%d%d%d", &T[i].a, &T[i].b, &T[i].L, &T[i].R);
			T[i].a--, T[i].b--;
		}
		std::sort(T, T + m, cmp); // sort by L
		int ans = -1;
		for (int i = 0; i < m; i++){ // choose a edge (L,R) to be a standard
			for (int j = 0; j < n; j++)
				P[j] = j;
			for (int j = 0; j < m; j++){
				if (T[i].R < T[j].L) // cut	
					break;
				if (T[j].R < T[i].R) // can not match standard
					continue;
				connect(T[j].a, T[j].b);
				if (find(0) == find(n - 1)){
					ans = MAX(ans, T[i].R - T[j].L + 1);
				}
			}
		}
		if (ans>0)
			printf("%d\n", ans);
		else
			puts("Nice work, Dima!");
	}
	return 0;
}
/*

D. Dima and Trap Graph
time limit per test3 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Dima and Inna love spending time together. The problem is, Seryozha isn't too enthusiastic to leave his room for some reason. But Dima and Inna love each other so much that they decided to get criminal...

Dima constructed a trap graph. He shouted: "Hey Seryozha, have a look at my cool graph!" to get his roommate interested and kicked him into the first node.

A trap graph is an undirected graph consisting of n nodes and m edges. For edge number k, Dima denoted a range of integers from lk to rk (lk ≤ rk). In order to get out of the trap graph, Seryozha initially (before starting his movements) should pick some integer (let's call it x), then Seryozha must go some way from the starting node with number 1 to the final node with number n. At that, Seryozha can go along edge k only if lk ≤ x ≤ rk.

Seryozha is a mathematician. He defined the loyalty of some path from the 1-st node to the n-th one as the number of integers x, such that if he initially chooses one of them, he passes the whole path. Help Seryozha find the path of maximum loyalty and return to his room as quickly as possible!

Input
The first line of the input contains two integers n and m (2 ≤ n ≤ 103, 0 ≤ m ≤ 3·103). Then follow m lines describing the edges. Each line contains four integers ak, bk, lk and rk (1 ≤ ak, bk ≤ n, 1 ≤ lk ≤ rk ≤ 106). The numbers mean that in the trap graph the k-th edge connects nodes ak and bk, this edge corresponds to the range of integers from lk to rk.

Note that the given graph can have loops and multiple edges.

Output
In a single line of the output print an integer — the maximum loyalty among all paths from the first node to the n-th one. If such paths do not exist or the maximum loyalty equals 0, print in a single line "Nice work, Dima!" without the quotes.

Sample test(s)
input
4 4
1 2 1 10
2 4 3 5
1 3 1 5
2 4 2 7
output
6
input
5 6
1 2 1 10
2 5 11 20
1 4 2 5
1 3 10 11
3 4 12 10000
4 5 6 6
output
Nice work, Dima!
Note
Explanation of the first example.

Overall, we have 2 ways to get from node 1 to node 4: first you must go along the edge 1-2 with range [1-10], then along one of the two edges 2-4.

One of them contains range [3-5], that is, we can pass through with numbers 3, 4, 5. So the loyalty of such path is 3.

If we go along edge 2-4 with range [2-7], then we can pass through with numbers 2, 3, 4, 5, 6, 7. The loyalty is 6. That is the answer.

The edge 1-2 have no influence on the answer because its range includes both ranges of the following edges.

*/