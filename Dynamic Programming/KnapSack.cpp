This File contains Knapsack Code and How a recrsive code can be converted into Dynamic Programming

Recursive Function for Knapsack:

int KnapSack(int wt[], int val[], int W, int n) {
	if(n==0 || W==0) //If Wieght is zero or number of items are zero then we return zero
		return 0;
	else{
		if(wt[n-1]<=W) { // If given weight is less than the maximum weight we either select the weight 
					or reject it, in either case we select maximum.
			return max(val[n-1]+Knapsack(wt, val, W-wt[n-1], n-1), Knapsack(wt, val, W, n-1));	
		}
		else{ // If wt[n-1]>W we simpily reject it
			Knapsack(wt, val, W, n-1);
		}
	}
}

Memoize Code or Bottom Up Approach for knapsack:

Firstly Initialize a 2d matrix
int t[n+1][W+1];
memset(t,-1, sizeof(t));

//There are very Minor changes for converting Recursive to Memoize Code

int KnapSack(int wt[], int val[], int W, int n) {
	if(n==0 || W==0) 
		return 0;
	if(t[n][w]!=-1)
		return t[n][w];
	if(wt[n-1]<=W) { 
		return t[n][w] = max(val[n-1]+Knapsack(wt, val, W-wt[n-1], n-1), Knapsack(wt, val, W, n-1));	
	}
	else{
		t[n][w] = Knapsack(wt, val, W, n-1);
	}
}

Top Down Approach Or Dynamic Programming:

//There are very Minor changes for converting Memoize Code to Top Down Approach

int KnapSack(int wt[], int val[], int W, int n) {
	int t[n+1][W+1];
	for(int i=0; i<=n; i++) {
		for(int j=0; j<=W; j++) { 
			if(n==0 || W==0) 
				t[i][j] = 0;
			if(wt[i-1]<=j) { 
				t[i][j] = max(val[n-1]+t[i-1][j-wt[i-1]], t[i-1][j]);	
			}
			else{
				t[i][j] = t[i-1][j];
			}
		}
	}
	return t[n][w];
}	