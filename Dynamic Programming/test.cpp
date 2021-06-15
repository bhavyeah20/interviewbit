#include<bits/stdc++.h>

using namespace std;

unordered_map<string, int> mp;

bool partition(string A, int i, int j) {
	if (i == A.size())
		return true;

	for (int k = i; k < A.size(); k++) {
		if (mp.find(A.substr(i, k - i + 1)) != mp.end() && partition(A, k + 1, j)) {
			return true;
		}
	}

	return false;

}

int Solution::wordBreak(string A, vector<string> &B) {
	mp.clear();

	for (string b : B)
		mp[b]++;

	return partition(A, 0, A.size() - 1);
}

int main() {
	vector<vector<int> > M({
		{ -1, -2}, { -3, -4}

	});

	cout << maximumSumRectangle(2, 2, M);
}
