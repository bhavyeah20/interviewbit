#include<bits/stdc++.h>

using namespace std;
class Solution {
public:

	void print(	queue<pair<int, pair<int, int>> > &q) {
		while (!q.empty()) {
			pair<int, pair<int, int>> f = q.front();
			cout << f.first << " " << f.second.first << " " << f.second.second << endl;
			q.pop();
		}
	}
	int jump(vector<int>& A) {
		int n = A.size();
		queue<pair<int, pair<int, int>> > q;
		pair<int, pair<int, int>> ans;
		// min jumps,idx,jumps from A[i]
		q.push({0, {0, A[0]}});

		for (int i = 1; i < n; i++) {
			print(q);
			pair<int, pair<int, int>> f = q.front();
			while (!q.empty() && f.second.first + f.second.second < i) {
				q.pop();
				if (!q.empty())
					f = q.front();
			}
			if (q.empty())
				return -1;

			ans = {f.first + 1, {i, A[i]}};
			q.push(ans);

		}

		return ans.first;
	}

};

int main() {
	vector<int> v({2, 3, 1, 1, 4});
	Solution s;
	cout << s.jump(v);

}
