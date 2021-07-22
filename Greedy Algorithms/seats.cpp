#define ll long long

int Solution::seats(string A) {
	vector<ll> gap;
	ll dist = 0, ans = 0;
	ll mod = 1e7+3;
	bool first = 0;
	for(auto ch : A){
		if(ch == 'x'){
			if(first)
				gap.push_back(dist);

			if(!first)
				first = 1;
			
			dist = 0;
		}

		else
			dist++;
	}


	ll sz = gap.size();
	if(!sz)
	    return 0;

	ll mid = (sz-1)/2;
	ll prev =0;
	for(ll i = mid; i >= 0; i--){
		prev = ((prev % mod) +  (gap[i] % mod)) % mod; 
		ans = ((ans % mod) +  (prev % mod)) % mod;
	}
	prev = 0;
	for(ll i = mid+1; i < sz; i++){
		prev = ((prev % mod) +  (gap[i] % mod)) % mod; 
		ans = ((ans % mod) +  (prev % mod)) % mod;
	}


	return ans % mod;
}
