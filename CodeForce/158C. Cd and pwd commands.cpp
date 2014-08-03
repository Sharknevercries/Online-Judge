/* 1290882	 Mar 5, 2012 5:57:18 PM	Shark	 158C - Cd and pwd commands	 GNU C++	Accepted	 30 ms	 1500 KB */
#include<stdio.h>
#include<string.h>
char name[500][301]; // 宣告到500才過...
int ptr;
void print(){
	putchar('/');
	for(int i=0;i<ptr;i++)
		printf("%s/",name[i]);
	putchar('\n');
}
void clear(){
	ptr=0;
}
void push(char str[]){
	strcpy(name[ptr++],str);
}
void back(){
	if(ptr-1>=0)
		ptr--;
}
int main(){
	int n;
	while(scanf("%d",&n)==1){
		(void)	getchar();
		ptr=0;

		char str[10001];
		for(int i=0;i<n;i++){
			int index=3,j;
			gets(str);
			if(strncmp(str,"pwd",3)==0)
				print();
			else if(str[index]=='/'){
				clear();
				index++;
			}
			for( ;str[index]!='\0';){
				char temp[10000];
				for(j=0;str[index]!='/'&&str[index]!='\0';)
					temp[j++]=str[index++];
				temp[j]='\0';
				if(strcmp(temp,"..")==0)
					back();
				else
					push(temp);
				if(str[index]=='/')
					index++;
			}
		}
	}
	return 0;
}
/*

Vasya is writing an operating system shell, and it should have commands for working with directories. To begin with, he decided to go with just two commands: cd (change the current directory) and pwd (display the current directory).

Directories in Vasya's operating system form a traditional hierarchical tree structure. There is a single root directory, denoted by the slash character "/". Every other directory has a name — a non-empty string consisting of lowercase Latin letters. Each directory (except for the root) has a parent directory — the one that contains the given directory. It is denoted as "..".

The command cd takes a single parameter, which is a path in the file system. The command changes the current directory to the directory specified by the path. The path consists of the names of directories separated by slashes. The name of the directory can be "..", which means a step up to the parent directory. «..» can be used in any place of the path, maybe several times. If the path begins with a slash, it is considered to be an absolute path, that is, the directory changes to the specified one, starting from the root. If the parameter begins with a directory name (or ".."), it is considered to be a relative path, that is, the directory changes to the specified directory, starting from the current one.

The command pwd should display the absolute path to the current directory. This path must not contain "..".

Initially, the current directory is the root. All directories mentioned explicitly or passed indirectly within any command cd are considered to exist. It is guaranteed that there is no attempt of transition to the parent directory of the root directory.

Input

The first line of the input data contains the single integer n (1 ≤ n ≤ 50) — the number of commands.

Then follow n lines, each contains one command. Each of these lines contains either command pwd, or command cd, followed by a space-separated non-empty parameter.

The command parameter cd only contains lower case Latin letters, slashes and dots, two slashes cannot go consecutively, dots occur only as the name of a parent pseudo-directory. The command parameter cd does not end with a slash, except when it is the only symbol that points to the root directory. The command parameter has a length from 1 to 200 characters, inclusive.

Directories in the file system can have the same names.

Output

For each command pwd you should print the full absolute path of the given directory, ending with a slash. It should start with a slash and contain the list of slash-separated directories in the order of being nested from the root to the current folder. It should contain no dots.

input

7
pwd
cd /home/vasya
pwd
cd ..
pwd
cd vasya/../petya
pwd
4
cd /a/b
pwd
cd ../a/b
pwd

output

/
/home/vasya/
/home/
/home/petya/
/a/b/
/a/a/b/

*/