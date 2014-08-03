/* 9294049 10017 The Never Ending Towers of Hanoi Accepted C++ 0.016 2011-09-24 07:12:08 */
#include<stdio.h>
int index[3],stack[3][255];
int n,m,step;
bool show(){
    if(step<=m){
        int i;
        if(index[0]>0)
            printf("A=>  ");
        else
            printf("A=>");
        for(i=0;i<index[0];i++)
            printf(" %d",stack[0][i]);
        putchar('\n');
        
        if(index[1]>0)
            printf("B=>  ");
        else
            printf("B=>");
        for(i=0;i<index[1];i++)
            printf(" %d",stack[1][i]);
        putchar('\n');
        
        if(index[2]>0)
            printf("C=>  ");
        else
            printf("C=>");
        for(i=0;i<index[2];i++)
            printf(" %d",stack[2][i]);    
        putchar('\n');
        putchar('\n');
        step++;  
        return true;  
    }
    return false;
}
void result(int n,int start,int mid,int end){
    if(n==1){       
        stack[end][index[end]++]=stack[start][--index[start]];
        if( !show() )   return ;        
    }
    else{
        result(n-1,start,end,mid);
        stack[end][index[end]++]=stack[start][--index[start]];
        if( !show() )   return ;     
        result(n-1,mid,start,end);
    }
}
int main()
{
   int t=1;
   while(scanf("%d%d",&n,&m)==2){
        if(n==0&&m==0)
            break;
        printf("Problem #%d\n",t++);
        for(int i=0;i<n;i++)
            stack[0][i]=n-i;
        index[0]=n;
        step=index[1]=index[2]=0;
        
        putchar('\n');
        (void)show();
        result(n,0,1,2);
   }
   return 0;
}
/*

In 1883, Edward Lucas invented, or perhaps reinvented, one of the most popular puzzles of all times - the Tower of Hanoi, as he called it - which is still used today in many computer science textbooks to demonstrate how to write a recursive algorithm or program. First of all, we will make a list of the rules of the puzzle: 
¡P There are three pegs: A, B and C. 
¡P There are n disks. The number n is constant while working the puzzle. 
¡P All disks are different in size. 
¡P The disks are initially stacked on peg A so that they increase in size from the top to the bottom. 
¡P The goal of the puzzle is to transfer the entire tower from the A peg to the peg C. 
¡P One disk at a time can be moved from the top of a stack either to an empty peg or to a peg with a larger disk than itself on the top of its stack. 

Your job will be to write a program which will show a copy of the puzzle on the screen step by step, as you move the disks around. This program has to solve the problem in an efficient way. 

TIP: It is well known and rather easy to prove that the minimum number of moves needed to complete the puzzle with n disks is  2n -1. 
  
The Input

The input file will consist of a series of lines. Each line will contain two integers n, m. n, lying within the range [1,250], will denote the number of disks and m, belonging to [0,2n-1], will be the number of the last move, you may assume that m will also be less than 216, and you may also assume that a good algorithm will always have enough time. The file will end at a line formed by two zeros. 

The Output

The output will consist again of a series of lines, formatted as show below. 

NOTES: There are 3 spaces between de ¡¥=>¡¦ and the first number printed. If there isn't any number, there should be no spaces. 
               All the disks in a single peg are printed in a single line.
Print a blank line after every problem.
 
Sample Input
64 2 
8 45 
0 0 

Sample Output 

Problem #1

A=>   64 63 62 61 60 59 58 57 56 55 54 53 52 51 50 49 48 47 46 45 44 43 42 41 40 39 38 37 36 35 34 33 32 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1
B=>
C=>

A=>   64 63 62 61 60 59 58 57 56 55 54 53 52 51 50 49 48 47 46 45 44 43 42 41 40 39 38 37 36 35 34 33 32 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2
B=>   1
C=>

A=>   64 63 62 61 60 59 58 57 56 55 54 53 52 51 50 49 48 47 46 45 44 43 42 41 40 39 38 37 36 35 34 33 32 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3
B=>   1
C=>   2

Problem #2

A=>   8 7 6 5 4 3 2 1
B=>
C=>

A=>   8 7 6 5 4 3 2
B=>   1
C=>

A=>   8 7 6 5 4 3
B=>   1
C=>   2

A=>   8 7 6 5 4 3
B=>
C=>   2 1

A=>   8 7 6 5 4
B=>   3
C=>   2 1

A=>   8 7 6 5 4 1
B=>   3
C=>   2

A=>   8 7 6 5 4 1
B=>   3 2
C=>

A=>   8 7 6 5 4
B=>   3 2 1
C=>

A=>   8 7 6 5
B=>   3 2 1
C=>   4

A=>   8 7 6 5
B=>   3 2
C=>   4 1

A=>   8 7 6 5 2
B=>   3
C=>   4 1

A=>   8 7 6 5 2 1
B=>   3
C=>   4

A=>   8 7 6 5 2 1
B=>
C=>   4 3

A=>   8 7 6 5 2
B=>   1
C=>   4 3

A=>   8 7 6 5
B=>   1
C=>   4 3 2

A=>   8 7 6 5
B=>
C=>   4 3 2 1

A=>   8 7 6
B=>   5
C=>   4 3 2 1

A=>   8 7 6 1
B=>   5
C=>   4 3 2

A=>   8 7 6 1
B=>   5 2
C=>   4 3

A=>   8 7 6
B=>   5 2 1
C=>   4 3

A=>   8 7 6 3
B=>   5 2 1
C=>   4

A=>   8 7 6 3
B=>   5 2
C=>   4 1

A=>   8 7 6 3 2
B=>   5
C=>   4 1

A=>   8 7 6 3 2 1
B=>   5
C=>   4

A=>   8 7 6 3 2 1
B=>   5 4
C=>

A=>   8 7 6 3 2
B=>   5 4 1
C=>

A=>   8 7 6 3
B=>   5 4 1
C=>   2

A=>   8 7 6 3
B=>   5 4
C=>   2 1

A=>   8 7 6
B=>   5 4 3
C=>   2 1

A=>   8 7 6 1
B=>   5 4 3
C=>   2

A=>   8 7 6 1
B=>   5 4 3 2
C=>

A=>   8 7 6
B=>   5 4 3 2 1
C=>

A=>   8 7
B=>   5 4 3 2 1
C=>   6

A=>   8 7
B=>   5 4 3 2
C=>   6 1

A=>   8 7 2
B=>   5 4 3
C=>   6 1

A=>   8 7 2 1
B=>   5 4 3
C=>   6

A=>   8 7 2 1
B=>   5 4
C=>   6 3

A=>   8 7 2
B=>   5 4 1
C=>   6 3

A=>   8 7
B=>   5 4 1
C=>   6 3 2

A=>   8 7
B=>   5 4
C=>   6 3 2 1

A=>   8 7 4
B=>   5
C=>   6 3 2 1

A=>   8 7 4 1
B=>   5
C=>   6 3 2

A=>   8 7 4 1
B=>   5 2
C=>   6 3

A=>   8 7 4
B=>   5 2 1
C=>   6 3

A=>   8 7 4 3
B=>   5 2 1
C=>   6

A=>   8 7 4 3
B=>   5 2
C=>   6 1

*/
