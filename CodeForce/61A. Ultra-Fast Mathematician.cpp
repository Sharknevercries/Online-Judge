/* 1205663	 Feb 20, 2012 5:01:39 PM	Shark	 61A - Ultra-Fast Mathematician	 GNU C++	Accepted	 30 ms	 1300 KB */
#include<stdio.h>
int main(){
	char str1[1000],str2[1000];
	while(scanf("%s%s",str1,str2)==2){
		char ans[1000];
		int i;
		for(i=0;str1[i]!='\0';i++)
			if(str1[i]==str2[i])
				ans[i]='0';
			else
				ans[i]='1';
		ans[i]='\0';
		printf("%s\n",ans);
	}
	return 0;
}
/*

Shapur was an extremely gifted student. He was great at everything including Combinatorics, Algebra, Number Theory, Geometry, Calculus, etc. He was not only smart but extraordinarily fast! He could manage to sum 1018 numbers in a single second.

One day in 230 AD Shapur was trying to find out if any one can possibly do calculations faster than him. As a result he made a very great contest and asked every one to come and take part.

In his contest he gave the contestants many different pairs of numbers. Each number is made from digits 0 or 1. The contestants should write a new number corresponding to the given pair of numbers. The rule is simple: The i-th digit of the answer is 1 if and only if the i-th digit of the two given numbers differ. In the other case the i-th digit of the answer is 0.

Shapur made many numbers and first tried his own speed. He saw that he can perform these operations on numbers of length ¡Û (length of a number is number of digits in it) in a glance! He always gives correct answers so he expects the contestants to give correct answers, too. He is a good fellow so he won't give anyone very big numbers and he always gives one person numbers of same length.

Now you are going to take part in Shapur's contest. See if you are faster and more accurate.

Input

There are two lines in each input. Each of them contains a single number. It is guaranteed that the numbers are made from 0 and 1 only and that their length is same. The numbers may start with 0. The length of each number doesn't exceed 100.

Output

Write one line ¡X the corresponding answer. Do not omit the leading 0s.

input

1010100
0100101
000
111
1110
1010
01110
01100

output

1110001
111
0100
00010

*/