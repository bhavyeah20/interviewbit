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
        parent[i] = -1;
    
    for(int i = 0; i < V; i++)
        rank[i] = 1;
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
            rank[s2] += rank[s1];
            parent[s1] = s2;
        }

        else{

            rank[s1] += rank[s2];
            parent[s2] = s1;
        }
    }
  }
};

int solve(vector<int> &A, vector<int> &B, vector<vector<int> > &C) {
    int V = A.size();
    DSU dsu(V);

    for(auto edge: C){
        int i = A[edge[0]-1]-1, j = A[edge[1]-1]-1;
        int s1 = dsu.find(i), s2 = dsu.find(j);

        if(s1 != s2)
            dsu.unite(i,j);
    }

    for(int i = 0; i < V; i++){
        if(dsu.find(A[i]-1) != dsu.find(B[i]-1))
            return 0;
    }

    return 1;
}