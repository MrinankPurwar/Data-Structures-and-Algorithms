Nearest Smallest Element to LEFT // or Right:

Input:
arr[]: 1,2,4,3
 
Output:
-1 1 2 2 

CODE:

// uses stack

vector<int> NSL (int arr[], int n) {
	stack<int> s;
	vector<int> v;
	for(int i=0; i<n; i++){
		if(s.size()==0)
			v.push_back(-1);
		else if(s.size()>0 && s.top()<=arr[i])
		{
			v.push _back(s.top());
		}
		else if(s.size()>0 && s.top()>arr[i])
		{
			while(s.size()!=0 && s.top<=arr[i])
				s.pop();		
			if(s.size()==0)
				v.push_back(-1);
			else
				v.push_back(s.top());
		}
		s.push(arr[i]);
	}
	return v;
}

For Smallest element to right:

vector<int> NSL (int arr[], int n) {
	stack<int> s;
	vector<int> v;
	for(int i=n-1; i>=0; i--){
		if(s.size()==0)
			v.push _back(-1);
		else if(s.size()>0 && s.top()<=arr[i])
		{
			v.push_back(s.top());
		}
		else if(s.size()>0 && s.top()>arr[i])
		{
			while(s.size()!=0 && s.top<=arr[i])
				s.pop();		
			if(s.size()==0)
				v.push_back(-1);
			else
				v.push_back(s.top());
		}
		s.push(arr[i]);
	}
	reverse(v.begin(), v.end());
	return v;
}