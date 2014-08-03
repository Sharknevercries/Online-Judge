/* 5349221	 Dec 4, 2013 8:40:01 PM	Shark	 145A - Lucky Conversion	 GNU C++	Accepted	 30 ms	 200 KB */
#include<stdio.h>
#define ABS(x) ( (x) >= 0 ? (x) : -(x) )
#define MIN(x,y) ( (x) >= (y) ? (y) : (x) )
int main(){
	char A[100001];
	char B[100001];
	while (scanf("%s%s", A, B) == 2){
		int count = 0;
		int _4, _7;
		_4 = _7 = 0;
		for (int i = 0; A[i] != '\0'; i++){
			if (A[i] != B[i]){
				count++;
				if (A[i] == '4')
					_4++;
				else
					_7++;
			}	
		}
		int ans = 0, min;
		min = MIN(_4, _7);
		ans += min;
		_4 -= min, _7 -= min;
		ans += _4 + _7;
		printf("%d\n", ans);
		
	}
	return 0;
}
/*

A. Lucky Conversion
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Petya loves lucky numbers very much. Everybody knows that lucky numbers are positive integers whose decimal record contains only the lucky digits 4 and 7. For example, numbers 47, 744, 4 are lucky and 5, 17, 467 are not.

Petya has two strings a and b of the same length n. The strings consist only of lucky digits. Petya can perform operations of two types:

replace any one digit from string a by its opposite (i.e., replace 4 by 7 and 7 by 4);
swap any pair of digits in string a.
Petya is interested in the minimum number of operations that are needed to make string a equal to string b. Help him with the task.

Input
The first and the second line contains strings a and b, correspondingly. Strings a and b have equal lengths and contain only lucky digits. The strings are not empty, their length does not exceed 105.

Output
Print on the single line the single number ¡X the minimum number of operations needed to convert string a into string b.

Sample test(s)
input
47
74
output
1
input
774
744
output
1
input
777
444
output
3
Note
In the first sample it is enough simply to swap the first and the second digit.

In the second sample we should replace the second digit with its opposite.

In the third number we should replace all three digits with their opposites.

*/