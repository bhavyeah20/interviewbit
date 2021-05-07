#include<bits/stdc++.h>

using namespace std;
string multiply(string s1, string s2) {
	int n = s1.size();
	int m = s2.size();
	string ans(m + n, '0');

	for (int i = n - 1; i >= 0; i--) {
		for (int j = m - 1; j >= 0 ; j--) {
			int num = ((s1[i] - '0') * (s2[j] - '0')) + (ans[i + j + 1] - '0');
			ans[i + j + 1] = (num % 10) + '0';
			ans[i + j] += (num / 10);
		}
	}

	for (int i = 0; i < m + n; i++) {
		if (ans[i] != '0')
			return ans.substr(i);
	}

	return "0";

}


int main() {


	cout << '0' + 1;
}
