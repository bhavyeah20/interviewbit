void bfs(vector<vector<bool> > &edges, vector<int> &distance){
	queue<int> q;
	q.push(1);
	distance[1] = 0;

	while(!q.empty()){
		int v = q.front();
		q.pop();

		for(int i = 1; i <= 100; i++){
			if(edges[v][i] && distance[i] == -1){
				q.push(i);
				distance[i] = distance[v] + 1;
			}
		}
	}
}

int Solution::snakeLadder(vector<vector<int> > &A, vector<vector<int> > &B) {
	vector<vector<bool> > edges(101,vector<bool> (101,0));
	unordered_map<int,int> jump;

	for(int i = 0; i < A.size(); i++){
		jump[A[i][0]] = A[i][1] - A[i][0];
	}


	for(int i = 0; i < B.size(); i++){
		jump[B[i][0]] = B[i][1] - B[i][0];
	}

	for(int i = 1; i < 100; i++){
		for(int j = 1; j <= 6; j++){
			if(i+j+jump[i+j] <= 100)
				edges[i][i+j+jump[i+j]] = 1;
		}
	}
	vector<int> distance(101,-1);
	bfs(edges,distance);
	return distance[100];


}
