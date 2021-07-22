Rod Cutting Problem:

// This is a similar approach to unbounded knapsack

Input:
Rod_len = 8
length[]: 1,2,3,4,5,6,7,8
price[]:  1,5,8,9,10,17,17,20


Output: Maximum profit one can make with rod is 22

Top Down Approach Or Dynamic Programming:

int RodCut(int length[], int price[], int L, int n) {
	int t[n+1][L+1];
	for(int i=0; i<=n; i++)
	{
	    t[0][i] = 0;
	    t[i][0] = 0;
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=L; j++) { 
			if(length[i-1]<=j) { 
				t[i][j] = max(price[i-1]+t[i-1][j-length[i-1]], t[i-1][j]);	
			}
			else{
				t[i][j] = t[i-1][j];
			}
		}
	}
	return t[n][L];
}	

int main()
{
    int Rod_len = 8;
    int length[] = {1,2,3,4,5,6,7,8};
    int price[] = {1,5,8,9,10,17,23,23};
    int z = RodCut(length, price, 8, 8);
    cout<<z;
    return 0;
}