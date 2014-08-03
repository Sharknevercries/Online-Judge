/* 13309329	10202	Pairsumonious Numbers	Accepted	C++	0.016	2014-03-12 06:59:19 */
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std; 
int P[100];
int A[100];
int N, fix;
int n;
vector<int> T;
bool remove(int target){
	for (int i = 0; i < T.size(); i++){
		if (T[i] == target){
			T.erase(T.begin() + i);
			return true;
		}
	}
	return false;
}
bool solve(int s){
	int ptr = 3;
	A[0] = s, A[1] = P[0] - A[0], A[2] = P[1] - A[0];
	T.clear();
	for (int i = 2; i < N; i++)
		T.push_back(P[i]);
	while (true){
		for (int i = 1; i < ptr - 1; i++){
			int target = A[i] + A[ptr - 1];
			if (!remove(target))
				return false;
		}
		if (T.size() == 0)
			return true;
		if (T[0] - A[0] < A[ptr - 1])
			return false;
		A[ptr++] = T[0] - A[0];
		T.erase(T.begin());
	}
}
void print(){
	printf("%d", A[0] - fix / 2);
	for (int i = 1; i < n; i++)
		printf(" %d", A[i] - fix / 2);
	putchar('\n');
}
int main(){
	while (scanf("%d", &n) == 1){
		N = n*(n - 1) / 2;
		for (int i = 0; i < N; i++)
			scanf("%d", P + i);
		sort(P, P + N);
		bool found = false;
		for (int i = 2; i < N; i++){
			int sum = P[0] + P[1] - P[i];
			if (sum % 2 == 1)	continue;
			if (solve(sum / 2)){
				print();
				found = true;
				break;
			}
		}

		if (!found)
			puts("Impossible");
	}
	return 0;
}
/*


Problem B: Pairsumonious Numbers

For 10 > N > 2 numbers we form N*(N-1)/2 sums by adding every pair of the numbers. Your task is to find the N numbers given the sums. Each line of input contains N followed by N*(N-1)/2 integer numbers separated by a space. For each line of input, output one line containing N integers in non-descending order such that the input numbers are pairwise sums of the N numbers. If there is more than one solution, any one will do; if there is no solution, print "Impossible".
Sample input

3 1269 1160 1663
3 1 1 1
5 226 223 225 224 227 229 228 226 225 227
5 216 210 204 212 220 214 222 208 216 210
5 -1 0 -1 -2 1 0 -1 1 0 -1
5 79950 79936 79942 79962 79954 79972 79960 79968 79924 79932
Output for sample input

383 777 886
Impossible
111 112 113 114 115
101 103 107 109 113
-1 -1 0 0 1
39953 39971 39979 39983 39989

*/