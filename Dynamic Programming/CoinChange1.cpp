Coin Change problem: Max  no. of ways

Input:
coin[]: 1,2,3
sum = 5

Output:
No of ways is = 5 using 3 coins 
Explanation: 2+3 ; 1+2+2; 1+1+3; 1+1+1+2; 1+1+1+1+1
		

Code:
int coinChange(int coin[], int sum, int n) {
	int t[n+1][sum+1];
	for(int i=1; i<=sum; i++)
	{
	    t[0][i] = 0;
	}
	for(int i=0; i<=n; i++)
	{
	    t[i][0] = 1;
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=sum; j++) { 
			if(coin[i-1]<=j) { 
				t[i][j] = t[i][j-coin[i-1]] + t[i-1][j];	
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
    int z = coinChange(coin,5,3);
    cout<<z;
    return 0;
}