/* 12417564	10281	Average Speed	Accepted	C++	0.028	2013-09-29 08:42:46 */
#include<stdio.h>
int main(){
	char str[30];
	int H,M,S;
	int HH=0,MM=0,SS=0,speed=0;
	double distance=0;
	while( gets(str) ){
		
		sscanf(str+0,"%2d",&H);
		sscanf(str+3,"%2d",&M);
		sscanf(str+6,"%2d",&S);
		distance+=((H-HH)+(M-MM)/60.0+(S-SS)/3600.0)*speed;
		HH=H,MM=M,SS=S;
		if( str[8]=='\0' )
			printf("%02d:%02d:%02d %.2lf km\n",H,M,S,distance);
		else
			sscanf(str+9,"%d",&speed);
	}
	return 0;
}
/*

Problem A: Average Speed

You have bought a car in order to drive from Waterloo to a big city. The odometer on their car is broken, so you cannot measure distance. But the speedometer and cruise control both work, so the car can maintain a constant speed which can be adjusted from time to time in response to speed limits, traffic jams, and border queues. You have a stopwatch and note the elapsed time every time the speed changes. From time to time you wonder, "how far have I come?". To solve this problem you must write a program to run on your laptop computer in the passenger seat.
Standard input contains several lines of input: Each speed change is indicated by a line specifying the elapsed time since the beginning of the trip (hh:mm:ss), followed by the new speed in km/h. Each query is indicated by a line containing the elapsed time. At the outset of the trip the car is stationary. Elapsed times are given in non-decreasing order and there is at most one speed change at any given time.

For each query in standard input, you should print a line giving the time and the distance travelled, in the format below.

Sample Input

00:00:01 100
00:15:01
00:30:01
01:00:01 50
03:00:01
03:00:05 140
Output for Sample Output

00:15:01 25.00 km
00:30:01 50.00 km
03:00:01 200.00 km

*/