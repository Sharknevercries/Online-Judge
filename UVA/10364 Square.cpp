/* 15454750	10364	Square	Accepted	C++	0.036	2015-05-09 09:21:38 */
#include<bits\stdc++.h>
using namespace std;
bool V[25];
int n, w[25];
bool DFS(int cnt, int len, int start, int target){
	if (cnt == 3)	return true;
	for (int i = start; i < n; i++){
		if (!V[i] && len + w[i] <= target){
			V[i] = true;
			if (len + w[i] == target && DFS(cnt + 1, 0, 0, target))
				return true;
			if (len + w[i] < target && DFS(cnt, len + w[i], i + 1, target))
				return true;
			V[i] = false;
		}
	}
	return false;
}
bool cmp(int a, int b){
	return a > b;
}
int main(){
	int t;
	scanf("%d", &t);
	while (t--){
		int sum = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", w + i), sum += w[i];
		memset(V, false, sizeof(V));
		sort(w, w + n, cmp);
		if (sum % 4 == 0)
			if (w[0] > sum / 4)
				puts("no");
			else
				puts(DFS(0, 0, 0, sum / 4) ? "yes" : "no");
		else
			puts("no");
	}
	return 0;
}
/*

Given a set of sticks of various
lengths, is it possible to join them
end-to-end to form a square?
Input
The first line of input contains N,
the number of test cases. Each
test case begins with an integer
4 ≤ M ≤ 20, the number of sticks.
M integers follow; each gives the
length of a stick — an integer between
1 and 10,000.
Output
For each case, output a line containing ‘yes’ if is is possible to form a square; otherwise output ‘no’.
Sample Input
3
4 1 1 1 1
5 10 20 30 40 50
8 1 7 2 6 4 4 3 5
Sample Output
yes
no
yes

*/