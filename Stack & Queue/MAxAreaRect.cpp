Maximum Area Rectangle:

Input:
arr[]: {{0,1,1,1}, {1,1,1,1}, {1,1,1,1}, {0,1,1,1}}

Output:
Max Area: 12

CODE:

#include <iostream>
#include<vector>
#include <bits/stdc++.h>

using namespace std;

int maxAreaH(int arr[], int n){
	stack<pair<int, int>> s;
	vector<int> left;
	for(int i=0; i<n; i++){
		if(s.size()==0)
			left.push_back(-1);
		else if(s.size()>0 && s.top().first<=arr[i])
		{
			left.push_back(s.top().second);
		}
		else if(s.size()>0 && s.top().first>arr[i])
		{
			while(s.size()!=0 && s.top().first<=arr[i])
				s.pop();		
			if(s.size()==0)
				left.push_back(-1);
			else
				left.push_back(s.top().second);
		}
		s.push({arr[i], i});
	}
	s.empty();
	vector<int> right;
	for(int i=0; i<n; i++){
		if(s.size()==0)
			right.push_back(-1);
		else if(s.size()>0 && s.top().first<=arr[i])
		{
			right.push_back(s.top().second);
		}
		else if(s.size()>0 && s.top().first>arr[i])
		{
			while(s.size()!=0 && s.top().first<=arr[i])
				s.pop();		
			if(s.size()==0)
				right.push_back(-1);
			else
				right.push_back(s.top().second);
		}
		s.push({arr[i], i});
	}
	reverse(right.begin(), right.end());

	vector<int> width;
	for(int i=0; i<n; i++){
		width[i] = right[i]-left[i]-1;
	}

	vector<int> Area;
	int maxA;
	for(int i=0; i<n; i++){
		Area[i] = arr[i]*width[i];
		maxA = max(maxA, Area[i]);
	}
	return maxA;
}

int maxAreaRect(int arr[50][50], int n, int m){
	int maxi=0;
	for(int i=1; i<n; i++){
		for(int j=1; j<m; j++){
			arr[i][j] += arr[i-1][j-1];
			cout<<arr[i][j];
		}
	}
	for(int i=0; i<n; i++){
		maxi = max(maxi, maxAreaH(arr[i], n));
		cout<<maxi;
	}
	return maxi;
}
int main()
{
    int arr[50][50] = {{0,1,1,1}, {1,1,1,1}, {1,1,1,1}, {0,1,1,1}};
    int z = maxAreaRect(arr,4,4);
    cout<<z;
    return 0;
}

