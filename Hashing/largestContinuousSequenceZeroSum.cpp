vector<int> Solution::lszero(vector<int> &A) {
	unordered_map<int, int> mp; //sum -> first last occurence

	int sum = 0;
	int len = INT_MIN;
	int start = -1;
	mp[0] = -1;
	for (int i = 0; i < A.size(); i++) {
		sum += A[i];
		if (mp.find(sum) != mp.end()) {

			if (i - mp[sum] > len) {
				start = mp[sum] + 1;
				len = i - mp[sum];
			}
		}
		else
			mp[sum] = i;
	}

	vector<int> ans;
	if (len == INT_MIN)
		return ans;

	for (int i = start; i < start + len; i++)
		ans.push_back(A[i]);

	return ans;




}
