/* 8867485 10365 Blocks Accepted C++ 0.172 2011-05-20 14:52:04 */
#include<stdio.h>
#include<math.h>
#define INT_MAX 2147483647
int main(){
	int n;
	scanf("%d",&n);
	for(int t=1;t<=n;t++){
		int min;
		int m3,p;
		int l,w,h;
		scanf("%d",&p);
		m3=ceil(pow((double)p,1.0/3));
		for(l=1,min=INT_MAX;l<=m3;l++)
			if(p%l==0){
				int m2=ceil(sqrt((double)p/l));			
				for(w=1;w<=m2;w++)
					if((p/l)%w==0){
						h=(p/l)/w;
						if(min>2*(l*w+w*h+h*l))
							min=2*(l*w+w*h+h*l);
					}
			}
		printf("%d\n",min);
	}
	return 0;
}
/*

 Donald wishes to send a gift to his new nephew, Fooey. Donald is a bit of a traditionalist, so he has chosen to send a set of N classic baby blocks. Each block is a cube, 1 inch by 1 inch by 1 inch. Donald wants to stack the blocks together into a rectangular solid and wrap them all up in brown paper for shipping. How much brown paper does Donald need?
 
 The first line of input contains C, the number of test cases. For each case there is an additional line containing N, the number of blocks to be shipped. N does not exceed 1000. Your program should produce one line of output per case, giving the minimal area of paper (in square inches) needed to wrap the blocks when they are stacked together.
 
Sample Input

5
9
10
26
27
100
 
Output for Sample Input

30
34
82
54
130

 */