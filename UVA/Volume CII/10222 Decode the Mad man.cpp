/* 10222 Decode the Mad man Accepted C++ 0.016 2011-01-07 12:34:49  */
#include<stdio.h>
char change(char a){
	switch(a){		
		case '2':
			return '`';
		case '3':
			return '1';
		case '4':
			return '2';
		case '5':
			return '3';
		case '6':
			return '4';
		case '7':
			return '5';
		case '8':
			return '6';
		case '9':
			return '7';
		case '0':
			return '8';
		case '-':
			return '9';
		case '=':
			return '0';
		case '\\':
			return '-';		
		case 'e':
			return 'q';
		case 'r':
			return 'w';
		case 't':
			return 'e';
		case 'y':
			return 'r';
		case 'u':
			return 't';
		case 'i':
			return 'y';
		case 'o':
			return 'u';
		case 'p':
			return 'i';
		case '[':
			return 'o';
		case ']':
			return 'p';		
		case 'd':
			return 'a';
		case 'f':
			return 's';
		case 'g':
			return 'd';
		case 'h':
			return 'f';
		case 'j':
			return 'g';
		case 'k':
			return 'h';
		case 'L':
			return 'j';
		case ';':
			return 'k';
		case '\'':
			return 'l';
		case 'c':
			return 'z';
		case 'v':
			return 'x';
		case 'b':
			return 'c';
		case 'n':
			return 'v';
		case 'm':
			return 'b';
		case ',':
			return 'n';
		case '.':
			return 'm';
		case '/':
			return ',';
		case ' ':
			return ' ';

	}
}
int main(){
	char str[10000];
	while(gets(str)){
		char c;
		for(int i=0;str[i]!='\0';i++){
			c=change(str[i]);
			putchar(c);
		}
		putchar('\n');
	}
	return 0;
}
