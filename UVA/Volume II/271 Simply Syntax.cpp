/* 9012513 271 Simply Syntax Accepted C++ 0.008 2011-07-03 11:59:18 */
#include<stdio.h>
#define NOT 0
#define N 1
#define CDEI 2
#define qz 3
int check1(char c){
	switch(c){
	case 'N':	return N;
	case 'E':	return CDEI;
	case 'D':	return CDEI;
	case 'C':	return CDEI;
	case 'I':	return CDEI;
	case 'p':	return qz;
	case 'q':	return qz;
	case 'r':	return qz;
	case 's':	return qz;
	case 't':	return qz;
	case 'u':	return qz;
	case 'v':	return qz;
	case 'w':	return qz;
	case 'x':	return qz;
	case 'y':	return qz;
	case 'z':	return qz;
	default:	return NOT;
	}
}
int check2(char str[],int *index){
	if(str[*index]=='\0')
		return false;
	int temp=check1(str[(*index)++]);
	if(temp==N) // N
		if(check2(str,index))
			return true;
		else
			return false;
	else if(temp==CDEI) // CDEI
		if(check2(str,index))
			if(check2(str,index))
				return true;
			else
				return false;
		else
			return false;
	else 
		return true; // q~z

}
int main(){
	char str[1000];
	while(gets(str)){
		bool YES=true;
		int index=0;
		int i;
		for(i=0;str[i]!='\0';i++)
			if(!check1(str[i])){
				YES=false;
				break;
			}
		if(YES&&(!check2(str,&index)||str[index]!='\0'))
			YES=false;
		if(YES)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
/*

In the land of Hedonia the official language is Hedonian. A Hedonian professor had noticed that many of her students still did not master the syntax of Hedonian well. Tired of correcting the many syntactical mistakes, she decided to challenge the students and asked them to write a program that could check the syntactical correctness of any sentence they wrote. Similar to the nature of Hedonians, the syntax of Hedonian is also pleasantly simple. Here are the rules:
 
0. The only characters in the language are the characters p through z and N, C, D, E, and I.
 
1. Every character from p through z is a correct sentence. 

2. If s is a correct sentence, then so is Ns. 

3. If s and t are correct sentences, then so are Cst, Dst, Est and Ist. 

4. Rules 0. to 3. are the only rules to determine the syntactical correctness of a sentence.
 
You are asked to write a program that checks if sentences satisfy the syntax rules given in Rule 0. - Rule 4.
 
Input
 
The input consists of a number of sentences consisting only of characters p through z and N, C, D, E, and I. Each sentence is ended by a new-line character. The collection of sentences is terminated by the end-of-file character. If necessary, you may assume that each sentence has at most 256 characters and at least 1 character.
 
Output
 
The output consists of the answers YES for each well-formed sentence and NO for each not-well-formed sentence. The answers are given in the same order as the sentences. Each answer is followed by a new-line character, and the list of answers is followed by an end-of-file character.
 
Sample Input
 
Cp
Isz
NIsz
Cqpq 

Sample Output 

NO
YES
YES
NO 

 */