/* 13065762	11786	Global Raining at Bididibus	Accepted	C++	0.075	2014-02-01 06:32:47 */
#include<cstdio>
#include<cstring>
int main(){
	int t;
	scanf("%d", &t);
	while (t--){
		char S[10001];
		scanf("%s", S);

		int len = strlen(S);
		int H[10010] = { 0 };
		bool done[10010] = { false };
		double ans = 0, tmp = 0;
		for (int i = 0; S[i] != '\0'; i++){
			if (S[i] == '/')
				H[i + 1] = H[i] + 1;
			else if (S[i] == '\\')
				H[i + 1] = H[i] - 1;
			else
				H[i + 1] = H[i];
		}
		int cur, next;
		for (cur = 1; cur <= len; cur++){
			if (H[cur] == H[cur - 1] - 1){ // down
				tmp = 0;
				for (next = cur; next <= len&&H[next] <= H[cur - 1]; next++){
					tmp += (H[cur - 1] - H[next - 1] + H[cur - 1] - H[next]) / 2.0; // (L+R)/2
					if (H[next] == H[cur - 1]) // found
						break;
				}
				if (next <= len)
					ans += tmp, cur = next;
			}
		}
		printf("%d\n", (int)ans);
	}
	return 0;
}
/*


A - Global Raining at Bididibus
Background

Bididibus is an ancient two-dimensional universe populated by the Bididibusians. Bididibusians have their own 2D water, 2D mountains, 1D television, and even an amazing new technology of 2D cinemas!

These days, some Bididibusian scholars are warning the public about the risks of global raining. Such climate catastrophe would fill with water all the valleys of the universe.

The Problem

Bididibus consists of blocks with uniform width and height. Bididibusian orography is described by a series of symbols, from left to right, indicating that the land rises one unit (represented by "/"), descends one unit (represented by "\"), or it is flat (represented by "_").

For example, we can have a 2D universe like this:

_
/ \
/   \__/\_
/\_   _/          \   _
/\/   \_/             \_/ \    /\
/                           \/\/
It goes without saying that native geographers are big fans of ASCII art. They also use a simplified representation, where each column (from left to right) is replaced by the symbol it contains. For example, the simplified representation of the previous universe would be:

//\//\_\_/_///_\\__/\_\\_/_\\/\//\
After the global rain, water would fill all the blocks of the valleys. If we represent water areas in blue, we would have the following:

bididibus.png

Observe that a block with "/" or "\" partially filled with water corresponds to 1/2 units of water. A block completely filled with water corresponds to 1 unit of water. For example, in the previous universe we have a total of 21 units of water.

Given a simplified representation of a universe, your task is to compute the units of water that we would have after the global rain.

The Input

The first line of the input contains an integer indicating the number of test cases.

For each test case, there is a line which can contain three possible symbols:   "/", "\", "_". There will be at most 10000 symbols in each line.

The Output

For each test case, the output should contain a single integer indicating the units of water of the corresponding case.

Sample Input

4
//\//\_\_/_///_\\__/\_\\_/_\\/\//\
////\\\\\\\\
\/
\\\\\\\\\\//////////
Sample Output

21
0
1
100
OMP'10
Facultad de Informatica
Universidad de Murcia (SPAIN)

*/