Area under Histogram:

Input:
arr[]: 6,2,4,5,4,1,6

Output:
Max Area: 12

CODE:

This Technique uses concept of NSL/ NSR

int MaxArea(int arr[], int n){
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
		s.push(arr[i], i);
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
		s.push(arr[i], i);
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