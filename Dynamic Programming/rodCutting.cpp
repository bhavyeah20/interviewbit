int calcCost(int x, vector<int> v, int end) {
	int prevNum = 0;
	int nextNum = end;
	for (int num : v) {
		if (num < x && num > prevNum)
			prevNum = num;

		if (num > x && num < nextNum)
			nextNum = num;

	}

	return nextNum - prevNum;
}

void nextCut(vector<int> comb, vector<int> &B, int currCost, int &cost, vector<int> &ans, int A) {
	if (comb.size() == B.size()) {
		if (currCost < cost)
			ans = comb, cost = currCost;
		return ;
	}

	for (int i = 0; i < B.size(); i++) {
		if (find(comb.begin(), comb.end(), B[i]) == comb.end()) {
			currCost += calcCost(B[i], comb, A);
			comb.push_back(B[i]);
			nextCut(comb, B, currCost, cost, ans, A);

			comb.pop_back();
			currCost -= calcCost(B[i], comb, A);

		}
	}
}


vector<int> Solution::rodCut(int A, vector<int> &B) {
	vector<int> ans;
	int cost = INT_MAX;
	nextCut(vector<int> (), B, 0, cost, ans, A);
	return ans;
}
