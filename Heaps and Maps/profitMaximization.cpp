int Solution::solve(vector<int> &A, int B) {
    
    priority_queue<int> pq;
    for(int x: A)
        pq.push(x);
        
    int ans = 0;
    
    while(B--){
        int it = pq.top();
        pq.pop();
        ans += it;
        pq.push(--it);
    }
    
    return ans;
    
}
