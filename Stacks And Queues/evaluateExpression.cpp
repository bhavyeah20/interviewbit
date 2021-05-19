bool isOp(string x) {
	if (x == "+" || x == "-" || x == "*" || x == "/")
		return 1;

	return 0;
}

int perform(int op1, string x, int op2) {

	if (x == "+")
		return op1 + op2;
	if (x == "-")
		return op1 - op2;
	if (x == "*")
		return op1 * op2;
	if (x == "/")
		return op1 / op2;

}


int Solution::evalRPN(vector<string> &A) {
	stack<int> s;

	int n = A.size();

	for (int i = 0; i < n; i++) {
		if (isOp(A[i])) {
			int op2 = s.top();
			s.pop();
			int op1 = s.top();
			s.pop();
			s.push(perform(op1, A[i], op2));
		} else {
			s.push(stoi(A[i]));
		}
	}

	return s.top();
}
