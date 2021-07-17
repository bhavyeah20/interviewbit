int Solution::bulbs(vector<int> &A) {
	int cnt = 0;

	for(auto it: A){
		if((cnt & 1) == it)
			cnt++;
	}

	return cnt;
}
