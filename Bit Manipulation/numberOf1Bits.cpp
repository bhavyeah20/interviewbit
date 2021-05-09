int numSetBits(unsigned int A) {

	int cnt = 0;
	for (int i = 0; i < 32; i++) {
		if (A & (1 << i))
			cnt++;

	}

	return cnt;

}

// or

int Solution::numSetBits(unsigned int A) {
	// Do not write main() function.
	// Do not read input, instead use the arguments to the function.
	// Do not print the output, instead return values as specified
	// Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	int cnt = 0;

	while (A) {
		A &= A - 1;
		cnt++;
	}

	return cnt;

}

// or

bitset<32> bs(A);
return bs.count();