Longest Pallindromic Subsequence:

INPUT:
x: abcbaf

Output:
5

Dynamic Approach for LPS:

Code:
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int LPS(string x, int n) {
	int t[n+1][n+1];
	string y;
	for(int k=x.length()-1; k>=0; k--){
		y += x[k];
	}
	for(int i=0; i<=n; i++) {
		for(int j=0; j<=n; j++) { 
            if(i==0 || j==0)
                t[i][j]=0;
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) { 
			if(x[i-1] == y[j-1]) { 
				t[i][j] = 1+t[i-1][j-1];
			}
			else{
				t[i][j] = max(t[i-1][j], t[i][j-1]);
			}
		}
	}
	return t[n][m];
}	
int main()
{
    string s1 = "abcbaf";
    int z = LPS(s1,6);
    cout<<z;
    return 0;
}