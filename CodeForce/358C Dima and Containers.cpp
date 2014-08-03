/* 4906065	 Oct 26, 2013 8:58:40 PM	Shark	 358C - Dima and Containers	 GNU C++	Accepted	46 ms	400 KB */
#include<stdio.h>
int main(){
	int n;
	while( scanf("%d",&n)==1 ){
		int M[100000];
		int B[3],P[3];
		for(int i=0;i<n;i++)
			scanf("%d",&M[i]);
		int L,R;
		
		for(L=R=0;R<n;R++){
			if( M[R]==0 ){
				B[0]=B[1]=B[2]=-1;
				for(int i=L;i<R;i++){
					if( B[0]==-1||M[B[0]]<M[i] )
						B[2]=B[1],B[1]=B[0],B[0]=i;
					else if( B[1]==-1||M[B[1]]<M[i] )
						B[2]=B[1],B[1]=i;
					else if( B[2]==-1||M[B[2]]<M[i] )
						B[2]=i;
				}
				for(int i=L;i<R;i++)
					if( i==B[0] )
						puts("pushStack");
					else if( i==B[1] )
						puts("pushQueue");
					else if( i==B[2] )
						puts("pushFront");
					else
						puts("pushBack");
				
				int count=0;
				if( B[0]>=0 )	count++;
				if( B[1]>=0 )	count++;
				if( B[2]>=0 )	count++;;
				printf("%d",count);
				for(int i=0;i<count;i++)
					if( i==0 )
						printf(" popStack");
					else if( i==1 )
						printf(" popQueue");
					else
						printf(" popFront");
				putchar('\n');
				L=R+1;
			}
		}
		for(int i=L;i<R;i++)
			puts("pushStack");
	}
	return 0;
}
/*

C. Dima and Containers
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Dima has a birthday soon! It's a big day! Saryozha's present to Dima is that Seryozha won't be in the room and won't disturb Dima and Inna as they celebrate the birthday. Inna's present to Dima is a stack, a queue and a deck.

Inna wants her present to show Dima how great a programmer he is. For that, she is going to give Dima commands one by one. There are two types of commands:

Add a given number into one of containers. For the queue and the stack, you can add elements only to the end. For the deck, you can add elements to the beginning and to the end.
Extract a number from each of at most three distinct containers. Tell all extracted numbers to Inna and then empty all containers. In the queue container you can extract numbers only from the beginning. In the stack container you can extract numbers only from the end. In the deck number you can extract numbers from the beginning and from the end. You cannot extract numbers from empty containers.
Every time Dima makes a command of the second type, Inna kisses Dima some (possibly zero) number of times. Dima knows Inna perfectly well, he is sure that this number equals the sum of numbers he extracts from containers during this operation.

As we've said before, Dima knows Inna perfectly well and he knows which commands Inna will give to Dima and the order of the commands. Help Dima find the strategy that lets him give as more kisses as possible for his birthday!

Input
The first line contains integer n (1 ≤ n ≤ 105) — the number of Inna's commands. Then n lines follow, describing Inna's commands. Each line consists an integer:

Integer a (1 ≤ a ≤ 105) means that Inna gives Dima a command to add number a into one of containers.
Integer 0 shows that Inna asks Dima to make at most three extractions from different containers.
Output
Each command of the input must correspond to one line of the output — Dima's action.

For the command of the first type (adding) print one word that corresponds to Dima's choice:

pushStack — add to the end of the stack;
pushQueue — add to the end of the queue;
pushFront — add to the beginning of the deck;
pushBack — add to the end of the deck.
For a command of the second type first print an integer k (0 ≤ k ≤ 3), that shows the number of extract operations, then print k words separated by space. The words can be:

popStack — extract from the end of the stack;
popQueue — extract from the beginning of the line;
popFront — extract from the beginning from the deck;
popBack — extract from the end of the deck.
The printed operations mustn't extract numbers from empty containers. Also, they must extract numbers from distinct containers.

The printed sequence of actions must lead to the maximum number of kisses. If there are multiple sequences of actions leading to the maximum number of kisses, you are allowed to print any of them.

Sample test(s)
input
10
0
1
0
1
2
0
1
2
3
0
output
0
pushStack
1 popStack
pushStack
pushQueue
2 popStack popQueue
pushStack
pushQueue
pushFront
3 popStack popQueue popFront
input
4
1
2
3
0
output
pushStack
pushQueue
pushFront
3 popStack popQueue popFront

*/