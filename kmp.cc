#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

//Knuth Morris Pratt Algorithm Implementation to find pattern

void computeLPSArray(string pat, int M, int *lps);

void KMPSearch(string pat, string txt) {
	int M = pat.length();
	int N = txt.length();
	int lps[M];
	computeLPSArray(pat, M, lps);
	int i = 0;
	int j = 0;
	while (i < N) {
		if (pat[j] == txt[i]) {
			j++; i++;
		}
		if (j == M) {
			printf("Found pattern at index %d \n", i-j);
			j = lps[j-1];
		}
		else if (i < N && pat[j] != txt[i]) {
			if (j != 0)
				j = lps[j-1];
			else
				i++;
		}
	}
}

void computeLPSArray(string pat, int M, int *lps) {
	int len = 0;
	lps[0] = 0;
	int i = 1;
	while (i < M) {
		if (pat[i] == pat[len]) {
			len++;
			lps[i] = len;
			i++;
		}
		else {
			if (len != 0) {
				len = lps[len-1];
			}
			else {
				lps[i] = 0;
				i++;
			}
		}
	}
}

int main() {
	string txt = "AABAACAADAABAABA";
	string pat = "AABA";
	KMPSearch(pat, txt);
	return 0;
}