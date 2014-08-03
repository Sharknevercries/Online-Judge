/* 9060759 11462 Age Sort Accepted C++ 0.708 2011-07-19 07:22:01 */
#include<stdio.h>
#include<math.h>
#define EQN(x) ((4*x+3)*x+1)
static int x[2000001];
void sort(int n){
	int power2=log((-3.0+sqrt(16.0*n-7.0))/8.0)/log(2.0);
	power2=1<<(power2+1);
	int gap;
	do{
		power2>>=1;
		gap=EQN(power2);
		for(int i=gap;i<n;i++)
			for(int j=i-gap;j>=0&&x[j]>x[j+gap];j-=gap){
				int temp=x[j];
				x[j]=x[j+gap];
				x[j+gap]=temp;
			}
	}while(gap>1);
}
int main(){
	int n;
	while(scanf("%d",&n)==1&&n!=0){
		for(int i=0;i<n;i++)
			scanf("%d",&x[i]);
		sort(n);
		printf("%d",x[0]);
		for(int i=1;i<n;i++)
			printf(" %d",x[i]);
		putchar('\n');
	}
	return 0;
}
/*

You are given the ages (in years) of all people of a country with at least 1 year of age. You know that no individual in that country lives for 100 or more years. Now, you are given a very simple task of sorting all the ages in ascending order.

Input

There are multiple test cases in the input file. Each case starts with an integer n (0<n<=2000000), the total number of people. In the next line, there are n integers indicating the ages. Input is terminated with a case where n = 0. This case should not be processed.

Output 

For each case, print a line with n space separated integers. These integers are the ages of that country sorted in ascending order.

Warning: Input Data is pretty big (~  25 MB) so use faster IO.

Sample Input

5
3 4 2 1 5
5
2 3 2 3 1
0

Output for Sample Input

1 2 3 4 5
1 2 2 3 3 

Note: The memory limit of this problem is 2 Megabyte Only.

--------------------------------------------------------------------------------

Problem Setter: Mohammad Mahmudur Rahman

Special Thanks: Shahriar Manzoor

*/