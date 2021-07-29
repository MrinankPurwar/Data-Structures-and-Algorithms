MAtrix Chain multiplication:

Input: p[] = {10, 20, 30, 40, 30} 
Output: 30000 

CODE:
int MCM(int arr[], int i, int j)
{
	if(i>j)
		return 0;
	int mn = INT_MAX;
	for(int k=i; k<j; k++)
	{
		int temp = MCM(arr,i,k) + MCM(arr,k+1,j) + arr[i-1]*arr[k]*arr[j];
		if(temp<mn)
			mn = temp;		
	}
	return mn;
}
int main()
{
    int arr[] = { 1, 2, 3, 4, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    cout << "Minimum number of multiplications is "
         << MCM(arr, 1, n - 1);
}


Memoized Version for MCM:
int matrixChainMemoised(int* p, int i, int j)
{
    if (i == j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    dp[i][j] = INT_MAX;
    for (int k = i; k < j; k++)
    {
        dp[i][j] = min(
            dp[i][j], matrixChainMemoised(p, i, k)
                     + matrixChainMemoised(p, k + 1, j)
                       + p[i - 1] * p[k] * p[j]);
    }
    return dp[i][j];
}
int MatrixChainOrder(int* p, int n)
{
    int i = 1, j = n - 1;
    return matrixChainMemoised(p, i, j);
}
 
// Driver Code
int main()
{
    int arr[] = { 1, 2, 3, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);
    memset(dp, -1, sizeof dp);
 
    cout << "Minimum number of multiplications is "
         << MatrixChainOrder(arr, n);
}