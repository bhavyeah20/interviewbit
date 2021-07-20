bool comp(vector<int> it1, vector<int> it2){
	return it1[1] < it2[1];
}

int Solution::solve(vector<vector<int> > &A) {		
	int n = A.size();
	sort(A.begin(), A.end(), comp);

	int ans = 1;

	int end = A[0][1];

	for(int i = 1; i < n; i++){
		if(A[i][0] > end){
			ans++;
			end = A[i][1];
		}
	}

	return ans;

}
