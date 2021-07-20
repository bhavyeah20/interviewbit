int Solution::solve(vector<vector<int> > &A) {
	vector<pair<int,int>> v;
	for(auto it: A){
		v.push_back({it[0],1});
		v.push_back({it[1],-1});

	}
	sort(v.begin(), v.end());
	int ans = 0, curr = 0;
	for(auto it: v){
		curr += it.second;
		ans = max(curr,ans);
	}
	return ans;
}
