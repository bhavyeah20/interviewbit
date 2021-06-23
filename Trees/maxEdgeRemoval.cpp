int subtreeSize(int &ans, map<int,vector<int>> &mp, int root){

	if(mp[root].empty())
		return 1;

	int currSz = 0;
	for(auto it: mp[root]){
		int sz = subtreeSize(ans,mp,it);
		if(sz && sz % 2 == 0){
			ans++;
		}
		currSz += sz;
	}

	return currSz + 1;
}



int Solution::solve(int A, vector<vector<int> > &B) {
	map<int,vector<int> > mp; //parent to children

	for(int i = 0; i < B.size(); i++){
		mp[B[i][0]].push_back(B[i][1]);
	}

	int ans = 0;
	int sz = subtreeSize(ans,mp,1);
	return ans;
}
