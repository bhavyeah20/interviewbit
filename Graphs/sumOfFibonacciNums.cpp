int Solution::fibsum(int A) {
	if(A == 0)
		return 0;
	int f1 = 1, f2 = 1, num = 1;
	while(f1 + f2 <= A){
		num = f1 + f2;
		f1 = f2;
		f2 = num;
	}

	return 1 + fibsum(A-num);
}
