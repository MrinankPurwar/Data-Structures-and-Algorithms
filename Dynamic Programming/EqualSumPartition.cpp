EqualSum Partition Problem:
Input: 1,2,3,4,5,6,7

Ouput: Yes, There can be a equal sum partition

//This is similar to knapsack Problem

Dynamic Approach:

Top Down Approach Or Dynamic Programming:

int EqualSum(int arr[], int n) {
	int sum = 0;
	for(int i=0; i<n; i++)
		sum+=arr[i];
	if(sum%2!=0)
		return -1;
	else{
		sum = sum/2;
		int t[n+1][sum+1];
		for(int i=0; i<=n; i++) {
			for(int j=0; j<=sum; j++) { 
				if(j==0) 
					t[i][j] = True;
				if(i==0)
					t[i][j] = False;
				if(arr[i-1]<=j) { 
					t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];	
				}
				else{
					t[i][j] = t[i-1][j];
				}
			}
		}
		return t[n][sum];
	}
}	
