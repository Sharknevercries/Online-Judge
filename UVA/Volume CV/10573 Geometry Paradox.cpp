/* 8877326 10573 Geometry Paradox Accepted C++ 0.040 2011-05-23 14:04:19 */
#include<stdio.h>
#include<math.h>
int main(){
	const double PI=2*acos(0.0);
	int t,n;
	scanf("%d",&n);
	(void) getchar();
	for(t=1;t<=n;t++){	
		int i;
		int r1,r2,s;
		char str[100];
		gets(str);
		for(i=0;str[i]!='\0'&&str[i]!=' ';i++);
		if(str[i]==' '){
			sscanf(str,"%d%d",&r1,&r2);
			printf("%.4lf\n",(double)2*r1*r2*PI);
		}
		else{
			sscanf(str,"%d",&s);
			printf("%.4lf\n",(double)s*s/8*PI);
		}
	}
	return 0;
}
/*

In the picture below you can see two small circles touching each other. The larger circle touches both pf them. The length of the common tangent inscribed inside the larger circle is t and the radiuses of the two smaller circles are r1 and r2. The centers of the three circles are collinear. You will be given the value of r1 and r2 or the value of t. You will have to find the area that is within the larger circle but out of the two smaller circles (marked gray in the picture). If the given data is not enough to find the gray area, print the line ¡§Impossible.¡¨ in a single line 

Input  

First line of the input file contains an integer N (N<=100) which denotes how many sets of inputs are there. Each of the next N lines contain a set of input. 
 
Each set either contains one or two integer. If it contains one integer then it is the value of t, otherwise the two values are the values of r1 and r2.  All these integers are less than 100

Output 

For each line of input produce one line of output. This line contains the area of the gray part if the given information is enough to find the area of the gray part. Otherwise it contains the line ¡§Impossible.¡¨ The area should have four digits after the decimal point. Assume that pi=2*cos-1(0).
 
Sample Input                          

2 
10 10 
15 20 

Output for Sample Input

628.3185
1884.9556 

--------------------------------------------------------------------------------

Problemsetter: Shahriar Manzoor, Member of Elite Problemsetters' Panel

*/