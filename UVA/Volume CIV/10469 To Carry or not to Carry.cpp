/* 8871869 10469 To Carry or not to Carry Accepted C++ 0.008 2011-05-22 02:42:43 */
#include<stdio.h>
int main(){
	int a,b;
	while(scanf("%d%d",&a,&b)==2){
		unsigned long long i,j,s;
		char m[3][32];
		for(i=0;i<32;i++)
			m[0][i]=m[1][i]=m[2][i]='0';
		for(i=0;a>0;i++,a>>=1)
			if((a&1)==1)
				m[0][i]='1';
		for(i=0;b>0;i++,b>>=1)
			if((b&1)==1)
				m[1][i]='1';
		for(i=0;i<32;i++)
			m[2][i]=(m[0][i]==m[1][i]?'0':'1');
		for(i=s=0,j=1;i<32;i++,j<<=1)
			if(m[2][i]=='1')
				s+=j;
		printf("%llu\n",s);
	}
	return 0;
}
/*

--------------------------------------------------------------------------------

6+9=15 seems okay. But how come 4+6=2? 

You see, Mofiz had worked hard throughout his digital logic course, but when he was asked to implement a 32 bit adder for the laboratory exam, he did some mistake in the design part. After tracing the design for half an hour, he found his flaw!! He was doing bitwise addition but his carry bit always had zero output. Thus,
 
 4 = 00000000 00000000 00000000 00000100
+6 = 00000000 00000000 00000000 00000110
----------------------------------------
 2 = 00000000 00000000 00000000 00000010

 Its a good thing that he finally found his mistake, but it was too late. Considering his effort throughout the course, the instructor gave him one more chance. Mofiz has to write an efficient program that would take 2 unsigned 32 bit decimal numbers as input, and produce an unsigned 32 bit decimal number as the output adding in the same was as his circuit does.
 
 Input

 In each line of input there will be a pair of integer separated by a single space. Input ends at EOF.
 
 Output

 For each line of input, output one line -- the value after adding the two numbers in the "Mofiz way".
 
 Sample Input

4 6
6 9
 
Sample Output

 2
15
 
--------------------------------------------------------------------------------

Problem setter: Monirul Hasan (Tomal), CSE Dept, Southeast University, Bangladesh
 
"that you used cut and paste there is really nerdy." -- goose
 "really? i use cut and paste all the time." -- trip

 Collected from: nerd quotes 

*/