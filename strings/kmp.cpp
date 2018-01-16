#include <bits/stdc++.h>
#define MAX_N 100010
using namespace std;

char T[MAX_N], P[MAX_N];
int b[MAX_N], n, m;

//optimized process
void kmpPreprocess() {
	int j=-1, i=0;
	for(i=0;i<m;i++){
		if(j>=0 && P[i]==P[j]) b[i]=b[j];
		else b[i]=j;
		while(j>=0 && P[i]!=P[j]) j=b[j];
		j++;
	}
}

void kmpSearch() {
	int i = 0, j = 0;
	while (i < n) {
		while (j >= 0 && T[i] != P[j]) j = b[j];
		i++; j++;
		if (j == m) {
			printf("P is found at index %d in T\n", i - j);
			j = b[j];
		}
	}
}

/* Find just the first match of the pattern in the text,
 * and return the position of the caracther after the match
 */
int kmpSearch() {
	int j=0, i;
	for(i=0;i<n;i++){
		while(j>=0 && T[i]!=P[j]) j=b[j];
		if(j+1==m){
			return i-j+1;
		}
		j++;
	}
	return -1;
}

int main(){
	strcpy(T,"heyhelloyou");
	strcpy(P,"hel");
	n=strlen(T);
	m=strlen(P);
	memset(b,0,sizeof b);
	kmpPreprocess();
	kmpSearch();
}