/* 8909359 10800 Not That Kind of Graph Accepted C++ 0.008 2011-06-01 12:39:39 */
#include<stdio.h>
#include<string.h>
#define RISE 1
#define FALL 2
#define CONSTANT 3
int main(){
	freopen("input.txt","r",stdin);
	freopen("ouput.txt","w",stdout);
	int n;
	while(scanf("%d",&n)==1){
		(void) getchar();
		int t;
		for(t=1;t<=n;t++){
			int i,j;
			int length,high,low,pre,depth;
			int m[60]={0};
			char table[60][60]={0};
			char str[60];
			gets(str);
			high=low=0;
			length=strlen(str)+3;			
			if(str[0]=='R')
				pre=RISE;
			else if(str[0]=='F')
				pre=FALL;
			else
				pre=CONSTANT;
			// 算出高度(行數)
			for(i=1;str[i]!='\0';i++)
				if(str[i]=='R'){
					if(pre==RISE){
						m[i]=m[i-1]+1;
						if(m[i]>high)
							high=m[i];
					}
					else
						m[i]=m[i-1];
					pre=RISE;					
				}
				else if(str[i]=='F'){
					if(pre==FALL||pre==CONSTANT){
						m[i]=m[i-1]-1;
						if(low>m[i])
							low=m[i];
					}
					else
						m[i]=m[i-1];
					pre=FALL;					
				}
				else{
					if(pre==FALL||pre==CONSTANT)
						m[i]=m[i-1];
					else{
						m[i]=m[i-1]+1;
						if(m[i]>high)
							high=m[i];
					}
					pre=CONSTANT;
				}
			for(i=0;str[i]!='\0';i++)
				m[i]-=low;
			depth=high-low+1;
			// 初始化
			for(i=0;i<depth;i++)
				for(j=0;j<length-1;j++){						
					if(j==0)
						table[i][j]='|';
					else
						table[i][j]=' ';
				}
			// 排股票走跌
			for(i=0,j=2;str[i]!='\0';i++,j++)
				if(str[i]=='R')
					table[m[i]][j]='/';
				else if(str[i]=='C')
					table[m[i]][j]='_';
				else
					table[m[i]][j]='\\';
			// 省略尾部的多餘空白
			for(i=depth-1;i>=0;i--){
				for(j=length-1;table[i][j]!='/'&&table[i][j]!='_'&&table[i][j]!='\\'&&j>=0;j--)
					table[i][j]='\0';
				if(j==length-1)
					table[i][j+1]='\0';
			}
			// 輸出結果
			printf("Case #%d:\n",t);
			for(i=depth-1;i>=0;i--)
				printf("%s\n",table[i]);
			putchar('+');
			for(i=0;i<length-1;i++)
				putchar('-');
			putchar('\n');
			putchar('\n');
		}
	}
	return 0;
}
/*

"You know, it's all very sweet, stealing from the rich, selling to the poor..." 

Jose Molina, "Firefly." 

Your task is to graph the price of a stock over time. In one unit of time, the stock can either Rise, Fall or stay Constant. The stock's price will be given to you as a string of R's, F's and C's. You need to graph it using the characters '/' (slash), '\' (backslash) and '_' (underscore).
 
Input

The first line of input gives the number of cases, N. N test cases follow. Each one contains a string of at least 1 and at most 50 upper case characters (R, F or C).
 
Output

For each test case, output the line "Case #x:", where x is the number of the test case. Then print the graph, as shown in the sample output, including the x- and y-axes. The x-axis should be one character longer than the graph, and there should be one space between the y-axis and the start of the graph. There should be no trailing spaces on any line. Do not print unnecessary lines. The x-axis should always appear directly below the graph. Finally, print an empty line after each test case.
 
Sample Input 

1
RCRFCRFFCCRRC

Sample Output

Case #1:
|             _
|  _/\_/\    /
| /      \__/
+---------------

--------------------------------------------------------------------------------
Problemsetter: Igor Naverniouk 

*/