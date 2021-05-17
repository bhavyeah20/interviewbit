#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define lld long long int

int braces(string A) {
	stack<char> s;
	for (char x : A) {
		if (x != ')')
			s.push(x);

		else {
			int cnt = 0;

			while (!s.empty() && s.top() != '(') {
				cout << s.top() << endl;
				s.pop(), cnt++;
			}
			s.pop();



			if (cnt <= 1)
				return 1;
		}
	}


	return 0;
}


int main () {

	cout << braces("((a+b)*(c+d))");


}
