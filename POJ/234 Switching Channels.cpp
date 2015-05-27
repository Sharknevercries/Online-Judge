/* 15455117	234	Switching Channels	Accepted	C++	0.146	2015-05-09 10:48:35 */
#include<bits\stdc++.h>
using namespace std;
int order[10];
bool V[10];
int ans[6], ansOrder[10];
int tmp[6];
int w[10], a[10], b[10];
int n, m;
bool cmp(){
	for (int i = 1; i < 6; i++)
		if (ans[i] > tmp[i])
			return true;
		else if (ans[i] < tmp[i])
			return false;
	return false;
}
void solve(){
	memset(tmp, 0, sizeof(tmp));
	int p[10] = { 0 };
	for (int i = 0; i < n; i++)
		p[i + 1] = p[i] + w[order[i]];
	for (int i = 0; i < m; i++){
		int minGap = 2e9;
		for (int j = 0; j <= n; j++)
			minGap = min(minGap, abs(p[j] - b[i]));
		tmp[a[i]] += minGap;
	}
	if (cmp()){
		for (int i = 0; i < n; i++)
			ansOrder[i] = order[i];
		for (int i = 1; i < 6; i++)
			ans[i] = tmp[i];
	}	
}
void DFS(int cnt){
	if (cnt == n)
		solve();
	else{
		for (int i = 0; i < n; i++){
			if (!V[i]){
				V[i] = true;
				order[cnt] = i;
				DFS(cnt + 1);
				V[i] = false;
			}
		}
	}
}
int main(){
	int c = 1;
	while (scanf("%d", &n) == 1 && n){
		for (int i = 0; i < n; i++)
			scanf("%d", w + i);
		scanf("%d", &m);
		for (int i = 0; i < m; i++)
			scanf("%d%d", a + i, b + i);
		for (int i = 1; i < 6; i++)
			ans[i] = 2e9;
		memset(V, false, sizeof(V));
		DFS(0);
		printf("Data set %d\n", c++);
		printf("Order:");
		for (int i = 0; i < n; i++)
			printf(" %d", w[ansOrder[i]]);
		putchar('\n');
		printf("Error:");
		int sum = 0;
		for (int i = 1; i < 6; i++)
			sum += ans[i];
		printf(" %d\n", sum);
	}
	return 0;
}
/*


Switching Channels

CPN (The Couch Potato Network) owns several cable channels. They would like to arrange the timing of programmes so viewers can switch channels without missing the end of one programme or the beginning of another. To do this they have identified certain times, called ``alignment points," where ideally one programme should end and another should begin. Some of these alignment points are more important than others. For example, the time when the nightly news begins is an important alignment point. Since many viewers watch the news, they would be less likely to watch a CPN programme whose ending time causes them to miss the beginning of the news, or which starts before the news finishes. Your task is to write a solution which determines the best order in which programmes can be shown on one channel.

A ``miss" time is the absolute value of the difference between the time of an alignment point and the nearest time of the beginning or end of a programme. The ``total miss time" at a particular level of importance is the sum of all the miss times for alignment points at that level of importance. One programme order is better than another if it has a lower total miss time at some level of importance and the same total miss time at all higher levels of importance (if any).

Input

Your solution must accept multiple input data sets. Each set will begin with an integer, p ( tex2html_wrap_inline29 ), specifying the number of programmes to be ordered. When a data set beginning with 0 is encountered, your solution should terminate. Following p on the same line will be p integers specifying the lengths of the programmes in minutes. There is no significance to the order in which these are given.

The next line of input specifies the alignment points. The total number of such points, a ( tex2html_wrap_inline37 ), appears first followed by a pairs of integers. The first integer in each pair, i ( tex2html_wrap_inline43 ), gives the importance of the alignment point. Alignment points marked 1 are most important; those marked 2 are of secondary importance, etc. The second integer in each pair, t, specifies the time when the alignment point occurs. No two alignment points in the same data set will have the same value of t.

Output

Your solution must output three lines for each data set. The first line identifies the data set being processed and should be in the form:

Data set n

where n is the number of the data set (1 for the first data set, 2 for the second, etc.). On the following line, your solution should output the lengths of the programmes in the order in which they should be shown to achieve the best synchronization with the alignment points. On the third line, output the total number of minutes by which the alignment points were missed (the sum of all total miss times).

There may be more than one best programme order for an input data set. Any one of these best orders is acceptable.

Sample Input

4  30 45 45 15
3  1 60  2 90  3 15
6  10 15 13 18 25 33
4  1 30  2 15  2 45  1 60
0
Sample Output

Data set 1
Order: 15 45 30 45
Error: 0
Data set 2
Order: 15 13 33 25 18 10
Error: 19

*/