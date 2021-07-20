int Solution::mice(vector<int> &A, vector<int> &B) {

	//similar to policeman catch theives

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	int currMax = 0;

	for(int i = 0; i < A.size(); i++){
		currMax = max(currMax, abs(B[i]-A[i]));
	}

	return currMax;
}
