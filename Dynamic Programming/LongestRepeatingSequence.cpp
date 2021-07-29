Longest Common Subsequence:

INPUT:
x: abcdaf

Output:
1

Dynamic Approach for LRS:

Code:
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int LRS(string x, int n) {
	int t[n+1][n+1];
	for(int i=0; i<=n; i++) {
		for(int j=0; j<=n; j++) { 
            		if(i==0 || j==0)
                		t[i][j]=0;
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) { 
			if(x[i-1] == x[j-1] && i!=j) { 
				t[i][j] = 1+t[i-1][j-1];
			}
			else{
				t[i][j] = max(t[i-1][j], t[i][j-1]);
			}
		}
	}
	return t[n][n];
}	
int main()
{
    string s1 = "acdbecff";
    int z = LRS(s1,8);
    cout<<z;
    return 0;
}


//MINE EASY WAY
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int LRS(string x, int n) {
    unordered_map<int, int> mp;
    int count =0;
	for(int i = 0; i<x.length(); i++){
	    mp[x[i]]++;
	}
	for(int i = 0; i<x.length(); i++){
	    if(mp[x[i]]==-1){
	        continue;
	    }
	    else if(mp[x[i]]%2==0){
	        count++;
	    }
	}
	return count/2;
}	
int main()
{
    string s1 = "AABEBCDD";
    int z = LRS(s1,8);
    cout<<z;
    return 0;
}