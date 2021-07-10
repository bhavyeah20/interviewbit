// O(ElogE)

#include<bits/stdc++.h>

using namespace std;

class DSU{
    int V;
    int *parent;
    int *rank;
public:
    DSU(int V){
        this->V = V;
        parent = new int[V];
        rank = new int[V];

        for(int i = 0; i < V; i++)
            parent[i] = -1, rank[i] = 1;
    }

    int find(int i){
        if(parent[i] == -1)
            return i;

        return parent[i] = find(parent[i]);
    }

    void unite(int i, int j){
        int s1 = find(i), s2 = find(j);

        if(s1 != s2){
            if(rank[s1] < rank[s2]){
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }
            
            else{
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }
};

class Graph{
    int V;
    vector<vector<int> > edgeList;
public:
    Graph(int V){
        this->V = V;
        edgeList.clear();
    }

    void addEdge(int x, int y, int w){
        edgeList.push_back({w,x,y});
    }

    int kruskalMST(){
        DSU s(V);
        int cost = 0;

        sort(edgeList.begin(), edgeList.end());

        for(auto edge: edgeList){
            int x = edge[1], y = edge[2], w = edge[0];

            if(s.find(x) != s.find(y)){
                s.unite(x,y);
                cost += w;
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

    cout<<g.kruskalMST();



}
