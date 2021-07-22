Shortest Common Supersequence:

INPUT:
x: abcdaf
y: abcf

Output:
6

Dynamic Approach for LCS:

Code:
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int SCS(string x, int n, string y, int m) {
	int t[n+1][m+1];
	for(int i=0; i<=n; i++) {
		for(int j=0; j<=m; j++) { 
            if(i==0 || j==0)
                t[i][j]=0;
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) { 
			if(x[i-1] == y[j-1]) { 
				t[i][j] = 1+t[i-1][j-1];
			}
			else{
				t[i][j] = max(t[i-1][j], t[i][j-1]);
			}
		}
	}
	return (n+m - t[n][m]);
}	
int main()
{
    string s1 = "abcdef";
    string s2 = "anfuebcd";
    int z = SCS(s1,6,s2,8);
    cout<<z;
    return 0;
}