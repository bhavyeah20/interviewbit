vector<int> Solution::solve(vector<int> &A, int B) {
	int n = A.size();
	vector<int> idx(n);

	for(int i = 0; i < n; i++){
		idx[A[i]-1] = i;
	}

	int i = 0, val = n;
	while(B && i < n){
		if(val > A[i]){
			B--;
			idx[A[i]-1] = idx[val-1];
			A[idx[val-1]] = A[i];
			A[i] = val;
		}
		val--;
		i++;
	}
	return A;
}

//or

vector<int> Solution::solve(vector<int> &A, int B) {
	int n = A.size();
	set<pair<int,int>, greater<pair<int,int>>> s; //val,idx

	for(int i = 0; i < n; i++){
		s.insert({A[i],i});
	}

	int i = 0;
	while(B && i < n){
		
		auto [val, idx] = *(s.begin());
		s.erase(s.begin());
		
		if(val > A[i]){
			B--;
			s.erase({A[i],i});
			swap(A[i], A[idx]);
			s.insert({A[idx],idx});	
		}

		i++;

	}

	return A;
}
