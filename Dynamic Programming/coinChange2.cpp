Coin Change problem: Min no. of coins

Input:
coin[]: 1,2,3
sum = 5

Output: 2
No of ways is = 5 using 3 coins 
Explanation: 
No of coin      To make coins = SUM
    2		2+3 ;
    3		1+2+2; 
    3		1+1+3; 
    4		1+1+1+2; 
    5		1+1+1+1+1
			

Code:
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int coinChange2(int coin[], int sum, int n) {
	int t[n+1][sum+1];
	for(int i=0; i<=sum; i++)
	{
	    t[0][i] = INT_MAX-1; // Since it would take infinite coins to make sum I when there are no coins present
	}
	for(int i=1; i<=n; i++)
	{
	    t[i][0] = 0; //sum=0, we need zero coin
	}
	for(int j=1; j<=sum; j++)
	{	
		if(j % coin[0] == 0)
			t[1][j] = j/coin[0]; 
		else
			t[1][j] = INT_MAX-1;
	}	
	for(int i=2; i<=n; i++) {
		for(int j=1; j<=sum; j++) { 
			if(coin[i-1]<=j) { 
				t[i][j] = min(1+t[i][j-coin[i-1]], t[i-1][j]);	
			}
			else{
				t[i][j] = t[i-1][j];
			}
		}
	}
	return t[n][sum];
}	
int main()
{
    int coin[]= {1,2,3};
    int z = coinChange2(coin,82,3);
    cout<<z;
    return 0;
}