vector<int> Solution::dNums(vector<int> &A, int B) {
	unordered_map<int,int> mp;
	vector<int> ans;
	int cnt = 0;
	int n = A.size();
	if(B > n)
		return ans;

	for(int i = 0; i < n; i++){
		if(i >= B && mp[A[i-B]] == 1){
			cnt--;
		}

		if(i >= B)
			mp[A[i-B]]--;

		if(mp.find(A[i]) == mp.end() || mp[A[i]] == 0){
			cnt++;
		}
		mp[A[i]]++;

		if(i >= B-1){
			ans.push_back(cnt);
		}
	}

	return ans;
}
