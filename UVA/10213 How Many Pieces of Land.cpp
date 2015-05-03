/* 15398656	10213	How Many Pieces of Land ?	Accepted	C++	0.049	2015-04-28 13:49:08 */
#include<bits\stdc++.h>
using namespace std;
const int MAX = 1e4;
const int LEN = 4;
struct BigInteger{
	int m[500];
	int len;
	BigInteger(){
		len = 1, memset(m, 0, sizeof(m));
	}
	BigInteger(const int &s){
		int c, d = s;
		len = 0;
		memset(m, 0, sizeof(m));
		while (d >= MAX){
			c = d - (d / MAX) * MAX;
			d /= MAX;
			m[len++] = c;
		}
		m[len++] = d;
	}
	BigInteger(const char *s){
		memset(m, 0, sizeof(m));
		int L = strlen(s);
		len = L / LEN + L % LEN != 0;
		for (int i = L - 1, ptr = 0; i >= 0; i -= LEN){
			int tmp = 0, k = i - LEN + 1;
			if (k < 0)	k = 0;
			for (int j = k; j <= i; j++)
				tmp = tmp * 10 + s[j] - '0';
			m[ptr++] = tmp;
		}
	}
	BigInteger(const BigInteger &T){
		len = T.len;
		memset(m, 0, sizeof(m));
		for (int i = 0; i < len; i++)
			m[i] = T.m[i];
	}
	BigInteger operator = (const BigInteger &T){
		len = T.len;
		memset(m, 0, sizeof(m));
		for (int i = 0; i < len; i++)
			m[i] = T.m[i];
		return *this;
	}
	friend istream& operator >> (istream &in, BigInteger &b){
		char ch[LEN * 100];
		int i = -1;
		in >> ch;
		int L = strlen(ch);
		int ptr = 0, sum;
		for (int i = L - 1; i >= 0;){
			sum = 0;
			for (int j = 0, t = 1; j < LEN && i >= 0; j++, i--, t *= 10)
				sum += (ch[i] - '0') * t;
			b.m[ptr++] = sum;
		}
		b.len = ptr++;
		return in;
	}
	friend ostream& operator << (ostream &out, BigInteger &b){
		printf("%d", b.m[b.len - 1]);
		for (int i = b.len - 2; i >= 0; i--)
			printf("%0.*d", LEN, b.m[i]);
		return out;
	}
	BigInteger operator + (const BigInteger &T){
		BigInteger res(*this);
		int L = max(T.len, len);
		for (int i = 0; i < L; i++){
			res.m[i] += T.m[i];
			if (res.m[i] >= MAX)
				res.m[i + 1]++, res.m[i] -= MAX;
		}
		res.len = res.m[L] != 0 ? L + 1 : L;
		return res;
	}
	BigInteger operator - (const BigInteger &T){
		bool minus;
		BigInteger t1, t2;
		if (*this > T)
			t1 = *this, t2 = T, minus = false;
		else
			t1 = T, t2 = *this, minus = true;
		int L = t1.len;
		for (int i = 0; i<L; i++){
			if (t1.m[i] < t2.m[i]){
				int j = i + 1;
				while (t1.m[j] == 0)
					j++;
				t1.m[j--]--;
				while (j > i)
					t1.m[j--] += MAX - 1;
				t1.m[i] += MAX - t2.m[i];
			}
			else
				t1.m[i] -= t2.m[i];
		}
		t1.len = L;
		while (t1.m[t1.len - 1] == 0 && t1.len > 1)
			t1.len--, L--;
		if (minus)
			t1.m[L - 1] = 0 - t1.m[L - 1];
		return t1;
	}
	BigInteger operator * (const BigInteger &T){
		BigInteger res;
		int i, j;
		int tmp, carry;
		for (i = 0; i < len; i++){
			carry = 0;
			for (j = 0; j < T.len; j++){
				tmp = m[i] * T.m[j] + res.m[i + j] + carry;
				if (tmp >= MAX){
					carry = tmp / MAX;
					tmp = tmp - tmp / MAX * MAX;
					res.m[i + j] = tmp;
				}
				else
					carry = 0, res.m[i + j] = tmp;
			}
			if (carry != 0)
				res.m[i + j] = carry;
		}
		res.len = i + j;
		while (res.m[res.len - 1] == 0 && res.len > 1)
			res.len--;
		return res;
	}
	BigInteger operator * (const int &T){
		return (*this) * BigInteger(T);
	}
	BigInteger operator / (const int &T){
		BigInteger res;
		for (int i = len - 1, down = 0; i >= 0; i--){
			res.m[i] = (m[i] + down * MAX) / T;
			down = m[i] + down * MAX - res.m[i] * T;
		}
		res.len = len;
		while (res.m[res.len - 1] == 0 && res.len > 1)
			res.len--;
		return res;
	}
	BigInteger operator % (const int &T){
		int res = 0;
		for (int i = len - 1; i >= 0; i--)
			res = ((res * MAX) % T + m[i]) % T;
		return res;
	}
	bool operator > (const BigInteger &T){
		if (len > T.len)
			return true;
		else if (len == T.len){
			int L = len - 1;
			while (m[L] == T.m[L] && L >= 0)
				L--;
			if (L >= 0 && m[L] > T.m[L])
				return true;
			else
				return false;
		}
		else
			return false;
	}
	bool operator > (const int &T){
		return *this > BigInteger(T);
	}
	void print(){
		printf("%d", m[len - 1]);
		for (int i = len - 2; i >= 0; i--)
			printf("%0.*d",LEN , m[i]);
		putchar('\n');
	}
};
int main(){
	int t;
	scanf("%d", &t);
	while (t--){
		int n;
		scanf("%d", &n);
		BigInteger res = BigInteger(n);
		res = res*res*res*res + res*res * 23 - res*res*res * 6 - res * 18 + 24;
		res = res / 24;
		res.print();
	}
	return 0;
}
/*

You are given an elliptical shaped land and you are asked to choose n arbitrary points on its boundary.
Then you connect all these points with one another with straight lines (that’s n ∗ (n−1)/2 connections
for n points). What is the maximum number of pieces of land you will get by choosing the points on
the boundary carefully?
Fig: When the value of n is 6
Input
The first line of the input file contains one integer S (0 < S < 3500), which indicates how many
sets of input are there. The next S lines contain S sets of input. Each input contains one integer N
(0 ≤ N < 2
31).
Output
For each set of input you should output in a single line the maximum number pieces of land possible
to get for the value of N.
Sample Input
4
1
2
3
4
Sample Output
1
2
4
8

*/