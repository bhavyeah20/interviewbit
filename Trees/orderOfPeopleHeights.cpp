//O(nlogn)
vector<int> segmentTree;
vector<int> ans;

//segmentTree[idx] holds number of vacant spots between arr[left,right]
void buildSegmentTree(int idx, int left, int right){
    if(left == right){
        segmentTree[idx] = 1;
        return ;
    }

    int mid = left + (right-left)/ 2;
    buildSegmentTree(2*idx+1,left,mid);
    buildSegmentTree(2*idx+2,mid+1,right);

    segmentTree[idx] = segmentTree[2*idx+1] + segmentTree[2*idx+2];
}

//each query puts the person at correct height
void query(int idx, int left, int right, int pos, int h){
    //leaf node
    if(left == right){
        ans[left] = h;
        segmentTree[idx]--;
        return ;
    }

    //if number of vacant spots are less than the require position
    if(segmentTree[idx] < pos)
        return ;

    int mid = left + (right-left)/ 2;
    
    //if leftsubtree can accomodate 
    if(segmentTree[2*idx+1] >= pos)
        query(2*idx+1,left,mid,pos,h);
    //else right tree will accomodate
    else
        query(2*idx+2,mid+1,right,pos-segmentTree[2*idx+1],h);

    //reduce vacant spots
    segmentTree[idx]--;

}

vector<int> Solution::order(vector<int> &heights, vector<int> &infronts) {

    segmentTree.clear();
    ans.clear();

    int n = heights.size();
    segmentTree.resize(4*n,0);
    ans.resize(n,0);

    vector<vector<int>> order;
    for(int i = 0; i < n; i++){
        order.push_back({heights[i],infronts[i]});
    }

    sort(order.begin(),order.end());

    buildSegmentTree(0,0,n-1);
    
    for(auto it: order){
        int h = it[0];
        int pos = it[1];

        query(0,0,n-1,pos+1,h);
        
    }
    
    return ans;

}


// O(n^2)

vector<int> Solution::order(vector<int> &heights, vector<int> &infronts) {
    int n = heights.size();
    vector<int> ans(n);

    vector<vector<int>> order;
    vector<int> sett(n);

    for(int i = 0; i < n; i++){
        order.push_back({heights[i],infronts[i]});
        sett[i] = i;
    }

    sort(order.begin(), order.end());

    for(auto it: order){
        int h = it[0];
        int pos = it[1];
        int actualPos = sett[pos];
        sett.erase(sett.begin()+pos);
        ans[actualPos] = h;
    }

    return ans;


}
