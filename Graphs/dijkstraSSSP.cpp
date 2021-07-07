#include<bits/stdc++.h>

using namespace std;

class Graph{
    int V;
    unordered_map<int,vector<pair<int,int>>> adjList; // wt,node

public:
    Graph(int V){
        this->V = V;
        adjList.clear();
    }

    void addEdge(int x, int y, int w){
        adjList[x].push_back({w,y});
        adjList[y].push_back({w,x});
    }

    void dijkstra(){
        vector<int> distance(V,INT_MAX);

        // priority_queue<pair<int,int>, vector<pair<int,int>, greater<pair<int,int>> pq; pq gives min in O(1) and is in general faster than set
        // With pq multiple copies of vertices are inserted if distances are updated as final result of distance[] would be same
        set<pair<int,int>> s; //distance,node
        s.insert({0,0});
        distance[0] = 0;

        while(!s.empty()){
            auto node = *s.begin();
            s.erase(s.begin());

            int curr = node.first, src = node.second;

            for(auto nbr : adjList[src]){
                if(nbr.first + curr < distance[nbr.second]){
                    distance[nbr.second] = nbr.first + curr;
                    s.insert({distance[nbr.second], nbr.second}); // if searching a target, break here
                }
            }

        }

        for(auto it: distance){
            cout<<it<<" ";
        }
    }
        
};

int main(){
    Graph g(8);

    g.addEdge(0,1,1);
    g.addEdge(0,4,3);
    g.addEdge(1,2,1);
    g.addEdge(2,3,1);
    g.addEdge(3,4,2);
    g.addEdge(3,5,2);
    g.addEdge(5,6,4);
    g.addEdge(5,7,1);
    g.addEdge(6,7,1);

    g.dijkstra();



}
