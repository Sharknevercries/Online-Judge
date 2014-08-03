/* 9190521 11677 Alarm Clock Accepted C++ 0.028 2011-08-25 13:08:19 */
#include<stdio.h>
int main(){
	int h1,h2,m1,m2;
	while(scanf("%d%d%d%d",&h1,&m1,&h2,&m2)==4){
		if(h1==0&&m1==0&&h2==0&&m2==0)
			break;
		int h,m;
		h = (h2-h1)>=0 ? h2-h1 : h2+24-h1 ;
		if(m2-m1<0)
			h = (h==0) ? 23 : h-1;
		m = (m2-m1<0) ? m2+60-m1 : m2-m1;
		printf("%d\n",h*60+m);
	}
	return 0;
}
/*

 Daniela is a nurse in a large hospital, which causes her working shifts to constantly change. To make it worse, she has deep sleep, and a difficult time to wake up using alarm clocks.
 Recently she got a digital clock as a gift, with several different options of alarm sounds, and she has hope that it might help solve her problem. But, lately, she's been very tired and want to enjoy every single moment of rest. So she carries her new clock to every place she goes, and whenever she has some spare time, she tries to sleep, setting her alarm clock to the time when she needs to wake up. But, with so much anxiety to sleep, she ends up with some difficulty to fall asleep and enjoy some rest.
 
A problem that has been tormenting her is to know how many minutes of sleep she would have if she felt asleep immediately and woken up when the alarm clock ringed. But she is not very good with numbers, and asked you for help to write a program that, given the current time and the alarm time, find out the number of minutes she could sleep.
 
Input  

The input contains several test cases. Each test case is described in one line, containing four integers H1, M1, H2 and M2, with H1 : M1 representing the current hour and minute, and H2 : M2 representing the time (hour and minute) when the alarm clock is set to ring ( 0H123, 0M159, 0H223, 0M259).
 The end of the input is indicated by a line containing only four zeros, separated by blank spaces.
 
Output  

For each test case, your program must print one line, containing a single integer, indicating the number of minutes Daniela has to sleep.
 
Sample Input  

1 5 3 5
23 59 0 34
21 33 21 10
0 0 0 0

 Sample Output  
 
120
35
1417

--------------------------------------------------------------------------------

*/