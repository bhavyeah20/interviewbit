#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"

using namespace std;

int numSetBits(unsigned int A) {
	// Do not write main() function.
	// Do not read input, instead use the arguments to the function.
	// Do not print the output, instead return values as specified
	// Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details


	int n = 0;
	int cnt = 0;
	for (int i = 0; i < 32; i++) {
		if (A & (1 << i))
			cnt++;

	}

	return cnt;

}


int main() {

	bitset<32> bs(5);
	bool a;
	unsigned long long b;
	cout << sizeof(b);

}

