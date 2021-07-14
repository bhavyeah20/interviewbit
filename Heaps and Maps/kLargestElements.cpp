vector<int> Solution::solve(vector<int> &A, int B) {
    priority_queue<int> pq;
    
    for(auto it: A)
        pq.push(it);
        
        
    vector<int> ans;
    while(B--){
        ans.push_back(pq.top());
        pq.pop();
    }
    
    return ans;
    
}

//or

// Quick select algo to find kth smallest in O(n)

int partition(int start, int end, vector<int> &nums, int k){
    
    if(start == end)
        return start;        
    
    int random = start + (rand() % (end-start+1));
    swap(nums[random], nums[end]);
    
    int idx = start;
    for(int i = start; i < end; i++){
        if(nums[i] < nums[end]){
            swap(nums[i], nums[idx]);
            idx++;
        }
    }
    
    swap(nums[end], nums[idx]);
    
    if(idx+1 == k)
        return idx;
    
    else if(idx+1 < k)
        return partition(idx+1,end,nums,k);
    
    return partition(start,idx-1,nums,k);
}
    
   
vector<int> Solution::solve(vector<int> &nums, int k) {
    k = nums.size() - k + 1;
    int idx = partition(0,nums.size()-1,nums,k);
    vector<int> ans(nums.begin()+idx, nums.end());
    return ans;
}

