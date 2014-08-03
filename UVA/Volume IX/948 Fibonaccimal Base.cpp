/* 8923600 948 Fibonaccimal Base Accepted C++ 0.012 2011-06-06 09:30:47 */
#include<stdio.h>
static unsigned long long fib[45];
static int index;
void make_fib(){
	fib[0]=1;
	fib[1]=2;
	index=2;
	for(;index<45;index++)
		fib[index]=fib[index-1]+fib[index-2];
}
int main(){	
	make_fib();
	int s;
	scanf("%d",&s);
	for(int t=1;t<=s;t++){
		unsigned long long n;
		scanf("%llu",&n);
		int i,p;
		char str[100];
		unsigned long long temp;
		temp=n;
		for(i=0;fib[i]<=temp;i++);
		i-=1;
		for(p=0;i>=0;i--)
			if(temp>=fib[i]){
				temp-=fib[i];
				str[p++]='1';
			}
			else
				str[p++]='0';
		str[p]='\0';
		printf("%llu = %s (fib)\n",n,str); 
	}
	return 0;
}
/*

 The well known Fibonacci sequence is obtained by starting with 0 and 1 and then adding the two last numbers to get the next one. For example the third number in the sequence is 1 (1=1+0), the forth is 2 (2=1+1), the fifth is 3 (3=2+1) and so on.
  
The sequence appears on many things in our life, in nature, and has a great significance. Among other things, do you know that all positive integer numbers can be represented as a sum of numbers in the Fibonacci sequence? More than that, all positive integers can be represented as a sum of a set of Fibonacci numbers, that is, numbers from the sequence, without repetition. For example: 13 can be the sum of the sets {13}, {5,8} or {2,3,8} and 17 is represented by {1,3,13} or {1,3,5,8}. Since all numbers have this property (do you want to try to prove this for yourself?) this set could be a nice way to use as a "base" to represent the number. But, as we have seen, some numbers have more than one set whose sum is the number. How can we solve that? Simple! If we add the constraint that the sets cannot have two consecutive Fibonacci numbers, than we have a unique representation for each number! This restriction is because the sum of any two consecutive Fibonacci numbers is just the following Fibonacci number.
 
Now that we know all this we can prepare a nice way to represent any positive integer. We will use a binary sequence (just zeros and ones) to do that. For example, 17 = 1 + 3 + 13 (remember that no two consecutive Fibonacci numbers can be used). Let's write a zero for each Fibonacci number that is not used and one for each one that is used, starting at the right. Then, 17 = 100101. See figure 2 for a detailed explanation. In this representation we should not have zeros at the left, this is, we should only write starting with the first one. In order for you to understand better, note that in this scheme, not using two consecutive Fibonacci numbers means that the binary sequence will not have two consecutive ones. When we use this representation for a number we say that we are using the Fibonaccimal base, and we write it like 17 = 100101 (fib).

The Problem

 Given a set of numbers in decimal base, your task is to write them in the Fibonaccimal base.
 
Input

 The first line of input contains a single number N, representing the quantity of numbers that follow ( 1 ≤ N ≤ 500).
 
Than follow exactly N lines, each one containing a single positive integer smaller than 100 000 000. These numbers can come in any order.
 
Output

 You should output a single line for each of the N integers in the input, with the format "DEC_BASE = FIB_BASE (fib)". DEC_BASE is the original number in decimal base and FIB_BASE is its representation in Fibonaccimal base. See the sample output for an example.
 
Example Input

10
1
2
3
4
5
6
7
8
9
10

 Example Output

 1 = 1 (fib)
2 = 10 (fib)
3 = 100 (fib)
4 = 101 (fib)
5 = 1000 (fib)
6 = 1001 (fib)
7 = 1010 (fib)
8 = 10000 (fib)
9 = 10001 (fib)
10 = 10010 (fib)

--------------------------------------------------------------------------------
 
2005 Programming Contest of Porto University
 Round 2, 28th of September of 2005  
 (Author: Pedro Ribeiro - DCC/FCUP)

--------------------------------------------------------------------------------

*/