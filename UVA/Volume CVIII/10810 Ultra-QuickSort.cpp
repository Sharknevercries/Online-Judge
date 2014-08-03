/* 13117370	10810	Ultra-QuickSort	Accepted	C++	0.202	2014-02-10 11:17:29 */
#include<cstdio>
int M[500000];
int T[500000];
int n;
long long int count;
void merge(int L, int R){
	int Lptr, Rptr, mid, ptr = L;
	Lptr = L, mid = (L + R) / 2, Rptr = mid + 1;
	for (int i = L; i <= R; i++)
		T[i] = M[i];
	while (Lptr <= mid&&Rptr <= R){
		if (T[Lptr] > T[Rptr])
			M[ptr++] = T[Rptr++], count += mid - Lptr + 1;
		else
			M[ptr++] = T[Lptr++];
	}
	while (Lptr <= mid)	M[ptr++] = T[Lptr++];
	while (Rptr <= R)	M[ptr++] = T[Rptr++];
}
void mergeSort(int L, int R){
	if (R > L){
		int mid = (L + R) / 2;
		mergeSort(L, mid);
		mergeSort(mid + 1, R);
		merge(L, R);
	}
}
int main(){
	while (scanf("%d", &n) == 1){
		if (n == 0)
			break;
		for (int i = 0; i < n; i++)
			scanf("%d", M + i);
		count = 0;
		mergeSort(0, n - 1);
		printf("%lld\n", count);
	}
	return 0;
}
/*


Problem B: Ultra-QuickSort

In this problem, you have to analyze a particular sorting algorithm. The algorithm processes a sequence of n distinct integers by swapping two adjacent sequence elements until the sequence is sorted in ascending order. For the input sequence
9 1 0 5 4 ,
Ultra-QuickSort produces the output
0 1 4 5 9 .
Your task is to determine how many swap operations Ultra-QuickSort needs to perform in order to sort a given input sequence.
The input contains several test cases. Every test case begins with a line that contains a single integer n < 500,000 -- the length of the input sequence. Each of the the following n lines contains a single integer 0 ≤ a[i] ≤ 999,999,999, the i-th input sequence element. Input is terminated by a sequence of length n = 0. This sequence must not be processed.

For every input sequence, your program prints a single line containing an integer number op, the minimum number of swap operations necessary to sort the given input sequence.

Sample Input

5
9
1
0
5
4
3
1
2
3
0
Output for Sample Input

6
0
Stefan B�ttcher

*/