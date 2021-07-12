int Solution::nchoc(int A, vector<int> &B) {
    int mod = 1e9 + 7;
    priority_queue<int> pq;
    for(auto it : B) pq.push(it);
    int ans = 0;
    while(A--){
        int t = pq.top(); 
        ans = ans % mod + t % mod;
        ans %= mod;
        pq.pop();
        pq.push(t/2);
    }
    
    return ans;
}
