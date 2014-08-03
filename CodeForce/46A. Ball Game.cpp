/* 1254582	 Mar 1, 2012 6:40:27 PM	Shark	 46A - Ball Game	 GNU C++	Accepted	 30 ms	 1300 KB */
#include<stdio.h>
int main(){
	int n;
	while(scanf("%d",&n)==1){
		bool visit[1000]={false};
		int ptr=0,gap=1,count=0;
		while(count<n-1){
			ptr+=gap;
			gap++;
			if(ptr>=n)
				ptr%=n;
			if(count==0)
				printf("%d",ptr+1);
			else
				printf(" %d",ptr+1);
			count++;
		}
		putchar('\n');
	}
	return 0;
}
/*

A kindergarten teacher Natalia Pavlovna has invented a new ball game. This game not only develops the children's physique, but also teaches them how to count.

The game goes as follows. Kids stand in circle. Let's agree to think of the children as numbered with numbers from 1 to n clockwise and the child number 1 is holding the ball. First the first child throws the ball to the next one clockwise, i.e. to the child number 2. Then the child number 2 throws the ball to the next but one child, i.e. to the child number 4, then the fourth child throws the ball to the child that stands two children away from him, i.e. to the child number 7, then the ball is thrown to the child who stands 3 children away from the child number 7, then the ball is thrown to the child who stands 4 children away from the last one, and so on. It should be mentioned that when a ball is thrown it may pass the beginning of the circle. For example, if n = 5, then after the third throw the child number 2 has the ball again. Overall, n - 1 throws are made, and the game ends.

The problem is that not all the children get the ball during the game. If a child doesn't get the ball, he gets very upset and cries until Natalia Pavlovna gives him a candy. That's why Natalia Pavlovna asks you to help her to identify the numbers of the children who will get the ball after each throw.

Input

The first line contains integer n (2 ≤ n ≤ 100) which indicates the number of kids in the circle.

Output

In the single line print n - 1 numbers which are the numbers of children who will get the ball after each throw. Separate the numbers by spaces.

input

10
3

output

2 4 7 1 6 2 9 7 6
2 1

*/