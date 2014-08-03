/* 8866555 10310 Dog and Gopher Accepted C++ 0.012 2011-05-20 10:01:30 */
#include<stdio.h>
#include<math.h>
int main(){
	int n;
	double gopher_x,gopher_y,dog_x,dog_y;
	while(scanf("%d%lf%lf%lf%lf",&n,&gopher_x,&gopher_y,&dog_x,&dog_y)==5){
		bool escape=false;
		double x,y,tx,ty;
		int i,j;
		for(i=1;i<=n;i++){
			scanf("%lf%lf",&x,&y);
			if(!escape&&sqrt((gopher_x-x)*(gopher_x-x)+(gopher_y-y)*(gopher_y-y))*2<=sqrt((dog_x-x)*(dog_x-x)+(dog_y-y)*(dog_y-y))){
				escape=true;
				tx=x;
				ty=y;
			}
		}
		if(escape)
			printf("The gopher can escape through the hole at (%.3lf,%.3lf).\n",tx,ty);
		else
			puts("The gopher cannot escape.");

	}
	return 0;
}
/*

A large field has a gopher and a dog. The dog wants to eat the gopher, while the gopher wants to run to safety through one of several gopher holes dug in the surface of the field. 

Neither the dog nor the gopher is a math major; however, neither is entirely stupid. The gopher decides on a particular gopher hole and heads for that hole in a straight line at a fixed speed. The dog, which is very good at reading body language, anticipates which hole the gopher has chosen, and heads at double the speed of the gopher to the hole, where it intends to gobble up the gopher. If the dog reaches the hole first, the gopher gets gobbled; otherwise, the gopher escapes. 

You have to select a hole for the gopher through which it can escape, if such a hole exists. 

Input

The input file contains several sets of input. The first line of each set contains one integer and four floating point numbers. The integer n denotes how many holes are in the set and the four floating point numbers denote the (x,y) coordinates of the gopher followed by the (x,y) coordinates of the dog. Subsequent n lines of input each contain two floating point numbers: the (x, y) coordinates of a gopher hole. All distances are in meters; to the nearest mm. Input is terminated by end of file. There is a blank line between two consecutive sets.

Output

Your should output a single line for each set of input. For each set, if the gopher can escape the output line should read "The gopher can escape through the hole at (x,y)." identifying the appropriate hole to the nearest mm. Otherwise the output line should read "The gopher cannot escape." If the gopher may escape through more than one hole, report the one that appears first in the input. There are not more than 1000 gopher holes in a set of input and all coordinates are between -10000 and +10000. 

Sample Input:

1 1.000 1.000 2.000 2.000
1.500 1.500 

2 2.000 2.000 1.000 1.000
1.500 1.500
2.500 2.500

Sample Output

The gopher cannot escape.The gopher can escape through the hole at (2.500,2.500).

--------------------------------------------------------------------------------

(Joint Effort Contest, Source: Waterloo ACM Programming Contest)
 
*/