//Assume bst is valid
int Solution::solve(vector<int> &A) {
	int n = A.size();
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			if(A[j] > A[i]){
				while(j < n && A[j] > A[i]){
					j++;
				}

				if(j != n)
					return 0;
			}
		}
	}
	return 1;
}

//or

int Solution::solve(vector<int> &A) {
	stack<int> s;
	int root = INT_MIN;
	int n = A.size();
	for(int i = 0; i < n; i++){
		if(root != INT_MIN && A[i] < root)
			return 0;
		while(!s.empty() && s.top() < A[i]){
			root = s.top();
			s.pop();
		}
		s.push(A[i]);
	}
	return 1;
}
