No of Subset for a given Sum Problem:
Input: 1,2,3,4,5,6,7
Sum: 10

Ouput: Yes, There is a subset present with 10 sum

//This is similar to knapsack Problem

Dynamic Approach:

Top Down Approach Or Dynamic Programming:

int SubsetSum(int arr[], int Sum, int n) {
	int t[n+1][Sum+1];
	for(int i=0; i<=n; i++) 
		t[i][0] = 1;
	for(int j=1; j<=fsum; j++) 		
    		t[0][j] = 0;
	
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=Sum; j++) { 
			if(arr[i-1]<=j) { 
				t[i][j] = t[i-1][j-arr[i-1]] + t[i-1][j];	
			}
			else{
				t[i][j] = t[i-1][j];
			}
		}
	}
	return t[n][Sum];
}	
