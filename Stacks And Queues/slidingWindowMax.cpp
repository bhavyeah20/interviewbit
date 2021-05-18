// O(n) deque/ doubly LL

vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {

	deque<int> q;

	vector<int> ans;
	int n = A.size();
	for (int i = 0; i < n; i++) {
		while (!q.empty() && q.front() < i - B + 1)
			q.pop_front();

		while (!q.empty() && A[q.back()] < A[i])
			q.pop_back();

		q.push_back(i);
		if (i >= B - 1) {
			ans.push_back(A[q.front()]);
		}
	}

	return ans;
}

// O(NlogK) heap, priority_queue

vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
	vector<int> ans;
	priority_queue<int> q;
	unordered_map<int, int> mp;
	int N = A.size();
	if (B > N)
		B = N;

	int i = 0;
	for (i; i < B; i++) {
		mp[A[i]]++;
		if (mp[A[i]] == 1)
			q.push(A[i]);
	}

	ans.push_back(q.top());

	for (i; i < N; i++) {
		mp[A[i - B]]--;
		mp[A[i]]++;

		while (!q.empty() && !mp[q.top()])
			q.pop();

		if (mp[A[i]] == 1)
			q.push(A[i]);

		ans.push_back(q.top());
	}

	return ans;


}
