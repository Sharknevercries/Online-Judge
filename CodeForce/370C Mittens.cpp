/* 5380436	 Dec 8, 2013 11:10:11 AM	Shark	 370C - Mittens	 GNU C++	Accepted	 15 ms	 0 KB */
#include<stdio.h>
#include<algorithm>
#include<vector>
struct data{
	int count, ID;
};
int n, m;
std::vector<struct data> A;
std::vector<struct data> B;
bool cmp (struct data A, struct data B){
	return A.count > B.count || (A.count == B.count && A.ID > B.ID);
}
int main(){
	while (scanf("%d%d", &n, &m) == 2){
		struct data M[101];
		int ans[5000][2] = { 0 };
		for (int i = 0; i <= 100; i++)
			M[i].count = 0, M[i].ID = i;
		A.clear();
		B.clear();
		for (int i = 0; i < n; i++){
			int tmp;
			scanf("%d", &tmp);
			M[tmp].count++;
		}
		for (int i = 1; i <= m; i++){
			if (M[i].count > 0)
				A.push_back(M[i]);
		}
		std::sort(A.begin(), A.end(), cmp); // sort by frequence
		for (int i = 1; i < A.size(); i++){ // let the one of the most frequence and place it begind
			B.push_back(A[i]);
		}
		B.push_back(A[0]);
		int count = 0;
		int ptrA = 0, ptrB = 0;
		int countA = 0, countB = 0;
		for (int i = 0; i < n; i++){
			ans[i][0] = A[ptrA].ID;
			ans[i][1] = B[ptrB].ID;
			if (ans[i][0] != ans[i][1])
				count++;
			countA++;
			countB++;
			if (countA >= A[ptrA].count)
				ptrA++, countA = 0;
			if (countB >= B[ptrB].count)
				ptrB++, countB = 0;
		}
		printf("%d\n", count);
		for (int i = 0; i < n; i++){
			printf("%d %d\n", ans[i][0], ans[i][1]);
		}
	}
	return 0;
}
/*

C. Mittens
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
A Christmas party in city S. had n children. All children came in mittens. The mittens can be of different colors, but each child had the left and the right mitten of the same color. Let's say that the colors of the mittens are numbered with integers from 1 to m, and the children are numbered from 1 to n. Then the i-th child has both mittens of color ci.

The Party had Santa Claus ('Father Frost' in Russian), his granddaughter Snow Girl, the children danced around the richly decorated Christmas tree. In fact, everything was so bright and diverse that the children wanted to wear mittens of distinct colors. The children decided to swap the mittens so that each of them got one left and one right mitten in the end, and these two mittens were of distinct colors. All mittens are of the same size and fit all the children.

The children started exchanging the mittens haphazardly, but they couldn't reach the situation when each child has a pair of mittens of distinct colors. Vasily Petrov, the dad of one of the children, noted that in the general case the children's idea may turn out impossible. Besides, he is a mathematician and he came up with such scheme of distributing mittens that the number of children that have distinct-colored mittens was maximum. You task is to repeat his discovery. Note that the left and right mittens are different: each child must end up with one left and one right mitten.

Input
The first line contains two integers n and m — the number of the children and the number of possible mitten colors (1 ≤ n ≤ 5000, 1 ≤ m ≤ 100). The second line contains n integers c1, c2, ... cn, where ci is the color of the mittens of the i-th child (1 ≤ ci ≤ m).

Output
In the first line, print the maximum number of children who can end up with a distinct-colored pair of mittens. In the next n lines print the way the mittens can be distributed in this case. On the i-th of these lines print two space-separated integers: the color of the left and the color of the right mitten the i-th child will get. If there are multiple solutions, you can print any of them.

Sample test(s)
input
6 3
1 3 2 2 1 1
output
6
2 1
1 2
2 1
1 3
1 2
3 1
input
4 2
1 2 1 1
output
2
1 2
1 1
2 1
1 1

*/