Pallindrome partitioning:

Input : str = “geek” 
Output : 2 
We need to make minimum 2 cuts, i.e., “g ee k”
Input : str = “aaaa” 
Output : 0 
The string is already a palindrome.

#include <bits/stdc++.h>
using namespace std;

CODE:
bool isPalindrome(string String, int i, int j)
{
    while(i < j)
    {
      if(String[i] != String[j])
        return false; 
      i++;
      j--;
    }
    return true;
}
int minPalPartion(string String, int i, int j)
{
    if( i >= j || isPalindrome(String, i, j) )
      return 0;
    int ans = INT_MAX, count;
    for(int k = i; k < j; k++)
    {
      count = minPalPartion(String, i, k) +
        minPalPartion(String, k + 1, j) + 1;
  
      ans = min(ans, count);
    }
    return ans;
}
 
// Driver code
int main() {
    string str = "ababbbabbababa";
    cout << "Min cuts needed for " <<
      "Palindrome Partitioning is " << 
      minPalPartion(str, 0, str.length() - 1) << endl;
    return 0;
}