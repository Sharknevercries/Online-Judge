/* 10331858	2015-03-18 06:01:27	Shark	527C - Glass Carving	GNU C++	Accepted	156 ms	9900 KB */
#include<bits\stdc++.h>
using namespace std;
int w, h, n;
struct Query{
	char type;
	int pos;
	long long int ans;
};
Query Q[200005];
int pw[200005], ph[200005];
int lw[200005], lh[200005];
int sw[200005], sh[200005];
int maxW, maxH;
vector<int> W, H;
int find(int x, int p[]){
	return x == p[x] ? x : p[x] = find(p[x], p);
}
int main(){
	scanf("%d%d%d", &w, &h, &n);
	for (int i = 0; i < n; i++){
		scanf(" %c %d", &Q[i].type, &Q[i].pos);
		if (Q[i].type == 'H')
			H.push_back(Q[i].pos);
		else
			W.push_back(Q[i].pos);
	}
	H.push_back(h), W.push_back(w);
	sort(H.begin(), H.end());
	sort(W.begin(), W.end());
	maxH = maxW = 0;
	for (int i = 0; i < H.size(); i++)
		sh[i] = H[i], lh[i] = i - 1 >= 0 ? sh[i] - sh[i - 1] : sh[i], ph[i] = i, maxH = max(maxH, lh[i]);
	for (int i = 0; i < W.size(); i++)
		sw[i] = W[i], lw[i] = i - 1 >= 0 ? sw[i] - sw[i - 1] : sw[i], pw[i] = i, maxW = max(maxW, lw[i]);
	for (int i = n - 1; i >= 0; i--){
		Q[i].ans = 1LL * maxW * maxH;
		if (Q[i].type == 'H'){
			int pos = lower_bound(sh, sh + H.size(), Q[i].pos) - sh;
			int x = find(pos, ph);
			ph[pos + 1] = x;
			lh[x] += lh[pos + 1];
			maxH = max(maxH, lh[x]);
		}
		else{
			int pos = lower_bound(sw, sw + W.size(), Q[i].pos) - sw;
			int x = find(pos, pw);
			pw[pos + 1] = x;
			lw[x] += lw[pos + 1];
			maxW = max(maxW, lw[x]);
		}
	}
	for (int i = 0; i < n; i++)
		printf("%lld\n", Q[i].ans);
	return 0;
}
/*

C. Glass Carving
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Leonid wants to become a glass carver (the person who creates beautiful artworks by cutting the glass). He already has a rectangular w mm  ×  h mm sheet of glass, a diamond glass cutter and lots of enthusiasm. What he lacks is understanding of what to carve and how.

In order not to waste time, he decided to practice the technique of carving. To do this, he makes vertical and horizontal cuts through the entire sheet. This process results in making smaller rectangular fragments of glass. Leonid does not move the newly made glass fragments. In particular, a cut divides each fragment of glass that it goes through into smaller fragments.

After each cut Leonid tries to determine what area the largest of the currently available glass fragments has. Since there appear more and more fragments, this question takes him more and more time and distracts him from the fascinating process.

Leonid offers to divide the labor — he will cut glass, and you will calculate the area of the maximum fragment after each cut. Do you agree?

Input
The first line contains three integers w, h, n (2 ≤ w, h ≤ 200 000, 1 ≤ n ≤ 200 000).

Next n lines contain the descriptions of the cuts. Each description has the form H y or V x. In the first case Leonid makes the horizontal cut at the distance y millimeters (1 ≤ y ≤ h - 1) from the lower edge of the original sheet of glass. In the second case Leonid makes a vertical cut at distance x (1 ≤ x ≤ w - 1) millimeters from the left edge of the original sheet of glass. It is guaranteed that Leonid won't make two identical cuts.

Output
After each cut print on a single line the area of the maximum available glass fragment in mm2.

Sample test(s)
input
4 3 4
H 2
V 2
V 3
V 1
output
8
4
4
2
input
7 6 5
H 4
V 3
V 5
H 2
V 1
output
28
16
12
6
4
Note
Picture for the first sample test:

Picture for the second sample test:

*/