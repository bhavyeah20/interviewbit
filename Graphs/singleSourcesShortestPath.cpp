void SSSP(int startingVertex, int N,unordered_map<int,vector<int>> adjList){
	vector<int> distance(N,-1);
	queue<int> q;
	q.push(startingVertex);
	distance[startingVertex] = 0;

	while(!q.empty()){
		int vtx = q.front();
		q.pop();

		for(auto child: adjList[vtx]){
			if(distance[child] == -1){
				q.push(child);
				distance[child] = distance[vtx] + 1;
			}
		}
	}

	for(int i = 0; i < N; i++)
		cout<<distance[vtx]<<endl;

}