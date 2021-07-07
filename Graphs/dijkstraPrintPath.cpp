#include<bits/stdc++.h>

using namespace std;

#define endl "/n"
#define ll long long

class Graph{
	int V;
	unordered_map<int,vector<pair<int,int>>> mp; 
	// wt,node

public:
	Graph(int V){
		this->V = V;
		mp.clear();
	}

	void addEdge(int x, int y, int w){
		mp[x].push_back({w,y});
		mp[y].push_back({w,x});
	}

	void dijkstra(){
		int *parent = new int[V];
		int *dist = new int[V];
		bool *vis = new bool[V];

		for(int i = 0; i < V; i++){
			dist[i] = INT_MAX;
			parent[i] = -1;
			vis[i] = 0;		
		}

		priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
		//dist,node
		pq.push({0,0});	
		parent[0] = -1;
		dist[0] = 0;
		while(!pq.empty()){
			int distToCurr = pq.top().first, node = pq.top().second;
			pq.pop();
			vis[node] = 1;

			for(auto nbrPair: mp[node]){
				int wtEdge = nbrPair.first, nbr = nbrPair.second;
				if(!vis[nbr] && dist[nbr] > distToCurr + wtEdge){
					dist[nbr] = distToCurr + wtEdge;
					pq.push({dist[nbr],nbr});
					parent[nbr] = node;
				}
			}
		}


		if(dist[V-1] == INT_MAX){
			cout<<-1;
		}

		else{
			int vtx = V-1;
			list<int> ans;

			while(vtx != -1){
				ans.push_front(vtx);
				vtx = parent[vtx];
			}

			for(auto it: ans){
				cout<<it+1<<" ";
			}
		}
	}
};

int main(){
  	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    Graph g(n);
    while(m--){
    	int x, y, w;
    	cin >> x >> y >> w;
    	g.addEdge(x-1,y-1,w);
    }

    g.dijkstra();

}
