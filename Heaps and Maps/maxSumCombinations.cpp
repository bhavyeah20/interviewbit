vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
	int n = A.size();
	set<pair<int,int>> s;
	vector<int> ans;
	priority_queue<vector<int>> pq;

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());


	pq.push({A[n-1]+B[n-1],n-1,n-1});
	s.insert({n-1,n-1});

	while(C--){
		int sum = pq.top()[0], i = pq.top()[1], j = pq.top()[2];
		pq.pop();
		ans.push_back(sum);
	
		if(i-1 >= 0 && !(s.count({i-1,j}))){
			pq.push({A[i-1]+B[j],i-1,j});
			s.insert({i-1,j});
		}

		if(j-1 >= 0 && !(s.count({i,j-1}))){
			pq.push({A[i]+B[j-1],i,j-1});
			s.insert({i,j-1});
		}

	}

	return ans;
}
