string Solution::multiple(int N) {
    if(N == 1) return "1";
    vector<string> dp(N);
    queue<int> q;
    q.push(1);
    dp[1] = "1";
    while(!q.empty()){
        int r = q.front();
        q.pop();
        if(r == 0){
            return dp[r];
        }

       
        for(int step = 0; step <= 1; step++){
            int newRem = (r*10+step)%N;
            if(dp[newRem].empty()){
                dp[newRem] = dp[r] + char(step + '0');
                q.push(newRem);
            }
        }
    }
}

//or


int rem(string s, int N){
	int r = 0;
	for(int i = 0; i < s.length(); i++){
		r = r*10 + (s[i] - '0');
		r %= N;
	}

	return r;
}

string Solution::multiple(int N) {
	vector<bool> vis(N,0);
	queue<string> q;
	q.push("1");

	while(!q.empty()){
		string s = q.front();
		q.pop();
		int r = rem(s,N);
		if(r == 0){
			return s;
		}

		if(!vis[r]){
			vis[r] = 1;
			q.push(s+"0");
			q.push(s+"1");
		}
	}
}
