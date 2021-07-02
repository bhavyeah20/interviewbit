#include <bits/stdc++.h>

using namespace std;

#define ll long long

class Graph{
    unordered_map<ll, list<ll>> l;
    
public:
    Graph(){
        l.clear();
    }    
    
    void addEdge(ll x, ll y){
        l[x].push_back(y);
    }
    
    //counts nodes in a connected graph
    ll dfsHelper(ll src, ll cnt, vector<bool> &visited){
        visited[src] = 1;
        cnt = 1;
        
        for(auto nbr: l[src]){
            if(!visited[nbr]){
                cnt += dfsHelper(nbr,0,visited);
            }
        }
        
        return cnt;
    }
    
    ll dfs(ll n){
        vector<bool> visited(n,0);
        vector<ll> count;
        for(ll i = 0; i < n; i++){
            if(!visited[i]){
                count.push_back(dfsHelper(i,0,visited));
            }
        }
        
        vector<ll> prefix(count.size(),count.back());
        
        for(ll i = count.size() - 2; i >= 0; i--){
            prefix[i] = count[i] + prefix[i+1];
        }
        
        ll ans = 0;
        
        for(ll i = 0; i < prefix.size() - 1; i++){
            ans += 1LL * count[i] * prefix[i+1];
        }
        
        return ans;
    }
    
    void addEdges(ll n, vector<vector<int>> &astronaut){
        vector<ll> freq(n,0);
        for(ll i = 0; i < astronaut.size(); i++){
            freq[astronaut[i][0]]++;
            freq[astronaut[i][1]]++;            
            addEdge(astronaut[i][0], astronaut[i][1]);
            addEdge(astronaut[i][1], astronaut[i][0]);
            
        }
        
        for(ll i = 0; i < n; i++){
            if(!freq[i]){
                addEdge(i,i);
            }
        }
        
    }
};

ll journeyToMoon(int n, vector<vector<int>> astronaut) {
    Graph g;
    g.addEdges(n, astronaut);
    return g.dfs(n);
}
