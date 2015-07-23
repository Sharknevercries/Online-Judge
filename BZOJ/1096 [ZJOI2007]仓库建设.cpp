/* 1045076	840502	1096	Accepted	52052 kb	2328 ms	C++/Edit	1444 B	2015-07-14 14:53:11 */
#include<bits\stdc++.h>
#define MAXN 1000005
using namespace std;
int n;
long long x[MAXN], p[MAXN], c[MAXN];
long long sump[MAXN], sumpx[MAXN];
long long DP[MAXN];
int Q[MAXN];
long long X(int t){ return sump[t]; }
long long Y(int t){ return DP[t] + sumpx[t]; }
long long DX(int a, int b){ return X(b) - X(a); }
long long DY(int a, int b){ return Y(b) - Y(a); }
int main(){
  scanf("%d", &n);
  memset(sump, 0, sizeof(sump));
  memset(sumpx, 0, sizeof(sumpx));
  for (int i = 1; i <= n; i++){
    scanf("%lld%lld%lld", x + i, p + i, c + i);
    sump[i] = sump[i - 1] + p[i];
    sumpx[i] = sumpx[i - 1] + p[i] * x[i];
  }
  int L = 0, R = 1;
  for (int i = 1; i <= n; i++){
    while (L + 1 < R && DY(Q[L], Q[L + 1]) <= x[i] * DX(Q[L], Q[L + 1]))  L++;
    DP[i] = Y(Q[L]) - x[i] * sump[Q[L]] + x[i] * sump[i] - sumpx[i] + c[i];
    while (L + 1 < R && DY(Q[R - 2], Q[R - 1]) * DX(Q[R - 1], i) >= DY(Q[R - 1], i) * DX(Q[R - 2], Q[R - 1])) R--;
    Q[R++] = i;
  }
  printf("%lld\n", DP[n]);
  return 0;
}
/*

Description

L公司有N个工厂，由高到底分布在一座山上。如图所示，工厂1在山顶，工厂N在山脚。 由于这座山处于高原内陆地区（干燥少雨），L公司一般把产品直接堆放在露天，以节省费用。突然有一天，L公司的总裁L先生接到气象部门的电话，被告知三天之后将有一场暴雨，于是L先生决定紧急在某些工厂建立一些仓库以免产品被淋坏。由于地形的不同，在不同工厂建立仓库的费用可能是不同的。第i个工厂目前已有成品Pi件，在第i个工厂位置建立仓库的费用是Ci。对于没有建立仓库的工厂，其产品应被运往其他的仓库进行储藏，而由于L公司产品的对外销售处设置在山脚的工厂N，故产品只能往山下运（即只能运往编号更大的工厂的仓库），当然运送产品也是需要费用的，假设一件产品运送1个单位距离的费用是1。假设建立的仓库容量都都是足够大的，可以容下所有的产品。你将得到以下数据： 工厂i距离工厂1的距离Xi（其中X1=0）;  工厂i目前已有成品数量Pi;  在工厂i建立仓库的费用Ci; 请你帮助L公司寻找一个仓库建设的方案，使得总的费用（建造费用+运输费用）最小。

Input

第一行包含一个整数N，表示工厂的个数。接下来N行每行包含两个整数Xi, Pi, Ci, 意义如题中所述。

Output

仅包含一个整数，为可以找到最优方案的费用。

Sample Input

3
0 5 10
5 3 100
9 6 10

Sample Output

32
HINT

在工厂1和工厂3建立仓库，建立费用为10+10=20，运输费用为(9-5)*3 = 12，总费用32。如果仅在工厂3建立仓库，建立费用为10，运输费用为(9-0)*5+(9-5)*3=57，总费用67，不如前者优。

【数据规模】

对于100%的数据， N ≤1000000。 所有的Xi, Pi, Ci均在32位带符号整数以内，保证中间计算结果不超过64位带符号整数。

Source

*/