Sort an array of 0s, 1s and 2s 
Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.


Example 1:

Input: 
N = 5
arr[]= {0 2 1 2 0}
Output:
0 0 1 2 2
Explanation:
0s 1s and 2s are segregated 
into ascending order.
Example 2:

Input: 
N = 3
arr[] = {0 1 0}
Output:
0 0 1
Explanation:
0s 1s and 2s are segregated 
into ascending order.

Your Task:
You don't need to read input or print anything. Your task is to complete the function sort012() that takes an array arr and N as input parameters and sorts the array in-place.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

void sort012(int a[], int n)
{
    int c1=0, c2=0, c3=0;
    for(int i=0; i<n; i++) {
        if(a[i]==0)
            c1++;
        else if(a[i]==1)
            c2++;
        else 
            c3++;
    }
    for(int i=0; i<c1; i++) {
        a[i]=0;
    }
    for(int i=c1; i<c1+c2; i++) {
        a[i]=1;
    }
    for(int i=c1+c2; i<c1+c2+c3; i++) {
        a[i]=2;
    }
}

// { Driver Code Starts.

int main() {

    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);
        int arr[n];
        for(int i=0;i<n;i++){
            scanf("%d", &arr[i]);
        }

        sort012(arr, n);

        for (int i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }
    return 0;
}
  // } Driver Code Ends