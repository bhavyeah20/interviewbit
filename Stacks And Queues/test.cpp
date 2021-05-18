#include "bits/stdc++.h"
using namespace std;


vector<int> slidingMaximum(const vector<int> &A, int B) {
	vector<int> ans;
	priority_queue<int> q;
	unordered_map<int, int> mp; //val->cnt;
	int N = A.size();
	if (B > N)
		B = N;

	int i = 0;
	for (i; i < B; i++) {
		mp[A[i]]++;
		if (mp[A[i]] <= 1)
			q.push(A[i]);


		cout << A[i] << " ";
	}

	cout << " max is " << q.top() << endl;

	ans.push_back(q.top());

	for (i; i < N; i++) {

		cout << "remove " << A[i - B];
		cout << " add " << A[i];

		mp[A[i - B]]--;

		if (!mp[q.top()])
			q.pop();

		mp[A[i]]++;
		if (mp[A[i]] <= 1)
			q.push(A[i]);

		ans.push_back(q.top());

		cout << " max is " << q.top() << endl;
	}

	return ans;


}

int main() {
	vector<int> test({251, 286, 420, 491, 506, 34, 716, 829, 615, 53, 807, 837, 750, 650, 181, 140, 543, 944, 210, 113, 551, 379, 818, 817, 227, 525, 257, 735, 932, 172, 410, 935, 351, 347, 521, 168, 482, 885, 612, 352});
	int B = 9;

	vector<int> ans = slidingMaximum(test, B);
}
