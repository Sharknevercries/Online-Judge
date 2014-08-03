/* 8863109 10286 Trouble with a Pentagon Accepted C++ 0.020 2011-05-19 12:04:21 */
#include<stdio.h>
#include<math.h>
int main(){
	const double PI=2*acos(0.0);
	double F;
	while(~scanf("%lf",&F)){
		printf("%.10lf\n",F*(sin(108.0/180.0*PI)/sin(63.0/180.0*PI)));
	}
	return 0;
}
/*

You are asked to place the largest possible square inside a regular pentagon (whose internal angles are same and all the sides are same in length). You are given the information that one vertex of the square will be coincident with a vertex of the square as shown in the figure below. You will have to find the length of a side of the square when a side of the regular pentagon is given. 

Fig: Square in a pentagon. 

Input

The input file contains several lines of input. Each line contains a floating point number F (0<=F<=100000) which indicates the length of a side of the pentagon. Input is terminated by end of file.

Output

For each line of input produce one line of output containing a floating point number with ten digits after the decimal point. This number indicates the largest possible side of a square that fits in the pentagon. This output will be judged with a special correction program, so don¡¦t worry about small precision errors.

Sample Input

0.0000001

0.0000002

0.0000003 

Sample Output

0.0000001067

0.0000002135

0.0000003202

--------------------------------------------------------------------------------

(World Finals Warm-up Contest, Problem Setter: Shahriar Manzoor)
 
 */