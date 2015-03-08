/* 9988414	2015-02-24 19:59:14	Shark	518C - Anya and Smartphone	GNU C++	Accepted	61 ms	800 KB */
#include<bits\stdc++.h>
using namespace std;
int app[100005];
int pos[100005];
int main(){
	int n, m, k;
	long long ans = 0;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++){
		int tmp;
		scanf("%d", &tmp);
		app[tmp] = i;
		pos[i] = tmp;
	}
	for (int i = 0; i < m; i++){
		int target, tmp;
		scanf("%d", &target);
		ans += app[target] / k + 1LL;
		tmp = app[target];
		if (tmp > 0){
			swap(app[pos[tmp]], app[pos[tmp - 1]]);
			swap(pos[tmp], pos[tmp - 1]);
		}
	}
	printf("%lld\n", ans);
	return 0;
}
/*

C. Anya and Smartphone
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Anya has bought a new smartphone that uses Berdroid operating system. The smartphone menu has exactly n applications, each application has its own icon. The icons are located on different screens, one screen contains k icons. The icons from the first to the k-th one are located on the first screen, from the (k + 1)-th to the 2k-th ones are on the second screen and so on (the last screen may be partially empty).

Initially the smartphone menu is showing the screen number 1. To launch the application with the icon located on the screen t, Anya needs to make the following gestures: first she scrolls to the required screen number t, by making t - 1 gestures (if the icon is on the screen t), and then make another gesture — press the icon of the required application exactly once to launch it.

After the application is launched, the menu returns to the first screen. That is, to launch the next application you need to scroll through the menu again starting from the screen number 1.

All applications are numbered from 1 to n. We know a certain order in which the icons of the applications are located in the menu at the beginning, but it changes as long as you use the operating system. Berdroid is intelligent system, so it changes the order of the icons by moving the more frequently used icons to the beginning of the list. Formally, right after an application is launched, Berdroid swaps the application icon and the icon of a preceding application (that is, the icon of an application on the position that is smaller by one in the order of menu). The preceding icon may possibly be located on the adjacent screen. The only exception is when the icon of the launched application already occupies the first place, in this case the icon arrangement doesn't change.

Anya has planned the order in which she will launch applications. How many gestures should Anya make to launch the applications in the planned order?

Note that one application may be launched multiple times.

Input
The first line of the input contains three numbers n, m, k (1 ≤ n, m, k ≤ 105) — the number of applications that Anya has on her smartphone, the number of applications that will be launched and the number of icons that are located on the same screen.

The next line contains n integers, permutation a1, a2, ..., an — the initial order of icons from left to right in the menu (from the first to the last one), ai —  is the id of the application, whose icon goes i-th in the menu. Each integer from 1 to n occurs exactly once among ai.

The third line contains m integers b1, b2, ..., bm(1 ≤ bi ≤ n) — the ids of the launched applications in the planned order. One application may be launched multiple times.

Output
Print a single number — the number of gestures that Anya needs to make to launch all the applications in the desired order.

Sample test(s)
input
8 3 3
1 2 3 4 5 6 7 8
7 8 1
output
7
input
5 4 2
3 1 5 2 4
4 4 4 4
output
8
Note
In the first test the initial configuration looks like (123)(456)(78), that is, the first screen contains icons of applications 1, 2, 3, the second screen contains icons 4, 5, 6, the third screen contains icons 7, 8.

After application 7 is launched, we get the new arrangement of the icons — (123)(457)(68). To launch it Anya makes 3 gestures.

After application 8 is launched, we get configuration (123)(457)(86). To launch it Anya makes 3 gestures.

After application 1 is launched, the arrangement of icons in the menu doesn't change. To launch it Anya makes 1 gesture.

In total, Anya makes 7 gestures.

*/