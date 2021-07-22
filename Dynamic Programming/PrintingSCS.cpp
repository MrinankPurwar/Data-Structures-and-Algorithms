Shortest Common Subsequence:

INPUT:
x: abcdaf
y: aebcf

Output:
aebcdaf

Dynamic Approach for SCS:

Code:
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string SCS(string x, int n, string y, int m) {
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
	int i = n, j = m;
	string v;
	while(i>0 && j>0){
		if(x[i-1]==y[j-1]){
			v.push_back(x[i-1]);
			i--;
			j--;
		}
		else{
			if(t[i-1][j]>t[i][j-1])
			{
				v.push_back(x[i-1]);
				i--;
			}
			else
			{	
				v.push_back(y[j-1]);
				j--;
			}
		}
	}
	while(i>0 || j>0){
		if(i>0)
		{	
			v.push_back(x[i-1]);
			i--;
		}
		if(j>0)
		{	
			v.push_back(y[j-1]);
			j--;
		}
	}
	reverse(v.begin(), v.end());
	return v;
}	
int main()
{
    string s1 = "abcf";
    string s2 = "abcf";
    string z = SCS(s1,6,s2,4);
    cout<<z;
    return 0;
}