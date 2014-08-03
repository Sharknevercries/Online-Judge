/* 9025621 537 Artificial Intelligence? Accepted C++ 0.040 2011-07-07 11:11:35 */
#include<stdio.h>
#define m 0.001
#define M 1000000
#define K 1000
int main(){
	int n;
	scanf("%d",&n);
	for(int count=1;count<=n;count++){
		(void) getchar();
		char str[1000];		
		int temp,i;
		double I,V,P;
		bool I_,V_,P_;
		I_=V_=P_=false;
		I=V=P=0;
		gets(str);
		for(i=0;str[i]!='\0';i++)
			if((str[i]=='P'||str[i]=='U'||str[i]=='I')&&str[i+1]=='=')	
				if(str[i]=='P'){
					i+=2;
					P_=true;
					sscanf(str+i,"%lf",&P);
					for(;(str[i]>='0'&&str[i]<='9')||str[i]=='.';i++);
					if(str[i]=='m'||str[i]=='k'||str[i]=='M')
						if(str[i]=='m')
							P*=m;
						else if(str[i]=='k')
							P*=K;
						else
							P*=M;
				}
				else if(str[i]=='U'){
					i+=2;
					V_=true;
					sscanf(str+i,"%lf",&V);
					for(;(str[i]>='0'&&str[i]<='9')||str[i]=='.';i++);
					if(str[i]=='m'||str[i]=='k'||str[i]=='M')
						if(str[i]=='m')
							V*=m;
						else if(str[i]=='k')
							V*=K;
						else
							V*=M;
				}
				else{
					i+=2;
					I_=true;
					sscanf(str+i,"%lf",&I);
					for(;(str[i]>='0'&&str[i]<='9')||str[i]=='.';i++);
					if(str[i]=='m'||str[i]=='k'||str[i]=='M')
						if(str[i]=='m')
							I*=m;
						else if(str[i]=='k')
							I*=K;
						else
							I*=M;
				}
		printf("Problem #%d\n",count);
		if(I_&&V_)
			printf("P=%.2lfW\n",I*V);
		if(V_&&P_)
			printf("I=%.2lfA\n",P/V);
		if(P_&&I_)
			printf("U=%.2lfV\n",P/I);
		putchar('\n');
	}
	return 0;
}
/*

Physics teachers in high school often think that problems given as text are more demanding than pure computations. After all, the pupils have to read and understand the problem first!
 
So they don't state a problem like ``U=10V, I=5A, P=?" but rather like ``You have an electrical circuit that contains a battery with a voltage of U=10V and a light-bulb. There's an electrical current of I=5A through the bulb. Which power is generated in the bulb?".
 
However, half of the pupils just don't pay attention to the text anyway. They just extract from the text what is given: U=10V, I=5A. Then they think: ``Which formulae do I know? Ah yes, P=U*I. Therefore P=10V*5A=500W. Finished."
 
OK, this doesn't always work, so these pupils are usually not the top scorers in physics tests. But at least this simple algorithm is usually good enough to pass the class. (Sad but true.)
 
Today we will check if a computer can pass a high school physics test. We will concentrate on the P-U-I type problems first. That means, problems in which two of power, voltage and current are given and the third is wanted.
 
Your job is to write a program that reads such a text problem and solves it according to the simple algorithm given above.
 
Input  

The first line of the input file will contain the number of test cases. 
Each test case will consist of one line containing exactly two data fields and some additional arbitrary words. A data field will be of the form I=xA, U=xV or P=xW, where x is a real number.
 
Directly before the unit (A, V or W) one of the prefixes m (milli), k (kilo) and M (Mega) may also occur. To summarize it: Data fields adhere to the following grammar:
 
DataField ::= Concept '=' RealNumber [Prefix] Unit
Concept   ::= 'P' | 'U' | 'I'
Prefix    ::= 'm' | 'k' | 'M'
Unit      ::= 'W' | 'V' | 'A'

 Additional assertions: 

•The equal sign (`=') will never occur in an other context than within a data field.
 •There is no whitespace (tabs,blanks) inside a data field. 
•Either P and U, P and I, or U and I will be given. 

Output  

For each test case, print three lines: 

•a line saying ``Problem #k" where k is the number of the test case 
•a line giving the solution (voltage, power or current, dependent on what was given), written without a prefix and with two decimal places as shown in the sample output
 •a blank line 
 
Sample Input  

3
If the voltage is U=200V and the current is I=4.5A, which power is generated?
A light-bulb yields P=100W and the voltage is U=220V. Compute the current, please.
bla bla bla lightning strike I=2A bla bla bla P=2.5MW bla bla voltage?

 Sample Output  

Problem #1
P=900.00W

Problem #2
I=0.45A

Problem #3
U=1250000.00V


--------------------------------------------------------------------------------

Miguel A. Revilla 
1999-01-11 

*/