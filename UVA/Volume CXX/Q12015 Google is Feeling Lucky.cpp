/* 8923488 12015 Google is Feeling Lucky Accepted C++ 0.012 2011-06-06 08:37:05 */
#include<stdio.h>
int main(){
	int t;
	int i;
	scanf("%d",&t);	
	for(i=1;i<=t;i++){
		int j;
		char website[10][100];
		int m[10];
		int highest;
		for(j=0;j<10;j++)
			scanf("%s%d",website[j],&m[j]);
		for(j=highest=0;j<10;j++)
			if(m[j]>highest)
				highest=m[j];
		printf("Case #%d:\n",i); 
		for(j=0;j<10;j++)
			if(m[j]==highest)
				printf("%s\n",website[j]);
	}
	return 0;
}
/*

Google is one of the most famous Internet search engines which hosts and develops a number of Internet-based services and products. On its search engine website, an interesting button `I'm feeling lucky' attracts our eyes. This feature could allow the user skip the search result page and goes directly to the first ranked page. Amazing! It saves a lot of time.
 
The question is, when one types some keywords and presses `I'm feeling lucky' button, which web page will appear? Google does a lot and comes up with excellent approaches to deal with it. In this simplified problem, let us just consider that Google assigns every web page an integer-valued relevance. The most related page will be chosen. If there is a tie, all the pages with the highest relevance are possible to be chosen.
 
Your task is simple, given 10 web pages and their relevance. Just pick out all the possible candidates which will be served to the user when `I'm feeling lucky'.
 
Input 

The input contains multiple test cases. The number of test cases T is in the first line of the input file.
 For each test case, there are 10 lines, describing the web page and the relevance. Each line contains a character string without any blank characters denoting the URL of this web page and an integer Vi denoting the relevance of this web page. The length of the URL is between 1 and 100 inclusively. ( 1Vi100)
 
Output  

For each test case, output several lines which are the URLs of the web pages which are possible to be chosen. The order of the URLs is the same as the input. Please look at the sample output for further information of output format.
 
Sample Input  

2
www.youtube.com 1
www.google.com 2
www.google.com.hk 3
www.alibaba.com 10
www.taobao.com 5
www.bad.com 10
www.good.com 7
www.fudan.edu.cn 8
www.university.edu.cn 9
acm.university.edu.cn 10
www.youtube.com 1
www.google.com 2
www.google.com.hk 3
www.alibaba.com 11
www.taobao.com 5
www.bad.com 10
www.good.com 7
www.fudan.edu.cn 8
acm.university.edu.cn 9
acm.university.edu.cn 10

 Sample Output  

Case #1:
www.alibaba.com
www.bad.com
acm.university.edu.cn
Case #2:
www.alibaba.com

--------------------------------------------------------------------------------

 */