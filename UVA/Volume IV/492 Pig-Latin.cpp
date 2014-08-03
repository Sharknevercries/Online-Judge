/* 492 Pig-Latin Accepted C++ 0.044 2011-02-17 11:04:43 */
#include<stdio.h>
#include<ctype.h>
int aeiou(char c){ // 判斷是否為 a e i o u
	if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U')
		return true;
	else
		return false;
}
int main(){
	char c;
	bool YES=false;
	bool new_word=true;
	char temp;
	while(c=getchar()){ // 此題測資極大，無法使用gets()來讀資料，會RE。同時注意為一個"字"的條件
		if(c==-1) break;
		int i,j;
		bool eof=false;
		if(new_word)
			if(isalpha(c)){
				if(aeiou(c)){
					YES=true;					
					printf("%c",c);}
				else{
					YES=false;
					temp=c;}
				new_word=false;}
			else
				printf("%c",c);
		else{
			if(isalpha(c))
				printf("%c",c);
			else{
				new_word=true;
				if(YES)
					printf("ay%c",c);
				else
					printf("%cay%c",temp,c);}}
	}
	return 0;
}