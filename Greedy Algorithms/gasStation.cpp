int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B) {
	int totalGas = 0, totalCost = 0, currGas = 0, currCost = 0;
	int start = 0;

	for(int i = 0; i < A.size(); i++){
		totalGas += A[i];
		totalCost += B[i];

		currGas += A[i];
		currCost += B[i];

		if(currGas - currCost < 0){
			start = i+1;
			currGas = 0;
			currCost = 0;
		}
	}

	if(totalCost > totalGas)
		return -1;

	return start;

}
