No of Subset for a given Differnce between subset Problem:
Input: 1,2,3,4,5,6,7
Sum: 10

Ouput: Yes, There are X subset with difference z 
//This is similar to knapsack Problem

Dynamic Approach:

Top Down Approach Or Dynamic Programming:

int SubsetDiff(int arr[], int n, int diff) {
	int sum = 0;
	for(int i=0; i<n; i++) {
		sum += arr[i];
	}
	int fsum = (sum+diff)/2;
	int t[n+1][fsum+1];
	for(int i=0; i<=n; i++) 
		t[i][0] = 1;
	for(int j=1; j<=fsum; j++) 		
    		t[0][j] = 0;
	
	for(int i=0; i<=n; i++) {
		for(int j=0; j<=fsum; j++) { 
			if(arr[i-1]<=j) { 
				t[i][j] = t[i-1][j-arr[i-1]] + t[i-1][j];	
			}
			else{
				t[i][j] = t[i-1][j];
			}
		}
	}
	return t[n][fsum];
}	
