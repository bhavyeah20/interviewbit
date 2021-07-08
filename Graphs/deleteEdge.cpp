#define ll long long

long long mod = 1e9 + 7;

ll calculateSum(int src, vector<vector<int>> &adjList, vector<bool> &vis, vector<int> &wt, vector<ll> &total,ll &ans, ll totalSumOfTree){
    ll sum = 0;
    vis[src] = 1;
    sum += wt[src];

    for(auto nbr: adjList[src]){
        if(!vis[nbr]){
            ll currNodeSum = calculateSum(nbr,adjList,vis,wt,total,ans,totalSumOfTree);
            sum += currNodeSum;
            ans = max(ans, ((((totalSumOfTree - total[nbr]) % mod) * (total[nbr] % mod))) % mod);
        }
    }

    total[src] = sum;
    return sum;
}

int Solution::deleteEdge(vector<int> &wt, vector<vector<int> > &edges) {
    int V = wt.size();
    vector<ll> total(V);
    vector<vector<int>> adjList(V);
    vector<bool> vis(V,0);

    for(auto edge: edges){
        adjList[edge[0]-1].push_back(edge[1]-1);
        adjList[edge[1]-1].push_back(edge[0]-1);
    }
    
    ll totalSumOfTree = 0;
    
    for(auto it: wt)
        totalSumOfTree += it;
    
    long long ans = 0;

    calculateSum(0,adjList,vis,wt,total,ans,totalSumOfTree);
    return ans;

}
