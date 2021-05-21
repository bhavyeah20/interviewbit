#include <bits/stdc++.h>
using namespace std;



vector<int>  grayCode(int n) {
	// Do not write main() function.
	// Do not read input, instead use the arguments to the function.
	// Do not print the output, instead return values as specified
	// Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	vector<string> v({"0", "1"});


	vector<string> v2;

	n -= 2;


	while (n--) {
		for (int i = 0; i < v.size(); i++) {
			v2.push_back("0" + v[i]);
		}
		for (int i = 0; i < v.size(); i++) {
			v2.push_back("1" + v[v.size() - 1 - i]);
		}

		v = v2;
		v2.clear();
	}


	vector<int> ans;
	for (string s : v) {
		ans.push_back(stoi(s));
	}

	return ans;

}

int main()
{
	vector<int> v1({1, 2, 3});
	vector<int> v2({1, 2, 3});

	if (v1 == v2) {
		cout << "hello";
	}
}
