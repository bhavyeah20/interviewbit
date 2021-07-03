#include<bits/stdc++.h>

using namespace std;

class Graph{
    int V;
    list<pair<int,int>> l;

public:
    Graph(int V){
        this->V = V;
    }

    void addEdge(int x, int y){
        l.push_back({x,y});
    }

    int findSet(int i, int *parent){
        if(parent[i] == -1)
            return i;

        return parent[i] = findSet(parent[i],parent);
    }

    void unionSet(int i, int j, int *parent, int *rank){
        int s1 = findSet(i,parent);
        int s2 = findSet(j,parent);

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

    bool isCycle(){
        int *parent = new int[V];
        int *rank = new int[V];
        for(int i = 0; i < V; i++)
            parent[i] = -1, rank[i] = 1;

        for(auto edge: l){
            int i = edge.first, j = edge.second;

            int s1 = findSet(i,parent), s2 = findSet(j,parent);
            if(s1 != s2)
                unionSet(i,j,parent,rank);

            else{
                cout<<"Cycle present with parent "<<s1<<endl;
                return true;
            }
        }

        delete [] parent;
        delete [] rank;
        return false;
    }
};

int main(){
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    // g.addEdge(3,0);
    cout<<g.isCycle();

}

