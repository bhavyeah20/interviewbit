#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"

using namespace std;

string solve(string A) {

	int n = A.size();
	int i = n - 1;

	string ans = "";
	string word = "";

	int j = 0;

	while (j < n && A[j] == '1')
		j++;

	cout << "j " << j << endl;

	while (i >= 0) {

		while (i >= 0 && A[i] == '1') {
			i--;
		}

		while (i >= 0 && A[i] != '1') {
			word.push_back(A[i]);
			i--;
		}

		reverse(word.begin(), word.end());
		ans += word;
		cout << "i" << i << endl;
		if (i != j - 1 && i != -1)
			ans.push_back('1');

		word = "";
	}

	return ans;
}

int main() {

	string s = "1111111fwbpudnbrozzifml1osdt1ulc1jsx1kxorifrhubk1ouhsuhf1sswz1qfho1dqmy1sn1myq1igjgip1iwfcqq11111111111111111";
	cout << solve(s);


}

