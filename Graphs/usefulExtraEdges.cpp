void dijkstra(vector<vector<pair<int,int>>> &adjList, vector<int> &dist, int src){
	priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>> pq;
	//dist,node

	int V = adjList.size();
	vector<bool> vis(V+1,0);

	dist[src] = 0;
	pq.push({0,src});

	while(!pq.empty()){
		int distToCurr = pq.top().first, node = pq.top().second;
		pq.pop();
		vis[node] = 1;

		for(auto nbrPair: adjList[node]){
			int wtEdge = nbrPair.first, nbr = nbrPair.second;

			if(!vis[nbr] && dist[nbr] > distToCurr + wtEdge){
				dist[nbr] = distToCurr + wtEdge;
				pq.push({dist[nbr],nbr});
			}
		}
	}

}

int Solution::solve(int V, vector<vector<int> > &B, int C, int D, vector<vector<int> > &E) {
	vector<vector<pair<int,int>>> adjList(V+1);
	// wt,node
	for(auto it: B){
		//B is directed but we need distEnd array thats why
		adjList[it[0]].push_back({it[2],it[1]});
		adjList[it[1]].push_back({it[2],it[0]});

	}

	vector<int> distStart(V+1,1e9);
	vector<int> distEnd(V+1,1e9);

	dijkstra(adjList,distStart,C);
	dijkstra(adjList,distEnd,D);

	int ans = distStart[D];

	for(auto it: E){
		int dist1 = distStart[it[0]] + distEnd[it[1]] + it[2];
		int dist2 = distStart[it[1]] + distEnd[it[0]] + it[2];
		ans = min({ans,dist1,dist2});
	}

	return ans == 1e9 ? -1 : ans;

}
