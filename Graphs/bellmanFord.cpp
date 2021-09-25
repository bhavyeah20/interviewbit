SSSP

idea: 1 edge at a time, 2 edges at a time, .... V-1 edges at a time
	: Works unless negative weight cycle

O(VE)

for(int i = 1; i <= V; i++){
	for(all directed edges(u,v)){
		if(dist[v] > dist[u] + wt[u][v])
			dist[v] = dist[u] + wt[u][v];
	}
}

for(all directed edges(u,v)){
	if(dist[v] > dist[u] + wt[u][v])
		graph contains negative weight cycle
}

