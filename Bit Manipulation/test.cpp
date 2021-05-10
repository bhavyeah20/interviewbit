#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"

using namespace std;
vector<int> ans;

int val(int len, int num) {
	int ans = num << (len >> 1), mul = 1 << (len >> 1);
	if (len & 1)
		num >>= 1;
	//cout << num << ' ';
	while (num) {
		mul >>= 1;
		ans += (num & 1) * mul;
		//cout << ans << ' ';
		num >>= 1;
	}
	// while(ans){
	//     cout << (ans & 1);
	//     ans >>= 1;
	// }
	// cout << '\n';
	return ans;
}
int call = 0;
void preprocess() {
	if (call)
		return;
	call = 1;
	ans.push_back(0);
	ans.push_back(1);
	int f = 1, max_n = 2e4 + 1, l = 2;
	for (int i = 1; i < max_n; i ++) {
		//val(l,f);
		ans.push_back(val(l, f));
		//cout << ans.back() << '\n';
		if ((f & (f + 1)) == 0) {
			l ++;
			f = (1 << ((l - 1) >> 1));
		} else
			f ++;
	}
}

int Solution::solve(int A) {
	preprocess();
	return ans[A];
}


int solve(int A) {
	return generateP(A);
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	return solve(20000);

}

