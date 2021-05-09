unsigned int Solution::reverse(unsigned int A) {
	unsigned int ans = 0;
	for (int i = 0; i < 32 && A; i++) {
		ans |= (A & 1) << (31 - i);

		A >>= 1;
	}
	return ans;
}


