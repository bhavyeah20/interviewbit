#include<bits/stdc++.h>

using namespace std;

vector<int> equal(vector<int> &A) {
	int n = A.size();
	vector<int> ans;
	unordered_map<int, vector<pair<int, int>> > mp; // sum->i,j

	for (int c = 0; c < n; c++) {
		for (int d = c + 1; d < n; d++) {
			int sum = A[c] + A[d];

			cout << "c is " << c << " d is " << d << endl;

			if (mp.find(sum) != mp.end()) {
				for (auto ele : mp[sum]) {
					int a = ele.first, b = ele.second;


					cout << a << " " << b << " " << c << " " << d << endl;

					if (a < b && c < d && a < c && b != d && b != c) {
						vector<int> temp = {a, b, c, d};
						if (ans.empty() || temp < ans)
							ans = temp;
					}
				}
			}

			mp[sum].push_back({c, d});
		}
	}

	return ans;
}

int main() {
	vector<int> v({1, 3, 2, 2});

	vector<int> ans =  equal(v);
	for (int x : ans)
		cout << x << " ";
	cout << endl;
}

