vector<int> merge2(vector<int> &v1, vector<int> &v2){
	vector<int> ans;

	int i = 0, j = 0;
	int a, b;
	while(i < v1.size() || j < v2.size()){
		if(i < v1.size())
			a = v1[i];
		else
			a = 1e9;

		if(j < v2.size())
			b = v2[j];
		else
			b = 1e9;

		if(a < b){
			ans.push_back(a);
			i++;
		}

		else{
			ans.push_back(b);
			j++;
		}
	}

	return ans;
}

vector<int> merge(vector<vector<int>> &v, int start, int end){	
	vector<int> ans;
	if(start > end)
		return ans;

	int sz = end - start + 1;
	int mid = start + (end-start)/2;
	if(sz == 1)
		return v[start];

	if(sz == 2)
		return merge2(v[start], v[end]);

	vector<int> v1 = merge(v,start,mid);
	vector<int> v2 = merge(v,mid+1,end);

	return merge2(v1,v2);
}

vector<int> Solution::solve(vector<vector<int> > &A) {
	
	return merge(A,0,A.size()-1);
}

//or

vector<int> Solution::solve(vector<vector<int> > &A) {
	vector<int> ans;
	priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
	//val,pos in idx, idx
	for(int i = 0; i < A.size(); i++){
		pq.push({A[i][0],0,i});
	}

	while(!pq.empty()){
		auto val = pq.top()[0];
		auto aIdx = pq.top()[1];
		auto idx = pq.top()[2];

		pq.pop();

		ans.push_back(val);

		if(aIdx+1 != A[0].size()){
			pq.push({A[idx][aIdx+1],aIdx+1,idx});
		}
	}

	return ans;
}
