//Kruskal

bool comp(vector<int> &A, vector<int> &B){
	return A[2] < B[2];
}

class DSU{
	int V;
	int *parent;
	int *rank;

public:
	DSU(int V){
		this->V = V;
		parent = new int[V];
		rank = new int[V];
	
		for(int i = 0; i < V; i++){
			parent[i] = -1;
			rank[i] = 0;
		}
	}

	int find(int i){
		if(parent[i] == -1)
			return i;

		return parent[i] = find(parent[i]);
	}

	void unite(int i, int j){
		int s1 = find(i), s2 = find(j);

		if(s1 != s2){
			if(rank[s1] > rank[s2]){
				parent[s2] = s1;
				rank[s1] += rank[s2];
			}

			else{
				parent[s1] = s2;
				rank[s2] += rank[s1];
			}
		}
	}
};

int Solution::solve(int A, vector<vector<int> > &B) {
	DSU dsu(A+1);
	int cost = 0;
	sort(B.begin(), B.end(),comp);
	for(auto edge: B){
		int s1 = dsu.find(edge[0]), s2 = dsu.find(edge[1]);

		if(s1 != s2){
			dsu.unite(edge[0],edge[1]);
			cost += edge[2];
		}
	}

	return cost;

}

//Prim
int Solution::solve(int A, vector<vector<int> > &B) {
	vector<vector<pair<int,int>>> adjList(A+1);
	vector<bool> vis(A+1);

	for(auto edge: B){
		adjList[edge[0]].push_back({edge[2],edge[1]});
		adjList[edge[1]].push_back({edge[2],edge[0]});
	}

	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	pq.push({0,1});
	int cost = 0;

	while(!pq.empty()){
		int wt = pq.top().first, src = pq.top().second;
		pq.pop();
    	if(!vis[src]){
		    cost += wt;
		    vis[src] = 1;
    	}

		for(auto nbrPair : adjList[src]){
			auto wtEdge = nbrPair.first, nbr = nbrPair.second;

			if(!vis[nbr]){
			
				pq.push({wtEdge,nbr});
			}
		}
	}

	return cost;
}
