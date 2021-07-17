int Solution::maxp3(vector<int> &A) {
	vector<int> v;
	sort(A.begin(), A.end());

	unordered_set<int> s;

	int n = A.size();

	for(int i = 0; i < 3 && i < n; i++){
		if(!(s.count(i))){
			s.insert(i);
			v.push_back(A[i]);
		}

		if(!(s.count(n-1-i))){
			s.insert(n-1-i);
			v.push_back(A[n-1-i]);
		}
	}

	int ans = INT_MIN;

	for(int i = 0; i < v.size(); i++){
		for(int j = i+1; j < v.size(); j++){
			for(int k = j+1; k < v.size(); k++){
				ans = max(ans, v[i]*v[j]*v[k]);
			}
		}
	}

	return ans;	
}

// or

int Solution::maxp3(vector<int> &A) {
    int a, b, c, z, y;
    a = b = c = INT_MIN;
    z = y = INT_MAX;

    for (auto k : A) {
        if (k > a)
            c = b, b = a, a = k;
        else if (k > b)
            c = b, b = k;
        else if (k > c)
            c = k;

        if (k < z)
            y = z, z = k;
        else if (k < y)
            y = k;
    }

    return max(a * b * c, a * z * y);
}