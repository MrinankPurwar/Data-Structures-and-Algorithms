Minimum Insertion Deletion to covert X into Y

INPUT:
x: heap
y: pea

Output:
1 Insertion 2 Deletion

Dynamic Approach for This question:

Code:
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int MID(string x, int n, string y, int m) {
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
	vector<int> v;
	int insertion = 0, deletion = 0;
	insertion = y.length() - t[n][m];
	deletion = x.length() - t[n][m];
	v.push_back(insertion);
	v.push_back(deletion);
	return v;

}
int main()
{
    string s1 = "abcdef";
    string s2 = "anfuebcd";
    int z = MID(s1,6,s2,8);
    cout<<z;
    return 0;
}