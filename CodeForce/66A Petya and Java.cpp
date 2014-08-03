/* 4848245	 Oct 23, 2013 8:39:42 AM	Shark	 66A - Petya and Java	 GNU C++	Accepted	 30 ms	 100 KB */
#include<stdio.h>
#include<string.h>
char limitByte[2][50]={"128","127"};
char limitShort[2][50]={"32768","32767"};
char limitInt[2][50]={"2147483648","2147483647"};
char limitLong[2][50]={"9223372036854775808","9223372036854775807"};
bool cmp(char A[],char B[][50],int sign){
	int len1=strlen(A);
	int len2=strlen(B[sign]);

	if( len1>len2 )
		return false;
	if( len2>len1 )
		return true;
	for(int i=0;A[i]!='\0';i++){
		if( A[i]>B[sign][i] )
			return false;
		if( A[i]<B[sign][i] )
			return true;
	}
	return true;

}
int judge(char S[]){
	int fix= S[0]=='-' ? 1 : 0;
	if( cmp(S+fix,limitByte,!fix) )
		return 0;
	else if( cmp(S+fix,limitShort,!fix) )
		return 1;
	else if( cmp(S+fix,limitInt,!fix) )
		return 2;
	else if( cmp(S+fix,limitLong,!fix) )
		return 3;
	else
		return 4;
}
int main(){
	char str[100000];
	while( scanf("%s",str)==1 ){
		int result=judge(str);
		if( result==0 )
			puts("byte");
		else if( result==1 )
			puts("short");
		else if( result==2 )
			puts("int");
		else if( result==3 )
			puts("long");
		else
			puts("BigInteger");
	}
	return 0;
}
/*

A. Petya and Java
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Little Petya has recently started attending a programming club. Naturally he is facing the problem of choosing a programming language. After long considerations he realized that Java is the best choice. The main argument in favor of choosing Java was that it has a very large integer data type, called BigInteger.

But having attended several classes of the club, Petya realized that not all tasks require using the BigInteger type. It turned out that in some tasks it is much easier to use small data types. That's why a question arises: "Which integer type to use if one wants to store a positive integer n?"

Petya knows only 5 integer types:

1) byte occupies 1 byte and allows you to store numbers from  - 128 to 127

2) short occupies 2 bytes and allows you to store numbers from  - 32768 to 32767

3) int occupies 4 bytes and allows you to store numbers from  - 2147483648 to 2147483647

4) long occupies 8 bytes and allows you to store numbers from  - 9223372036854775808 to 9223372036854775807

5) BigInteger can store any integer number, but at that it is not a primitive type, and operations with it are much slower.

For all the types given above the boundary values are included in the value range.

From this list, Petya wants to choose the smallest type that can store a positive integer n. Since BigInteger works much slower, Peter regards it last. Help him.

Input
The first line contains a positive number n. It consists of no more than 100 digits and doesn't contain any leading zeros. The number n can't be represented as an empty string.

Please, do not use %lld specificator to read or write 64-bit integers in C++. It is preffered to use cout (also you may use %I64d).

Output
Print the first type from the list "byte, short, int, long, BigInteger", that can store the natural number n, in accordance with the data given above.

Sample test(s)
input
127
output
byte
input
130
output
short
input
123456789101112131415161718192021222324
output
BigInteger

*/