#include<bits/stdc++.h>
using namespace std;

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

int main(){
    vector<int> A({ 40, 9, 58, 59, 20, 68, 49, 43, 7, 19, 52, 23, 14, 24, 63, 30, 55, 6, 79, 51, 61, 31, 60, 71, 29, 32, 8, 72, 56, 77, 41, 2, 44, 12, 27, 54, 3, 28, 36, 69, 17, 66, 33, 1, 46, 5, 53, 26, 39, 78, 62, 4, 80, 22, 76, 25, 18, 10, 74, 15, 35, 73, 82, 64, 42, 21, 45, 48, 67, 47, 34, 65, 38, 11, 13, 50, 81, 37, 75, 70, 57, 16});
    vector<int> B({51, 9, 58, 27, 20, 68, 49, 43, 7, 11, 53, 23, 14, 24, 21, 65, 8, 57, 75, 28, 61, 60, 40, 71, 34, 32, 55, 72, 56, 77, 47, 46, 44, 4, 59, 54, 42, 16, 36, 62, 17, 66, 33, 12, 2, 41, 52, 26, 39, 78, 74, 6, 80, 22, 76, 67, 18, 10, 69, 15, 35, 73, 82, 64, 3, 63, 45, 19, 25, 5, 29, 30, 38, 48, 13, 50, 81, 37, 79, 70, 31, 1 });

    vector<vector<int>> C({ {41, 53},
  {4, 35},
  {14, 82},
  {5, 60},
  {18, 38},
  {19, 79},
  {1, 23},
  {37, 65},
  {30, 81},
  {4, 58},
  {11, 47},
  {34, 44},
  {40, 51},
  {61, 75},
  {36, 56},
  {63, 73},
  {48, 58},
  {24, 31},
  {40, 59},
  {16, 57},
  {8, 43},
  {22, 23},
  {51, 59},
  {6, 46},
  {38, 44},
  {15, 66},
  {36, 69},
  {34, 52},
  {28, 60},
  {3, 41},
  {17, 27},
  {35, 58},
  {8, 71},
  {5, 28},
  {15, 80},
  {11, 64},
  {54, 70},
  {4, 48},
  {25, 71},
  {18, 44},
  {32, 45},
  {10, 74},
  {18, 52},
  {33, 55},
  {56, 69},
  {57, 72},
  {16, 72},
  {66, 80},
  {25, 43}});

    cout<<solve(A,B,C);
}
