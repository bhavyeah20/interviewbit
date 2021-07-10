vector<vector<int>> adjList;
vector<int> hght;

int diameter(int src){
    int mx1 = 0, mx2 = 0;
    int d = 0;

    for(auto nbr: adjList[src]){

        d = max(d,diameter(nbr));
        //for dfs, hght[nbr] will always be known for src
        if(hght[nbr] > mx1){
            mx2 = mx1;
            mx1 = hght[nbr];
        }

        else if(hght[nbr] > mx2)
            mx2 = hght[nbr];
    }

  	hght[src] = mx1+1;
    return d = max(d,mx1+mx2);
}

int Solution::solve(vector<int> &A) {
    int V = A.size();

    adjList.clear();
    hght.clear();

    adjList.resize(V);
    hght.resize(V);

    hght.assign(V,1);

    for(int i = 0; i < V; i++){
        if(A[i] != -1)
            adjList[A[i]].push_back(i);
    }

    return diameter(0);
}
