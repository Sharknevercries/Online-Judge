/* 4862148	 Oct 24, 2013 4:53:51 PM	Shark	 80B - Depression	 GNU C++	Accepted	 30 ms	 0 KB */
#include<stdio.h>
int main(){
	int H,M;
	while( scanf("%2d:%2d",&H,&M)==2 ){
		if( H>=12 )
			H-=12;
		double HH,MM;
		MM=M*6;
		HH=H*30+M*0.5;
		printf("%lf %lf\n",HH,MM);
	}
	return 0;
}
/*

B. Depression
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Do you remember a kind cartoon "Beauty and the Beast"? No, no, there was no firing from machine guns or radiation mutants time-travels!

There was a beauty named Belle. Once she had violated the Beast's order and visited the West Wing. After that she was banished from the castle...

Everybody was upset. The beautiful Belle was upset, so was the Beast, so was Lumiere the candlestick. But the worst thing was that Cogsworth was upset. Cogsworth is not a human, but is the mantel clock, which was often used as an alarm clock.

Due to Cogsworth's frustration all the inhabitants of the castle were in trouble: now they could not determine when it was time to drink morning tea, and when it was time for an evening stroll.

Fortunately, deep in the basement are lying digital clock showing the time in the format HH:MM. Now the residents of the castle face a difficult task. They should turn Cogsworth's hour and minute mustache hands in such a way, that Cogsworth began to show the correct time. Moreover they need to find turn angles in degrees for each mustache hands. The initial time showed by Cogsworth is 12:00.

You can only rotate the hands forward, that is, as is shown in the picture:


As since there are many ways too select such angles because of full rotations, choose the smallest angles in the right (non-negative) direction.

Note that Cogsworth's hour and minute mustache hands move evenly and continuously. Hands are moving independently, so when turning one hand the other hand remains standing still.

Input
The only line of input contains current time according to the digital clock, formatted as HH:MM (00 ≤ HH ≤ 23, 00 ≤ MM ≤ 59). The mantel clock initially shows 12:00.

Pretests contain times of the beginning of some morning TV programs of the Channel One Russia.

Output
Print two numbers x and y — the angles of turning the hour and minute hands, respectively (0 ≤ x, y < 360). The absolute or relative error in the answer should not exceed 10 - 9.

Sample test(s)
input
12:00
output
0 0
input
04:30
output
135 180
input
08:17
output
248.5 102
Note
A note to the second example: the hour hand will be positioned exactly in the middle, between 4 and 5.

*/