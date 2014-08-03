/* 9205896 920 Sunny Mountains Accepted C++ 0.008 2011-08-30 12:59:09 */
#include<stdio.h>
#include<math.h>
#define SWAP(x,y) {	int temp=x; x=y; y=temp;	}
struct data{
	int x,y;
};
typedef struct data MAKE;
MAKE m[100];
void qsort(int left,int right){
	if(right>left){
		int split,next;
		split=left;
		for(next=split+1;next<=right;next++)
			if(m[left].x<m[next].x){
				split++;
				SWAP(m[next].x,m[split].x);
				SWAP(m[next].y,m[split].y);
			}
		SWAP(m[left].x,m[split].x);
		SWAP(m[left].y,m[split].y);
		qsort(left,split-1);
		qsort(split+1,right);
	}
}
double result(int n){
	double sum;
	int pre_x,pre_y,temp_x,temp_y;

	sum=0;
	temp_y=pre_y=m[0].y;
	temp_x=pre_x=m[0].x;
	for(int i=1;i<n;i++){
		if(m[i].y>temp_y){
			int  x=pre_x-m[i].x;
			int  y=m[i].y-pre_y;
			sum+=(double)(m[i].y-temp_y)*sqrt((double)x*x+y*y)/(m[i].y-pre_y);
			temp_x=m[i].x;
			temp_y=m[i].y;
		}
		pre_x=m[i].x;
		pre_y=m[i].y;
	}
	return sum;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d%d",&m[i].x,&m[i].y);
		qsort(0,n-1);
		printf("%.2lf\n",result(n));
	}
	return 0;
}
/* 

Sunny Mountains

During their honeymoon, Mrs and Mr Smith went to the Himalayas. How they were surprised when they observed that, during the sunset, all the snow touched by the sunbeams turned red.

Such a magnificent landscape leaves everyone plenty of emotion, but Mr Smith's number obsession overcame all this. He rapidly began evaluating distances, which made Mrs Smith quite upset.

Problem

Your work is to help him calculate the size, in meters, of the mountainsides that became red as the sun sets. Mr Smith's honeymoon depends on you! Please be quick and efficient.

For the sake of simplicity, consider that, during the sunset, the sunbeams are horizontal and assume that the landscape is described by the set of coordinates of the mountain peaks and cols. This can be depicted by the following figure. A landscape, in this context, is then a sequence of peaks and cols (i.e., only a col follows a peak and conversely).

Note that, in this picture, the sunny mountainsides are emphasized by bold lines and the coordinates of the landscape are emphasized by bold points.

Thus, the goal of this problem is to calculate the total length in meters of the bold lines.

For this task consider that: (1) for all coordinates (x, y), 0 <=x <= 30000 and 0 <= y <= 8848; (2) the unit is the meter; (3) all the X-coordinates are pair-wise distinct; (4) the leftmost point has 0 as X-coordinate and the rightmost point has 0 as Y-coordinate; (5) The total number of coordinates given is n <= 100.

Input

The first line of input contains C (0 < C < 100 ), the number of test cases that follows. 

Each test case starts with a line containing the number N of coordinate pairs. The remaining  N lines for each test case contain the coordinates defining the landscape. Each of these lines contains two integers, x and y, separated by a single space. The first integer, x, is the X-coordinate, and the second, y, is the Y-coordinate of the considered point.

Output

The output is formed by a sequence of lines, one for each test case. Each line contains a single real number with exactly two decimal digits. This number represents the length in meters of the sunny mountainsides for the corresponding test case.

Sample Input

2
11
1100 1200
0 500
1400 100
600 600
2800 0
400 1100
1700 600
1500 800
2100 300
1800 700
2400 500
2
0 1000
1000 0

Sample Output

1446.34
1414.21 

--------------------------------------------------------------------------------

MIUP'2004: Fourth Portuguese National Programming Contest 

--------------------------------------------------------------------------------

Problem setter: Simão Melo de Sousa

*/