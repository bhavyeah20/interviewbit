#include<bits/stdc++.h>

using namespace std;


class Graph{
    int V;
    unordered_map<int,vector<pair<int,int>>> adjList;
public:
    Graph(int V){
        this->V = V;
        adjList.clear();
    }

    void addEdge(int x, int y, int w){
        adjList[x].push_back({w,y});
        adjList[y].push_back({w,x});
    }

    int primMST(){
        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> pq;
        vector<bool> vis(V,0);
        int cost = 0;
        pq.push({0,0});

        while(!pq.empty()){
            auto node = pq.top();
            pq.pop();

            int wt = node.first, to = node.second;

            if(vis[to])
                continue;

            cost += wt;

            for(auto nbr: adjList[to]){
                if(!vis[nbr.second]){
                    pq.push(nbr);
                }
            }
        }

        return cost;
    }
        
};

int main(){
    int n, m;
    cin >> n >> m;
    Graph g(n);

    while(m--){
        int a, b, w;
        cin >> a >> b >> w;
        g.addEdge(a-1,b-1,w);
    }

    cout<<g.primMST();
}
