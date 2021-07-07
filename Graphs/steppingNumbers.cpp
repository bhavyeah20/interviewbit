void dfs(int n, int m,int num,vector<int> &ans){
	if(num >= n && num <= m){
		ans.push_back(num);
	}

	if(num == 0 || num > m)
		return ;

	int lastDigit = num % 10;

	if(lastDigit == 0){
		dfs(n,m,num * 10 + 1,ans);
	}

	else if(lastDigit == 9){
		dfs(n,m,num * 10 + 8,ans);
	}
    
    else{
    	dfs(n,m,num * 10 + lastDigit + 1,ans);
    	dfs(n,m,num * 10 + lastDigit - 1,ans);
    }
}

vector<int> Solution::stepnum(int n, int m) {
	vector<int> ans;

	for(int i = 0; i <= 9; i++){
		dfs(n,m,i,ans);
	}
  	
  	sort(ans.begin(), ans.end());
  	return ans;
}



//or

void dfs(int n, int m,int digit, int dg, int curr, set<int> &ans, map<int, vector<int>> &adjList, int node){
	curr = curr * 10 + node;
	dg++;
	if(dg >= digit){
		if(curr >= n && curr <= m){
			ans.insert(curr);
		}
		return;
	}

	for(auto nbr: adjList[node]){
		dfs(n,m,digit,dg,curr,ans,adjList,nbr);
	}
}

vector<int> Solution::stepnum(int n, int m) {
	map<int, vector<int>> adjList;
	set<int> ans;
	for(int i = 1; i < 9; i++){
		adjList[i].push_back(i-1);
		adjList[i].push_back(i+1);
	}

	adjList[0].push_back(1), adjList[9].push_back(8);

	for(int digit = 1; digit <= 8; digit++){
		for(auto node: adjList){
			dfs(n,m,digit,0,0,ans,adjList,node.first);
		}
	}
    vector<int> res;
    for(auto it: ans){
        res.push_back(it);
    }
	return res;
}
