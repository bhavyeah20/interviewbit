// Catalan number
// ncr  = n-1Cr + n-1Cr-1
#define ll long long

vector<vector<ll>> dp;

ll ncr(ll n, ll r){
	    

  if(r > n)
    return 0;
    if(r == 0 || n == 1)
        return 1;

    if(dp[n][r] != -1)
        return dp[n][r];

    return dp[n][r] = ncr(n-1,r-1) + ncr(n-1,r);

}


int Solution::numTrees(int A) {
    dp.clear();
    dp.resize(2*A+1,vector<ll> (2*A+1,-1));
    
    return ncr(2*A,A) / (A+1);
}


//or

// Place ith value as root. Total ways summation(ways(i-1) * ways(n-i))

int Solution::numTrees(int A) {
	vector<int> dp(A+1,0);
	dp[0] = dp[1] = 1;

	for(int i = 2; i <= A; i++){
		for(int j = 0; j < i; j++){
			dp[i] += dp[i-j-1] * dp[j];
		}
	}	

	return dp[A];
}