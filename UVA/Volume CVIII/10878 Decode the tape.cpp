/* 10878 Decode the tape Accepted C++ 0.016 2011-01-31 03:30:50 */
#include<stdio.h>
#include<string.h>
int main(){		
	char str[12];
	char head_tail[12]={"___________"};
	char result[10000];
	int index;
	bool start;
	start=false;
	while(gets(str)){
		if(strcmp(str,head_tail)==0){
			if(!start)
				index=0;
			if(start){
				result[index]='\0';
				printf("%s",result);}
			start=!start;			
			continue;}
		int i,j,sum;
		for(i=1,j=128,sum=0;i<11;i++){
			if(str[i]=='o')
				sum+=j;
			if(str[i]!='.')
				j/=2;}
		result[index++]=(char)sum;
	}
}
/*

你的老闆剛找到一卷舊式電腦的帶子。帶子上面有許多小洞，這些小洞可能含有某些有用的訊息。你必須要找出帶子上面有什麼樣的訊息。

Input

輸入包含一卷帶子。

Output

輸出帶子上的訊息。請參考 Sample Input及Sample Output，你應該可以找出小洞及輸出字元的關係。

Sample Input
___________
| o   .  o|
|  o  .   |
| ooo .  o|
| ooo .o o|
| oo o.  o|
| oo  . oo|
| oo o. oo|
|  o  .   |
| oo  . o |
| ooo . o |
| oo o.ooo|
| ooo .ooo|
| oo o.oo |
|  o  .   |
| oo  .oo |
| oo o.ooo|
| oooo.   |
|  o  .   |
| oo o. o |
| ooo .o o|
| oo o.o o|
| ooo .   |
| ooo . oo|
|  o  .   |
| oo o.ooo|
| ooo .oo |
| oo  .o o|
| ooo . o |
|  o  .   |
| ooo .o  |
| oo o.   |
| oo  .o o|
|  o  .   |
| oo o.o  |
| oo  .  o|
| oooo. o |
| oooo.  o|
|  o  .   |
| oo  .o  |
| oo o.ooo|
| oo  .ooo|
|  o o.oo |
|    o. o |
___________

Sample Output 

A quick brown fox jumps over the lazy dog.
 
*/