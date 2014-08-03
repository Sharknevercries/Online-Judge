/* 9083797 11579 Triangle Trouble Accepted C++ 1.100 2011-07-27 04:41:36 */
#include<stdio.h>
#include<math.h>
#define SWAP(x,y) { double temp=x; x=y; y=temp; }
void qsort(double x[],int left,int right){
	if(right>left){
		int key,split,next;
		key=x[left];
		split=left;
		for(next=split+1;next<=right;next++)
			if(x[next]<key){
				split++;
				SWAP(x[next],x[split]);
			}
		SWAP(x[split],x[left]);
		qsort(x,left,split-1);
		qsort(x,split+1,right);
	}
}
int main(){
	int t;
	scanf("%d",&t);
	for(int count=1;count<=t;count++){
		double s[100000];
		int i,n;
		double max;
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%lf",&s[i]);
		qsort(s,0,n-1);
		for(i=max=0;i<n-2;i++)
			if(s[i]+s[i+1]>s[i+2]){
				double m=(s[i]+s[i+1]+s[i+2])/2;
				double area=sqrt((double)m*(m-s[i])*(m-s[i+1])*(m-s[i+2]));
				if(area>max)
					max=area;
			}
		printf("%.2lf\n",max);
	}
	return 0;
}
/*

There is trouble at the triangle factory. The triangle assembler has gone down, so all that has been produced for the day is a bunch of triangle sides. To make the best of this situation, it has been decided to create the triangle with the largest possible area from the available sides, and sell it as a limited edition triangle.
 
You have been hired to write a program that will determine the area of the limited edition triangle.
 
Input begins with the number of test cases on its own line. Each test case begins with a positive integer N (3 ≤ N ≤ 10,000), followed by N positive real numbers si representing the lengths of the available triangle sides (0 < si ≤ 100,000). A single test case may be spread out over several consecutive lines of the input.
 
For each test case, output a line containing the largest possible area of a triangle built using three of the given sides (as a real number rounded to 2 decimal places). If it is not possible to construct any triangles then output "0.00" (quotes for clarity).
 
Sample input

2
4 3.0 4.0 5.0 100.0
3 1.0 2.0 4.0

 Sample output

6.00
0.00

--------------------------------------------------------------------------------
 Sumudu Fernando

*/