int Solution::majorityElement(const vector<int> &A) {
	int majority = A[0];
	int cnt = 0;

	for(auto it: A){
		if(it == majority)
			cnt++;

		else
			cnt--;

		if(cnt < 0){
			cnt = 1;
			majority = it;
		}
	}

	return majority;


}
