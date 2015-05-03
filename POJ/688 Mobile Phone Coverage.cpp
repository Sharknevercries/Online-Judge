/* 15404783	688	Mobile Phone Coverage	Accepted	C++	0.009	2015-04-29 14:26:27 */
#include<bits\stdc++.h>
#define EPS 1e-9
using namespace std;
struct Node{
	int L, R, cover;
	double len;
};
struct Segment{
	double x, y1, y2;
	int v;
	Segment(){}
	Segment(double x, double y1, double y2, int v) :x(x), y1(y1), y2(y2), v(v){}
};
Node T[10000];
Segment S[205];
double H[205];
int Sptr, Hptr;
bool cmp(Segment A, Segment B){
	return A.x < B.x;
}
void build(int pos, int L, int R){
	T[pos].L = L, T[pos].R = R;
	T[pos].len = T[pos].cover = 0;
	if (L + 1 >= R)
		return;
	int mid = (L + R) / 2;
	build(pos * 2, L, mid);
	build(pos * 2 + 1, mid, R);
}
void pushUp(int pos){
	if (T[pos].cover)
		T[pos].len = H[T[pos].R] - H[T[pos].L];
	else if (T[pos].L + 1 >= T[pos].R)
		T[pos].len = 0;
	else
		T[pos].len = T[pos * 2].len + T[pos * 2 + 1].len;
}
void update(int pos, int L, int R, int v){
	if (L >= T[pos].R || R <= T[pos].L)	return;
	if (L <= T[pos].L && R >= T[pos].R)
		T[pos].cover += v;
	else{
		update(pos * 2, L, R, v);
		update(pos * 2 + 1, L, R, v);
	}
	pushUp(pos);
}
int main(){
	int n, c = 1;
	while (scanf("%d", &n) == 1 && n){
		Sptr = Hptr = 0;
		for (int i = 0; i < n; i++){
			double x, y, r;
			scanf("%lf%lf%lf", &x, &y, &r);
			S[Sptr++] = Segment(x - r, y - r, y + r, 1);
			S[Sptr++] = Segment(x + r, y - r, y + r, -1);
			H[Hptr++] = y - r, H[Hptr++] = y + r;
		}
		sort(S, S + Sptr, cmp);
		sort(H, H + Hptr);
		Hptr = unique(H, H + Hptr) - H;
		build(1, 0, Hptr - 1);
		double ans = 0;
		for (int i = 0; i < Sptr; i++){
			int L = lower_bound(H, H + Hptr, S[i].y1) - H;
			int R = lower_bound(H, H + Hptr, S[i].y2) - H;
			update(1, L, R, S[i].v);
			if (i + 1 < Sptr)
				ans += T[1].len * (S[i + 1].x - S[i].x);
		}
		printf("%d %.2lf\n", c++, ans);
	}
	return 0;
}