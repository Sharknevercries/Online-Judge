/* 4849295	 Oct 23, 2013 11:57:12 AM	Shark	 257B - Playing Cubes	 GNU C++	Accepted	30 ms	0 KB */
#include<stdio.h>
int main(){
	int n,m;
	while( scanf("%d%d",&n,&m)==2 ){ // must oxxoo ... or xooxx ...
		int min= n>m ? m : n;
		printf("%d %d\n",(n+m-1-min),min); 
	}
	return 0;
}
/*

B. Playing Cubes
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Petya and Vasya decided to play a little. They found n red cubes and m blue cubes. The game goes like that: the players take turns to choose a cube of some color (red or blue) and put it in a line from left to right (overall the line will have n + m cubes). Petya moves first. Petya's task is to get as many pairs of neighbouring cubes of the same color as possible. Vasya's task is to get as many pairs of neighbouring cubes of different colors as possible.

The number of Petya's points in the game is the number of pairs of neighboring cubes of the same color in the line, the number of Vasya's points in the game is the number of neighbouring cubes of the different color in the line. Your task is to calculate the score at the end of the game (Petya's and Vasya's points, correspondingly), if both boys are playing optimally well. To "play optimally well" first of all means to maximize the number of one's points, and second — to minimize the number of the opponent's points.

Input
The only line contains two space-separated integers n and m (1 ≤ n, m ≤ 105) — the number of red and blue cubes, correspondingly.

Output
On a single line print two space-separated integers — the number of Petya's and Vasya's points correspondingly provided that both players play optimally well.

Sample test(s)
input
3 1
output
2 1
input
2 4
output
3 2
Note
In the first test sample the optimal strategy for Petya is to put the blue cube in the line. After that there will be only red cubes left, so by the end of the game the line of cubes from left to right will look as [blue, red, red, red]. So, Petya gets 2 points and Vasya gets 1 point.

If Petya would choose the red cube during his first move, then, provided that both boys play optimally well, Petya would get 1 point and Vasya would get 2 points.

*/