/* 13081037	12662	Good Teacher	Accepted	C++	0.022	2014-02-04 12:42:53 */
#include<cstdio>
char name[100][10];
int n;
void query(int target){
	if (name[target][0] != '?'){
		printf("%s\n", name[target]);
		return;
	}
	int L, R;
	L = target - 1, R = target + 1;
	while (true){
		if ((L >= 0 && name[L][0] != '?') && (R < n&&name[R][0] != '?')){
			printf("middle of %s and %s\n", name[L], name[R]);
			return;
		}
		else if (L >= 0 && name[L][0] != '?'){
			for (int i = target - L; i >= 1; i--)
				printf("right of ");
			printf("%s\n", name[L]);
			return;
		}
		else if (R < n && name[R][0] != '?'){
			for (int i = R - target; i >= 1; i--)
				printf("left of ");
			printf("%s\n", name[R]);
			return;
		}
		else{
			if (L - 1 >= 0)	L--;
			if (R + 1 < n)	R++;
		}
	}
}
int main(){
	while (scanf("%d", &n) == 1){
		for (int i = 0; i < n; i++)
			scanf("%s", name[i]);
		int Q;
		scanf("%d", &Q);
		for (int i = 0; i < Q; i++){
			int s;
			scanf("%d", &s);
			query(s - 1);
		}
	}
	return 0;
}
/*

I want to be a good teacher, so at least I need to remember all the student names. However, there are
too many students, so I failed. It is a shame, so I don't want my students to know this. Whenever I
need to call someone, I call his CLOSEST student instead. For example, there are 10 students:
A ? ? D ? ? ? H ? ?
Then, to call each student, I use this table:
Pos Reference
1 A
2 right of A
3 left of D
4 D
5 right of D
6 middle of D and H
7 left of H
8 H
9 right of H
10 right of right of H
Input
There is only one test case. The rst line contains n, the number of students (1  n  100). The next
line contains n space-separated names. Each name is either `?' or a string of no more than 3 English
letters. There will be at least one name not equal to `?'. The next line contains q, the number of
queries (1  q  100). Then each of the next q lines contains the position p (1  p  n) of a student
(counting from left).
Output
Print q lines, each for a student. Note that `middle of X and Y ' is only used when X and Y are
both closest of the student, and X is always to his left.
Sample Input
10
A ? ? D ? ? ? H ? ?
4
3
8
6
10
Sample Output
left of D
H
middle of D and H
right of right of H

*/