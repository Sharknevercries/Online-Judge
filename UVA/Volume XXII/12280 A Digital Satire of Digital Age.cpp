/* 13072851	12280	A Digital Satire of Digital Age	Accepted	C++	0.035	2014-02-02 16:58:11 */
#include<cstdio>
char str[8][20];
char ans[8][20];
int weight(char c){
	int code = (int)c;
	int W = 0;
	while (code > 0){
		if (code % 2 == 0)
			W += 250;
		else
			W += 500;
		code >>= 1;
	}
	return W;
}
void print(int fix, int state){
	for (int i = 0; i < 7; i++){
		for (int j = 0; j < 18; j++){
			ans[i][j] = '.';
		}
		ans[i][9] = ans[i][8] = '|';
		ans[i][18] = '\0';
	}
	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 8; j++){
			ans[i + state + fix][j] = str[i + state][j];
		}
	}
	for (int i = 0; i < 5; i++){
		for (int j = 10; j < 18; j++){
			ans[2 - state + i - fix][j] = str[2 - state + i][j];
		}
	}
	for (int i = 0; i < 7; i++)
		printf("%s\n", ans[i]);
}
int main(){
	int t, c = 1;
	scanf("%d", &t);
	while (t--){
		int state = 0;
		int L, R;
		for (int i = 0; i < 8; i++)
			scanf("%s", str[i]);
		if (str[0][3] == '/')	state = 0;
		if (str[1][3] == '/')	state = 1;
		if (str[2][3] == '/')	state = 2;
		L = R = 0;
		for (int i = 0; i < 7; i++){
			for (int j = 0; j < 8; j++){
				if (str[i][j] >= 'A'&&str[i][j] <= 'Z')
					L += weight(str[i][j]);
			}
		}
		for (int i = 0; i < 7; i++){
			for (int j = 10; j < 18; j++){
				if (str[i][j] >= 'A'&&str[i][j] <= 'Z')
					R += weight(str[i][j]);
			}
		}
		printf("Case %d:\n", c++);
		if ((L == R &&state == 1) || (L > R&&state == 2) || (R > L&&state == 0))
			puts("The figure is correct.");
		else{
			int curstate;
			if (R > L)	curstate = 0;
			if (L > R)	curstate = 2;
			if (L == R)	curstate = 1;
			print(curstate - state, state);
		}
	}
	return 0;
}
/*

The government of ``Moderdesh" is planning to enter the digital age and so people of different profession and business are proposing different ways to enter that age successfully. The hardware vendors are saying that we need to provide a laptop for each student, the mobile companies are saying that every children needs to have a mobile phone in his small hand and talk all night long, the multimedia experts are crying for Multimedia University and so on. But very few are crying for the overall improvement of Computer Science education. We do not understand that by being only the consumer of modern digital technologies we cannot enter the real digital age.

\epsfbox{p4854.eps}
Now as a protest, some local computer geeks are planning to digitize the local vegetable and grocery markets in a strange way. The local markets generally use weighing balances as shown in the figure-1 and they use conventional weight sets as shown in figure 2. The computer geeks want to introduce a new type of weight set, where each piece will have the shape of an upper case English alphabet, and strangely Figure 1: The weighing balance weighing a Figure 2: the weights of these pieces will papaya using letter shaped weights. Conventional weight set be related with their ASCII valuess. For example the ASCII value of `A' is 65, which is 10000012 in binary. For each `1' in binary representation a weight of 500 gms will be added and for each `0' in binary representation a weight of 250 gms will be added. So a piece with shape `A' actually weighs (250 * 5 + 2 * 500) gm = 2250 grams. Note that leading zeroes in binary representation are not considered. The geeks believe if others are correct about their ways to enter digital age, they are also correct about digitizing the local markets by introducing new weight sets related to ASCII characters.

Now in this problem you will be given (i) the picture of a weighing scale and the weight pieces that it contains in left pan and in the right pan (ii) You will also be informed which pan is heavier and which pan is lighter (Not necessarily correct). You will have to detect whether the given information is correct or not. If the given information is not correct you will have to rectify the picture and show it in the output.

Input

First line of the input file contains a positive integer T (T$ \le$6000) that denotes the number of test sets. The description of each set of input is given below:

Each set of input is given in a (7 * 18) grid. This grid actually contains the plain text description of a weighing scale. Each location of the grid is either a dot `.' (ASCII value 46) or a front slash `/' (ASCII Value 47) or a back slash `\' (ASCII value 92) or an under score `_' (ASCII value 95) or a pipe `|' (ASCII value 124) an upper case English Alphabet (ASCII value 65 to 90). The (7 * 18) grid is divided into two equal parts by two vertical lines formed with pipe character. The left part denotes the status of left pan and right part denotes the status of the right pan. The bottom of the pan is formed with 6 (six) under score characters and the ropes attached to the pans are formed with front slash and back slash. The weights on both pans are placed just above the row that denotes bottom of the pan and they are left justified. There can be maximum 6 weights on a single pan. There are three possible vertical positioning of the pans (i) Left pan is low and right pan is high (ii) Both pan is in the middle (iii) Left pan is high and right pan is low. If weight of both pan is same then they should be in state (ii), if the left pan is heavier then they should be in status (i) and so on. In the input the pans are always in position (i), (ii) or (iii) but that may not be the correct position according to the weights they contain.

A line containing 18 (eighteen) `-' (minus) signs follows each set of input.

Output

For each set of input produce two or eight line of output. First line should contain the serial of output. If the pans in the input figure are in correct position according to the weights they contain then in the second line print ``The figure is correct." (without the quotes). If the pans are not in correct position then print the weighing balance again in a (7 * 18) grid with the pans in the correct position. Look at the output for sample input for exact formatting.

Sample Input

4
........||.../\...
........||../..\..
.../\...||./....\.
../..\..||/G.....\
./....\.||\______/
/YQYFU.\||........
\______/||........
------------------
.../\...||........
../..\..||........
./....\.||.../\...
/WCGQG.\||../..\..
\______/||./....\.
........||/OYA...\
........||\______/
------------------
.../\...||........
../..\..||........
./....\.||.../\...
/A.....\||../..\..
\______/||./....\.
........||/A.....\
........||\______/
------------------
........||........
.../\...||.../\...
../..\..||../..\..
./....\.||./....\.
/NQ....\||/FG....\
\______/||\______/
........||........
------------------
Sample Output

Case 1:
The figure is correct.
Case 2:
........||.../\...
........||../..\..
.../\...||./....\.
../..\..||/OYA...\
./....\.||\______/
/WCGQG.\||........
\______/||........
Case 3:
........||........
.../\...||.../\...
../..\..||../..\..
./....\.||./....\.
/A.....\||/A.....\
\______/||\______/
........||........
Case 4:
The figure is correct.

*/