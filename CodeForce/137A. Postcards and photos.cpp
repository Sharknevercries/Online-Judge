/* 1240735	 Feb 28, 2012 11:38:43 AM	Shark	 137A - Postcards and photos	 GNU C++	Accepted	 30 ms	 1300 KB */
#include<stdio.h>
int main(){
	char str[1000];
	while(scanf("%s",str)==1){
		int count,step;
		step=1,count=1;
		for(int i=1;str[i]!='\0';)
			if(str[i]==str[i-1]){
				count++;
				if(count==5){
					if(str[i+1]!='\0')
						step++,count=1;
					i++;
				}
				if(str[i]=='\0')
					break;
				else
					i++;
			}
			else
				step++,count=1,i++;
		printf("%d\n",step);
	}
	return 0;
}
/*

Polycarpus has postcards and photos hung in a row on the wall. He decided to put them away to the closet and hang on the wall a famous painter's picture. Polycarpus does it like that: he goes from the left to the right and removes the objects consecutively. As Polycarpus doesn't want any mix-ups to happen, he will not carry in his hands objects of two different types. In other words, Polycarpus can't carry both postcards and photos simultaneously. Sometimes he goes to the closet and puts the objects there, thus leaving his hands free. Polycarpus must put all the postcards and photos to the closet. He cannot skip objects. What minimum number of times he should visit the closet if he cannot carry more than 5 items?

Input

The only line of the input data contains a non-empty string consisting of letters "С" and "P" whose length does not exceed 100 characters. If the i-th character in the string is the letter "С", that means that the i-th object (the numbering goes from the left to the right) on Polycarpus' wall is a postcard. And if the i-th character is the letter "P", than the i-th object on the wall is a photo.

Output

Print the only number — the minimum number of times Polycarpus has to visit the closet.

input

CPCPCPC
CCCCCCPPPPPP
CCCCCCPPCPPPPPPPPPP
CCCCCCCCCC

output

7
4
6
2

Note

In the first sample Polycarpus needs to take one item to the closet 7 times.

In the second sample Polycarpus can first take 3 postcards to the closet; then 3 more. He can take the 6 photos that are left in the similar way, going to the closet twice.

In the third sample Polycarpus can visit the closet twice, both times carrying 3 postcards. Then he can take there 2 photos at once, then one postcard and finally, he can carry the last 10 photos if he visits the closet twice.

In the fourth sample Polycarpus can visit the closet twice and take there all 10 postcards (5 items during each go).

*/